/*
 * Copyright (C) 2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 * Copyright (C) 2011 Denis 'GNUtoo' Carikli <GNUtoo@no-log.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

/*
 * TODO: change debug in logger calls
 */

//===========================================================================


int data_fd;
FsoAudio.PcmDevice pcm;
bool status = false;


//TODO: add fsomusicd config for that
const bool file_interface = false;
const bool loop_interface = false;
const bool alsa_interface = true;

const string voice_file = "/home/root/voice/voice_data.raw";


//===========================================================================

public static void handleAlsaSrc(CmtSpeech.FrameBuffer ulbuf)
{

}

public static void handleAlsaSink(CmtSpeech.FrameBuffer dlbuf)
{
	pcm.write( (uint8[])dlbuf.payload, ( dlbuf.pcount /2 ) );
}
public static void handleLoop(CmtSpeech.FrameBuffer ulbuf,
                              CmtSpeech.FrameBuffer dlbuf)
{
	if ( ulbuf.pcount == dlbuf.pcount ){
        debug( @"looping DL packet to UL with %u payload bytes".printf( dlbuf.pcount ) );
		Memory.copy( ulbuf.payload, dlbuf.payload, dlbuf.pcount );
	}else{
        debug( @"ulbuf.pcount(%d) != dlbuf.pcount(%d)",ulbuf.pcount,dlbuf.pcount );
	}

}

public static void handleFileSink(CmtSpeech.FrameBuffer dlbuf)
{
	Posix.write(data_fd,dlbuf.payload,dlbuf.pcount);
}
//===========================================================================
public static void fileSetup()
{
    debug( "Initializing File output");
    data_fd = Posix.open(voice_file,Posix.O_CREAT|Posix.O_WRONLY);
}

public static void alsaSinkSetup()
{
    int channels = 1;
    int rate = 8000;
    Alsa2.PcmFormat format = Alsa2.PcmFormat.S16_LE;
    Alsa2.PcmAccess access = Alsa2.PcmAccess.RW_INTERLEAVED;

    pcm = new FsoAudio.PcmDevice();
    debug (@"Setup alsa card for modem audio");
    try {
        //TODO: plug:default plughw:default plughw:0.0 plug:hw:0 could also be tried
        pcm.open("plug:dmix");
        pcm.setFormat(access,format, rate, channels );
    }catch(Error e){
        debug(@"Error: %s\n", e.message);
    }
}
//===========================================================================

public static void alsaSinkCleanup()
{
	pcm.close();
}

public static void fileCleanup()
{
	Posix.close(data_fd);
}

//===========================================================================

/**
 * @class CmtHandler
 *
 * Handles Audio via libcmtspeechdata
 **/
public class CmtHandler : FsoFramework.AbstractObject
{
    private CmtSpeech.Connection connection;
    private IOChannel channel;
    //
    // Private API
    //

    private void handleDataEvent()
    {
        assert( logger.debug( @"handleDataEvent during protocol state $(connection.protocol_state())" ) );

        CmtSpeech.FrameBuffer dlbuf = null;
        CmtSpeech.FrameBuffer ulbuf = null;

        var ok = connection.dl_buffer_acquire( out dlbuf );
        if ( ok == 0 )
        {
            assert( logger.debug( "received DL packet w/ %u bytes".printf( dlbuf.count ) ) );

            if (file_interface)
                handleFileSink(dlbuf);
            if (alsa_interface)
                handleAlsaSink(dlbuf);

            if ( connection.protocol_state() == CmtSpeech.State.ACTIVE_DLUL )
            {
                assert( logger.debug( "protocol state is ACTIVE_DLUL, uploading as well..." ) );
                ok = connection.ul_buffer_acquire( out ulbuf );

                if (loop_interface)
                    handleLoop(ulbuf,dlbuf);

                connection.ul_buffer_release( ulbuf );
            }
            connection.dl_buffer_release( dlbuf );
        }
    }

    private void handleControlEvent()
    {
        assert( logger.debug( @"handleControlEvent during protocol state $(connection.protocol_state())" ) );

        CmtSpeech.Event event = CmtSpeech.Event();
        CmtSpeech.Transition transition = 0;

        connection.read_event( event );

        assert( logger.debug( @"read event, type is $(event.msg_type)" ) );
        transition = connection.event_to_state_transition( event );

        switch( transition )
        {
            case CmtSpeech.Transition.INVALID:
              assert( logger.debug( "ERROR: invalid state transition") );
              break;

            case CmtSpeech.Transition.1_CONNECTED:
            case CmtSpeech.Transition.2_DISCONNECTED:
            case CmtSpeech.Transition.3_DL_START:
            case CmtSpeech.Transition.4_DLUL_STOP:
            case CmtSpeech.Transition.5_PARAM_UPDATE:
              assert( logger.debug( @"state transition ok, new state is $transition" ) );
              break;

            case CmtSpeech.Transition.6_TIMING_UPDATE:
            case CmtSpeech.Transition.7_TIMING_UPDATE:
              assert( logger.debug( "WARNING: modem UL timing update ignored" ) );
              break;

            case CmtSpeech.Transition.10_RESET:
            case CmtSpeech.Transition.11_UL_STOP:
            case CmtSpeech.Transition.12_UL_START:
              assert( logger.debug( @"state transition ok, new state is $transition" ) );
              break;

            default:
              assert_not_reached();
        }
    }

    private bool onInputFromChannel( IOChannel source, IOCondition condition )
    {
        assert( logger.debug( "onInputFromChannel, condition = %d".printf( condition ) ) );

        assert( condition == IOCondition.HUP || condition == IOCondition.IN );

        if ( condition == IOCondition.HUP )
        {
            logger.warning( "HUP! Will no longer handle input from cmtspeechdata" );
            return false;
        }

        CmtSpeech.EventType flags = 0;
        var ok = connection.check_pending( out flags );
        if ( ok < 0 )
        {
            assert( logger.debug( "error while checking for pending events..." ) );
        }
        else if ( ok == 0 )
        {
            assert( logger.debug( "D'oh, cmt speech readable, but no events pending..." ) );
        }
        else
        {
            assert( logger.debug( "connection reports pending events with flags 0x%0X".printf( flags ) ) );

            if ( ( flags & CmtSpeech.EventType.DL_DATA ) == CmtSpeech.EventType.DL_DATA )
            {
                handleDataEvent();
            }
            else if ( ( flags & CmtSpeech.EventType.CONTROL ) == CmtSpeech.EventType.CONTROL )
            {
                handleControlEvent();
            }
            else
            {
                assert( logger.debug( "event no DL_DATA nor CONTROL, ignoring" ) );
            }
        }

        return true;
    }

    //
    // Public API
    //

    public CmtHandler()
    {
        assert( logger.debug( "Initializing cmtspeech" ) );
        CmtSpeech.init();

        assert( logger.debug( "Setting up traces" ) );
        CmtSpeech.trace_toggle( CmtSpeech.TraceType.STATE_CHANGE, true );
        CmtSpeech.trace_toggle( CmtSpeech.TraceType.IO, true );
        CmtSpeech.trace_toggle( CmtSpeech.TraceType.DEBUG, true );

        assert( logger.debug( "Instanciating connection" ) );
        connection = new CmtSpeech.Connection();
        if ( connection == null )
        {
            logger.error( "Can't instanciate connection" );
            return;
        }

        var fd = connection.descriptor();

        if ( fd == -1 )
        {
            logger.error( "Cmtspeech file descriptor invalid" );
        }

        assert( logger.debug( "Hooking up fd with main loop" ) );
        channel = new IOChannel.unix_new( fd );
        channel.add_watch( IOCondition.IN | IOCondition.HUP, onInputFromChannel );

        logger.info( "Created" );
    }

    public override string repr()
    {
        CmtSpeech.State state = ( connection != null ) ? connection.protocol_state() : 0;
        return @"<$state>";
    }

    public void setAudioStatus( bool enabled )
    {
        if ( enabled == status )
        {
            debug(@"not %s", enabled ? "enabling" : "disabling" );
            return;
        }
        if ( enabled ){
            debug(@"enabling");
            if (file_interface)
                fileSetup();
            if (alsa_interface)
                alsaSinkSetup();
        }
        else{
            debug(@"disabling");
            if (file_interface)
                fileCleanup();
            if(alsa_interface)
                alsaSinkCleanup();
        }

        assert( logger.debug( @"Setting call status to $enabled" ) );
        connection.state_change_call_status( enabled );

        status = enabled;

    }
}

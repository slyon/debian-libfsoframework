/**
 * Copyright (C) 2009 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

using Alsa;

/**
 * Errordomain
 **/
public errordomain FsoFramework.SoundError
{
    NO_DEVICE,
    DEVICE_ERROR,
    NOT_ENOUGH_CONTROLS,
    INVALID_DESCRIPTOR,
}

/**
 * @class FsoFramework.SoundDevice
 **/
public class FsoFramework.SoundDevice : FsoFramework.AbstractObject
{
    private Card card;
    private ElemList list;
    public string name;
    public string fullname;
    public string mixername;

    private SoundDevice( ref Card card, ref ElemList list, string name, string fullname, string mixername )
    {
        this.card = (owned) card;
        this.list = (owned) list;
        this.name = name;
        this.fullname = fullname;
        this.mixername = mixername;
    }

    /**
     * Create @a SoundDevice class, attached to a specific Alsa card.
     **/
    public static SoundDevice create( string cardname = "default" ) throws SoundError
    {
        Card card;

        int res = Card.open( out card, cardname );
        if ( res < 0 )
            throw new SoundError.NO_DEVICE( "%s".printf( Alsa.strerror( res ) ) );

        CardInfo info;
        res = CardInfo.alloc( out info );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        res = card.card_info( info );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        ElemList list;
        res = ElemList.alloc( out list );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        res = card.elem_list( list );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        list.set_offset( 0 );
        res = list.alloc_space( list.get_count() );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        res = card.elem_list( list );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        return new SoundDevice( ref card, ref list, info.get_id(), info.get_longname(), info.get_mixername() );
    }

    public override string repr()
    {
        return "<Device %s>".printf( name );
    }

    private MixerControl controlForId( uint idx ) throws SoundError
    {
        ElemId eid;
        var res = ElemId.alloc( out eid );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        assert( list != null );
        list.get_id( idx, eid );

        ElemInfo info;
        res = ElemInfo.alloc( out info );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        info.set_id( eid );

        res = card.elem_info( info );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        ElemValue value;
        res = ElemValue.alloc( out value );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        value.set_id( eid );

        res = card.elem_read( value );
        if ( res < 0 )
            throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );

        return new MixerControl( ref eid, ref info, ref value );
    }

    /**
     * Set control to the value specified by @a MixerControl.
     **/
    public void setControl( MixerControl control ) throws SoundError
    {
        var type = control.info.get_type();
        if ( type != ElemType.IEC958 )
        {
            var res = card.elem_write( control.value );
            if ( res < 0 )
                throw new SoundError.DEVICE_ERROR( "%s".printf( Alsa.strerror( res ) ) );
        }
        else
            message( "ignoring IEC958 setting" );
    }

    /**
     * Get all controls (aka a scenario).
     **/
    public MixerControl[] allMixerControls() throws SoundError
    {
        MixerControl[] controls = {};
        var count = list.get_count();

        for ( int i = 0; i < count; ++i )
        {
            controls += controlForId( i );
        }
        return controls;
    }

    /**
     * Set all controls (aka a scenario).
     **/
    public void setAllMixerControls( MixerControl[] controls ) throws SoundError
    {
        foreach ( var control in controls )
            setControl( control );
    }

    /**
     * Construct @a MixerControl from a string description.
     **/
    public MixerControl controlForString( string description ) throws SoundError
    {
        var strings = description.split( ":" );
        if ( strings.length != 4 )
            throw new SoundError.INVALID_DESCRIPTOR( "Expected 4 descriptor components, got %d".printf( strings.length ) );
        var idx = strings[0].to_int();
        var name = strings[1].replace( "'", "" );
        var count = strings[2].to_int();
        var segments = strings[3].strip().split( "," );
        if ( segments.length != count )
            throw new SoundError.INVALID_DESCRIPTOR( "Expected %d value parameters, got %d".printf( count, segments.length ) );

        // populate defaults
        var control = controlForId( idx - 1 );
        // overwrite with values from string

        switch ( control.info.get_type() )
        {
            case ElemType.BOOLEAN:
                for ( var i = 0; i < count; ++i )
                    control.value.set_boolean( i, segments[i] == "1" );
                break;
            case ElemType.INTEGER:
                for ( var i = 0; i < count; ++i )
                    control.value.set_integer( i, segments[i].to_int() );
                break;
            case ElemType.INTEGER64:
                for ( var i = 0; i < count; ++i )
                    control.value.set_integer64( i, segments[i].to_int64() );
                break;
            case ElemType.ENUMERATED:
                for ( var i = 0; i < count; ++i )
                    control.value.set_enumerated( i, segments[i].to_int() );
                break;
            case ElemType.BYTES:
                for ( var i = 0; i < count; ++i )
                    control.value.set_byte( i, (uchar) ( segments[i].to_int() & 0xff ) );
                break;
            case ElemType.IEC958:
                message( "can't restore IEC958 element" );
                break;
            default:
                message( "unknown type %d... ignoring".printf( control.info.get_type() ) );
                break;
        }
        return control;
    }
}

/**
 * @class FsoFramework.MixerControl
 **/
public class FsoFramework.MixerControl
{
    public ElemId eid;
    public ElemInfo info;
    public ElemValue value;

    public MixerControl( ref ElemId eid, ref ElemInfo info, ref ElemValue value )
    {
        this.eid = (owned) eid;
        this.info = (owned) info;
        this.value = (owned) value;
    }

    public string to_string()
    {
        var infoline = "%u:'%s':%u:".printf( eid.get_numid(), eid.get_name(), info.get_count() );

        var type = info.get_type();
        var count = info.get_count();

        switch (type)
        {
            case ElemType.BOOLEAN:
                for ( var i = 0; i < count; ++i )
                    infoline += "%u,".printf( (uint)value.get_boolean( i ) );
                break;
            case ElemType.INTEGER:
                for ( var i = 0; i < count; ++i )
                    infoline += "%ld,".printf( value.get_integer( i ) );
                break;
            case ElemType.INTEGER64:
                for ( var i = 0; i < count; ++i )
                    infoline += "%ld,".printf( (long)value.get_integer64( i ) );
                break;
            case ElemType.ENUMERATED:
                for ( var i = 0; i < count; ++i )
                    infoline += "%u,".printf( value.get_enumerated( i ) );
                break;
            case ElemType.BYTES:
                for ( var i = 0; i < count; ++i )
                    infoline += "%2.2x,".printf( value.get_byte( i ) );
                break;
            case ElemType.IEC958:
                AesIec958 iec958 = {};
                value.get_iec958( iec958 );
                infoline += "<IEC958>";
                break;
            default:
                for ( var i = 0; i < count; ++i )
                    infoline += "<unknown>,";
                break;
        }
        return infoline;
    }
}


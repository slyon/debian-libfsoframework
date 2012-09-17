/*
 * Copyright (C) 2009-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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

using GLib;

public delegate void FsoFramework.KObjectNotifierFunc( HashTable<string, string> properties );

[Compact]
internal class KObjectDelegateHolder
{
    public FsoFramework.KObjectNotifierFunc func;
    public KObjectDelegateHolder( FsoFramework.KObjectNotifierFunc func )
    {
        this.func = func;
    }
}

/**
 * @class FsoFramework.BaseKObjectNotifier
 **/
public class FsoFramework.BaseKObjectNotifier : Object
{
    public static BaseKObjectNotifier instance;

    private int fd = -1;
    private uint watch;
    private IOChannel channel;

    private char[] buffer;

    private const ssize_t BUFFER_LENGTH = 4096;

    private HashTable<string, List<KObjectDelegateHolder>> add;
    private HashTable<string, List<KObjectDelegateHolder>> change;
    private HashTable<string, List<KObjectDelegateHolder>> remove;

    public BaseKObjectNotifier()
    {
        buffer = new char[BUFFER_LENGTH];

        add = new HashTable<string, List<KObjectDelegateHolder>>( str_hash, str_equal );
        change = new HashTable<string, List<KObjectDelegateHolder>>( str_hash, str_equal );
        remove = new HashTable<string, List<KObjectDelegateHolder>>( str_hash, str_equal );

        fd = Posix.socket( Linux.Socket.AF_NETLINK, Posix.SOCK_DGRAM, Linux.Netlink.NETLINK_KOBJECT_UEVENT );
        assert( fd != -1 );

        Linux.Netlink.SockAddrNl addr = { Linux.Socket.AF_NETLINK,
                                          0,
                                          Posix.getpid(),
                                          1 };
        var res = Posix.bind( fd, (void*)(&addr), sizeof( Linux.Netlink.SockAddrNl ) );
        assert( res != -1 );

        channel = new IOChannel.unix_new( fd );
        watch = channel.add_watch( IOCondition.IN | IOCondition.HUP, onActionFromSocket );
    }

    ~BaseKObjectNotifier()
    {
        if ( watch != 0 )
            Source.remove( watch );

        if ( fd != -1 )
            Posix.close( fd );
    }

    protected bool onActionFromSocket( IOChannel source, IOCondition condition )
    {
        if ( ( condition & IOCondition.HUP ) == IOCondition.HUP )
        {
            FsoFramework.theLogger.error( "HUP on kobject uevent socket, will no longer get any notifications" );
            return false;
        }

        if ( ( condition & IOCondition.IN ) == IOCondition.IN )
        {
            assert( fd != -1 );
            assert( buffer != null );
            ssize_t bytesread = Posix.read( fd, buffer, BUFFER_LENGTH );
            for( int i = 0; i < bytesread-1; ++i )
                if ( buffer[i] == 0x00 )
                    buffer[i] = 0x09;

            var parts = ( (string)buffer ).split( "\t" );

            handleMessage( parts );

            return true;
        }

        critical( "Unsupported IOCondition %u", (int)condition );
        return true;
    }

    protected void handleMessage( string[] parts )
    {
        var properties = new HashTable<string, string>( str_hash, str_equal );
        foreach ( var part in parts )
        {
#if DEBUG
            debug( @"$part" );
#endif
            var elements = part.split( "=" );
            if ( elements.length == 2 )
            {
                properties.insert( elements[0], elements[1] );
            }
        }

        var action = properties.lookup( "ACTION" );
        assert( action != null );
        var subsystem = properties.lookup( "SUBSYSTEM" );
        assert( subsystem != null );
#if DEBUG
        debug( @"Dealing with action $action for subsystem $subsystem" );
#endif

        HashTable<string, List<KObjectDelegateHolder>> table = null;

        switch( action )
        {
            case "add":
                table = add;
                break;
            case "change":
                table = change;
                break;
            case "remove":
                table = remove;
                break;
            default:
                FsoFramework.theLogger.warning( @"Unsupported kobject message action $action, must be one of { add, change, remove }" );
                break;
        }

        weak List<weak KObjectDelegateHolder> list = table.lookup( subsystem );
        if ( list == null )
            return;

        foreach( var delegateholder in list )
            delegateholder.func( properties );
    }

    protected void _addMatch( string action, string subsystem, KObjectNotifierFunc callback )
    {
        HashTable<string, List<KObjectDelegateHolder>> table = null;

        switch( action )
        {
            case "add":
                table = add;
                break;
            case "change":
                table = change;
                break;
            case "remove":
                table = remove;
                break;
            default:
                FsoFramework.theLogger.warning( @"Unsupported action $action in _addMatch, must be one of { add, change, remove }" );
                break;
        }

        weak List<KObjectDelegateHolder> list = table.lookup( subsystem );
        if ( list == null )
        {
            List<KObjectDelegateHolder> newlist = new List<KObjectDelegateHolder>();
            newlist.append( new KObjectDelegateHolder( callback ) );
#if DEBUG
            debug( @"# delegates for action $action and subsystem $subsystem now $(newlist.length())" );
#endif
            table.insert( subsystem, (owned) newlist );
        }
        else
        {
            list.append( new KObjectDelegateHolder( callback ) );
#if DEBUG
            debug( @"# delegates for action $action and subsystem $subsystem now $(list.length())" );
#endif
        }
    }

    //
    // public API
    //
    public static void addMatch( string action, string subsystem, KObjectNotifierFunc callback )
    {
        if ( BaseKObjectNotifier.instance == null )
            BaseKObjectNotifier.instance = new BaseKObjectNotifier();

        BaseKObjectNotifier.instance._addMatch( action, subsystem, callback );
    }

}

// vim:ts=4:sw=4:expandtab


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

namespace FsoFramework {

/**
 * AbstractSimpleResource: A DBus Resource API service object
 */
public abstract class AbstractDBusResource : FreeSmartphone.Resource, FsoFramework.AbstractObject
{
    private FsoFramework.DBusSubsystem subsystem;
    private FreeSmartphone.Usage usage;
    private ObjectPath path;
    private FsoFramework.DBusServiceNotifier dbusnotifier;
    private bool resourceRegistrationPending = false;
    private bool resourceRegistered = false;

    protected string name { get; private set; }

    private void onUsageServiceAppearing( string busname )
    {
        if (busname != FsoFramework.Usage.ServiceDBusName)
            return;

        if ( !resourceRegistered && !resourceRegistrationPending )
        {
            assert( logger.debug( @"$busname service appeared. Registering resource '$name' ..." ) );

            resourceRegistrationPending = true;
            Idle.add( () => { registerWithUsage(); return false; });
        }
    }

    private void onUsageServiceDisappearing( string busname )
    {
        if (busname != FsoFramework.Usage.ServiceDBusName)
            return;

        resourceRegistered = false;
    }

    public AbstractDBusResource( string name, FsoFramework.Subsystem subsystem )
    {
        this.name = name;
        this.subsystem = subsystem as FsoFramework.DBusSubsystem;
        this.path = new ObjectPath( "%s/%s".printf( FsoFramework.Resource.ServicePathPrefix, name ) );

        this.dbusnotifier = new FsoFramework.DBusServiceNotifier();
        this.dbusnotifier.notifyAppearing( FsoFramework.Usage.ServiceDBusName, onUsageServiceAppearing );
        this.dbusnotifier.notifyDisappearing( FsoFramework.Usage.ServiceDBusName, onUsageServiceDisappearing );

        resourceRegistrationPending = true;
        resourceRegistered = false;

        Idle.add( () => {
            registerWithUsage();
            return false;
        } );
    }

    public override string repr()
    {
        return @"<$name>";
    }

    public async void registerWithUsage()
    {
        var conn = subsystem.dbusConnection();
        assert( conn != null );

        try
        {
            conn.register_object<FreeSmartphone.Resource>( this.path, this );
            usage = yield conn.get_proxy<FreeSmartphone.Usage>( FsoFramework.Usage.ServiceDBusName, FsoFramework.Usage.ServicePathPrefix );
            yield usage.register_resource( name, path );

            logger.info( "Ok. Registered with org.freesmartphone.ousaged" );

            resourceRegistered = true;
        }
        catch ( Error e1 )
        {
            logger.error( @"Could not register $name with ousaged: $(e1.message); trying to enable the resource unconditionally" );
        }

        // If we could not register the resource we should enable the resource at least
        if ( !resourceRegistered )
        {
            try
            {
                yield enableResource();
            }
            catch ( Error e2 )
            {
                logger.error( @"Can't enable the resource: $(e2.message)" );
            }
        }

        resourceRegistrationPending = false;
    }

    /**
     * Override this to enable your resource. Only complete once the resource has been fully initialized.
     **/
    public abstract async void enableResource() throws FreeSmartphone.ResourceError;

    public abstract async void disableResource();

    public abstract async void suspendResource();

    public abstract async void resumeResource();

    /**
     * This method has a default implementation for backwards compatibility,
     * subclasses need to override this.
     **/
    public virtual async GLib.HashTable<string,GLib.Variant> dependencies()
    {
        return new GLib.HashTable<string,GLib.Variant?>( GLib.str_hash, GLib.str_equal );
    }

    public virtual FreeSmartphone.UsageResourcePolicy default_policy()
    {
        return FreeSmartphone.UsageResourcePolicy.AUTO;
    }

    //
    // DBUS API
    //
    public async void disable() throws FreeSmartphone.ResourceError, DBusError, IOError
    {
        assert( logger.debug( @"Disabling resource $classname..." ) );
        yield disableResource();
    }

    public async void enable() throws FreeSmartphone.ResourceError, DBusError, IOError
    {
        assert( logger.debug( @"Enabling resource $classname..." ) );
        yield enableResource();
    }

    public async void resume() throws FreeSmartphone.ResourceError, DBusError, IOError
    {
        assert( logger.debug( @"Resuming resource $classname..." ) );
        yield resumeResource();
    }

    public async void suspend() throws FreeSmartphone.ResourceError, DBusError, IOError
    {
        assert( logger.debug( @"Suspending resource $classname..." ) );
        yield suspendResource();
    }

    public async GLib.HashTable<string,GLib.Variant?> get_dependencies() throws DBusError, IOError
    {
        assert( logger.debug( @"Inquiring dependencies for $classname..." ) );
        var result = yield dependencies();
        return result;
    }

    public async FreeSmartphone.UsageResourcePolicy get_default_policy() throws FreeSmartphone.ResourceError, FreeSmartphone.Error, DBusError, IOError
    {
        assert( logger.debug( @"Inquiring default policy for $classname..." ) );
        var result = default_policy();
        return result;
    }
}

} /* namespace FsoFramework */

// vim:ts=4:sw=4:expandtab

/* fsoresource-2.0.vapi generated by valac 0.16.1, do not modify. */

namespace FsoFramework {
	[CCode (cheader_filename = "fsoresource.h")]
	public abstract class AbstractDBusResource : FreeSmartphone.Resource, FsoFramework.AbstractObject {
		public AbstractDBusResource (string name, FsoFramework.Subsystem subsystem);
		public virtual FreeSmartphone.UsageResourcePolicy default_policy ();
		public virtual async GLib.HashTable<string,GLib.Variant> dependencies ();
		public abstract async void disableResource ();
		public abstract async void enableResource () throws FreeSmartphone.ResourceError;
		public async void registerWithUsage ();
		public override string repr ();
		public abstract async void resumeResource ();
		public abstract async void suspendResource ();
		protected string name { get; private set; }
	}
}
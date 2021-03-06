/* gsm0710mux-1.0.vapi generated by valac 0.16.1, do not modify. */

namespace Gsm0710mux {
	[CCode (cheader_filename = "gsm0710mux.h")]
	public class ChannelInfo {
		public string consumer;
		public int number;
		public FsoFramework.Transport transport;
		public ChannelInfo ();
	}
	[CCode (cheader_filename = "gsm0710mux.h")]
	public class Manager : GLib.Object {
		public uint channel_ack_timeout;
		public static bool leave_fc_alone;
		public static bool leave_mux_alone;
		public Manager ();
		public async int allocChannel (Gsm0710mux.ChannelInfo channel) throws Gsm0710mux.MuxerError;
		public void closeSession () throws Gsm0710mux.MuxerError;
		public string getVersion ();
		public bool hasAutoSession ();
		public void openSession (bool advanced, int framesize, string porttype, string portname, int portspeed) throws Gsm0710mux.MuxerError;
		public void releaseChannel (string name) throws Gsm0710mux.MuxerError;
		public string repr ();
		public void setSendPauseThreshold (uint ms) throws Gsm0710mux.MuxerError;
		public void setStatus (int channel, string status) throws Gsm0710mux.MuxerError;
		public void setWakeupThreshold (uint seconds, uint waitms) throws Gsm0710mux.MuxerError;
		public void testCommand (uint8[] data) throws Gsm0710mux.MuxerError;
	}
	[CCode (cheader_filename = "gsm0710mux.h")]
	public errordomain MuxerError {
		CHANNEL_TAKEN,
		INVALID_CHANNEL,
		INVALID_TRANSPORT,
		NO_SESSION,
		NO_CHANNEL,
		SESSION_ALREADY_OPEN,
		SESSION_OPEN_ERROR
	}
}
namespace CONST {
}

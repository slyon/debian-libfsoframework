/* serial.c generated by valac 0.16.1, the Vala compiler
 * generated from serial.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


#define FSO_FRAMEWORK_TYPE_TRANSPORT (fso_framework_transport_get_type ())
#define FSO_FRAMEWORK_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT, FsoFrameworkTransport))
#define FSO_FRAMEWORK_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_TRANSPORT, FsoFrameworkTransportClass))
#define FSO_FRAMEWORK_IS_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT))
#define FSO_FRAMEWORK_IS_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_TRANSPORT))
#define FSO_FRAMEWORK_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT, FsoFrameworkTransportClass))

typedef struct _FsoFrameworkTransport FsoFrameworkTransport;
typedef struct _FsoFrameworkTransportClass FsoFrameworkTransportClass;
typedef struct _FsoFrameworkTransportPrivate FsoFrameworkTransportPrivate;

#define FSO_FRAMEWORK_TYPE_BASE_TRANSPORT (fso_framework_base_transport_get_type ())
#define FSO_FRAMEWORK_BASE_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, FsoFrameworkBaseTransport))
#define FSO_FRAMEWORK_BASE_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, FsoFrameworkBaseTransportClass))
#define FSO_FRAMEWORK_IS_BASE_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_BASE_TRANSPORT))
#define FSO_FRAMEWORK_IS_BASE_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_BASE_TRANSPORT))
#define FSO_FRAMEWORK_BASE_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, FsoFrameworkBaseTransportClass))

typedef struct _FsoFrameworkBaseTransport FsoFrameworkBaseTransport;
typedef struct _FsoFrameworkBaseTransportClass FsoFrameworkBaseTransportClass;
typedef struct _FsoFrameworkBaseTransportPrivate FsoFrameworkBaseTransportPrivate;

#define FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT (fso_framework_serial_transport_get_type ())
#define FSO_FRAMEWORK_SERIAL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT, FsoFrameworkSerialTransport))
#define FSO_FRAMEWORK_SERIAL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT, FsoFrameworkSerialTransportClass))
#define FSO_FRAMEWORK_IS_SERIAL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT))
#define FSO_FRAMEWORK_IS_SERIAL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT))
#define FSO_FRAMEWORK_SERIAL_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT, FsoFrameworkSerialTransportClass))

typedef struct _FsoFrameworkSerialTransport FsoFrameworkSerialTransport;
typedef struct _FsoFrameworkSerialTransportClass FsoFrameworkSerialTransportClass;
typedef struct _FsoFrameworkSerialTransportPrivate FsoFrameworkSerialTransportPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef void (*FsoFrameworkTransportFunc) (FsoFrameworkTransport* transport, void* user_data);
struct _FsoFrameworkTransport {
	GObject parent_instance;
	FsoFrameworkTransportPrivate * priv;
	FsoFrameworkLogger* logger;
};

struct _FsoFrameworkTransportClass {
	GObjectClass parent_class;
	gboolean (*isOpen) (FsoFrameworkTransport* self);
	void (*openAsync) (FsoFrameworkTransport* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*openAsync_finish) (FsoFrameworkTransport* self, GAsyncResult* _res_);
	gboolean (*open) (FsoFrameworkTransport* self);
	void (*close) (FsoFrameworkTransport* self);
	gchar* (*getName) (FsoFrameworkTransport* self);
	void (*setDelegates) (FsoFrameworkTransport* self, FsoFrameworkTransportFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target);
	void (*getDelegates) (FsoFrameworkTransport* self, FsoFrameworkTransportFunc* readfun, void** readfun_target, GDestroyNotify* readfun_target_destroy_notify, FsoFrameworkTransportFunc* hupfun, void** hupfun_target, GDestroyNotify* hupfun_target_destroy_notify);
	void (*setPriorities) (FsoFrameworkTransport* self, gint rp, gint wp);
	void (*setBuffered) (FsoFrameworkTransport* self, gboolean on);
	gint (*writeAndRead) (FsoFrameworkTransport* self, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait);
	gint (*read) (FsoFrameworkTransport* self, void* data, gint length);
	gint (*write) (FsoFrameworkTransport* self, void* data, gint length);
	gint (*freeze) (FsoFrameworkTransport* self);
	void (*thaw) (FsoFrameworkTransport* self);
	void (*drain) (FsoFrameworkTransport* self);
	void (*flush) (FsoFrameworkTransport* self);
	gboolean (*suspend) (FsoFrameworkTransport* self);
	void (*resume) (FsoFrameworkTransport* self);
};

struct _FsoFrameworkBaseTransport {
	FsoFrameworkTransport parent_instance;
	FsoFrameworkBaseTransportPrivate * priv;
	gchar* name;
	guint speed;
	gboolean raw;
	gboolean hard;
	gint fd;
	FsoFrameworkTransportFunc hupfunc;
	gpointer hupfunc_target;
	GDestroyNotify hupfunc_target_destroy_notify;
	FsoFrameworkTransportFunc readfunc;
	gpointer readfunc_target;
	GDestroyNotify readfunc_target_destroy_notify;
	GByteArray* buffer;
};

struct _FsoFrameworkBaseTransportClass {
	FsoFrameworkTransportClass parent_class;
	gssize (*_real_write) (FsoFrameworkBaseTransport* self, gint fd, void* data, gint len);
	void (*configure) (FsoFrameworkBaseTransport* self);
	gchar* (*repr) (FsoFrameworkBaseTransport* self);
	gssize (*_real_read) (FsoFrameworkBaseTransport* self, gint fd, void* data, gint len);
};

struct _FsoFrameworkSerialTransport {
	FsoFrameworkBaseTransport parent_instance;
	FsoFrameworkSerialTransportPrivate * priv;
	gboolean dtr_cycle;
};

struct _FsoFrameworkSerialTransportClass {
	FsoFrameworkBaseTransportClass parent_class;
};


static gpointer fso_framework_serial_transport_parent_class = NULL;

GType fso_framework_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_base_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_serial_transport_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_SERIAL_TRANSPORT_DUMMY_PROPERTY
};
FsoFrameworkSerialTransport* fso_framework_serial_transport_new (const gchar* portname, guint portspeed, gboolean raw, gboolean hard);
FsoFrameworkSerialTransport* fso_framework_serial_transport_construct (GType object_type, const gchar* portname, guint portspeed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
static gboolean fso_framework_serial_transport_set_dtr (FsoFrameworkSerialTransport* self, gboolean on);
static gboolean fso_framework_serial_transport_real_open (FsoFrameworkTransport* base);
void fso_framework_base_transport_configure (FsoFrameworkBaseTransport* self);
gboolean fso_framework_transport_open (FsoFrameworkTransport* self);
static gchar* fso_framework_serial_transport_real_repr (FsoFrameworkBaseTransport* base);
static void fso_framework_serial_transport_finalize (GObject* obj);


FsoFrameworkSerialTransport* fso_framework_serial_transport_construct (GType object_type, const gchar* portname, guint portspeed, gboolean raw, gboolean hard) {
	FsoFrameworkSerialTransport * self = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (portname != NULL, NULL);
	_tmp0_ = portname;
	_tmp1_ = portspeed;
	_tmp2_ = raw;
	_tmp3_ = hard;
	self = (FsoFrameworkSerialTransport*) fso_framework_base_transport_construct (object_type, _tmp0_, _tmp1_, _tmp2_, _tmp3_);
	self->dtr_cycle = FALSE;
	return self;
}


FsoFrameworkSerialTransport* fso_framework_serial_transport_new (const gchar* portname, guint portspeed, gboolean raw, gboolean hard) {
	return fso_framework_serial_transport_construct (FSO_FRAMEWORK_TYPE_SERIAL_TRANSPORT, portname, portspeed, raw, hard);
}


static gboolean fso_framework_serial_transport_set_dtr (FsoFrameworkSerialTransport* self, gboolean on) {
	gboolean result = FALSE;
	gint bits;
	gint rc = 0;
	gint _tmp0_ = 0;
	gboolean _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	gint _tmp4_ = 0;
	gint _tmp5_;
	g_return_val_if_fail (self != NULL, FALSE);
	bits = TIOCM_DTR;
	_tmp1_ = on;
	if (_tmp1_) {
		_tmp0_ = TIOCMBIS;
	} else {
		_tmp0_ = TIOCMBIC;
	}
	_tmp2_ = ((FsoFrameworkBaseTransport*) self)->fd;
	_tmp3_ = _tmp0_;
	_tmp4_ = ioctl (_tmp2_, _tmp3_, &bits);
	rc = _tmp4_;
	_tmp5_ = rc;
	if (_tmp5_ < 0) {
		FsoFrameworkLogger* _tmp6_;
		gint _tmp7_;
		const gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		_tmp6_ = ((FsoFrameworkTransport*) self)->logger;
		_tmp7_ = errno;
		_tmp8_ = strerror (_tmp7_);
		_tmp9_ = g_strdup_printf ("could not set dtr bit for serial transport: %s", _tmp8_);
		_tmp10_ = _tmp9_;
		fso_framework_logger_warning (_tmp6_, _tmp10_);
		_g_free0 (_tmp10_);
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}


static gboolean fso_framework_serial_transport_real_open (FsoFrameworkTransport* base) {
	FsoFrameworkSerialTransport * self;
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	gint _tmp2_;
	gboolean _tmp9_;
	gboolean _tmp10_ = FALSE;
	self = (FsoFrameworkSerialTransport*) base;
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->name;
	_tmp1_ = open (_tmp0_, (O_RDWR | O_NOCTTY) | O_NONBLOCK, (mode_t) 0);
	((FsoFrameworkBaseTransport*) self)->fd = _tmp1_;
	_tmp2_ = ((FsoFrameworkBaseTransport*) self)->fd;
	if (_tmp2_ == (-1)) {
		FsoFrameworkLogger* _tmp3_;
		const gchar* _tmp4_;
		gint _tmp5_;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		_tmp3_ = ((FsoFrameworkTransport*) self)->logger;
		_tmp4_ = ((FsoFrameworkBaseTransport*) self)->name;
		_tmp5_ = errno;
		_tmp6_ = strerror (_tmp5_);
		_tmp7_ = g_strdup_printf ("could not open %s: %s", _tmp4_, _tmp6_);
		_tmp8_ = _tmp7_;
		fso_framework_logger_warning (_tmp3_, _tmp8_);
		_g_free0 (_tmp8_);
		result = FALSE;
		return result;
	}
	fso_framework_base_transport_configure ((FsoFrameworkBaseTransport*) self);
	_tmp9_ = self->dtr_cycle;
	if (_tmp9_) {
		fso_framework_serial_transport_set_dtr (self, FALSE);
		sleep ((guint) 1);
		fso_framework_serial_transport_set_dtr (self, TRUE);
	}
	_tmp10_ = FSO_FRAMEWORK_TRANSPORT_CLASS (fso_framework_serial_transport_parent_class)->open ((FsoFrameworkTransport*) FSO_FRAMEWORK_BASE_TRANSPORT (self));
	result = _tmp10_;
	return result;
}


static gchar* fso_framework_serial_transport_real_repr (FsoFrameworkBaseTransport* base) {
	FsoFrameworkSerialTransport * self;
	gchar* result = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	gint _tmp2_;
	gchar* _tmp3_ = NULL;
	self = (FsoFrameworkSerialTransport*) base;
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->name;
	_tmp1_ = ((FsoFrameworkBaseTransport*) self)->speed;
	_tmp2_ = ((FsoFrameworkBaseTransport*) self)->fd;
	_tmp3_ = g_strdup_printf ("<Serial %s@%u (fd %d)>", _tmp0_, _tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


static void fso_framework_serial_transport_class_init (FsoFrameworkSerialTransportClass * klass) {
	fso_framework_serial_transport_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->open = fso_framework_serial_transport_real_open;
	FSO_FRAMEWORK_BASE_TRANSPORT_CLASS (klass)->repr = fso_framework_serial_transport_real_repr;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_serial_transport_finalize;
}


static void fso_framework_serial_transport_instance_init (FsoFrameworkSerialTransport * self) {
}


static void fso_framework_serial_transport_finalize (GObject* obj) {
	FsoFrameworkSerialTransport * self;
	self = FSO_FRAMEWORK_SERIAL_TRANSPORT (obj);
	G_OBJECT_CLASS (fso_framework_serial_transport_parent_class)->finalize (obj);
}


/**
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
GType fso_framework_serial_transport_get_type (void) {
	static volatile gsize fso_framework_serial_transport_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_serial_transport_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkSerialTransportClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_serial_transport_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkSerialTransport), 0, (GInstanceInitFunc) fso_framework_serial_transport_instance_init, NULL };
		GType fso_framework_serial_transport_type_id;
		fso_framework_serial_transport_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, "FsoFrameworkSerialTransport", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_serial_transport_type_id__volatile, fso_framework_serial_transport_type_id);
	}
	return fso_framework_serial_transport_type_id__volatile;
}



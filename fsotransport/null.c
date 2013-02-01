/* null.c generated by valac 0.16.1, the Vala compiler
 * generated from null.vala, do not modify */

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
/*===========================================================================*/

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>


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

#define FSO_FRAMEWORK_TYPE_NULL_TRANSPORT (fso_framework_null_transport_get_type ())
#define FSO_FRAMEWORK_NULL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransport))
#define FSO_FRAMEWORK_NULL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransportClass))
#define FSO_FRAMEWORK_IS_NULL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT))
#define FSO_FRAMEWORK_IS_NULL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT))
#define FSO_FRAMEWORK_NULL_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransportClass))

typedef struct _FsoFrameworkNullTransport FsoFrameworkNullTransport;
typedef struct _FsoFrameworkNullTransportClass FsoFrameworkNullTransportClass;
typedef struct _FsoFrameworkNullTransportPrivate FsoFrameworkNullTransportPrivate;

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

struct _FsoFrameworkNullTransport {
	FsoFrameworkBaseTransport parent_instance;
	FsoFrameworkNullTransportPrivate * priv;
};

struct _FsoFrameworkNullTransportClass {
	FsoFrameworkBaseTransportClass parent_class;
};


static gpointer fso_framework_null_transport_parent_class = NULL;

GType fso_framework_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_base_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_null_transport_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_NULL_TRANSPORT_DUMMY_PROPERTY
};
FsoFrameworkNullTransport* fso_framework_null_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkNullTransport* fso_framework_null_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
static gboolean fso_framework_null_transport_real_open (FsoFrameworkTransport* base);
static gboolean fso_framework_null_transport_real_isOpen (FsoFrameworkTransport* base);
static gchar* fso_framework_null_transport_real_repr (FsoFrameworkBaseTransport* base);
static gchar* fso_framework_null_transport_real_getName (FsoFrameworkTransport* base);
static void fso_framework_null_transport_real_close (FsoFrameworkTransport* base);
static gint fso_framework_null_transport_real_read (FsoFrameworkTransport* base, void* data, gint len);
static gint fso_framework_null_transport_real_write (FsoFrameworkTransport* base, void* data, gint len);
static gint fso_framework_null_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait);
static gint fso_framework_null_transport_real_freeze (FsoFrameworkTransport* base);
static void fso_framework_null_transport_real_thaw (FsoFrameworkTransport* base);


FsoFrameworkNullTransport* fso_framework_null_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard) {
	FsoFrameworkNullTransport * self = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	gboolean _tmp2_;
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = name;
	_tmp1_ = speed;
	_tmp2_ = raw;
	self = (FsoFrameworkNullTransport*) fso_framework_base_transport_construct (object_type, _tmp0_, _tmp1_, _tmp2_, TRUE);
	return self;
}


FsoFrameworkNullTransport* fso_framework_null_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard) {
	return fso_framework_null_transport_construct (FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, name, speed, raw, hard);
}


static gboolean fso_framework_null_transport_real_open (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	gboolean result = FALSE;
	self = (FsoFrameworkNullTransport*) base;
	result = TRUE;
	return result;
}


static gboolean fso_framework_null_transport_real_isOpen (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	gboolean result = FALSE;
	self = (FsoFrameworkNullTransport*) base;
	result = TRUE;
	return result;
}


static gchar* fso_framework_null_transport_real_repr (FsoFrameworkBaseTransport* base) {
	FsoFrameworkNullTransport * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoFrameworkNullTransport*) base;
	_tmp0_ = g_strdup ("<>");
	result = _tmp0_;
	return result;
}


static gchar* fso_framework_null_transport_real_getName (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (FsoFrameworkNullTransport*) base;
	_tmp0_ = g_strdup ("null");
	result = _tmp0_;
	return result;
}


static void fso_framework_null_transport_real_close (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	self = (FsoFrameworkNullTransport*) base;
}


static gint fso_framework_null_transport_real_read (FsoFrameworkTransport* base, void* data, gint len) {
	FsoFrameworkNullTransport * self;
	gint result = 0;
	gint _tmp0_;
	self = (FsoFrameworkNullTransport*) base;
	_tmp0_ = len;
	result = _tmp0_;
	return result;
}


static gint fso_framework_null_transport_real_write (FsoFrameworkTransport* base, void* data, gint len) {
	FsoFrameworkNullTransport * self;
	gint result = 0;
	gint _tmp0_;
	self = (FsoFrameworkNullTransport*) base;
	_tmp0_ = len;
	result = _tmp0_;
	return result;
}


static gint fso_framework_null_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait) {
	FsoFrameworkNullTransport * self;
	gint result = 0;
	gint _tmp0_;
	self = (FsoFrameworkNullTransport*) base;
	_tmp0_ = rlength;
	result = _tmp0_;
	return result;
}


static gint fso_framework_null_transport_real_freeze (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	gint result = 0;
	self = (FsoFrameworkNullTransport*) base;
	result = -1;
	return result;
}


static void fso_framework_null_transport_real_thaw (FsoFrameworkTransport* base) {
	FsoFrameworkNullTransport * self;
	self = (FsoFrameworkNullTransport*) base;
}


static void fso_framework_null_transport_class_init (FsoFrameworkNullTransportClass * klass) {
	fso_framework_null_transport_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->open = fso_framework_null_transport_real_open;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->isOpen = fso_framework_null_transport_real_isOpen;
	FSO_FRAMEWORK_BASE_TRANSPORT_CLASS (klass)->repr = fso_framework_null_transport_real_repr;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->getName = fso_framework_null_transport_real_getName;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->close = fso_framework_null_transport_real_close;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->read = fso_framework_null_transport_real_read;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->write = fso_framework_null_transport_real_write;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->writeAndRead = fso_framework_null_transport_real_writeAndRead;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->freeze = fso_framework_null_transport_real_freeze;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->thaw = fso_framework_null_transport_real_thaw;
}


static void fso_framework_null_transport_instance_init (FsoFrameworkNullTransport * self) {
}


GType fso_framework_null_transport_get_type (void) {
	static volatile gsize fso_framework_null_transport_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_null_transport_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkNullTransportClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_null_transport_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkNullTransport), 0, (GInstanceInitFunc) fso_framework_null_transport_instance_init, NULL };
		GType fso_framework_null_transport_type_id;
		fso_framework_null_transport_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, "FsoFrameworkNullTransport", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_null_transport_type_id__volatile, fso_framework_null_transport_type_id);
	}
	return fso_framework_null_transport_type_id__volatile;
}



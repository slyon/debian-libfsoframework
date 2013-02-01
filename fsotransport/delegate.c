/* delegate.c generated by valac 0.16.1, the Vala compiler
 * generated from delegate.vala, do not modify */

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

#define FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT (fso_framework_delegate_transport_get_type ())
#define FSO_FRAMEWORK_DELEGATE_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT, FsoFrameworkDelegateTransport))
#define FSO_FRAMEWORK_DELEGATE_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT, FsoFrameworkDelegateTransportClass))
#define FSO_FRAMEWORK_IS_DELEGATE_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT))
#define FSO_FRAMEWORK_IS_DELEGATE_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT))
#define FSO_FRAMEWORK_DELEGATE_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT, FsoFrameworkDelegateTransportClass))

typedef struct _FsoFrameworkDelegateTransport FsoFrameworkDelegateTransport;
typedef struct _FsoFrameworkDelegateTransportClass FsoFrameworkDelegateTransportClass;
typedef struct _FsoFrameworkDelegateTransportPrivate FsoFrameworkDelegateTransportPrivate;

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

struct _FsoFrameworkDelegateTransport {
	FsoFrameworkBaseTransport parent_instance;
	FsoFrameworkDelegateTransportPrivate * priv;
};

struct _FsoFrameworkDelegateTransportClass {
	FsoFrameworkBaseTransportClass parent_class;
};

typedef gint (*FsoFrameworkTransportDataFunc) (void* data, gint length, FsoFrameworkTransport* transport, void* user_data);
typedef gboolean (*FsoFrameworkTransportBoolFunc) (FsoFrameworkTransport* transport, void* user_data);
typedef gint (*FsoFrameworkTransportIntFunc) (FsoFrameworkTransport* transport, void* user_data);
struct _FsoFrameworkDelegateTransportPrivate {
	FsoFrameworkTransportDataFunc writefuncd;
	gpointer writefuncd_target;
	GDestroyNotify writefuncd_target_destroy_notify;
	FsoFrameworkTransportDataFunc readfuncd;
	gpointer readfuncd_target;
	GDestroyNotify readfuncd_target_destroy_notify;
	FsoFrameworkTransportFunc hupfuncd;
	gpointer hupfuncd_target;
	GDestroyNotify hupfuncd_target_destroy_notify;
	FsoFrameworkTransportBoolFunc openfuncd;
	gpointer openfuncd_target;
	GDestroyNotify openfuncd_target_destroy_notify;
	FsoFrameworkTransportFunc closefuncd;
	gpointer closefuncd_target;
	GDestroyNotify closefuncd_target_destroy_notify;
	FsoFrameworkTransportIntFunc freezefuncd;
	gpointer freezefuncd_target;
	GDestroyNotify freezefuncd_target_destroy_notify;
	FsoFrameworkTransportFunc thawfuncd;
	gpointer thawfuncd_target;
	GDestroyNotify thawfuncd_target_destroy_notify;
};


static gpointer fso_framework_delegate_transport_parent_class = NULL;

GType fso_framework_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_base_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_delegate_transport_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_DELEGATE_TRANSPORT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT, FsoFrameworkDelegateTransportPrivate))
enum  {
	FSO_FRAMEWORK_DELEGATE_TRANSPORT_DUMMY_PROPERTY
};
FsoFrameworkDelegateTransport* fso_framework_delegate_transport_new (FsoFrameworkTransportDataFunc writefunc, void* writefunc_target, FsoFrameworkTransportDataFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target, FsoFrameworkTransportBoolFunc openfunc, void* openfunc_target, FsoFrameworkTransportFunc closefunc, void* closefunc_target, FsoFrameworkTransportIntFunc freezefunc, void* freezefunc_target, FsoFrameworkTransportFunc thawfunc, void* thawfunc_target);
FsoFrameworkDelegateTransport* fso_framework_delegate_transport_construct (GType object_type, FsoFrameworkTransportDataFunc writefunc, void* writefunc_target, FsoFrameworkTransportDataFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target, FsoFrameworkTransportBoolFunc openfunc, void* openfunc_target, FsoFrameworkTransportFunc closefunc, void* closefunc_target, FsoFrameworkTransportIntFunc freezefunc, void* freezefunc_target, FsoFrameworkTransportFunc thawfunc, void* thawfunc_target);
FsoFrameworkBaseTransport* fso_framework_base_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
static gboolean fso_framework_delegate_transport_real_open (FsoFrameworkTransport* base);
static gboolean fso_framework_delegate_transport_real_isOpen (FsoFrameworkTransport* base);
static gint fso_framework_delegate_transport_real_write (FsoFrameworkTransport* base, void* data, gint length);
static gint fso_framework_delegate_transport_real_read (FsoFrameworkTransport* base, void* data, gint length);
static gint fso_framework_delegate_transport_real_freeze (FsoFrameworkTransport* base);
static void fso_framework_delegate_transport_real_thaw (FsoFrameworkTransport* base);
static void fso_framework_delegate_transport_real_close (FsoFrameworkTransport* base);
static void fso_framework_delegate_transport_real_setBuffered (FsoFrameworkTransport* base, gboolean on);
static gint fso_framework_delegate_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait);
static void fso_framework_delegate_transport_finalize (GObject* obj);


FsoFrameworkDelegateTransport* fso_framework_delegate_transport_construct (GType object_type, FsoFrameworkTransportDataFunc writefunc, void* writefunc_target, FsoFrameworkTransportDataFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target, FsoFrameworkTransportBoolFunc openfunc, void* openfunc_target, FsoFrameworkTransportFunc closefunc, void* closefunc_target, FsoFrameworkTransportIntFunc freezefunc, void* freezefunc_target, FsoFrameworkTransportFunc thawfunc, void* thawfunc_target) {
	FsoFrameworkDelegateTransport * self = NULL;
	FsoFrameworkTransportDataFunc _tmp0_;
	void* _tmp0__target;
	FsoFrameworkTransportDataFunc _tmp1_;
	void* _tmp1__target;
	FsoFrameworkTransportFunc _tmp2_;
	void* _tmp2__target;
	FsoFrameworkTransportBoolFunc _tmp3_;
	void* _tmp3__target;
	FsoFrameworkTransportFunc _tmp4_;
	void* _tmp4__target;
	FsoFrameworkTransportIntFunc _tmp5_;
	void* _tmp5__target;
	FsoFrameworkTransportFunc _tmp6_;
	void* _tmp6__target;
	self = (FsoFrameworkDelegateTransport*) fso_framework_base_transport_construct (object_type, "TransportDelegate", (guint) 0, TRUE, TRUE);
	_tmp0_ = writefunc;
	_tmp0__target = writefunc_target;
	(self->priv->writefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->writefuncd_target_destroy_notify (self->priv->writefuncd_target), NULL);
	self->priv->writefuncd = NULL;
	self->priv->writefuncd_target = NULL;
	self->priv->writefuncd_target_destroy_notify = NULL;
	self->priv->writefuncd = _tmp0_;
	self->priv->writefuncd_target = _tmp0__target;
	self->priv->writefuncd_target_destroy_notify = NULL;
	_tmp1_ = readfunc;
	_tmp1__target = readfunc_target;
	(self->priv->readfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->readfuncd_target_destroy_notify (self->priv->readfuncd_target), NULL);
	self->priv->readfuncd = NULL;
	self->priv->readfuncd_target = NULL;
	self->priv->readfuncd_target_destroy_notify = NULL;
	self->priv->readfuncd = _tmp1_;
	self->priv->readfuncd_target = _tmp1__target;
	self->priv->readfuncd_target_destroy_notify = NULL;
	_tmp2_ = hupfunc;
	_tmp2__target = hupfunc_target;
	(self->priv->hupfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->hupfuncd_target_destroy_notify (self->priv->hupfuncd_target), NULL);
	self->priv->hupfuncd = NULL;
	self->priv->hupfuncd_target = NULL;
	self->priv->hupfuncd_target_destroy_notify = NULL;
	self->priv->hupfuncd = _tmp2_;
	self->priv->hupfuncd_target = _tmp2__target;
	self->priv->hupfuncd_target_destroy_notify = NULL;
	_tmp3_ = openfunc;
	_tmp3__target = openfunc_target;
	(self->priv->openfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->openfuncd_target_destroy_notify (self->priv->openfuncd_target), NULL);
	self->priv->openfuncd = NULL;
	self->priv->openfuncd_target = NULL;
	self->priv->openfuncd_target_destroy_notify = NULL;
	self->priv->openfuncd = _tmp3_;
	self->priv->openfuncd_target = _tmp3__target;
	self->priv->openfuncd_target_destroy_notify = NULL;
	_tmp4_ = closefunc;
	_tmp4__target = closefunc_target;
	(self->priv->closefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->closefuncd_target_destroy_notify (self->priv->closefuncd_target), NULL);
	self->priv->closefuncd = NULL;
	self->priv->closefuncd_target = NULL;
	self->priv->closefuncd_target_destroy_notify = NULL;
	self->priv->closefuncd = _tmp4_;
	self->priv->closefuncd_target = _tmp4__target;
	self->priv->closefuncd_target_destroy_notify = NULL;
	_tmp5_ = freezefunc;
	_tmp5__target = freezefunc_target;
	(self->priv->freezefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->freezefuncd_target_destroy_notify (self->priv->freezefuncd_target), NULL);
	self->priv->freezefuncd = NULL;
	self->priv->freezefuncd_target = NULL;
	self->priv->freezefuncd_target_destroy_notify = NULL;
	self->priv->freezefuncd = _tmp5_;
	self->priv->freezefuncd_target = _tmp5__target;
	self->priv->freezefuncd_target_destroy_notify = NULL;
	_tmp6_ = thawfunc;
	_tmp6__target = thawfunc_target;
	(self->priv->thawfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->thawfuncd_target_destroy_notify (self->priv->thawfuncd_target), NULL);
	self->priv->thawfuncd = NULL;
	self->priv->thawfuncd_target = NULL;
	self->priv->thawfuncd_target_destroy_notify = NULL;
	self->priv->thawfuncd = _tmp6_;
	self->priv->thawfuncd_target = _tmp6__target;
	self->priv->thawfuncd_target_destroy_notify = NULL;
	return self;
}


FsoFrameworkDelegateTransport* fso_framework_delegate_transport_new (FsoFrameworkTransportDataFunc writefunc, void* writefunc_target, FsoFrameworkTransportDataFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target, FsoFrameworkTransportBoolFunc openfunc, void* openfunc_target, FsoFrameworkTransportFunc closefunc, void* closefunc_target, FsoFrameworkTransportIntFunc freezefunc, void* freezefunc_target, FsoFrameworkTransportFunc thawfunc, void* thawfunc_target) {
	return fso_framework_delegate_transport_construct (FSO_FRAMEWORK_TYPE_DELEGATE_TRANSPORT, writefunc, writefunc_target, readfunc, readfunc_target, hupfunc, hupfunc_target, openfunc, openfunc_target, closefunc, closefunc_target, freezefunc, freezefunc_target, thawfunc, thawfunc_target);
}


static gboolean fso_framework_delegate_transport_real_open (FsoFrameworkTransport* base) {
	FsoFrameworkDelegateTransport * self;
	gboolean result = FALSE;
	FsoFrameworkTransportBoolFunc _tmp0_;
	void* _tmp0__target;
	gboolean _tmp1_ = FALSE;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->openfuncd;
	_tmp0__target = self->priv->openfuncd_target;
	_tmp1_ = _tmp0_ ((FsoFrameworkTransport*) self, _tmp0__target);
	result = _tmp1_;
	return result;
}


static gboolean fso_framework_delegate_transport_real_isOpen (FsoFrameworkTransport* base) {
	FsoFrameworkDelegateTransport * self;
	gboolean result = FALSE;
	self = (FsoFrameworkDelegateTransport*) base;
	result = TRUE;
	return result;
}


static gint fso_framework_delegate_transport_real_write (FsoFrameworkTransport* base, void* data, gint length) {
	FsoFrameworkDelegateTransport * self;
	gint result = 0;
	FsoFrameworkTransportDataFunc _tmp0_;
	void* _tmp0__target;
	void* _tmp1_;
	gint _tmp2_;
	gint _tmp3_ = 0;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->writefuncd;
	_tmp0__target = self->priv->writefuncd_target;
	_tmp1_ = data;
	_tmp2_ = length;
	_tmp3_ = _tmp0_ (_tmp1_, _tmp2_, (FsoFrameworkTransport*) self, _tmp0__target);
	result = _tmp3_;
	return result;
}


static gint fso_framework_delegate_transport_real_read (FsoFrameworkTransport* base, void* data, gint length) {
	FsoFrameworkDelegateTransport * self;
	gint result = 0;
	FsoFrameworkTransportDataFunc _tmp0_;
	void* _tmp0__target;
	void* _tmp1_;
	gint _tmp2_;
	gint _tmp3_ = 0;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->readfuncd;
	_tmp0__target = self->priv->readfuncd_target;
	_tmp1_ = data;
	_tmp2_ = length;
	_tmp3_ = _tmp0_ (_tmp1_, _tmp2_, (FsoFrameworkTransport*) self, _tmp0__target);
	result = _tmp3_;
	return result;
}


static gint fso_framework_delegate_transport_real_freeze (FsoFrameworkTransport* base) {
	FsoFrameworkDelegateTransport * self;
	gint result = 0;
	FsoFrameworkTransportIntFunc _tmp0_;
	void* _tmp0__target;
	gint _tmp1_ = 0;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->freezefuncd;
	_tmp0__target = self->priv->freezefuncd_target;
	_tmp1_ = _tmp0_ ((FsoFrameworkTransport*) self, _tmp0__target);
	result = _tmp1_;
	return result;
}


static void fso_framework_delegate_transport_real_thaw (FsoFrameworkTransport* base) {
	FsoFrameworkDelegateTransport * self;
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->thawfuncd;
	_tmp0__target = self->priv->thawfuncd_target;
	_tmp0_ ((FsoFrameworkTransport*) self, _tmp0__target);
}


static void fso_framework_delegate_transport_real_close (FsoFrameworkTransport* base) {
	FsoFrameworkDelegateTransport * self;
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	self = (FsoFrameworkDelegateTransport*) base;
	_tmp0_ = self->priv->closefuncd;
	_tmp0__target = self->priv->closefuncd_target;
	_tmp0_ ((FsoFrameworkTransport*) self, _tmp0__target);
}


static void fso_framework_delegate_transport_real_setBuffered (FsoFrameworkTransport* base, gboolean on) {
	FsoFrameworkDelegateTransport * self;
	self = (FsoFrameworkDelegateTransport*) base;
}


static gint fso_framework_delegate_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait) {
	FsoFrameworkDelegateTransport * self;
	gint result = 0;
	self = (FsoFrameworkDelegateTransport*) base;
	g_assert_not_reached ();
	return result;
}


static void fso_framework_delegate_transport_class_init (FsoFrameworkDelegateTransportClass * klass) {
	fso_framework_delegate_transport_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkDelegateTransportPrivate));
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->open = fso_framework_delegate_transport_real_open;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->isOpen = fso_framework_delegate_transport_real_isOpen;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->write = fso_framework_delegate_transport_real_write;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->read = fso_framework_delegate_transport_real_read;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->freeze = fso_framework_delegate_transport_real_freeze;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->thaw = fso_framework_delegate_transport_real_thaw;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->close = fso_framework_delegate_transport_real_close;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->setBuffered = fso_framework_delegate_transport_real_setBuffered;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->writeAndRead = fso_framework_delegate_transport_real_writeAndRead;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_delegate_transport_finalize;
}


static void fso_framework_delegate_transport_instance_init (FsoFrameworkDelegateTransport * self) {
	self->priv = FSO_FRAMEWORK_DELEGATE_TRANSPORT_GET_PRIVATE (self);
}


static void fso_framework_delegate_transport_finalize (GObject* obj) {
	FsoFrameworkDelegateTransport * self;
	self = FSO_FRAMEWORK_DELEGATE_TRANSPORT (obj);
	(self->priv->writefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->writefuncd_target_destroy_notify (self->priv->writefuncd_target), NULL);
	self->priv->writefuncd = NULL;
	self->priv->writefuncd_target = NULL;
	self->priv->writefuncd_target_destroy_notify = NULL;
	(self->priv->readfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->readfuncd_target_destroy_notify (self->priv->readfuncd_target), NULL);
	self->priv->readfuncd = NULL;
	self->priv->readfuncd_target = NULL;
	self->priv->readfuncd_target_destroy_notify = NULL;
	(self->priv->hupfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->hupfuncd_target_destroy_notify (self->priv->hupfuncd_target), NULL);
	self->priv->hupfuncd = NULL;
	self->priv->hupfuncd_target = NULL;
	self->priv->hupfuncd_target_destroy_notify = NULL;
	(self->priv->openfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->openfuncd_target_destroy_notify (self->priv->openfuncd_target), NULL);
	self->priv->openfuncd = NULL;
	self->priv->openfuncd_target = NULL;
	self->priv->openfuncd_target_destroy_notify = NULL;
	(self->priv->closefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->closefuncd_target_destroy_notify (self->priv->closefuncd_target), NULL);
	self->priv->closefuncd = NULL;
	self->priv->closefuncd_target = NULL;
	self->priv->closefuncd_target_destroy_notify = NULL;
	(self->priv->freezefuncd_target_destroy_notify == NULL) ? NULL : (self->priv->freezefuncd_target_destroy_notify (self->priv->freezefuncd_target), NULL);
	self->priv->freezefuncd = NULL;
	self->priv->freezefuncd_target = NULL;
	self->priv->freezefuncd_target_destroy_notify = NULL;
	(self->priv->thawfuncd_target_destroy_notify == NULL) ? NULL : (self->priv->thawfuncd_target_destroy_notify (self->priv->thawfuncd_target), NULL);
	self->priv->thawfuncd = NULL;
	self->priv->thawfuncd_target = NULL;
	self->priv->thawfuncd_target_destroy_notify = NULL;
	G_OBJECT_CLASS (fso_framework_delegate_transport_parent_class)->finalize (obj);
}


/**
 * @class FsoFramework.DelegateTransport
 *
 * A delegate transport delegates all its operations to delegates.
 */
GType fso_framework_delegate_transport_get_type (void) {
	static volatile gsize fso_framework_delegate_transport_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_delegate_transport_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkDelegateTransportClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_delegate_transport_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkDelegateTransport), 0, (GInstanceInitFunc) fso_framework_delegate_transport_instance_init, NULL };
		GType fso_framework_delegate_transport_type_id;
		fso_framework_delegate_transport_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, "FsoFrameworkDelegateTransport", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_delegate_transport_type_id__volatile, fso_framework_delegate_transport_type_id);
	}
	return fso_framework_delegate_transport_type_id__volatile;
}



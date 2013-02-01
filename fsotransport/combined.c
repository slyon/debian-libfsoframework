/* combined.c generated by valac 0.16.1, the Vala compiler
 * generated from combined.vala, do not modify */

/*
 * Copyright (C) 2012 Simon Busch <morphis@gravedo.de>
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

#define FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT (fso_framework_combined_transport_get_type ())
#define FSO_FRAMEWORK_COMBINED_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT, FsoFrameworkCombinedTransport))
#define FSO_FRAMEWORK_COMBINED_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT, FsoFrameworkCombinedTransportClass))
#define FSO_FRAMEWORK_IS_COMBINED_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT))
#define FSO_FRAMEWORK_IS_COMBINED_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT))
#define FSO_FRAMEWORK_COMBINED_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT, FsoFrameworkCombinedTransportClass))

typedef struct _FsoFrameworkCombinedTransport FsoFrameworkCombinedTransport;
typedef struct _FsoFrameworkCombinedTransportClass FsoFrameworkCombinedTransportClass;
typedef struct _FsoFrameworkCombinedTransportPrivate FsoFrameworkCombinedTransportPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define FSO_FRAMEWORK_TYPE_NULL_TRANSPORT (fso_framework_null_transport_get_type ())
#define FSO_FRAMEWORK_NULL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransport))
#define FSO_FRAMEWORK_NULL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransportClass))
#define FSO_FRAMEWORK_IS_NULL_TRANSPORT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT))
#define FSO_FRAMEWORK_IS_NULL_TRANSPORT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT))
#define FSO_FRAMEWORK_NULL_TRANSPORT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_NULL_TRANSPORT, FsoFrameworkNullTransportClass))

typedef struct _FsoFrameworkNullTransport FsoFrameworkNullTransport;
typedef struct _FsoFrameworkNullTransportClass FsoFrameworkNullTransportClass;

#define FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC (fso_framework_transport_spec_get_type ())
#define FSO_FRAMEWORK_TRANSPORT_SPEC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC, FsoFrameworkTransportSpec))
#define FSO_FRAMEWORK_TRANSPORT_SPEC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC, FsoFrameworkTransportSpecClass))
#define FSO_FRAMEWORK_IS_TRANSPORT_SPEC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC))
#define FSO_FRAMEWORK_IS_TRANSPORT_SPEC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC))
#define FSO_FRAMEWORK_TRANSPORT_SPEC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_TRANSPORT_SPEC, FsoFrameworkTransportSpecClass))

typedef struct _FsoFrameworkTransportSpec FsoFrameworkTransportSpec;
typedef struct _FsoFrameworkTransportSpecClass FsoFrameworkTransportSpecClass;
#define _fso_framework_transport_spec_unref0(var) ((var == NULL) ? NULL : (var = (fso_framework_transport_spec_unref (var), NULL)))

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

struct _FsoFrameworkCombinedTransport {
	FsoFrameworkBaseTransport parent_instance;
	FsoFrameworkCombinedTransportPrivate * priv;
};

struct _FsoFrameworkCombinedTransportClass {
	FsoFrameworkBaseTransportClass parent_class;
};

struct _FsoFrameworkCombinedTransportPrivate {
	FsoFrameworkTransport* _rwtransport;
	FsoFrameworkTransport* _rotransport;
	gint readswitch;
};


static gpointer fso_framework_combined_transport_parent_class = NULL;

GType fso_framework_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_base_transport_get_type (void) G_GNUC_CONST;
GType fso_framework_combined_transport_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_COMBINED_TRANSPORT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT, FsoFrameworkCombinedTransportPrivate))
enum  {
	FSO_FRAMEWORK_COMBINED_TRANSPORT_DUMMY_PROPERTY
};
static void fso_framework_combined_transport_onRwTransportRead (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport);
static void fso_framework_combined_transport_onRwTransportHup (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport);
static void fso_framework_combined_transport_onRoTransportRead (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport);
static void fso_framework_combined_transport_onRoTransportHup (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport);
FsoFrameworkCombinedTransport* fso_framework_combined_transport_new (const gchar* specification);
FsoFrameworkCombinedTransport* fso_framework_combined_transport_construct (GType object_type, const gchar* specification);
FsoFrameworkBaseTransport* fso_framework_base_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkBaseTransport* fso_framework_base_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkNullTransport* fso_framework_null_transport_new (const gchar* name, guint speed, gboolean raw, gboolean hard);
FsoFrameworkNullTransport* fso_framework_null_transport_construct (GType object_type, const gchar* name, guint speed, gboolean raw, gboolean hard);
GType fso_framework_null_transport_get_type (void) G_GNUC_CONST;
gpointer fso_framework_transport_spec_ref (gpointer instance);
void fso_framework_transport_spec_unref (gpointer instance);
GParamSpec* fso_framework_param_spec_transport_spec (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_framework_value_set_transport_spec (GValue* value, gpointer v_object);
void fso_framework_value_take_transport_spec (GValue* value, gpointer v_object);
gpointer fso_framework_value_get_transport_spec (const GValue* value);
GType fso_framework_transport_spec_get_type (void) G_GNUC_CONST;
FsoFrameworkTransportSpec* fso_framework_transport_spec_parse (const gchar* line);
FsoFrameworkTransport* fso_framework_transport_spec_create (FsoFrameworkTransportSpec* self);
static gboolean fso_framework_combined_transport_real_open (FsoFrameworkTransport* base);
void fso_framework_transport_setDelegates (FsoFrameworkTransport* self, FsoFrameworkTransportFunc readfunc, void* readfunc_target, FsoFrameworkTransportFunc hupfunc, void* hupfunc_target);
static void _fso_framework_combined_transport_onRwTransportRead_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self);
static void _fso_framework_combined_transport_onRwTransportHup_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self);
static void _fso_framework_combined_transport_onRoTransportRead_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self);
static void _fso_framework_combined_transport_onRoTransportHup_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self);
gboolean fso_framework_transport_open (FsoFrameworkTransport* self);
void fso_framework_transport_close (FsoFrameworkTransport* self);
static gboolean fso_framework_combined_transport_real_isOpen (FsoFrameworkTransport* base);
gboolean fso_framework_transport_isOpen (FsoFrameworkTransport* self);
static gint fso_framework_combined_transport_real_write (FsoFrameworkTransport* base, void* data, gint length);
gint fso_framework_transport_write (FsoFrameworkTransport* self, void* data, gint length);
static gint fso_framework_combined_transport_real_read (FsoFrameworkTransport* base, void* data, gint length);
gint fso_framework_transport_read (FsoFrameworkTransport* self, void* data, gint length);
static gint fso_framework_combined_transport_real_freeze (FsoFrameworkTransport* base);
gint fso_framework_transport_freeze (FsoFrameworkTransport* self);
static void fso_framework_combined_transport_real_thaw (FsoFrameworkTransport* base);
void fso_framework_transport_thaw (FsoFrameworkTransport* self);
static void fso_framework_combined_transport_real_close (FsoFrameworkTransport* base);
static void fso_framework_combined_transport_real_setBuffered (FsoFrameworkTransport* base, gboolean on);
void fso_framework_transport_setBuffered (FsoFrameworkTransport* self, gboolean on);
static gint fso_framework_combined_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait);
gint fso_framework_transport_writeAndRead (FsoFrameworkTransport* self, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait);
static void fso_framework_combined_transport_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static void fso_framework_combined_transport_onRwTransportRead (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport) {
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	g_return_if_fail (self != NULL);
	g_return_if_fail (transport != NULL);
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->readfunc;
	_tmp0__target = ((FsoFrameworkBaseTransport*) self)->readfunc_target;
	if (_tmp0_ != NULL) {
		FsoFrameworkTransportFunc _tmp1_;
		void* _tmp1__target;
		FsoFrameworkTransport* _tmp2_;
		self->priv->readswitch = 0;
		_tmp1_ = ((FsoFrameworkBaseTransport*) self)->readfunc;
		_tmp1__target = ((FsoFrameworkBaseTransport*) self)->readfunc_target;
		_tmp2_ = transport;
		_tmp1_ (_tmp2_, _tmp1__target);
	}
}


static void fso_framework_combined_transport_onRwTransportHup (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport) {
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	g_return_if_fail (self != NULL);
	g_return_if_fail (transport != NULL);
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->hupfunc;
	_tmp0__target = ((FsoFrameworkBaseTransport*) self)->hupfunc_target;
	if (_tmp0_ != NULL) {
		FsoFrameworkTransportFunc _tmp1_;
		void* _tmp1__target;
		FsoFrameworkTransport* _tmp2_;
		_tmp1_ = ((FsoFrameworkBaseTransport*) self)->hupfunc;
		_tmp1__target = ((FsoFrameworkBaseTransport*) self)->hupfunc_target;
		_tmp2_ = transport;
		_tmp1_ (_tmp2_, _tmp1__target);
	}
}


static void fso_framework_combined_transport_onRoTransportRead (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport) {
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	g_return_if_fail (self != NULL);
	g_return_if_fail (transport != NULL);
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->readfunc;
	_tmp0__target = ((FsoFrameworkBaseTransport*) self)->readfunc_target;
	if (_tmp0_ != NULL) {
		FsoFrameworkTransportFunc _tmp1_;
		void* _tmp1__target;
		FsoFrameworkTransport* _tmp2_;
		self->priv->readswitch = 1;
		_tmp1_ = ((FsoFrameworkBaseTransport*) self)->readfunc;
		_tmp1__target = ((FsoFrameworkBaseTransport*) self)->readfunc_target;
		_tmp2_ = transport;
		_tmp1_ (_tmp2_, _tmp1__target);
	}
}


static void fso_framework_combined_transport_onRoTransportHup (FsoFrameworkCombinedTransport* self, FsoFrameworkTransport* transport) {
	FsoFrameworkTransportFunc _tmp0_;
	void* _tmp0__target;
	g_return_if_fail (self != NULL);
	g_return_if_fail (transport != NULL);
	_tmp0_ = ((FsoFrameworkBaseTransport*) self)->hupfunc;
	_tmp0__target = ((FsoFrameworkBaseTransport*) self)->hupfunc_target;
	if (_tmp0_ != NULL) {
		FsoFrameworkTransportFunc _tmp1_;
		void* _tmp1__target;
		FsoFrameworkTransport* _tmp2_;
		_tmp1_ = ((FsoFrameworkBaseTransport*) self)->hupfunc;
		_tmp1__target = ((FsoFrameworkBaseTransport*) self)->hupfunc_target;
		_tmp2_ = transport;
		_tmp1_ (_tmp2_, _tmp1__target);
	}
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


FsoFrameworkCombinedTransport* fso_framework_combined_transport_construct (GType object_type, const gchar* specification) {
	FsoFrameworkCombinedTransport * self = NULL;
	const gchar* _tmp0_;
	gchar** _tmp1_;
	gchar** _tmp2_ = NULL;
	gchar** specs;
	gint specs_length1;
	gint _specs_size_;
	gchar** _tmp3_;
	gint _tmp3__length1;
	gchar** _tmp11_;
	gint _tmp11__length1;
	const gchar* _tmp12_;
	FsoFrameworkTransportSpec* _tmp13_ = NULL;
	FsoFrameworkTransportSpec* _tmp14_;
	FsoFrameworkTransport* _tmp15_ = NULL;
	gchar** _tmp16_;
	gint _tmp16__length1;
	const gchar* _tmp17_;
	FsoFrameworkTransportSpec* _tmp18_ = NULL;
	FsoFrameworkTransportSpec* _tmp19_;
	FsoFrameworkTransport* _tmp20_ = NULL;
	g_return_val_if_fail (specification != NULL, NULL);
	self = (FsoFrameworkCombinedTransport*) fso_framework_base_transport_construct (object_type, "CombinedTransport", (guint) 0, TRUE, TRUE);
	_tmp0_ = specification;
	_tmp2_ = _tmp1_ = g_strsplit (_tmp0_, ",", 0);
	specs = _tmp2_;
	specs_length1 = _vala_array_length (_tmp1_);
	_specs_size_ = specs_length1;
	_tmp3_ = specs;
	_tmp3__length1 = specs_length1;
	if (_tmp3__length1 != 2) {
		FsoFrameworkLogger* _tmp4_;
		const gchar* _tmp5_;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		FsoFrameworkNullTransport* _tmp9_;
		FsoFrameworkNullTransport* _tmp10_;
		_tmp4_ = ((FsoFrameworkTransport*) self)->logger;
		_tmp5_ = specification;
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = g_strconcat ("Failed to create a combined transport; transport specification is inva" \
"lid: ", _tmp6_, NULL);
		_tmp8_ = _tmp7_;
		fso_framework_logger_error (_tmp4_, _tmp8_);
		_g_free0 (_tmp8_);
		_tmp9_ = fso_framework_null_transport_new ("null", (guint) 0, TRUE, TRUE);
		_g_object_unref0 (self->priv->_rwtransport);
		self->priv->_rwtransport = (FsoFrameworkTransport*) _tmp9_;
		_tmp10_ = fso_framework_null_transport_new ("null", (guint) 0, TRUE, TRUE);
		_g_object_unref0 (self->priv->_rotransport);
		self->priv->_rotransport = (FsoFrameworkTransport*) _tmp10_;
		specs = (_vala_array_free (specs, specs_length1, (GDestroyNotify) g_free), NULL);
		return self;
	}
	_tmp11_ = specs;
	_tmp11__length1 = specs_length1;
	_tmp12_ = _tmp11_[0];
	_tmp13_ = fso_framework_transport_spec_parse (_tmp12_);
	_tmp14_ = _tmp13_;
	_tmp15_ = fso_framework_transport_spec_create (_tmp14_);
	_g_object_unref0 (self->priv->_rwtransport);
	self->priv->_rwtransport = _tmp15_;
	_fso_framework_transport_spec_unref0 (_tmp14_);
	_tmp16_ = specs;
	_tmp16__length1 = specs_length1;
	_tmp17_ = _tmp16_[1];
	_tmp18_ = fso_framework_transport_spec_parse (_tmp17_);
	_tmp19_ = _tmp18_;
	_tmp20_ = fso_framework_transport_spec_create (_tmp19_);
	_g_object_unref0 (self->priv->_rotransport);
	self->priv->_rotransport = _tmp20_;
	_fso_framework_transport_spec_unref0 (_tmp19_);
	specs = (_vala_array_free (specs, specs_length1, (GDestroyNotify) g_free), NULL);
	return self;
}


FsoFrameworkCombinedTransport* fso_framework_combined_transport_new (const gchar* specification) {
	return fso_framework_combined_transport_construct (FSO_FRAMEWORK_TYPE_COMBINED_TRANSPORT, specification);
}


static void _fso_framework_combined_transport_onRwTransportRead_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self) {
	fso_framework_combined_transport_onRwTransportRead (self, transport);
}


static void _fso_framework_combined_transport_onRwTransportHup_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self) {
	fso_framework_combined_transport_onRwTransportHup (self, transport);
}


static void _fso_framework_combined_transport_onRoTransportRead_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self) {
	fso_framework_combined_transport_onRoTransportRead (self, transport);
}


static void _fso_framework_combined_transport_onRoTransportHup_fso_framework_transport_func (FsoFrameworkTransport* transport, gpointer self) {
	fso_framework_combined_transport_onRoTransportHup (self, transport);
}


static gboolean fso_framework_combined_transport_real_open (FsoFrameworkTransport* base) {
	FsoFrameworkCombinedTransport * self;
	gboolean result = FALSE;
	FsoFrameworkTransport* _tmp0_;
	FsoFrameworkTransport* _tmp1_;
	FsoFrameworkTransport* _tmp2_;
	gboolean _tmp3_ = FALSE;
	FsoFrameworkTransport* _tmp4_;
	gboolean _tmp5_ = FALSE;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	fso_framework_transport_setDelegates (_tmp0_, _fso_framework_combined_transport_onRwTransportRead_fso_framework_transport_func, self, _fso_framework_combined_transport_onRwTransportHup_fso_framework_transport_func, self);
	_tmp1_ = self->priv->_rotransport;
	fso_framework_transport_setDelegates (_tmp1_, _fso_framework_combined_transport_onRoTransportRead_fso_framework_transport_func, self, _fso_framework_combined_transport_onRoTransportHup_fso_framework_transport_func, self);
	_tmp2_ = self->priv->_rwtransport;
	_tmp3_ = fso_framework_transport_open (_tmp2_);
	if (!_tmp3_) {
		result = FALSE;
		return result;
	}
	_tmp4_ = self->priv->_rotransport;
	_tmp5_ = fso_framework_transport_open (_tmp4_);
	if (!_tmp5_) {
		FsoFrameworkTransport* _tmp6_;
		_tmp6_ = self->priv->_rwtransport;
		fso_framework_transport_close (_tmp6_);
		result = FALSE;
		return result;
	}
	result = TRUE;
	return result;
}


static gboolean fso_framework_combined_transport_real_isOpen (FsoFrameworkTransport* base) {
	FsoFrameworkCombinedTransport * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	FsoFrameworkTransport* _tmp1_;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp5_;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp1_ = self->priv->_rwtransport;
	_tmp2_ = fso_framework_transport_isOpen (_tmp1_);
	if (_tmp2_) {
		FsoFrameworkTransport* _tmp3_;
		gboolean _tmp4_ = FALSE;
		_tmp3_ = self->priv->_rotransport;
		_tmp4_ = fso_framework_transport_isOpen (_tmp3_);
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp5_ = _tmp0_;
	result = _tmp5_;
	return result;
}


static gint fso_framework_combined_transport_real_write (FsoFrameworkTransport* base, void* data, gint length) {
	FsoFrameworkCombinedTransport * self;
	gint result = 0;
	FsoFrameworkTransport* _tmp0_;
	void* _tmp1_;
	gint _tmp2_;
	gint _tmp3_ = 0;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	_tmp1_ = data;
	_tmp2_ = length;
	_tmp3_ = fso_framework_transport_write (_tmp0_, _tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


static gint fso_framework_combined_transport_real_read (FsoFrameworkTransport* base, void* data, gint length) {
	FsoFrameworkCombinedTransport * self;
	gint result = 0;
	gint _tmp0_;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->readswitch;
	if (_tmp0_ == 0) {
		FsoFrameworkTransport* _tmp1_;
		void* _tmp2_;
		gint _tmp3_;
		gint _tmp4_ = 0;
		_tmp1_ = self->priv->_rwtransport;
		_tmp2_ = data;
		_tmp3_ = length;
		_tmp4_ = fso_framework_transport_read (_tmp1_, _tmp2_, _tmp3_);
		result = _tmp4_;
		return result;
	} else {
		gint _tmp5_;
		_tmp5_ = self->priv->readswitch;
		if (_tmp5_ == 1) {
			FsoFrameworkTransport* _tmp6_;
			void* _tmp7_;
			gint _tmp8_;
			gint _tmp9_ = 0;
			_tmp6_ = self->priv->_rotransport;
			_tmp7_ = data;
			_tmp8_ = length;
			_tmp9_ = fso_framework_transport_read (_tmp6_, _tmp7_, _tmp8_);
			result = _tmp9_;
			return result;
		}
	}
	result = 0;
	return result;
}


static gint fso_framework_combined_transport_real_freeze (FsoFrameworkTransport* base) {
	FsoFrameworkCombinedTransport * self;
	gint result = 0;
	FsoFrameworkTransport* _tmp0_;
	FsoFrameworkTransport* _tmp1_;
	gint _tmp2_ = 0;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rotransport;
	fso_framework_transport_freeze (_tmp0_);
	_tmp1_ = self->priv->_rwtransport;
	_tmp2_ = fso_framework_transport_freeze (_tmp1_);
	result = _tmp2_;
	return result;
}


static void fso_framework_combined_transport_real_thaw (FsoFrameworkTransport* base) {
	FsoFrameworkCombinedTransport * self;
	FsoFrameworkTransport* _tmp0_;
	FsoFrameworkTransport* _tmp1_;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	fso_framework_transport_thaw (_tmp0_);
	_tmp1_ = self->priv->_rotransport;
	fso_framework_transport_thaw (_tmp1_);
}


static void fso_framework_combined_transport_real_close (FsoFrameworkTransport* base) {
	FsoFrameworkCombinedTransport * self;
	FsoFrameworkTransport* _tmp0_;
	FsoFrameworkTransport* _tmp1_;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	fso_framework_transport_close (_tmp0_);
	_tmp1_ = self->priv->_rotransport;
	fso_framework_transport_close (_tmp1_);
}


static void fso_framework_combined_transport_real_setBuffered (FsoFrameworkTransport* base, gboolean on) {
	FsoFrameworkCombinedTransport * self;
	FsoFrameworkTransport* _tmp0_;
	gboolean _tmp1_;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	_tmp1_ = on;
	fso_framework_transport_setBuffered (_tmp0_, _tmp1_);
}


static gint fso_framework_combined_transport_real_writeAndRead (FsoFrameworkTransport* base, void* wdata, gint wlength, void* rdata, gint rlength, gint maxWait) {
	FsoFrameworkCombinedTransport * self;
	gint result = 0;
	FsoFrameworkTransport* _tmp0_;
	void* _tmp1_;
	gint _tmp2_;
	void* _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	gint _tmp6_ = 0;
	self = (FsoFrameworkCombinedTransport*) base;
	_tmp0_ = self->priv->_rwtransport;
	_tmp1_ = wdata;
	_tmp2_ = wlength;
	_tmp3_ = rdata;
	_tmp4_ = rlength;
	_tmp5_ = maxWait;
	_tmp6_ = fso_framework_transport_writeAndRead (_tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_, _tmp5_);
	result = _tmp6_;
	return result;
}


static void fso_framework_combined_transport_class_init (FsoFrameworkCombinedTransportClass * klass) {
	fso_framework_combined_transport_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkCombinedTransportPrivate));
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->open = fso_framework_combined_transport_real_open;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->isOpen = fso_framework_combined_transport_real_isOpen;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->write = fso_framework_combined_transport_real_write;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->read = fso_framework_combined_transport_real_read;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->freeze = fso_framework_combined_transport_real_freeze;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->thaw = fso_framework_combined_transport_real_thaw;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->close = fso_framework_combined_transport_real_close;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->setBuffered = fso_framework_combined_transport_real_setBuffered;
	FSO_FRAMEWORK_TRANSPORT_CLASS (klass)->writeAndRead = fso_framework_combined_transport_real_writeAndRead;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_combined_transport_finalize;
}


static void fso_framework_combined_transport_instance_init (FsoFrameworkCombinedTransport * self) {
	self->priv = FSO_FRAMEWORK_COMBINED_TRANSPORT_GET_PRIVATE (self);
	self->priv->readswitch = 0;
}


static void fso_framework_combined_transport_finalize (GObject* obj) {
	FsoFrameworkCombinedTransport * self;
	self = FSO_FRAMEWORK_COMBINED_TRANSPORT (obj);
	_g_object_unref0 (self->priv->_rwtransport);
	_g_object_unref0 (self->priv->_rotransport);
	G_OBJECT_CLASS (fso_framework_combined_transport_parent_class)->finalize (obj);
}


GType fso_framework_combined_transport_get_type (void) {
	static volatile gsize fso_framework_combined_transport_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_combined_transport_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkCombinedTransportClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_combined_transport_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkCombinedTransport), 0, (GInstanceInitFunc) fso_framework_combined_transport_instance_init, NULL };
		GType fso_framework_combined_transport_type_id;
		fso_framework_combined_transport_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_TRANSPORT, "FsoFrameworkCombinedTransport", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_combined_transport_type_id__volatile, fso_framework_combined_transport_type_id);
	}
	return fso_framework_combined_transport_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




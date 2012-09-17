/* object.c generated by valac 0.16.0, the Vala compiler
 * generated from object.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT (fso_framework_abstract_object_get_type ())
#define FSO_FRAMEWORK_ABSTRACT_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, FsoFrameworkAbstractObject))
#define FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, FsoFrameworkAbstractObjectClass))
#define FSO_FRAMEWORK_IS_ABSTRACT_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT))
#define FSO_FRAMEWORK_IS_ABSTRACT_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT))
#define FSO_FRAMEWORK_ABSTRACT_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_ABSTRACT_OBJECT, FsoFrameworkAbstractObjectClass))

typedef struct _FsoFrameworkAbstractObject FsoFrameworkAbstractObject;
typedef struct _FsoFrameworkAbstractObjectClass FsoFrameworkAbstractObjectClass;
typedef struct _FsoFrameworkAbstractObjectPrivate FsoFrameworkAbstractObjectPrivate;

#define FSO_FRAMEWORK_TYPE_SMART_KEY_FILE (fso_framework_smart_key_file_get_type ())
#define FSO_FRAMEWORK_SMART_KEY_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_SMART_KEY_FILE, FsoFrameworkSmartKeyFile))
#define FSO_FRAMEWORK_SMART_KEY_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_SMART_KEY_FILE, FsoFrameworkSmartKeyFileClass))
#define FSO_FRAMEWORK_IS_SMART_KEY_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_SMART_KEY_FILE))
#define FSO_FRAMEWORK_IS_SMART_KEY_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_SMART_KEY_FILE))
#define FSO_FRAMEWORK_SMART_KEY_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_SMART_KEY_FILE, FsoFrameworkSmartKeyFileClass))

typedef struct _FsoFrameworkSmartKeyFile FsoFrameworkSmartKeyFile;
typedef struct _FsoFrameworkSmartKeyFileClass FsoFrameworkSmartKeyFileClass;

#define FSO_FRAMEWORK_TYPE_LOGGER (fso_framework_logger_get_type ())
#define FSO_FRAMEWORK_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_LOGGER, FsoFrameworkLogger))
#define FSO_FRAMEWORK_IS_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_LOGGER))
#define FSO_FRAMEWORK_LOGGER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_FRAMEWORK_TYPE_LOGGER, FsoFrameworkLoggerIface))

typedef struct _FsoFrameworkLogger FsoFrameworkLogger;
typedef struct _FsoFrameworkLoggerIface FsoFrameworkLoggerIface;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

typedef gchar* (*ReprDelegate) (void* user_data);
struct _FsoFrameworkLoggerIface {
	GTypeInterface parent_iface;
	void (*setLevel) (FsoFrameworkLogger* self, GLogLevelFlags level);
	void (*setDestination) (FsoFrameworkLogger* self, const gchar* destination);
	void (*setReprDelegate) (FsoFrameworkLogger* self, ReprDelegate repr, void* repr_target);
	GLogLevelFlags (*getLevel) (FsoFrameworkLogger* self);
	gchar* (*getDestination) (FsoFrameworkLogger* self);
	gboolean (*debug) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*info) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*warning) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*error) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*critical) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*data) (FsoFrameworkLogger* self, guint8* message, int message_length1, gboolean in, GLogLevelFlags when);
};

struct _FsoFrameworkAbstractObject {
	GObject parent_instance;
	FsoFrameworkAbstractObjectPrivate * priv;
	FsoFrameworkSmartKeyFile* config;
	FsoFrameworkLogger* logger;
	gchar* classname;
};

struct _FsoFrameworkAbstractObjectClass {
	GObjectClass parent_class;
	gchar* (*repr) (FsoFrameworkAbstractObject* self);
};


static gpointer fso_framework_abstract_object_parent_class = NULL;

GType fso_framework_abstract_object_get_type (void) G_GNUC_CONST;
GType fso_framework_smart_key_file_get_type (void) G_GNUC_CONST;
GType fso_framework_logger_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_ABSTRACT_OBJECT_DUMMY_PROPERTY
};
gchar* fso_framework_abstract_object_repr (FsoFrameworkAbstractObject* self);
static gchar* fso_framework_abstract_object_real_repr (FsoFrameworkAbstractObject* self);
FsoFrameworkAbstractObject* fso_framework_abstract_object_construct (GType object_type);
static GObject * fso_framework_abstract_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
FsoFrameworkSmartKeyFile* fso_framework_smart_key_file_defaultKeyFile (void);
FsoFrameworkLogger* fso_framework_logger_createFromKeyFile (FsoFrameworkSmartKeyFile* smk, const gchar* group, const gchar* domain);
void fso_framework_logger_setReprDelegate (FsoFrameworkLogger* self, ReprDelegate repr, void* repr_target);
static gchar* _fso_framework_abstract_object_repr_repr_delegate (gpointer self);
static void fso_framework_abstract_object_finalize (GObject* obj);


static gchar* fso_framework_abstract_object_real_repr (FsoFrameworkAbstractObject* self) {
	g_critical ("Type `%s' does not implement abstract method `fso_framework_abstract_object_repr'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar* fso_framework_abstract_object_repr (FsoFrameworkAbstractObject* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return FSO_FRAMEWORK_ABSTRACT_OBJECT_GET_CLASS (self)->repr (self);
}


FsoFrameworkAbstractObject* fso_framework_abstract_object_construct (GType object_type) {
	FsoFrameworkAbstractObject * self = NULL;
	self = (FsoFrameworkAbstractObject*) g_object_new (object_type, NULL);
	return self;
}


static gchar* _fso_framework_abstract_object_repr_repr_delegate (gpointer self) {
	gchar* result;
	result = fso_framework_abstract_object_repr (self);
	return result;
}


static GObject * fso_framework_abstract_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	FsoFrameworkAbstractObject * self;
	GType _tmp0_ = 0UL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	FsoFrameworkSmartKeyFile* _tmp3_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp4_;
	const gchar* _tmp5_;
	FsoFrameworkLogger* _tmp6_ = NULL;
	FsoFrameworkLogger* _tmp7_;
	parent_class = G_OBJECT_CLASS (fso_framework_abstract_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = FSO_FRAMEWORK_ABSTRACT_OBJECT (obj);
	_tmp0_ = G_TYPE_FROM_INSTANCE (self);
	_tmp1_ = g_type_name (_tmp0_);
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (self->classname);
	self->classname = _tmp2_;
	_tmp3_ = fso_framework_smart_key_file_defaultKeyFile ();
	_g_object_unref0 (self->config);
	self->config = _tmp3_;
	_tmp4_ = self->config;
	_tmp5_ = self->classname;
	_tmp6_ = fso_framework_logger_createFromKeyFile (_tmp4_, "logging", _tmp5_);
	_g_object_unref0 (self->logger);
	self->logger = _tmp6_;
	_tmp7_ = self->logger;
	fso_framework_logger_setReprDelegate (_tmp7_, _fso_framework_abstract_object_repr_repr_delegate, self);
	return obj;
}


static void fso_framework_abstract_object_class_init (FsoFrameworkAbstractObjectClass * klass) {
	fso_framework_abstract_object_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_ABSTRACT_OBJECT_CLASS (klass)->repr = fso_framework_abstract_object_real_repr;
	G_OBJECT_CLASS (klass)->constructor = fso_framework_abstract_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_abstract_object_finalize;
}


static void fso_framework_abstract_object_instance_init (FsoFrameworkAbstractObject * self) {
}


static void fso_framework_abstract_object_finalize (GObject* obj) {
	FsoFrameworkAbstractObject * self;
	self = FSO_FRAMEWORK_ABSTRACT_OBJECT (obj);
	_g_object_unref0 (self->config);
	_g_object_unref0 (self->logger);
	_g_free0 (self->classname);
	G_OBJECT_CLASS (fso_framework_abstract_object_parent_class)->finalize (obj);
}


/**
 * @class FsoFramework.BaseObject
 **/
GType fso_framework_abstract_object_get_type (void) {
	static volatile gsize fso_framework_abstract_object_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_abstract_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkAbstractObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_abstract_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkAbstractObject), 0, (GInstanceInitFunc) fso_framework_abstract_object_instance_init, NULL };
		GType fso_framework_abstract_object_type_id;
		fso_framework_abstract_object_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoFrameworkAbstractObject", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&fso_framework_abstract_object_type_id__volatile, fso_framework_abstract_object_type_id);
	}
	return fso_framework_abstract_object_type_id__volatile;
}




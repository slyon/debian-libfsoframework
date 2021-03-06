/* kernel.c generated by valac 0.16.1, the Vala compiler
 * generated from kernel.vala, do not modify */

/*
 * Copyright (C) 2010-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
#include <gobject/gvaluecollector.h>


#define FSO_FRAMEWORK_TYPE_KERNEL26_MODULE (fso_framework_kernel26_module_get_type ())
#define FSO_FRAMEWORK_KERNEL26_MODULE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE, FsoFrameworkKernel26Module))
#define FSO_FRAMEWORK_KERNEL26_MODULE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE, FsoFrameworkKernel26ModuleClass))
#define FSO_FRAMEWORK_IS_KERNEL26_MODULE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE))
#define FSO_FRAMEWORK_IS_KERNEL26_MODULE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE))
#define FSO_FRAMEWORK_KERNEL26_MODULE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE, FsoFrameworkKernel26ModuleClass))

typedef struct _FsoFrameworkKernel26Module FsoFrameworkKernel26Module;
typedef struct _FsoFrameworkKernel26ModuleClass FsoFrameworkKernel26ModuleClass;
typedef struct _FsoFrameworkKernel26ModulePrivate FsoFrameworkKernel26ModulePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _FsoFrameworkParamSpecKernel26Module FsoFrameworkParamSpecKernel26Module;

struct _FsoFrameworkKernel26Module {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FsoFrameworkKernel26ModulePrivate * priv;
};

struct _FsoFrameworkKernel26ModuleClass {
	GTypeClass parent_class;
	void (*finalize) (FsoFrameworkKernel26Module *self);
};

struct _FsoFrameworkKernel26ModulePrivate {
	gchar* _name;
	gboolean _active;
	gboolean _available;
	gchar* _arguments;
};

struct _FsoFrameworkParamSpecKernel26Module {
	GParamSpec parent_instance;
};


static gpointer fso_framework_kernel26_module_parent_class = NULL;

gpointer fso_framework_kernel26_module_ref (gpointer instance);
void fso_framework_kernel26_module_unref (gpointer instance);
GParamSpec* fso_framework_param_spec_kernel26_module (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void fso_framework_value_set_kernel26_module (GValue* value, gpointer v_object);
void fso_framework_value_take_kernel26_module (GValue* value, gpointer v_object);
gpointer fso_framework_value_get_kernel26_module (const GValue* value);
GType fso_framework_kernel26_module_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_KERNEL26_MODULE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_KERNEL26_MODULE, FsoFrameworkKernel26ModulePrivate))
enum  {
	FSO_FRAMEWORK_KERNEL26_MODULE_DUMMY_PROPERTY
};
static void fso_framework_kernel26_module_checkAvailability (FsoFrameworkKernel26Module* self);
const gchar* fso_framework_kernel26_module_get_name (FsoFrameworkKernel26Module* self);
static void fso_framework_kernel26_module_set_available (FsoFrameworkKernel26Module* self, gboolean value);
FsoFrameworkKernel26Module* fso_framework_kernel26_module_new (const gchar* name);
FsoFrameworkKernel26Module* fso_framework_kernel26_module_construct (GType object_type, const gchar* name);
void fso_framework_kernel26_module_set_name (FsoFrameworkKernel26Module* self, const gchar* value);
static void fso_framework_kernel26_module_set_active (FsoFrameworkKernel26Module* self, gboolean value);
gboolean fso_framework_kernel26_module_load (FsoFrameworkKernel26Module* self);
gboolean fso_framework_kernel26_module_get_available (FsoFrameworkKernel26Module* self);
gboolean fso_framework_kernel26_module_get_active (FsoFrameworkKernel26Module* self);
const gchar* fso_framework_kernel26_module_get_arguments (FsoFrameworkKernel26Module* self);
gboolean fso_framework_kernel26_module_unload (FsoFrameworkKernel26Module* self);
void fso_framework_kernel26_module_set_arguments (FsoFrameworkKernel26Module* self, const gchar* value);
static void fso_framework_kernel26_module_finalize (FsoFrameworkKernel26Module* obj);


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void fso_framework_kernel26_module_checkAvailability (FsoFrameworkKernel26Module* self) {
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gint _tmp5_ = 0;
	gint _tmp6_;
	gint rc;
	g_return_if_fail (self != NULL);
	_tmp0_ = fso_framework_kernel26_module_get_name (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = string_to_string (_tmp1_);
	_tmp3_ = g_strconcat ("/sbin/modinfo ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = system (_tmp4_);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	rc = _tmp6_;
	fso_framework_kernel26_module_set_available (self, rc == 0);
}


FsoFrameworkKernel26Module* fso_framework_kernel26_module_construct (GType object_type, const gchar* name) {
	FsoFrameworkKernel26Module* self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gint _tmp5_ = 0;
	gint _tmp6_;
	gint rc;
	g_return_val_if_fail (name != NULL, NULL);
	self = (FsoFrameworkKernel26Module*) g_type_create_instance (object_type);
	_tmp0_ = name;
	fso_framework_kernel26_module_set_name (self, _tmp0_);
	_tmp1_ = name;
	_tmp2_ = string_to_string (_tmp1_);
	_tmp3_ = g_strconcat ("/sbin/lsmod | grep ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = system (_tmp4_);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	rc = _tmp6_;
	fso_framework_kernel26_module_set_active (self, rc == 0);
	return self;
}


FsoFrameworkKernel26Module* fso_framework_kernel26_module_new (const gchar* name) {
	return fso_framework_kernel26_module_construct (FSO_FRAMEWORK_TYPE_KERNEL26_MODULE, name);
}


/**
         * Loads the named module into kernel space
         **/
gboolean fso_framework_kernel26_module_load (FsoFrameworkKernel26Module* self) {
	gboolean result = FALSE;
	gboolean _result_;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_result_ = FALSE;
	_tmp1_ = self->priv->_available;
	if (_tmp1_) {
		gboolean _tmp2_;
		_tmp2_ = self->priv->_active;
		_tmp0_ = !_tmp2_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		const gchar* _tmp6_ = NULL;
		const gchar* _tmp7_;
		const gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_;
		gint _tmp11_ = 0;
		gint _tmp12_;
		gint rc;
		gint _tmp13_;
		gboolean _tmp14_;
		_tmp4_ = fso_framework_kernel26_module_get_name (self);
		_tmp5_ = _tmp4_;
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = self->priv->_arguments;
		_tmp8_ = string_to_string (_tmp7_);
		_tmp9_ = g_strconcat ("/sbin/modprobe ", _tmp6_, " ", _tmp8_, NULL);
		_tmp10_ = _tmp9_;
		_tmp11_ = system (_tmp10_);
		_tmp12_ = _tmp11_;
		_g_free0 (_tmp10_);
		rc = _tmp12_;
		_tmp13_ = rc;
		_result_ = _tmp13_ == 0;
		_tmp14_ = _result_;
		fso_framework_kernel26_module_set_active (self, _tmp14_);
	}
	result = _result_;
	return result;
}


/**
         * Unloads the named module from kernel
         **/
gboolean fso_framework_kernel26_module_unload (FsoFrameworkKernel26Module* self) {
	gboolean result = FALSE;
	gboolean _result_;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_result_ = FALSE;
	_tmp1_ = self->priv->_available;
	if (_tmp1_) {
		gboolean _tmp2_;
		_tmp2_ = self->priv->_active;
		_tmp0_ = _tmp2_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		const gchar* _tmp4_;
		const gchar* _tmp5_;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		gint _tmp9_ = 0;
		gint _tmp10_;
		gint rc;
		gint _tmp11_;
		_tmp4_ = fso_framework_kernel26_module_get_name (self);
		_tmp5_ = _tmp4_;
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = g_strconcat ("/sbin/modprobe -r ", _tmp6_, NULL);
		_tmp8_ = _tmp7_;
		_tmp9_ = system (_tmp8_);
		_tmp10_ = _tmp9_;
		_g_free0 (_tmp8_);
		rc = _tmp10_;
		_tmp11_ = rc;
		_result_ = _tmp11_ == 0;
		fso_framework_kernel26_module_set_active (self, FALSE);
	}
	result = _result_;
	return result;
}


gboolean fso_framework_kernel26_module_get_active (FsoFrameworkKernel26Module* self) {
	gboolean result;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_active;
	result = _tmp0_;
	return result;
}


static void fso_framework_kernel26_module_set_active (FsoFrameworkKernel26Module* self, gboolean value) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_active = _tmp0_;
}


gboolean fso_framework_kernel26_module_get_available (FsoFrameworkKernel26Module* self) {
	gboolean result;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_available;
	result = _tmp0_;
	return result;
}


static void fso_framework_kernel26_module_set_available (FsoFrameworkKernel26Module* self, gboolean value) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_available = _tmp0_;
}


const gchar* fso_framework_kernel26_module_get_name (FsoFrameworkKernel26Module* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void fso_framework_kernel26_module_set_name (FsoFrameworkKernel26Module* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	fso_framework_kernel26_module_checkAvailability (self);
}


const gchar* fso_framework_kernel26_module_get_arguments (FsoFrameworkKernel26Module* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_arguments;
	result = _tmp0_;
	return result;
}


void fso_framework_kernel26_module_set_arguments (FsoFrameworkKernel26Module* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_arguments);
	self->priv->_arguments = _tmp1_;
}


static void fso_framework_value_kernel26_module_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void fso_framework_value_kernel26_module_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		fso_framework_kernel26_module_unref (value->data[0].v_pointer);
	}
}


static void fso_framework_value_kernel26_module_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = fso_framework_kernel26_module_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer fso_framework_value_kernel26_module_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* fso_framework_value_kernel26_module_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		FsoFrameworkKernel26Module* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = fso_framework_kernel26_module_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* fso_framework_value_kernel26_module_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	FsoFrameworkKernel26Module** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = fso_framework_kernel26_module_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* fso_framework_param_spec_kernel26_module (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	FsoFrameworkParamSpecKernel26Module* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer fso_framework_value_get_kernel26_module (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE), NULL);
	return value->data[0].v_pointer;
}


void fso_framework_value_set_kernel26_module (GValue* value, gpointer v_object) {
	FsoFrameworkKernel26Module* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		fso_framework_kernel26_module_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_framework_kernel26_module_unref (old);
	}
}


void fso_framework_value_take_kernel26_module (GValue* value, gpointer v_object) {
	FsoFrameworkKernel26Module* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FSO_FRAMEWORK_TYPE_KERNEL26_MODULE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		fso_framework_kernel26_module_unref (old);
	}
}


static void fso_framework_kernel26_module_class_init (FsoFrameworkKernel26ModuleClass * klass) {
	fso_framework_kernel26_module_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_KERNEL26_MODULE_CLASS (klass)->finalize = fso_framework_kernel26_module_finalize;
	g_type_class_add_private (klass, sizeof (FsoFrameworkKernel26ModulePrivate));
}


static void fso_framework_kernel26_module_instance_init (FsoFrameworkKernel26Module * self) {
	gchar* _tmp0_;
	self->priv = FSO_FRAMEWORK_KERNEL26_MODULE_GET_PRIVATE (self);
	self->priv->_active = FALSE;
	self->priv->_available = FALSE;
	_tmp0_ = g_strdup ("");
	self->priv->_arguments = _tmp0_;
	self->ref_count = 1;
}


static void fso_framework_kernel26_module_finalize (FsoFrameworkKernel26Module* obj) {
	FsoFrameworkKernel26Module * self;
	self = FSO_FRAMEWORK_KERNEL26_MODULE (obj);
	_g_free0 (self->priv->_name);
	_g_free0 (self->priv->_arguments);
}


/**
     * @class Kernel26Module
     **/
GType fso_framework_kernel26_module_get_type (void) {
	static volatile gsize fso_framework_kernel26_module_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_kernel26_module_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { fso_framework_value_kernel26_module_init, fso_framework_value_kernel26_module_free_value, fso_framework_value_kernel26_module_copy_value, fso_framework_value_kernel26_module_peek_pointer, "p", fso_framework_value_kernel26_module_collect_value, "p", fso_framework_value_kernel26_module_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkKernel26ModuleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_kernel26_module_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkKernel26Module), 0, (GInstanceInitFunc) fso_framework_kernel26_module_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType fso_framework_kernel26_module_type_id;
		fso_framework_kernel26_module_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FsoFrameworkKernel26Module", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&fso_framework_kernel26_module_type_id__volatile, fso_framework_kernel26_module_type_id);
	}
	return fso_framework_kernel26_module_type_id__volatile;
}


gpointer fso_framework_kernel26_module_ref (gpointer instance) {
	FsoFrameworkKernel26Module* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void fso_framework_kernel26_module_unref (gpointer instance) {
	FsoFrameworkKernel26Module* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FSO_FRAMEWORK_KERNEL26_MODULE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




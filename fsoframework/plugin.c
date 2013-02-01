/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>


#define FSO_FRAMEWORK_TYPE_SUBSYSTEM (fso_framework_subsystem_get_type ())
#define FSO_FRAMEWORK_SUBSYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_SUBSYSTEM, FsoFrameworkSubsystem))
#define FSO_FRAMEWORK_IS_SUBSYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_SUBSYSTEM))
#define FSO_FRAMEWORK_SUBSYSTEM_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_FRAMEWORK_TYPE_SUBSYSTEM, FsoFrameworkSubsystemIface))

typedef struct _FsoFrameworkSubsystem FsoFrameworkSubsystem;
typedef struct _FsoFrameworkSubsystemIface FsoFrameworkSubsystemIface;

#define FSO_FRAMEWORK_TYPE_PLUGIN_INFO (fso_framework_plugin_info_get_type ())
typedef struct _FsoFrameworkPluginInfo FsoFrameworkPluginInfo;
#define _g_free0(var) (var = (g_free (var), NULL))

#define FSO_FRAMEWORK_TYPE_PLUGIN (fso_framework_plugin_get_type ())
#define FSO_FRAMEWORK_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_PLUGIN, FsoFrameworkPlugin))
#define FSO_FRAMEWORK_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_PLUGIN))
#define FSO_FRAMEWORK_PLUGIN_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_FRAMEWORK_TYPE_PLUGIN, FsoFrameworkPluginIface))

typedef struct _FsoFrameworkPlugin FsoFrameworkPlugin;
typedef struct _FsoFrameworkPluginIface FsoFrameworkPluginIface;

#define FSO_FRAMEWORK_TYPE_BASE_PLUGIN (fso_framework_base_plugin_get_type ())
#define FSO_FRAMEWORK_BASE_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_BASE_PLUGIN, FsoFrameworkBasePlugin))
#define FSO_FRAMEWORK_BASE_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_BASE_PLUGIN, FsoFrameworkBasePluginClass))
#define FSO_FRAMEWORK_IS_BASE_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_BASE_PLUGIN))
#define FSO_FRAMEWORK_IS_BASE_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_BASE_PLUGIN))
#define FSO_FRAMEWORK_BASE_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_BASE_PLUGIN, FsoFrameworkBasePluginClass))

typedef struct _FsoFrameworkBasePlugin FsoFrameworkBasePlugin;
typedef struct _FsoFrameworkBasePluginClass FsoFrameworkBasePluginClass;
typedef struct _FsoFrameworkBasePluginPrivate FsoFrameworkBasePluginPrivate;
#define _g_module_close0(var) ((var == NULL) ? NULL : (var = (g_module_close (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

/**
 * Errors
 */
typedef enum  {
	FSO_FRAMEWORK_PLUGIN_ERROR_UNABLE_TO_LOAD,
	FSO_FRAMEWORK_PLUGIN_ERROR_REGISTER_NOT_FOUND,
	FSO_FRAMEWORK_PLUGIN_ERROR_FACTORY_NOT_FOUND,
	FSO_FRAMEWORK_PLUGIN_ERROR_UNABLE_TO_INITIALIZE
} FsoFrameworkPluginError;
#define FSO_FRAMEWORK_PLUGIN_ERROR fso_framework_plugin_error_quark ()
typedef void (*FsoFrameworkRegisterFunc) (GTypeModule* bar);
struct _FsoFrameworkPluginInfo {
	gchar* name;
	gboolean loaded;
};

struct _FsoFrameworkSubsystemIface {
	GTypeInterface parent_iface;
	guint (*registerPlugins) (FsoFrameworkSubsystem* self);
	guint (*loadPlugins) (FsoFrameworkSubsystem* self);
	gchar* (*name) (FsoFrameworkSubsystem* self);
	GList* (*pluginsInfo) (FsoFrameworkSubsystem* self);
	void (*registerObjectForService) (FsoFrameworkSubsystem* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const gchar* servicename, const gchar* objectpath, gconstpointer obj);
	void (*registerObjectForServiceWithPrefix) (FsoFrameworkSubsystem* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const gchar* servicename, const gchar* prefixpath, gconstpointer obj);
	void (*unregisterObjectForService) (FsoFrameworkSubsystem* self, GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, const gchar* servicename, const gchar* objectpath);
	GObject** (*allObjectsWithPrefix) (FsoFrameworkSubsystem* self, const gchar* prefix, int* result_length1);
	void (*shutdown) (FsoFrameworkSubsystem* self);
};

typedef gchar* (*FsoFrameworkFactoryFunc) (FsoFrameworkSubsystem* subsystem, GError** error);
typedef void (*FsoFrameworkShutdownFunc) ();
struct _FsoFrameworkPluginIface {
	GTypeInterface parent_iface;
	void (*loadAndInit) (FsoFrameworkPlugin* self, GError** error);
	void (*info) (FsoFrameworkPlugin* self, FsoFrameworkPluginInfo* result);
	void (*shutdown) (FsoFrameworkPlugin* self);
};

struct _FsoFrameworkBasePlugin {
	GTypeModule parent_instance;
	FsoFrameworkBasePluginPrivate * priv;
};

struct _FsoFrameworkBasePluginClass {
	GTypeModuleClass parent_class;
};

struct _FsoFrameworkBasePluginPrivate {
	gchar* filename;
	GModule* module;
	FsoFrameworkPluginInfo pluginInfo;
	FsoFrameworkSubsystem* subsystem;
};


static gpointer fso_framework_base_plugin_parent_class = NULL;
static FsoFrameworkPluginIface* fso_framework_base_plugin_fso_framework_plugin_parent_iface = NULL;

#define FSO_REGISTER_FUNCTION "fso_register_function"
#define FSO_FACTORY_FUNCTION "fso_factory_function"
#define FSO_SHUTDOWN_FUNCTION "fso_shutdown_function"
GQuark fso_framework_plugin_error_quark (void);
GType fso_framework_plugin_info_get_type (void) G_GNUC_CONST;
FsoFrameworkPluginInfo* fso_framework_plugin_info_dup (const FsoFrameworkPluginInfo* self);
void fso_framework_plugin_info_free (FsoFrameworkPluginInfo* self);
void fso_framework_plugin_info_copy (const FsoFrameworkPluginInfo* self, FsoFrameworkPluginInfo* dest);
void fso_framework_plugin_info_destroy (FsoFrameworkPluginInfo* self);
GType fso_framework_subsystem_get_type (void) G_GNUC_CONST;
GType fso_framework_plugin_get_type (void) G_GNUC_CONST;
void fso_framework_plugin_loadAndInit (FsoFrameworkPlugin* self, GError** error);
void fso_framework_plugin_info (FsoFrameworkPlugin* self, FsoFrameworkPluginInfo* result);
void fso_framework_plugin_shutdown (FsoFrameworkPlugin* self);
GType fso_framework_base_plugin_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_BASE_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_BASE_PLUGIN, FsoFrameworkBasePluginPrivate))
enum  {
	FSO_FRAMEWORK_BASE_PLUGIN_DUMMY_PROPERTY
};
FsoFrameworkBasePlugin* fso_framework_base_plugin_new (const gchar* filename, FsoFrameworkSubsystem* subsystem);
FsoFrameworkBasePlugin* fso_framework_base_plugin_construct (GType object_type, const gchar* filename, FsoFrameworkSubsystem* subsystem);
static void fso_framework_base_plugin_real_loadAndInit (FsoFrameworkPlugin* base, GError** error);
static void fso_framework_base_plugin_real_info (FsoFrameworkPlugin* base, FsoFrameworkPluginInfo* result);
static gboolean fso_framework_base_plugin_real_load (GTypeModule* base);
static void fso_framework_base_plugin_real_unload (GTypeModule* base);
static void fso_framework_base_plugin_real_shutdown (FsoFrameworkPlugin* base);
static void fso_framework_base_plugin_finalize (GObject* obj);


GQuark fso_framework_plugin_error_quark (void) {
	return g_quark_from_static_string ("fso_framework_plugin_error-quark");
}


void fso_framework_plugin_info_copy (const FsoFrameworkPluginInfo* self, FsoFrameworkPluginInfo* dest) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gboolean _tmp2_;
	_tmp0_ = (*self).name;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 ((*dest).name);
	(*dest).name = _tmp1_;
	_tmp2_ = (*self).loaded;
	(*dest).loaded = _tmp2_;
}


void fso_framework_plugin_info_destroy (FsoFrameworkPluginInfo* self) {
	_g_free0 ((*self).name);
}


FsoFrameworkPluginInfo* fso_framework_plugin_info_dup (const FsoFrameworkPluginInfo* self) {
	FsoFrameworkPluginInfo* dup;
	dup = g_new0 (FsoFrameworkPluginInfo, 1);
	fso_framework_plugin_info_copy (self, dup);
	return dup;
}


void fso_framework_plugin_info_free (FsoFrameworkPluginInfo* self) {
	fso_framework_plugin_info_destroy (self);
	g_free (self);
}


GType fso_framework_plugin_info_get_type (void) {
	static volatile gsize fso_framework_plugin_info_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_plugin_info_type_id__volatile)) {
		GType fso_framework_plugin_info_type_id;
		fso_framework_plugin_info_type_id = g_boxed_type_register_static ("FsoFrameworkPluginInfo", (GBoxedCopyFunc) fso_framework_plugin_info_dup, (GBoxedFreeFunc) fso_framework_plugin_info_free);
		g_once_init_leave (&fso_framework_plugin_info_type_id__volatile, fso_framework_plugin_info_type_id);
	}
	return fso_framework_plugin_info_type_id__volatile;
}


void fso_framework_plugin_loadAndInit (FsoFrameworkPlugin* self, GError** error) {
	g_return_if_fail (self != NULL);
	FSO_FRAMEWORK_PLUGIN_GET_INTERFACE (self)->loadAndInit (self, error);
}


void fso_framework_plugin_info (FsoFrameworkPlugin* self, FsoFrameworkPluginInfo* result) {
	g_return_if_fail (self != NULL);
	FSO_FRAMEWORK_PLUGIN_GET_INTERFACE (self)->info (self, result);
}


void fso_framework_plugin_shutdown (FsoFrameworkPlugin* self) {
	g_return_if_fail (self != NULL);
	FSO_FRAMEWORK_PLUGIN_GET_INTERFACE (self)->shutdown (self);
}


static void fso_framework_plugin_base_init (FsoFrameworkPluginIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


/**
 * Plugin
 */
GType fso_framework_plugin_get_type (void) {
	static volatile gsize fso_framework_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkPluginIface), (GBaseInitFunc) fso_framework_plugin_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_framework_plugin_type_id;
		fso_framework_plugin_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoFrameworkPlugin", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_framework_plugin_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&fso_framework_plugin_type_id__volatile, fso_framework_plugin_type_id);
	}
	return fso_framework_plugin_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


FsoFrameworkBasePlugin* fso_framework_base_plugin_construct (GType object_type, const gchar* filename, FsoFrameworkSubsystem* subsystem) {
	FsoFrameworkBasePlugin * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	FsoFrameworkSubsystem* _tmp2_;
	FsoFrameworkSubsystem* _tmp3_;
	FsoFrameworkPluginInfo _tmp4_ = {0};
	FsoFrameworkPluginInfo _tmp5_;
	g_return_val_if_fail (filename != NULL, NULL);
	g_return_val_if_fail (subsystem != NULL, NULL);
	self = (FsoFrameworkBasePlugin*) g_object_new (object_type, NULL);
	_tmp0_ = filename;
	_tmp1_ = g_strdup_printf ("%s.%s", _tmp0_, G_MODULE_SUFFIX);
	_g_free0 (self->priv->filename);
	self->priv->filename = _tmp1_;
	_tmp2_ = subsystem;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	_g_object_unref0 (self->priv->subsystem);
	self->priv->subsystem = _tmp3_;
	memset (&_tmp4_, 0, sizeof (FsoFrameworkPluginInfo));
	_g_free0 (_tmp4_.name);
	_tmp4_.name = NULL;
	_tmp4_.loaded = FALSE;
	fso_framework_plugin_info_destroy (&self->priv->pluginInfo);
	self->priv->pluginInfo = _tmp4_;
	_tmp5_ = self->priv->pluginInfo;
	g_object_ref ((GObject*) self);
	return self;
}


FsoFrameworkBasePlugin* fso_framework_base_plugin_new (const gchar* filename, FsoFrameworkSubsystem* subsystem) {
	return fso_framework_base_plugin_construct (FSO_FRAMEWORK_TYPE_BASE_PLUGIN, filename, subsystem);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void fso_framework_base_plugin_real_loadAndInit (FsoFrameworkPlugin* base, GError** error) {
	FsoFrameworkBasePlugin * self;
	const gchar* _tmp0_;
	GModule* _tmp1_ = NULL;
	GModule* _tmp2_;
	void* regfunc = NULL;
	GModule* _tmp11_;
	void* _tmp12_ = NULL;
	gboolean _tmp13_ = FALSE;
	gboolean ok;
	gboolean _tmp14_;
	void* _tmp22_;
	FsoFrameworkRegisterFunc fso_register_function;
	FsoFrameworkRegisterFunc _tmp23_;
	void* loadfunc = NULL;
	GModule* _tmp24_;
	void* _tmp25_ = NULL;
	gboolean _tmp26_ = FALSE;
	gboolean _tmp27_;
	void* _tmp35_;
	FsoFrameworkFactoryFunc fso_factory_func;
	GError * _inner_error_ = NULL;
	self = (FsoFrameworkBasePlugin*) base;
	_tmp0_ = self->priv->filename;
	_tmp1_ = g_module_open (_tmp0_, G_MODULE_BIND_LAZY | G_MODULE_BIND_LOCAL);
	_g_module_close0 (self->priv->module);
	self->priv->module = _tmp1_;
	_tmp2_ = self->priv->module;
	if (_tmp2_ == NULL) {
		const gchar* _tmp3_;
		const gchar* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		GError* _tmp9_;
		GError* _tmp10_;
		_tmp3_ = self->priv->filename;
		_tmp4_ = string_to_string (_tmp3_);
		_tmp5_ = g_module_error ();
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = g_strconcat ("Could not load ", _tmp4_, ": ", _tmp6_, NULL);
		_tmp8_ = _tmp7_;
		_tmp9_ = g_error_new_literal (FSO_FRAMEWORK_PLUGIN_ERROR, FSO_FRAMEWORK_PLUGIN_ERROR_UNABLE_TO_LOAD, _tmp8_);
		_tmp10_ = _tmp9_;
		_g_free0 (_tmp8_);
		_inner_error_ = _tmp10_;
		if (_inner_error_->domain == FSO_FRAMEWORK_PLUGIN_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp11_ = self->priv->module;
	_tmp13_ = g_module_symbol (_tmp11_, FSO_REGISTER_FUNCTION, &_tmp12_);
	regfunc = _tmp12_;
	ok = _tmp13_;
	_tmp14_ = ok;
	if (!_tmp14_) {
		const gchar* _tmp15_ = NULL;
		const gchar* _tmp16_ = NULL;
		const gchar* _tmp17_ = NULL;
		gchar* _tmp18_ = NULL;
		gchar* _tmp19_;
		GError* _tmp20_;
		GError* _tmp21_;
		_tmp15_ = string_to_string (FSO_REGISTER_FUNCTION);
		_tmp16_ = g_module_error ();
		_tmp17_ = string_to_string (_tmp16_);
		_tmp18_ = g_strconcat ("Could not find symbol ", _tmp15_, ": ", _tmp17_, NULL);
		_tmp19_ = _tmp18_;
		_tmp20_ = g_error_new_literal (FSO_FRAMEWORK_PLUGIN_ERROR, FSO_FRAMEWORK_PLUGIN_ERROR_REGISTER_NOT_FOUND, _tmp19_);
		_tmp21_ = _tmp20_;
		_g_free0 (_tmp19_);
		_inner_error_ = _tmp21_;
		if (_inner_error_->domain == FSO_FRAMEWORK_PLUGIN_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp22_ = regfunc;
	fso_register_function = (FsoFrameworkRegisterFunc) _tmp22_;
	_tmp23_ = fso_register_function;
	_tmp23_ ((GTypeModule*) self);
	_tmp24_ = self->priv->module;
	_tmp26_ = g_module_symbol (_tmp24_, FSO_FACTORY_FUNCTION, &_tmp25_);
	loadfunc = _tmp25_;
	ok = _tmp26_;
	_tmp27_ = ok;
	if (!_tmp27_) {
		const gchar* _tmp28_ = NULL;
		const gchar* _tmp29_ = NULL;
		const gchar* _tmp30_ = NULL;
		gchar* _tmp31_ = NULL;
		gchar* _tmp32_;
		GError* _tmp33_;
		GError* _tmp34_;
		_tmp28_ = string_to_string (FSO_FACTORY_FUNCTION);
		_tmp29_ = g_module_error ();
		_tmp30_ = string_to_string (_tmp29_);
		_tmp31_ = g_strconcat ("Could not find symbol ", _tmp28_, ": ", _tmp30_, NULL);
		_tmp32_ = _tmp31_;
		_tmp33_ = g_error_new_literal (FSO_FRAMEWORK_PLUGIN_ERROR, FSO_FRAMEWORK_PLUGIN_ERROR_FACTORY_NOT_FOUND, _tmp32_);
		_tmp34_ = _tmp33_;
		_g_free0 (_tmp32_);
		_inner_error_ = _tmp34_;
		if (_inner_error_->domain == FSO_FRAMEWORK_PLUGIN_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp35_ = loadfunc;
	fso_factory_func = (FsoFrameworkFactoryFunc) _tmp35_;
	{
		FsoFrameworkFactoryFunc _tmp36_;
		FsoFrameworkSubsystem* _tmp37_;
		gchar* _tmp38_ = NULL;
		gchar* _tmp39_;
		_tmp36_ = fso_factory_func;
		_tmp37_ = self->priv->subsystem;
		_tmp38_ = _tmp36_ (_tmp37_, &_inner_error_);
		_tmp39_ = _tmp38_;
		if (_inner_error_ != NULL) {
			goto __catch1_g_error;
		}
		_g_free0 (self->priv->pluginInfo.name);
		self->priv->pluginInfo.name = _tmp39_;
		self->priv->pluginInfo.loaded = TRUE;
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		GError* _tmp40_;
		const gchar* _tmp41_;
		const gchar* _tmp42_ = NULL;
		gchar* _tmp43_ = NULL;
		gchar* _tmp44_;
		GError* _tmp45_;
		GError* _tmp46_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_module_close0 (self->priv->module);
		self->priv->module = NULL;
		_tmp40_ = e;
		_tmp41_ = _tmp40_->message;
		_tmp42_ = string_to_string (_tmp41_);
		_tmp43_ = g_strconcat ("Factory function returned error: ", _tmp42_, NULL);
		_tmp44_ = _tmp43_;
		_tmp45_ = g_error_new_literal (FSO_FRAMEWORK_PLUGIN_ERROR, FSO_FRAMEWORK_PLUGIN_ERROR_UNABLE_TO_INITIALIZE, _tmp44_);
		_tmp46_ = _tmp45_;
		_g_free0 (_tmp44_);
		_inner_error_ = _tmp46_;
		_g_error_free0 (e);
		goto __finally1;
	}
	__finally1:
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == FSO_FRAMEWORK_PLUGIN_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
}


static void fso_framework_base_plugin_real_info (FsoFrameworkPlugin* base, FsoFrameworkPluginInfo* result) {
	FsoFrameworkBasePlugin * self;
	FsoFrameworkPluginInfo _tmp0_;
	FsoFrameworkPluginInfo _tmp1_ = {0};
	self = (FsoFrameworkBasePlugin*) base;
	_tmp0_ = self->priv->pluginInfo;
	fso_framework_plugin_info_copy (&_tmp0_, &_tmp1_);
	*result = _tmp1_;
	return;
}


static gboolean fso_framework_base_plugin_real_load (GTypeModule* base) {
	FsoFrameworkBasePlugin * self;
	gboolean result = FALSE;
	self = (FsoFrameworkBasePlugin*) base;
	result = TRUE;
	return result;
}


static void fso_framework_base_plugin_real_unload (GTypeModule* base) {
	FsoFrameworkBasePlugin * self;
	self = (FsoFrameworkBasePlugin*) base;
}


static void fso_framework_base_plugin_real_shutdown (FsoFrameworkPlugin* base) {
	FsoFrameworkBasePlugin * self;
	GModule* _tmp0_;
	void* func = NULL;
	GModule* _tmp1_;
	void* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	gboolean ok;
	gboolean _tmp4_;
	void* _tmp5_;
	FsoFrameworkShutdownFunc fso_shutdown_function;
	FsoFrameworkShutdownFunc _tmp6_;
	self = (FsoFrameworkBasePlugin*) base;
	_tmp0_ = self->priv->module;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp1_ = self->priv->module;
	_tmp3_ = g_module_symbol (_tmp1_, FSO_SHUTDOWN_FUNCTION, &_tmp2_);
	func = _tmp2_;
	ok = _tmp3_;
	_tmp4_ = ok;
	if (!_tmp4_) {
		return;
	}
	_tmp5_ = func;
	fso_shutdown_function = (FsoFrameworkShutdownFunc) _tmp5_;
	_tmp6_ = fso_shutdown_function;
	_tmp6_ ();
}


static void fso_framework_base_plugin_class_init (FsoFrameworkBasePluginClass * klass) {
	fso_framework_base_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkBasePluginPrivate));
	G_TYPE_MODULE_CLASS (klass)->load = fso_framework_base_plugin_real_load;
	G_TYPE_MODULE_CLASS (klass)->unload = fso_framework_base_plugin_real_unload;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_base_plugin_finalize;
}


static void fso_framework_base_plugin_fso_framework_plugin_interface_init (FsoFrameworkPluginIface * iface) {
	fso_framework_base_plugin_fso_framework_plugin_parent_iface = g_type_interface_peek_parent (iface);
	iface->loadAndInit = (void (*)(FsoFrameworkPlugin*, GError**)) fso_framework_base_plugin_real_loadAndInit;
	iface->info = (void (*)(FsoFrameworkPlugin*, FsoFrameworkPluginInfo*)) fso_framework_base_plugin_real_info;
	iface->shutdown = (void (*)(FsoFrameworkPlugin*)) fso_framework_base_plugin_real_shutdown;
}


static void fso_framework_base_plugin_instance_init (FsoFrameworkBasePlugin * self) {
	self->priv = FSO_FRAMEWORK_BASE_PLUGIN_GET_PRIVATE (self);
}


static void fso_framework_base_plugin_finalize (GObject* obj) {
	FsoFrameworkBasePlugin * self;
	self = FSO_FRAMEWORK_BASE_PLUGIN (obj);
	_g_free0 (self->priv->filename);
	_g_module_close0 (self->priv->module);
	fso_framework_plugin_info_destroy (&self->priv->pluginInfo);
	_g_object_unref0 (self->priv->subsystem);
	G_OBJECT_CLASS (fso_framework_base_plugin_parent_class)->finalize (obj);
}


/**
 * BasePlugin
 */
GType fso_framework_base_plugin_get_type (void) {
	static volatile gsize fso_framework_base_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_base_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkBasePluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_base_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkBasePlugin), 0, (GInstanceInitFunc) fso_framework_base_plugin_instance_init, NULL };
		static const GInterfaceInfo fso_framework_plugin_info = { (GInterfaceInitFunc) fso_framework_base_plugin_fso_framework_plugin_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_framework_base_plugin_type_id;
		fso_framework_base_plugin_type_id = g_type_register_static (G_TYPE_TYPE_MODULE, "FsoFrameworkBasePlugin", &g_define_type_info, 0);
		g_type_add_interface_static (fso_framework_base_plugin_type_id, FSO_FRAMEWORK_TYPE_PLUGIN, &fso_framework_plugin_info);
		g_once_init_leave (&fso_framework_base_plugin_type_id__volatile, fso_framework_base_plugin_type_id);
	}
	return fso_framework_base_plugin_type_id__volatile;
}




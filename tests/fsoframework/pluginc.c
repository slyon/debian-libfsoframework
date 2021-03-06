/* pluginc.c generated by valac 0.16.1, the Vala compiler
 * generated from pluginc.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_TEST_C (test_c_get_type ())
#define TEST_C(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_C, TestC))
#define TEST_C_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_C, TestCClass))
#define IS_TEST_C(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_C))
#define IS_TEST_C_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_C))
#define TEST_C_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_C, TestCClass))

typedef struct _TestC TestC;
typedef struct _TestCClass TestCClass;
typedef struct _TestCPrivate TestCPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _TestC {
	GObject parent_instance;
	TestCPrivate * priv;
};

struct _TestCClass {
	GObjectClass parent_class;
};


static gpointer test_c_parent_class = NULL;
static GType test_c_type_id = 0;
extern TestC* test;
TestC* test = NULL;

GType test_c_get_type (void) G_GNUC_CONST;
GType test_c_register_type (GTypeModule * module);
enum  {
	TEST_C_DUMMY_PROPERTY
};
TestC* test_c_new (gint foo);
TestC* test_c_construct (GType object_type, gint foo);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


TestC* test_c_construct (GType object_type, gint foo) {
	TestC * self = NULL;
	self = (TestC*) g_object_new (object_type, NULL);
	g_message ("pluginc.vala:25: Test Plugin C is alive but should not be!");
	return self;
}


TestC* test_c_new (gint foo) {
	return test_c_construct (TYPE_TEST_C, foo);
}


static void test_c_class_init (TestCClass * klass) {
	test_c_parent_class = g_type_class_peek_parent (klass);
}


static void test_c_instance_init (TestC * self) {
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
GType test_c_get_type (void) {
	return test_c_type_id;
}


GType test_c_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (TestCClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) test_c_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TestC), 0, (GInstanceInitFunc) test_c_instance_init, NULL };
	test_c_type_id = g_type_module_register_type (module, G_TYPE_OBJECT, "TestC", &g_define_type_info, 0);
	return test_c_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	GError* _tmp0_;
	TestC* _tmp1_;
	gchar* _tmp2_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_NAMETOOLONG, "can't initialize test plugin C");
	_inner_error_ = _tmp0_;
	g_propagate_error (error, _inner_error_);
	return NULL;
	_tmp1_ = test_c_new (42);
	_g_object_unref0 (test);
	test = _tmp1_;
	_tmp2_ = g_strdup ("tests.pluginc");
	result = _tmp2_;
	return result;
	return result;
}


/**
 * This (seemingly empty) function gets called on plugin load time
 * for registering new gobject types. Do not remove or alter!
 **/
void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	test_c_register_type (module);
}




/* pluginb.c generated by valac 0.16.1, the Vala compiler
 * generated from pluginb.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_TEST_B (test_b_get_type ())
#define TEST_B(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_B, TestB))
#define TEST_B_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_B, TestBClass))
#define IS_TEST_B(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_B))
#define IS_TEST_B_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_B))
#define TEST_B_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_B, TestBClass))

typedef struct _TestB TestB;
typedef struct _TestBClass TestBClass;
typedef struct _TestBPrivate TestBPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _TestB {
	GObject parent_instance;
	TestBPrivate * priv;
};

struct _TestBClass {
	GObjectClass parent_class;
};


static gpointer test_b_parent_class = NULL;
static GType test_b_type_id = 0;
extern TestB* test;
TestB* test = NULL;

GType test_b_get_type (void) G_GNUC_CONST;
GType test_b_register_type (GTypeModule * module);
enum  {
	TEST_B_DUMMY_PROPERTY
};
TestB* test_b_new (gint foo);
TestB* test_b_construct (GType object_type, gint foo);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


TestB* test_b_construct (GType object_type, gint foo) {
	TestB * self = NULL;
	self = (TestB*) g_object_new (object_type, NULL);
	g_message ("pluginb.vala:27: Test Plugin B is alive!");
	return self;
}


TestB* test_b_new (gint foo) {
	return test_b_construct (TYPE_TEST_B, foo);
}


static void test_b_class_init (TestBClass * klass) {
	test_b_parent_class = g_type_class_peek_parent (klass);
}


static void test_b_instance_init (TestB * self) {
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
GType test_b_get_type (void) {
	return test_b_type_id;
}


GType test_b_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (TestBClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) test_b_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TestB), 0, (GInstanceInitFunc) test_b_instance_init, NULL };
	test_b_type_id = g_type_module_register_type (module, G_TYPE_OBJECT, "TestB", &g_define_type_info, 0);
	return test_b_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	TestB* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = test_b_new (42);
	_g_object_unref0 (test);
	test = _tmp0_;
	_tmp1_ = g_strdup ("tests.pluginb");
	result = _tmp1_;
	return result;
}


/**
 * This (seemingly empty) function gets called on plugin load time
 * for registering new gobject types. Do not remove or alter!
 **/
void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	test_b_register_type (module);
}




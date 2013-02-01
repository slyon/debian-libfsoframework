/* plugin.c generated by valac 0.16.1, the Vala compiler
 * generated from plugin.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>


#define MY_PLUGIN_TYPE_TEST (my_plugin_test_get_type ())
#define MY_PLUGIN_TEST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_PLUGIN_TYPE_TEST, MyPluginTest))
#define MY_PLUGIN_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MY_PLUGIN_TYPE_TEST, MyPluginTestClass))
#define MY_PLUGIN_IS_TEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_PLUGIN_TYPE_TEST))
#define MY_PLUGIN_IS_TEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MY_PLUGIN_TYPE_TEST))
#define MY_PLUGIN_TEST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MY_PLUGIN_TYPE_TEST, MyPluginTestClass))

typedef struct _MyPluginTest MyPluginTest;
typedef struct _MyPluginTestClass MyPluginTestClass;
typedef struct _MyPluginTestPrivate MyPluginTestPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _MyPluginTest {
	GObject parent_instance;
	MyPluginTestPrivate * priv;
};

struct _MyPluginTestClass {
	GObjectClass parent_class;
};


static gpointer my_plugin_test_parent_class = NULL;
static GType my_plugin_test_type_id = 0;

GType my_plugin_test_get_type (void) G_GNUC_CONST;
GType my_plugin_test_register_type (GTypeModule * module);
enum  {
	MY_PLUGIN_TEST_DUMMY_PROPERTY
};
MyPluginTest* my_plugin_test_new (gint foo);
MyPluginTest* my_plugin_test_construct (GType object_type, gint foo);
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error);
void fso_register_function (GTypeModule* module);


MyPluginTest* my_plugin_test_construct (GType object_type, gint foo) {
	MyPluginTest * self = NULL;
	self = (MyPluginTest*) g_object_new (object_type, NULL);
	g_message ("plugin.vala:30: Test Plugin is alive!");
	return self;
}


MyPluginTest* my_plugin_test_new (gint foo) {
	return my_plugin_test_construct (MY_PLUGIN_TYPE_TEST, foo);
}


static void my_plugin_test_class_init (MyPluginTestClass * klass) {
	my_plugin_test_parent_class = g_type_class_peek_parent (klass);
}


static void my_plugin_test_instance_init (MyPluginTest * self) {
}


GType my_plugin_test_get_type (void) {
	return my_plugin_test_type_id;
}


GType my_plugin_test_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (MyPluginTestClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) my_plugin_test_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MyPluginTest), 0, (GInstanceInitFunc) my_plugin_test_instance_init, NULL };
	my_plugin_test_type_id = g_type_module_register_type (module, G_TYPE_OBJECT, "MyPluginTest", &g_define_type_info, 0);
	return my_plugin_test_type_id;
}


/**
 * This function gets called on plugin initialization time.
 * @return the name of your plugin here
 * @note that it needs to be a name in the format <subsystem>.<plugin>
 * else your module will be unloaded immediately.
 **/
gchar* fso_factory_function (FsoFrameworkSubsystem* subsystem, GError** error) {
	gchar* result = NULL;
	MyPluginTest* _tmp0_;
	MyPluginTest* t;
	gchar* _tmp1_;
	g_return_val_if_fail (subsystem != NULL, NULL);
	_tmp0_ = my_plugin_test_new (42);
	t = _tmp0_;
	_tmp1_ = g_strdup ("test.plugin");
	result = _tmp1_;
	_g_object_unref0 (t);
	return result;
}


/**
 * This (seemingly empty) function gets called on plugin load time
 * for registering new gobject types. Do not remove or alter!
 **/
void fso_register_function (GTypeModule* module) {
	g_return_if_fail (module != NULL);
	my_plugin_test_register_type (module);
}



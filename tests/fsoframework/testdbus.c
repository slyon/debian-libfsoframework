/* testdbus.c generated by valac 0.16.1, the Vala compiler
 * generated from testdbus.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsobasics.h>
#include <fsoframework.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



void test_dbus_masterkeyfile (void);
void test_dbus_is_valid_dbus_name (void);
void _vala_main (gchar** args, int args_length1);
static void _test_dbus_masterkeyfile_gcallback (void);
static void _test_dbus_is_valid_dbus_name_gcallback (void);


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
void test_dbus_masterkeyfile (void) {
	FsoFrameworkSmartKeyFile* _tmp0_ = NULL;
	FsoFrameworkSmartKeyFile* mkf;
	_tmp0_ = fso_framework_smart_key_file_defaultKeyFile ();
	mkf = _tmp0_;
	_g_object_unref0 (mkf);
}


void test_dbus_is_valid_dbus_name (void) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	_tmp0_ = fso_framework_isValidDBusName ("org.foo");
	g_assert (_tmp0_);
	_tmp1_ = fso_framework_isValidDBusName ("org.foo.bar");
	g_assert (_tmp1_);
	_tmp2_ = fso_framework_isValidDBusName ("org.foo.bar.baz");
	g_assert (_tmp2_);
	_tmp3_ = fso_framework_isValidDBusName ("org");
	g_assert (!_tmp3_);
	_tmp4_ = fso_framework_isValidDBusName ("org.");
	g_assert (!_tmp4_);
	_tmp5_ = fso_framework_isValidDBusName ("foo.org.");
	g_assert (!_tmp5_);
	_tmp6_ = fso_framework_isValidDBusName (".org.yo.kurt");
	g_assert (!_tmp6_);
}


static void _test_dbus_masterkeyfile_gcallback (void) {
	test_dbus_masterkeyfile ();
}


static void _test_dbus_is_valid_dbus_name_gcallback (void) {
	test_dbus_is_valid_dbus_name ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/Common/masterKeyFile", _test_dbus_masterkeyfile_gcallback);
	g_test_add_func ("/DBus/isValidDBusName", _test_dbus_is_valid_dbus_name_gcallback);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}




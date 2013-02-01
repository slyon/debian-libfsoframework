/* testpath.c generated by valac 0.16.1, the Vala compiler
 * generated from testpath.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
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
#include <fsosystem.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



void test_path_is_mount_point (void);
void test_path_is_absolute (void);
void _vala_main (gchar** args, int args_length1);
static void _test_path_is_mount_point_gcallback (void);
static void _test_path_is_absolute_gcallback (void);


void test_path_is_mount_point (void) {
	FsoFrameworkFileSystemPath* _tmp0_;
	FsoFrameworkFileSystemPath* path;
	gboolean _tmp1_ = FALSE;
	_tmp0_ = fso_framework_file_system_path_new ("/sys");
	path = _tmp0_;
	_tmp1_ = fso_framework_file_system_path_is_mount_point (path);
	g_assert (_tmp1_ == TRUE);
	_g_object_unref0 (path);
}


void test_path_is_absolute (void) {
	FsoFrameworkFileSystemPath* _tmp0_;
	FsoFrameworkFileSystemPath* path;
	FsoFrameworkFileSystemPath* _tmp1_;
	gboolean _tmp2_ = FALSE;
	FsoFrameworkFileSystemPath* _tmp3_;
	FsoFrameworkFileSystemPath* _tmp4_;
	gboolean _tmp5_ = FALSE;
	_tmp0_ = fso_framework_file_system_path_new ("/is/absolut/path");
	path = _tmp0_;
	_tmp1_ = path;
	_tmp2_ = fso_framework_file_system_path_is_absolute (_tmp1_);
	g_assert (_tmp2_ == TRUE);
	_tmp3_ = fso_framework_file_system_path_new ("is/relative/path");
	_g_object_unref0 (path);
	path = _tmp3_;
	_tmp4_ = path;
	_tmp5_ = fso_framework_file_system_path_is_absolute (_tmp4_);
	g_assert (_tmp5_ == FALSE);
	_g_object_unref0 (path);
}


static void _test_path_is_mount_point_gcallback (void) {
	test_path_is_mount_point ();
}


static void _test_path_is_absolute_gcallback (void) {
	test_path_is_absolute ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/FileSystem/Path/IsMountpoint", _test_path_is_mount_point_gcallback);
	g_test_add_func ("/FileSystem/Path/IsAbsolute", _test_path_is_absolute_gcallback);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}




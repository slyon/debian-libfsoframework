/* testcommandqueue.c generated by valac 0.16.0, the Vala compiler
 * generated from testcommandqueue.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsotransport.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



void test_commandqueue_enqueue (void);
void _vala_main (gchar** args, int args_length1);
static void _test_commandqueue_enqueue_gcallback (void);


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
void test_commandqueue_enqueue (void) {
	FsoFrameworkPtyTransport* _tmp0_;
	FsoFrameworkPtyTransport* t;
	gboolean _tmp1_ = FALSE;
	_tmp0_ = fso_framework_pty_transport_new ();
	t = _tmp0_;
	fso_framework_transport_open ((FsoFrameworkTransport*) t);
	_tmp1_ = fso_framework_transport_isOpen ((FsoFrameworkTransport*) t);
	g_assert (_tmp1_);
	_g_object_unref0 (t);
}


static void _test_commandqueue_enqueue_gcallback (void) {
	test_commandqueue_enqueue ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/CommandQueue/Enqueue", _test_commandqueue_enqueue_gcallback);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}




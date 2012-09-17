/* testtestcase.c generated by valac 0.16.0, the Vala compiler
 * generated from testtestcase.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsotest.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_TEST_CASE0 (test_case0_get_type ())
#define TEST_CASE0(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_CASE0, TestCase0))
#define TEST_CASE0_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_CASE0, TestCase0Class))
#define IS_TEST_CASE0(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_CASE0))
#define IS_TEST_CASE0_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_CASE0))
#define TEST_CASE0_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_CASE0, TestCase0Class))

typedef struct _TestCase0 TestCase0;
typedef struct _TestCase0Class TestCase0Class;
typedef struct _TestCase0Private TestCase0Private;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
typedef struct _TestCase0TestAsyncWithTimeoutData TestCase0TestAsyncWithTimeoutData;

struct _TestCase0 {
	FsoFrameworkTestTestCase parent_instance;
	TestCase0Private * priv;
};

struct _TestCase0Class {
	FsoFrameworkTestTestCaseClass parent_class;
};

struct _Block1Data {
	int _ref_count_;
	TestCase0 * self;
	gboolean done;
	gpointer _async_data_;
};

struct _TestCase0TestAsyncWithTimeoutData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	TestCase0* self;
	Block1Data* _data1_;
	GError * _inner_error_;
};


static gpointer test_case0_parent_class = NULL;

GType test_case0_get_type (void) G_GNUC_CONST;
enum  {
	TEST_CASE0_DUMMY_PROPERTY
};
TestCase0* test_case0_new (void);
TestCase0* test_case0_construct (GType object_type);
static void __lambda2_ (TestCase0* self, GAsyncReadyCallback cb, void* cb_target);
void test_case0_test_async_with_timeout (TestCase0* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void test_case0_test_async_with_timeout_finish (TestCase0* self, GAsyncResult* _res_, GError** error);
static void ___lambda2__fso_framework_test_async_begin (GAsyncReadyCallback callback, void* callback_target, gpointer self);
static void __lambda4_ (TestCase0* self, GAsyncResult* res, GError** error);
static void ___lambda4__fso_framework_test_async_finish (GAsyncResult* _result_, gpointer self, GError** error);
static void test_case0_test_async_with_timeout_data_free (gpointer _data);
static gboolean test_case0_test_async_with_timeout_co (TestCase0TestAsyncWithTimeoutData* _data_);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static gboolean __lambda3_ (Block1Data* _data1_);
static gboolean ___lambda3__gsource_func (gpointer self);
gint _vala_main (gchar** args, int args_length1);


static void __lambda2_ (TestCase0* self, GAsyncReadyCallback cb, void* cb_target) {
	GAsyncReadyCallback _tmp0_;
	void* _tmp0__target;
	_tmp0_ = cb;
	_tmp0__target = cb_target;
	test_case0_test_async_with_timeout (self, _tmp0_, _tmp0__target);
}


static void ___lambda2__fso_framework_test_async_begin (GAsyncReadyCallback callback, void* callback_target, gpointer self) {
	__lambda2_ (self, callback, callback_target);
}


static void __lambda4_ (TestCase0* self, GAsyncResult* res, GError** error) {
	GAsyncResult* _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (res != NULL);
	_tmp0_ = res;
	test_case0_test_async_with_timeout_finish (self, _tmp0_, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return;
	}
}


static void ___lambda4__fso_framework_test_async_finish (GAsyncResult* _result_, gpointer self, GError** error) {
	__lambda4_ (self, _result_, error);
}


TestCase0* test_case0_construct (GType object_type) {
	TestCase0 * self = NULL;
	self = (TestCase0*) fso_framework_test_test_case_construct (object_type, "TestCase0");
	fso_framework_test_test_case_add_async_test ((FsoFrameworkTestTestCase*) self, "AsyncWithTimeout", ___lambda2__fso_framework_test_async_begin, self, ___lambda4__fso_framework_test_async_finish, self, 4000);
	return self;
}


TestCase0* test_case0_new (void) {
	return test_case0_construct (TYPE_TEST_CASE0);
}


static void test_case0_test_async_with_timeout_data_free (gpointer _data) {
	TestCase0TestAsyncWithTimeoutData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (TestCase0TestAsyncWithTimeoutData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void test_case0_test_async_with_timeout (TestCase0* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	TestCase0TestAsyncWithTimeoutData* _data_;
	TestCase0* _tmp0_;
	_data_ = g_slice_new0 (TestCase0TestAsyncWithTimeoutData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, test_case0_test_async_with_timeout);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, test_case0_test_async_with_timeout_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	test_case0_test_async_with_timeout_co (_data_);
}


void test_case0_test_async_with_timeout_finish (TestCase0* self, GAsyncResult* _res_, GError** error) {
	TestCase0TestAsyncWithTimeoutData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		TestCase0 * self;
		self = _data1_->self;
		_g_object_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}


static gboolean __lambda3_ (Block1Data* _data1_) {
	TestCase0 * self;
	gboolean result = FALSE;
	self = _data1_->self;
	_data1_->done = TRUE;
	test_case0_test_async_with_timeout_co (_data1_->_async_data_);
	result = FALSE;
	return result;
}


static gboolean ___lambda3__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda3_ (self);
	return result;
}


static gboolean test_case0_test_async_with_timeout_co (TestCase0TestAsyncWithTimeoutData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_data1_ = g_slice_new0 (Block1Data);
	_data_->_data1_->_ref_count_ = 1;
	_data_->_data1_->self = g_object_ref (_data_->self);
	_data_->_data1_->_async_data_ = _data_;
	_data_->_data1_->done = FALSE;
	g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 3, ___lambda3__gsource_func, block1_data_ref (_data_->_data1_), block1_data_unref);
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	fso_framework_test_assert_is_true (_data_->_data1_->done, "", &_data_->_inner_error_);
	if (_data_->_inner_error_ != NULL) {
		g_simple_async_result_set_from_error (_data_->_async_result, _data_->_inner_error_);
		g_error_free (_data_->_inner_error_);
		block1_data_unref (_data_->_data1_);
		_data_->_data1_ = NULL;
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	block1_data_unref (_data_->_data1_);
	_data_->_data1_ = NULL;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void test_case0_class_init (TestCase0Class * klass) {
	test_case0_parent_class = g_type_class_peek_parent (klass);
}


static void test_case0_instance_init (TestCase0 * self) {
}


/**
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
GType test_case0_get_type (void) {
	static volatile gsize test_case0_type_id__volatile = 0;
	if (g_once_init_enter (&test_case0_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TestCase0Class), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) test_case0_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TestCase0), 0, (GInstanceInitFunc) test_case0_instance_init, NULL };
		GType test_case0_type_id;
		test_case0_type_id = g_type_register_static (FSO_FRAMEWORK_TEST_TYPE_TEST_CASE, "TestCase0", &g_define_type_info, 0);
		g_once_init_leave (&test_case0_type_id__volatile, test_case0_type_id);
	}
	return test_case0_type_id__volatile;
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	GTestSuite* _tmp0_ = NULL;
	GTestSuite* root;
	TestCase0* _tmp1_;
	TestCase0* _tmp2_;
	GTestSuite* _tmp3_ = NULL;
	g_test_init (&args_length1, &args, NULL);
	_tmp0_ = g_test_get_root ();
	root = _tmp0_;
	_tmp1_ = test_case0_new ();
	_tmp2_ = _tmp1_;
	_tmp3_ = fso_framework_test_test_case_get_suite ((FsoFrameworkTestTestCase*) _tmp2_);
	g_test_suite_add_suite (root, _tmp3_);
	_g_object_unref0 (_tmp2_);
	g_test_run ();
	result = 0;
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}




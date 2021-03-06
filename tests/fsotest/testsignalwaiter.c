/* testsignalwaiter.c generated by valac 0.16.1, the Vala compiler
 * generated from testsignalwaiter.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <fsotest.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_TEST_EMITTER (test_emitter_get_type ())
#define TEST_EMITTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_EMITTER, TestEmitter))
#define TEST_EMITTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TEST_EMITTER, TestEmitterClass))
#define IS_TEST_EMITTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_EMITTER))
#define IS_TEST_EMITTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TEST_EMITTER))
#define TEST_EMITTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_EMITTER, TestEmitterClass))

typedef struct _TestEmitter TestEmitter;
typedef struct _TestEmitterClass TestEmitterClass;
typedef struct _TestEmitterPrivate TestEmitterPrivate;
typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block2Data Block2Data;
typedef struct _Block3Data Block3Data;

struct _TestEmitter {
	GObject parent_instance;
	TestEmitterPrivate * priv;
};

struct _TestEmitterClass {
	GObjectClass parent_class;
};

struct _Block1Data {
	int _ref_count_;
	TestEmitter* emitter;
};

struct _Block2Data {
	int _ref_count_;
	TestEmitter* emitter;
};

struct _Block3Data {
	int _ref_count_;
	TestEmitter* emitter;
};


static gpointer test_emitter_parent_class = NULL;

GType test_emitter_get_type (void) G_GNUC_CONST;
enum  {
	TEST_EMITTER_DUMMY_PROPERTY
};
void test_emitter_emit0 (TestEmitter* self);
void test_emitter_emit1 (TestEmitter* self);
void test_emitter_emit2 (TestEmitter* self);
TestEmitter* test_emitter_new (void);
TestEmitter* test_emitter_construct (GType object_type);
void test_multi_signal_waiter_no_signal (void);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda2_ (Block1Data* _data1_);
static void ___lambda2__fso_framework_test_block (gpointer self);
void test_multi_signal_waiter_one_signal (void);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
static void __lambda3_ (Block2Data* _data2_);
static void ___lambda3__fso_framework_test_block (gpointer self);
static void __lambda4_ (Block2Data* _data2_);
static void ___lambda4__fso_framework_test_block (gpointer self);
static void __lambda5_ (Block2Data* _data2_);
static void ___lambda5__fso_framework_test_block (gpointer self);
void test_multi_signal_waiter_many_signals (void);
static Block3Data* block3_data_ref (Block3Data* _data3_);
static void block3_data_unref (void * _userdata_);
static void __lambda6_ (Block3Data* _data3_);
static void ___lambda6__fso_framework_test_block (gpointer self);
static void __lambda7_ (Block3Data* _data3_);
static void ___lambda7__fso_framework_test_block (gpointer self);
static void __lambda8_ (Block3Data* _data3_);
static void ___lambda8__fso_framework_test_block (gpointer self);
void _vala_main (gchar** args, int args_length1);
static void _test_multi_signal_waiter_no_signal_gcallback (void);
static void _test_multi_signal_waiter_one_signal_gcallback (void);
static void _test_multi_signal_waiter_many_signals_gcallback (void);


void test_emitter_emit0 (TestEmitter* self) {
	g_return_if_fail (self != NULL);
}


void test_emitter_emit1 (TestEmitter* self) {
	g_return_if_fail (self != NULL);
	g_signal_emit_by_name (self, "s0");
}


void test_emitter_emit2 (TestEmitter* self) {
	g_return_if_fail (self != NULL);
	g_signal_emit_by_name (self, "s0");
	g_signal_emit_by_name (self, "s1");
}


TestEmitter* test_emitter_construct (GType object_type) {
	TestEmitter * self = NULL;
	self = (TestEmitter*) g_object_new (object_type, NULL);
	return self;
}


TestEmitter* test_emitter_new (void) {
	return test_emitter_construct (TYPE_TEST_EMITTER);
}


static void test_emitter_class_init (TestEmitterClass * klass) {
	test_emitter_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("s0", TYPE_TEST_EMITTER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("s1", TYPE_TEST_EMITTER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void test_emitter_instance_init (TestEmitter * self) {
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
GType test_emitter_get_type (void) {
	static volatile gsize test_emitter_type_id__volatile = 0;
	if (g_once_init_enter (&test_emitter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TestEmitterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) test_emitter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TestEmitter), 0, (GInstanceInitFunc) test_emitter_instance_init, NULL };
		GType test_emitter_type_id;
		test_emitter_type_id = g_type_register_static (G_TYPE_OBJECT, "TestEmitter", &g_define_type_info, 0);
		g_once_init_leave (&test_emitter_type_id__volatile, test_emitter_type_id);
	}
	return test_emitter_type_id__volatile;
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->emitter);
		g_slice_free (Block1Data, _data1_);
	}
}


static void __lambda2_ (Block1Data* _data1_) {
	test_emitter_emit0 (_data1_->emitter);
}


static void ___lambda2__fso_framework_test_block (gpointer self) {
	__lambda2_ (self);
}


void test_multi_signal_waiter_no_signal (void) {
	Block1Data* _data1_;
	TestEmitter* _tmp0_;
	FsoFrameworkTestMultiSignalWaiter* _tmp1_;
	FsoFrameworkTestMultiSignalWaiter* waiter;
	gboolean _tmp2_ = FALSE;
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_tmp0_ = test_emitter_new ();
	_data1_->emitter = _tmp0_;
	_tmp1_ = fso_framework_test_multi_signal_waiter_new ();
	waiter = _tmp1_;
	fso_framework_test_multi_signal_waiter_add_signal (waiter, (GObject*) _data1_->emitter, "s0", 200);
	fso_framework_test_multi_signal_waiter_add_signal (waiter, (GObject*) _data1_->emitter, "s1", 200);
	_tmp2_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda2__fso_framework_test_block, _data1_, 200);
	g_assert (_tmp2_ == FALSE);
	_g_object_unref0 (waiter);
	block1_data_unref (_data1_);
	_data1_ = NULL;
}


static Block2Data* block2_data_ref (Block2Data* _data2_) {
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}


static void block2_data_unref (void * _userdata_) {
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		_g_object_unref0 (_data2_->emitter);
		g_slice_free (Block2Data, _data2_);
	}
}


static void __lambda3_ (Block2Data* _data2_) {
	test_emitter_emit0 (_data2_->emitter);
}


static void ___lambda3__fso_framework_test_block (gpointer self) {
	__lambda3_ (self);
}


static void __lambda4_ (Block2Data* _data2_) {
	test_emitter_emit1 (_data2_->emitter);
}


static void ___lambda4__fso_framework_test_block (gpointer self) {
	__lambda4_ (self);
}


static void __lambda5_ (Block2Data* _data2_) {
	test_emitter_emit2 (_data2_->emitter);
}


static void ___lambda5__fso_framework_test_block (gpointer self) {
	__lambda5_ (self);
}


void test_multi_signal_waiter_one_signal (void) {
	Block2Data* _data2_;
	TestEmitter* _tmp0_;
	FsoFrameworkTestMultiSignalWaiter* _tmp1_;
	FsoFrameworkTestMultiSignalWaiter* waiter;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	_data2_ = g_slice_new0 (Block2Data);
	_data2_->_ref_count_ = 1;
	_tmp0_ = test_emitter_new ();
	_data2_->emitter = _tmp0_;
	_tmp1_ = fso_framework_test_multi_signal_waiter_new ();
	waiter = _tmp1_;
	fso_framework_test_multi_signal_waiter_add_signal (waiter, (GObject*) _data2_->emitter, "s0", 200);
	_tmp2_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda3__fso_framework_test_block, _data2_, 200);
	g_assert (_tmp2_ == FALSE);
	_tmp3_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda4__fso_framework_test_block, _data2_, 200);
	g_assert (_tmp3_ == TRUE);
	_tmp4_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda5__fso_framework_test_block, _data2_, 200);
	g_assert (_tmp4_ == TRUE);
	_g_object_unref0 (waiter);
	block2_data_unref (_data2_);
	_data2_ = NULL;
}


static Block3Data* block3_data_ref (Block3Data* _data3_) {
	g_atomic_int_inc (&_data3_->_ref_count_);
	return _data3_;
}


static void block3_data_unref (void * _userdata_) {
	Block3Data* _data3_;
	_data3_ = (Block3Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data3_->_ref_count_)) {
		_g_object_unref0 (_data3_->emitter);
		g_slice_free (Block3Data, _data3_);
	}
}


static void __lambda6_ (Block3Data* _data3_) {
	test_emitter_emit1 (_data3_->emitter);
}


static void ___lambda6__fso_framework_test_block (gpointer self) {
	__lambda6_ (self);
}


static void __lambda7_ (Block3Data* _data3_) {
	test_emitter_emit2 (_data3_->emitter);
}


static void ___lambda7__fso_framework_test_block (gpointer self) {
	__lambda7_ (self);
}


static void __lambda8_ (Block3Data* _data3_) {
	test_emitter_emit0 (_data3_->emitter);
}


static void ___lambda8__fso_framework_test_block (gpointer self) {
	__lambda8_ (self);
}


void test_multi_signal_waiter_many_signals (void) {
	Block3Data* _data3_;
	TestEmitter* _tmp0_;
	FsoFrameworkTestMultiSignalWaiter* _tmp1_;
	FsoFrameworkTestMultiSignalWaiter* waiter;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	_data3_ = g_slice_new0 (Block3Data);
	_data3_->_ref_count_ = 1;
	_tmp0_ = test_emitter_new ();
	_data3_->emitter = _tmp0_;
	_tmp1_ = fso_framework_test_multi_signal_waiter_new ();
	waiter = _tmp1_;
	fso_framework_test_multi_signal_waiter_add_signal (waiter, (GObject*) _data3_->emitter, "s0", 200);
	fso_framework_test_multi_signal_waiter_add_signal (waiter, (GObject*) _data3_->emitter, "s1", 200);
	_tmp2_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda6__fso_framework_test_block, _data3_, 200);
	g_assert (_tmp2_ == FALSE);
	_tmp3_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda7__fso_framework_test_block, _data3_, 200);
	g_assert (_tmp3_ == TRUE);
	_tmp4_ = fso_framework_test_multi_signal_waiter_run (waiter, ___lambda8__fso_framework_test_block, _data3_, 200);
	g_assert (_tmp4_ == FALSE);
	_g_object_unref0 (waiter);
	block3_data_unref (_data3_);
	_data3_ = NULL;
}


static void _test_multi_signal_waiter_no_signal_gcallback (void) {
	test_multi_signal_waiter_no_signal ();
}


static void _test_multi_signal_waiter_one_signal_gcallback (void) {
	test_multi_signal_waiter_one_signal ();
}


static void _test_multi_signal_waiter_many_signals_gcallback (void) {
	test_multi_signal_waiter_many_signals ();
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_add_func ("/FsoFramework/Test/MultiSignalWaiter/NoSignal", _test_multi_signal_waiter_no_signal_gcallback);
	g_test_add_func ("/FsoFramework/Test/MultiSignalWaiter/TwoSignals", _test_multi_signal_waiter_one_signal_gcallback);
	g_test_add_func ("/FsoFramework/Test/MultiSignalWaiter/ManySignals", _test_multi_signal_waiter_many_signals_gcallback);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}




/* assert.c generated by valac 0.16.1, the Vala compiler
 * generated from assert.vala, do not modify */

/*
 * (C) 2011-2012 Simon Busch <morphis@gravedo.de>
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
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define FSO_FRAMEWORK_TEST_TYPE_ASSERT (fso_framework_test_assert_get_type ())
#define FSO_FRAMEWORK_TEST_ASSERT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TEST_TYPE_ASSERT, FsoFrameworkTestAssert))
#define FSO_FRAMEWORK_TEST_ASSERT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TEST_TYPE_ASSERT, FsoFrameworkTestAssertClass))
#define FSO_FRAMEWORK_TEST_IS_ASSERT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TEST_TYPE_ASSERT))
#define FSO_FRAMEWORK_TEST_IS_ASSERT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TEST_TYPE_ASSERT))
#define FSO_FRAMEWORK_TEST_ASSERT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TEST_TYPE_ASSERT, FsoFrameworkTestAssertClass))

typedef struct _FsoFrameworkTestAssert FsoFrameworkTestAssert;
typedef struct _FsoFrameworkTestAssertClass FsoFrameworkTestAssertClass;
typedef struct _FsoFrameworkTestAssertPrivate FsoFrameworkTestAssertPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

typedef enum  {
	FSO_FRAMEWORK_TEST_ASSERT_ERROR_UNEXPECTED_VALUE,
	FSO_FRAMEWORK_TEST_ASSERT_ERROR_UNEXPECTED_STATE
} FsoFrameworkTestAssertError;
#define FSO_FRAMEWORK_TEST_ASSERT_ERROR fso_framework_test_assert_error_quark ()
struct _FsoFrameworkTestAssert {
	GObject parent_instance;
	FsoFrameworkTestAssertPrivate * priv;
};

struct _FsoFrameworkTestAssertClass {
	GObjectClass parent_class;
};

typedef void (*FsoFrameworkTestAsyncBegin) (GAsyncReadyCallback callback, void* callback_target, void* user_data);
typedef void (*FsoFrameworkTestAsyncFinish) (GAsyncResult* _result_, void* user_data, GError** error);

static gpointer fso_framework_test_assert_parent_class = NULL;

GQuark fso_framework_test_assert_error_quark (void);
GType fso_framework_test_assert_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_TEST_ASSERT_DUMMY_PROPERTY
};
static gchar* fso_framework_test_assert_typed_value_to_string (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer value);
static void fso_framework_test_assert_throw_unexpected_value (const gchar* info, const gchar* message, GError** error);
void fso_framework_test_assert_are_equal (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer expected, gconstpointer actual, const gchar* message, GError** error);
void fso_framework_test_assert_are_not_equal (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer not_expected, gconstpointer actual, const gchar* message, GError** error);
void fso_framework_test_assert_is_true (gboolean actual, const gchar* message, GError** error);
void fso_framework_test_assert_is_false (gboolean actual, const gchar* message, GError** error);
void fso_framework_test_assert_fail (const gchar* message, GError** error);
void fso_framework_test_assert_should_throw_async (FsoFrameworkTestAsyncBegin fbegin, void* fbegin_target, FsoFrameworkTestAsyncFinish ffinish, void* ffinish_target, const gchar* domain, const gchar* message, GError** error);
gboolean fso_framework_test_wait_for_async (gint timeout, FsoFrameworkTestAsyncBegin async_function, void* async_function_target, FsoFrameworkTestAsyncFinish async_finish, void* async_finish_target, GError** error);
FsoFrameworkTestAssert* fso_framework_test_assert_new (void);
FsoFrameworkTestAssert* fso_framework_test_assert_construct (GType object_type);


GQuark fso_framework_test_assert_error_quark (void) {
	return g_quark_from_static_string ("fso_framework_test_assert_error-quark");
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gchar* bool_to_string (gboolean self) {
	gchar* result = NULL;
	if (self) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup ("true");
		result = _tmp0_;
		return result;
	} else {
		gchar* _tmp1_;
		_tmp1_ = g_strdup ("false");
		result = _tmp1_;
		return result;
	}
}


static gchar* fso_framework_test_assert_typed_value_to_string (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer value) {
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* _result_;
	GType value_type;
	GType _tmp1_;
	gboolean _tmp2_ = FALSE;
	_tmp0_ = g_strdup ("");
	_result_ = _tmp0_;
	value_type = t_type;
	_tmp1_ = value_type;
	_tmp2_ = G_TYPE_IS_VALUE_TYPE (_tmp1_);
	if (_tmp2_) {
		GType _tmp3_;
		gboolean _tmp4_ = FALSE;
		_tmp3_ = value_type;
		_tmp4_ = g_type_is_a (_tmp3_, G_TYPE_STRING);
		if (_tmp4_) {
			gconstpointer _tmp5_;
			const gchar* _tmp6_ = NULL;
			gchar* _tmp7_;
			_tmp5_ = value;
			_tmp6_ = string_to_string ((const gchar*) _tmp5_);
			_tmp7_ = g_strdup (_tmp6_);
			_g_free0 (_result_);
			_result_ = _tmp7_;
		} else {
			GType _tmp8_;
			gboolean _tmp9_ = FALSE;
			_tmp8_ = value_type;
			_tmp9_ = g_type_is_a (_tmp8_, G_TYPE_INT);
			if (_tmp9_) {
				gconstpointer _tmp10_;
				gchar* _tmp11_ = NULL;
				_tmp10_ = value;
				_tmp11_ = g_strdup_printf ("%i", (gint32) _tmp10_);
				_g_free0 (_result_);
				_result_ = _tmp11_;
			} else {
				GType _tmp12_;
				gboolean _tmp13_ = FALSE;
				_tmp12_ = value_type;
				_tmp13_ = g_type_is_a (_tmp12_, G_TYPE_UINT);
				if (_tmp13_) {
					gconstpointer _tmp14_;
					gchar* _tmp15_ = NULL;
					_tmp14_ = value;
					_tmp15_ = g_strdup_printf ("%u", (guint32) _tmp14_);
					_g_free0 (_result_);
					_result_ = _tmp15_;
				} else {
					GType _tmp16_;
					gboolean _tmp17_ = FALSE;
					_tmp16_ = value_type;
					_tmp17_ = g_type_is_a (_tmp16_, G_TYPE_INVALID);
					if (_tmp17_) {
						gconstpointer _tmp18_;
						gchar* _tmp19_ = NULL;
						_tmp18_ = value;
						_tmp19_ = g_strdup_printf ("%" G_GINT16_FORMAT, (gint16) _tmp18_);
						_g_free0 (_result_);
						_result_ = _tmp19_;
					} else {
						GType _tmp20_;
						gboolean _tmp21_ = FALSE;
						_tmp20_ = value_type;
						_tmp21_ = g_type_is_a (_tmp20_, G_TYPE_INVALID);
						if (_tmp21_) {
							gconstpointer _tmp22_;
							gchar* _tmp23_ = NULL;
							_tmp22_ = value;
							_tmp23_ = g_strdup_printf ("%hu", (guint16) _tmp22_);
							_g_free0 (_result_);
							_result_ = _tmp23_;
						} else {
							GType _tmp24_;
							gboolean _tmp25_ = FALSE;
							_tmp24_ = value_type;
							_tmp25_ = g_type_is_a (_tmp24_, G_TYPE_CHAR);
							if (_tmp25_) {
								gconstpointer _tmp26_;
								gchar* _tmp27_ = NULL;
								_tmp26_ = value;
								_tmp27_ = g_strdup_printf ("%hhi", (gint8) _tmp26_);
								_g_free0 (_result_);
								_result_ = _tmp27_;
							} else {
								GType _tmp28_;
								gboolean _tmp29_ = FALSE;
								_tmp28_ = value_type;
								_tmp29_ = g_type_is_a (_tmp28_, G_TYPE_UCHAR);
								if (_tmp29_) {
									gconstpointer _tmp30_;
									gchar* _tmp31_ = NULL;
									_tmp30_ = value;
									_tmp31_ = g_strdup_printf ("%hhu", (guint8) _tmp30_);
									_g_free0 (_result_);
									_result_ = _tmp31_;
								} else {
									GType _tmp32_;
									gboolean _tmp33_ = FALSE;
									_tmp32_ = value_type;
									_tmp33_ = g_type_is_a (_tmp32_, G_TYPE_BOOLEAN);
									if (_tmp33_) {
										gconstpointer _tmp34_;
										gchar* _tmp35_ = NULL;
										_tmp34_ = value;
										_tmp35_ = bool_to_string ((gboolean) _tmp34_);
										_g_free0 (_result_);
										_result_ = _tmp35_;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	result = _result_;
	return result;
}


static void fso_framework_test_assert_throw_unexpected_value (const gchar* info, const gchar* message, GError** error) {
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	GError* _tmp12_;
	GError* _tmp13_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (info != NULL);
	g_return_if_fail (message != NULL);
	_tmp1_ = message;
	_tmp2_ = strlen (_tmp1_);
	_tmp3_ = _tmp2_;
	if (_tmp3_ > 0) {
		const gchar* _tmp4_;
		const gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		_tmp4_ = message;
		_tmp5_ = string_to_string (_tmp4_);
		_tmp6_ = g_strconcat (" : ", _tmp5_, NULL);
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp6_;
	} else {
		gchar* _tmp7_;
		_tmp7_ = g_strdup ("");
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp7_;
	}
	_tmp8_ = info;
	_tmp9_ = _tmp0_;
	_tmp10_ = g_strconcat (_tmp8_, _tmp9_, NULL);
	_tmp11_ = _tmp10_;
	_tmp12_ = g_error_new_literal (FSO_FRAMEWORK_TEST_ASSERT_ERROR, FSO_FRAMEWORK_TEST_ASSERT_ERROR_UNEXPECTED_VALUE, _tmp11_);
	_tmp13_ = _tmp12_;
	_g_free0 (_tmp11_);
	_inner_error_ = _tmp13_;
	if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
		g_propagate_error (error, _inner_error_);
		_g_free0 (_tmp0_);
		return;
	} else {
		_g_free0 (_tmp0_);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (_tmp0_);
}


/**
         * Check wether two values of type T are the same. If both values are different an
         * exception of type AssertError is thrown.
         *
         * @param expected Expected value
         * @param actual Actual value to compare with the expected one
         * @param message Extra description message if both values are different
         **/
void fso_framework_test_assert_are_equal (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer expected, gconstpointer actual, const gchar* message, GError** error) {
	gconstpointer _tmp0_;
	gconstpointer _tmp1_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (message != NULL);
	_tmp0_ = expected;
	_tmp1_ = actual;
	if (_tmp0_ != _tmp1_) {
		gconstpointer _tmp2_;
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		const gchar* _tmp5_ = NULL;
		gconstpointer _tmp6_;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		const gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		gchar* msg;
		const gchar* _tmp12_;
		const gchar* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_;
		const gchar* _tmp16_;
		_tmp2_ = expected;
		_tmp3_ = fso_framework_test_assert_typed_value_to_string (t_type, (GBoxedCopyFunc) t_dup_func, t_destroy_func, _tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = string_to_string (_tmp4_);
		_tmp6_ = actual;
		_tmp7_ = fso_framework_test_assert_typed_value_to_string (t_type, (GBoxedCopyFunc) t_dup_func, t_destroy_func, _tmp6_);
		_tmp8_ = _tmp7_;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = g_strconcat (_tmp5_, " != ", _tmp9_, NULL);
		_tmp11_ = _tmp10_;
		_g_free0 (_tmp8_);
		_g_free0 (_tmp4_);
		msg = _tmp11_;
		_tmp12_ = msg;
		_tmp13_ = string_to_string (_tmp12_);
		_tmp14_ = g_strconcat ("Actual value is not the same as the expected one: ", _tmp13_, NULL);
		_tmp15_ = _tmp14_;
		_tmp16_ = message;
		fso_framework_test_assert_throw_unexpected_value (_tmp15_, _tmp16_, &_inner_error_);
		_g_free0 (_tmp15_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (msg);
				return;
			} else {
				_g_free0 (msg);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_g_free0 (msg);
	}
}


/**
         * Check wether two values of type T are not the same. If both values are the same an
         * exception of type AssertError is thrown.
         *
         * @param not_expected Not expected value
         * @param actual Actual value to compare with the not expected one
         * @param message Extra description message if both values are not different
         **/
void fso_framework_test_assert_are_not_equal (GType t_type, GBoxedCopyFunc t_dup_func, GDestroyNotify t_destroy_func, gconstpointer not_expected, gconstpointer actual, const gchar* message, GError** error) {
	gconstpointer _tmp0_;
	gconstpointer _tmp1_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (message != NULL);
	_tmp0_ = not_expected;
	_tmp1_ = actual;
	if (_tmp0_ == _tmp1_) {
		gchar* _tmp2_;
		gchar* msg;
		const gchar* _tmp3_;
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		const gchar* _tmp7_;
		_tmp2_ = g_strdup ("$(typed_value_to_string(expected)) == $(typed_value_to_string(actual))");
		msg = _tmp2_;
		_tmp3_ = msg;
		_tmp4_ = string_to_string (_tmp3_);
		_tmp5_ = g_strconcat ("Actual value is the same as the not expected one: ", _tmp4_, NULL);
		_tmp6_ = _tmp5_;
		_tmp7_ = message;
		fso_framework_test_assert_throw_unexpected_value (_tmp6_, _tmp7_, &_inner_error_);
		_g_free0 (_tmp6_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
				g_propagate_error (error, _inner_error_);
				_g_free0 (msg);
				return;
			} else {
				_g_free0 (msg);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_g_free0 (msg);
	}
}


/**
         * Check wether a boolean value is true and throw an exception otherwise.
         *
         * @param actual Value to check if it's true or not
         * @param message Text message to append to error message when assert failed
         **/
void fso_framework_test_assert_is_true (gboolean actual, const gchar* message, GError** error) {
	gboolean _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (message != NULL);
	_tmp0_ = actual;
	if (!_tmp0_) {
		const gchar* _tmp1_;
		_tmp1_ = message;
		fso_framework_test_assert_throw_unexpected_value ("Supplied value is not true", _tmp1_, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
}


/**
         * Check wether a boolean value is false and throw an exception otherwise.
         *
         * @param actual Value to check if it's false or not
         * @param message Text message to append to error message when assert failed
         **/
void fso_framework_test_assert_is_false (gboolean actual, const gchar* message, GError** error) {
	gboolean _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (message != NULL);
	_tmp0_ = actual;
	if (_tmp0_) {
		const gchar* _tmp1_;
		_tmp1_ = message;
		fso_framework_test_assert_throw_unexpected_value ("Supplied value is not false", _tmp1_, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
}


/**
         * Let test execution fail regardless any condition.
         *
         * @param message Text to append to error message
         **/
void fso_framework_test_assert_fail (const gchar* message, GError** error) {
	const gchar* _tmp0_;
	GError* _tmp1_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (message != NULL);
	_tmp0_ = message;
	_tmp1_ = g_error_new_literal (FSO_FRAMEWORK_TEST_ASSERT_ERROR, FSO_FRAMEWORK_TEST_ASSERT_ERROR_UNEXPECTED_STATE, _tmp0_);
	_inner_error_ = _tmp1_;
	if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
		g_propagate_error (error, _inner_error_);
		return;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


/**
         * Check wether an async operation throws a specific exception.
         *
         * @param fbegin Method to start execution of async operation
         * @param ffinish Method to finish execution of async operation
         * @param domain Error domain of the exception which should be thrown by the async
                         operation.
         * @param message Text message to append to error message when specific exception
         *                is not thrown.
         **/
void fso_framework_test_assert_should_throw_async (FsoFrameworkTestAsyncBegin fbegin, void* fbegin_target, FsoFrameworkTestAsyncFinish ffinish, void* ffinish_target, const gchar* domain, const gchar* message, GError** error) {
	GError* _tmp14_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (domain != NULL);
	g_return_if_fail (message != NULL);
	{
		FsoFrameworkTestAsyncBegin _tmp0_;
		void* _tmp0__target;
		FsoFrameworkTestAsyncFinish _tmp1_;
		void* _tmp1__target;
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_;
		_tmp0_ = fbegin;
		_tmp0__target = fbegin_target;
		_tmp1_ = ffinish;
		_tmp1__target = ffinish_target;
		_tmp2_ = fso_framework_test_wait_for_async (200, _tmp0_, _tmp0__target, _tmp1_, _tmp1__target, &_inner_error_);
		_tmp3_ = _tmp2_;
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
		if (!_tmp3_) {
			const gchar* _tmp4_;
			_tmp4_ = message;
			fso_framework_test_assert_throw_unexpected_value ("Execution of async method didn't returns the expected value", _tmp4_, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch0_g_error;
			}
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* err = NULL;
		GError* _tmp5_;
		GQuark _tmp6_;
		const gchar* _tmp7_ = NULL;
		const gchar* _tmp8_;
		err = _inner_error_;
		_inner_error_ = NULL;
		_tmp5_ = err;
		_tmp6_ = _tmp5_->domain;
		_tmp7_ = g_quark_to_string (_tmp6_);
		_tmp8_ = domain;
		if (g_strcmp0 (_tmp7_, _tmp8_) != 0) {
			const gchar* _tmp9_;
			const gchar* _tmp10_ = NULL;
			gchar* _tmp11_ = NULL;
			gchar* _tmp12_;
			const gchar* _tmp13_;
			_tmp9_ = domain;
			_tmp10_ = string_to_string (_tmp9_);
			_tmp11_ = g_strconcat ("Didn't receive the expected exception of type ", _tmp10_, NULL);
			_tmp12_ = _tmp11_;
			_tmp13_ = message;
			fso_framework_test_assert_throw_unexpected_value (_tmp12_, _tmp13_, &_inner_error_);
			_g_free0 (_tmp12_);
			if (_inner_error_ != NULL) {
				_g_error_free0 (err);
				goto __finally0;
			}
		}
		_g_error_free0 (err);
		return;
	}
	__finally0:
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp14_ = g_error_new_literal (FSO_FRAMEWORK_TEST_ASSERT_ERROR, FSO_FRAMEWORK_TEST_ASSERT_ERROR_UNEXPECTED_STATE, "Function didn't throw expected exception");
	_inner_error_ = _tmp14_;
	if (_inner_error_->domain == FSO_FRAMEWORK_TEST_ASSERT_ERROR) {
		g_propagate_error (error, _inner_error_);
		return;
	} else {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


FsoFrameworkTestAssert* fso_framework_test_assert_construct (GType object_type) {
	FsoFrameworkTestAssert * self = NULL;
	self = (FsoFrameworkTestAssert*) g_object_new (object_type, NULL);
	return self;
}


FsoFrameworkTestAssert* fso_framework_test_assert_new (void) {
	return fso_framework_test_assert_construct (FSO_FRAMEWORK_TEST_TYPE_ASSERT);
}


static void fso_framework_test_assert_class_init (FsoFrameworkTestAssertClass * klass) {
	fso_framework_test_assert_parent_class = g_type_class_peek_parent (klass);
}


static void fso_framework_test_assert_instance_init (FsoFrameworkTestAssert * self) {
}


GType fso_framework_test_assert_get_type (void) {
	static volatile gsize fso_framework_test_assert_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_test_assert_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkTestAssertClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_test_assert_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkTestAssert), 0, (GInstanceInitFunc) fso_framework_test_assert_instance_init, NULL };
		GType fso_framework_test_assert_type_id;
		fso_framework_test_assert_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoFrameworkTestAssert", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_test_assert_type_id__volatile, fso_framework_test_assert_type_id);
	}
	return fso_framework_test_assert_type_id__volatile;
}




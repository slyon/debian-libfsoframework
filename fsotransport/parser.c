/* parser.c generated by valac 0.16.1, the Vala compiler
 * generated from parser.vala, do not modify */

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


#define FSO_FRAMEWORK_TYPE_PARSER (fso_framework_parser_get_type ())
#define FSO_FRAMEWORK_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_PARSER, FsoFrameworkParser))
#define FSO_FRAMEWORK_IS_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_PARSER))
#define FSO_FRAMEWORK_PARSER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_FRAMEWORK_TYPE_PARSER, FsoFrameworkParserIface))

typedef struct _FsoFrameworkParser FsoFrameworkParser;
typedef struct _FsoFrameworkParserIface FsoFrameworkParserIface;

#define FSO_FRAMEWORK_TYPE_BASE_PARSER (fso_framework_base_parser_get_type ())
#define FSO_FRAMEWORK_BASE_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_BASE_PARSER, FsoFrameworkBaseParser))
#define FSO_FRAMEWORK_BASE_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_BASE_PARSER, FsoFrameworkBaseParserClass))
#define FSO_FRAMEWORK_IS_BASE_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_BASE_PARSER))
#define FSO_FRAMEWORK_IS_BASE_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_BASE_PARSER))
#define FSO_FRAMEWORK_BASE_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_BASE_PARSER, FsoFrameworkBaseParserClass))

typedef struct _FsoFrameworkBaseParser FsoFrameworkBaseParser;
typedef struct _FsoFrameworkBaseParserClass FsoFrameworkBaseParserClass;
typedef struct _FsoFrameworkBaseParserPrivate FsoFrameworkBaseParserPrivate;

#define FSO_FRAMEWORK_TYPE_NULL_PARSER (fso_framework_null_parser_get_type ())
#define FSO_FRAMEWORK_NULL_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_NULL_PARSER, FsoFrameworkNullParser))
#define FSO_FRAMEWORK_NULL_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_NULL_PARSER, FsoFrameworkNullParserClass))
#define FSO_FRAMEWORK_IS_NULL_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_NULL_PARSER))
#define FSO_FRAMEWORK_IS_NULL_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_NULL_PARSER))
#define FSO_FRAMEWORK_NULL_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_NULL_PARSER, FsoFrameworkNullParserClass))

typedef struct _FsoFrameworkNullParser FsoFrameworkNullParser;
typedef struct _FsoFrameworkNullParserClass FsoFrameworkNullParserClass;
typedef struct _FsoFrameworkNullParserPrivate FsoFrameworkNullParserPrivate;

#define FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER (fso_framework_line_by_line_parser_get_type ())
#define FSO_FRAMEWORK_LINE_BY_LINE_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER, FsoFrameworkLineByLineParser))
#define FSO_FRAMEWORK_LINE_BY_LINE_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER, FsoFrameworkLineByLineParserClass))
#define FSO_FRAMEWORK_IS_LINE_BY_LINE_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER))
#define FSO_FRAMEWORK_IS_LINE_BY_LINE_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER))
#define FSO_FRAMEWORK_LINE_BY_LINE_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER, FsoFrameworkLineByLineParserClass))

typedef struct _FsoFrameworkLineByLineParser FsoFrameworkLineByLineParser;
typedef struct _FsoFrameworkLineByLineParserClass FsoFrameworkLineByLineParserClass;
typedef struct _FsoFrameworkLineByLineParserPrivate FsoFrameworkLineByLineParserPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

typedef gboolean (*FsoFrameworkParserHaveCommandFunc) (void* user_data);
typedef gboolean (*FsoFrameworkParserExpectedPrefixFunc) (const gchar* line, void* user_data);
typedef void (*FsoFrameworkParserSolicitedCompletedFunc) (gchar** response, int response_length1, void* user_data);
typedef void (*FsoFrameworkParserUnsolicitedCompletedFunc) (gchar** response, int response_length1, void* user_data);
struct _FsoFrameworkParserIface {
	GTypeInterface parent_iface;
	void (*setDelegates) (FsoFrameworkParser* self, FsoFrameworkParserHaveCommandFunc haveCommand, void* haveCommand_target, FsoFrameworkParserExpectedPrefixFunc expectedPrefix, void* expectedPrefix_target, FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted, void* solicitedCompleted_target, FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted, void* unsolicitedCompleted_target);
	gint (*feed) (FsoFrameworkParser* self, void* data, gint len);
};

struct _FsoFrameworkBaseParser {
	GObject parent_instance;
	FsoFrameworkBaseParserPrivate * priv;
	FsoFrameworkParserHaveCommandFunc haveCommand;
	gpointer haveCommand_target;
	GDestroyNotify haveCommand_target_destroy_notify;
	FsoFrameworkParserExpectedPrefixFunc expectedPrefix;
	gpointer expectedPrefix_target;
	GDestroyNotify expectedPrefix_target_destroy_notify;
	FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted;
	gpointer solicitedCompleted_target;
	GDestroyNotify solicitedCompleted_target_destroy_notify;
	FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted;
	gpointer unsolicitedCompleted_target;
	GDestroyNotify unsolicitedCompleted_target_destroy_notify;
};

struct _FsoFrameworkBaseParserClass {
	GObjectClass parent_class;
	gint (*feed) (FsoFrameworkBaseParser* self, void* data, gint len);
};

struct _FsoFrameworkNullParser {
	FsoFrameworkBaseParser parent_instance;
	FsoFrameworkNullParserPrivate * priv;
};

struct _FsoFrameworkNullParserClass {
	FsoFrameworkBaseParserClass parent_class;
};

struct _FsoFrameworkLineByLineParser {
	FsoFrameworkBaseParser parent_instance;
	FsoFrameworkLineByLineParserPrivate * priv;
};

struct _FsoFrameworkLineByLineParserClass {
	FsoFrameworkBaseParserClass parent_class;
};

struct _FsoFrameworkLineByLineParserPrivate {
	gchar* termination;
	gchar* curline;
	gint curline_length1;
	gint _curline_size_;
	guint index;
	guint matched;
	gboolean swallow;
};


static gpointer fso_framework_base_parser_parent_class = NULL;
static FsoFrameworkParserIface* fso_framework_base_parser_fso_framework_parser_parent_iface = NULL;
static gpointer fso_framework_null_parser_parent_class = NULL;
static gpointer fso_framework_line_by_line_parser_parent_class = NULL;

GType fso_framework_parser_get_type (void) G_GNUC_CONST;
void fso_framework_parser_setDelegates (FsoFrameworkParser* self, FsoFrameworkParserHaveCommandFunc haveCommand, void* haveCommand_target, FsoFrameworkParserExpectedPrefixFunc expectedPrefix, void* expectedPrefix_target, FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted, void* solicitedCompleted_target, FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted, void* unsolicitedCompleted_target);
gint fso_framework_parser_feed (FsoFrameworkParser* self, void* data, gint len);
GType fso_framework_base_parser_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_BASE_PARSER_DUMMY_PROPERTY
};
static void fso_framework_base_parser_real_setDelegates (FsoFrameworkParser* base, FsoFrameworkParserHaveCommandFunc haveCommand, void* haveCommand_target, FsoFrameworkParserExpectedPrefixFunc expectedPrefix, void* expectedPrefix_target, FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted, void* solicitedCompleted_target, FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted, void* unsolicitedCompleted_target);
gint fso_framework_base_parser_feed (FsoFrameworkBaseParser* self, void* data, gint len);
static gint fso_framework_base_parser_real_feed (FsoFrameworkBaseParser* self, void* data, gint len);
FsoFrameworkBaseParser* fso_framework_base_parser_new (void);
FsoFrameworkBaseParser* fso_framework_base_parser_construct (GType object_type);
static void fso_framework_base_parser_finalize (GObject* obj);
GType fso_framework_null_parser_get_type (void) G_GNUC_CONST;
enum  {
	FSO_FRAMEWORK_NULL_PARSER_DUMMY_PROPERTY
};
static gint fso_framework_null_parser_real_feed (FsoFrameworkBaseParser* base, void* data, gint len);
FsoFrameworkNullParser* fso_framework_null_parser_new (void);
FsoFrameworkNullParser* fso_framework_null_parser_construct (GType object_type);
GType fso_framework_line_by_line_parser_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_LINE_BY_LINE_PARSER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER, FsoFrameworkLineByLineParserPrivate))
enum  {
	FSO_FRAMEWORK_LINE_BY_LINE_PARSER_DUMMY_PROPERTY
};
static void fso_framework_line_by_line_parser_resetLine (FsoFrameworkLineByLineParser* self);
static void fso_framework_line_by_line_parser_feedCharacter (FsoFrameworkLineByLineParser* self, gchar c);
static void _vala_array_add1 (gchar** array, int* length, int* size, gchar value);
static void fso_framework_line_by_line_parser_endofline (FsoFrameworkLineByLineParser* self);
static void _vala_array_add2 (gchar** array, int* length, int* size, gchar value);
static void _vala_array_add3 (gchar** array, int* length, int* size, gchar value);
FsoFrameworkLineByLineParser* fso_framework_line_by_line_parser_new (const gchar* termination, gboolean swallow);
FsoFrameworkLineByLineParser* fso_framework_line_by_line_parser_construct (GType object_type, const gchar* termination, gboolean swallow);
static gint fso_framework_line_by_line_parser_real_feed (FsoFrameworkBaseParser* base, gchar* data, gint len);
static void fso_framework_line_by_line_parser_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


/**
     * Set the delegates
     **/
void fso_framework_parser_setDelegates (FsoFrameworkParser* self, FsoFrameworkParserHaveCommandFunc haveCommand, void* haveCommand_target, FsoFrameworkParserExpectedPrefixFunc expectedPrefix, void* expectedPrefix_target, FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted, void* solicitedCompleted_target, FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted, void* unsolicitedCompleted_target) {
	g_return_if_fail (self != NULL);
	FSO_FRAMEWORK_PARSER_GET_INTERFACE (self)->setDelegates (self, haveCommand, haveCommand_target, expectedPrefix, expectedPrefix_target, solicitedCompleted, solicitedCompleted_target, unsolicitedCompleted, unsolicitedCompleted_target);
}


/**
     * Feed data into the parser.
     **/
gint fso_framework_parser_feed (FsoFrameworkParser* self, void* data, gint len) {
	g_return_val_if_fail (self != NULL, 0);
	return FSO_FRAMEWORK_PARSER_GET_INTERFACE (self)->feed (self, data, len);
}


static void fso_framework_parser_base_init (FsoFrameworkParserIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
	}
}


/**
 * @interface FsoFramework.Parser
 *
 * The Parser Interface
 **/
GType fso_framework_parser_get_type (void) {
	static volatile gsize fso_framework_parser_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkParserIface), (GBaseInitFunc) fso_framework_parser_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType fso_framework_parser_type_id;
		fso_framework_parser_type_id = g_type_register_static (G_TYPE_INTERFACE, "FsoFrameworkParser", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (fso_framework_parser_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&fso_framework_parser_type_id__volatile, fso_framework_parser_type_id);
	}
	return fso_framework_parser_type_id__volatile;
}


static void fso_framework_base_parser_real_setDelegates (FsoFrameworkParser* base, FsoFrameworkParserHaveCommandFunc haveCommand, void* haveCommand_target, FsoFrameworkParserExpectedPrefixFunc expectedPrefix, void* expectedPrefix_target, FsoFrameworkParserSolicitedCompletedFunc solicitedCompleted, void* solicitedCompleted_target, FsoFrameworkParserUnsolicitedCompletedFunc unsolicitedCompleted, void* unsolicitedCompleted_target) {
	FsoFrameworkBaseParser * self;
	FsoFrameworkParserHaveCommandFunc _tmp0_;
	void* _tmp0__target;
	FsoFrameworkParserExpectedPrefixFunc _tmp2_;
	void* _tmp2__target;
	FsoFrameworkParserSolicitedCompletedFunc _tmp4_;
	void* _tmp4__target;
	FsoFrameworkParserUnsolicitedCompletedFunc _tmp6_;
	void* _tmp6__target;
	FsoFrameworkParserHaveCommandFunc _tmp8_;
	void* _tmp8__target;
	FsoFrameworkParserExpectedPrefixFunc _tmp9_;
	void* _tmp9__target;
	FsoFrameworkParserSolicitedCompletedFunc _tmp10_;
	void* _tmp10__target;
	FsoFrameworkParserUnsolicitedCompletedFunc _tmp11_;
	void* _tmp11__target;
	self = (FsoFrameworkBaseParser*) base;
	_tmp0_ = haveCommand;
	_tmp0__target = haveCommand_target;
	if (_tmp0_ != NULL) {
		FsoFrameworkParserHaveCommandFunc _tmp1_;
		void* _tmp1__target;
		_tmp1_ = self->haveCommand;
		_tmp1__target = self->haveCommand_target;
		g_assert (_tmp1_ == NULL);
	}
	_tmp2_ = expectedPrefix;
	_tmp2__target = expectedPrefix_target;
	if (_tmp2_ != NULL) {
		FsoFrameworkParserExpectedPrefixFunc _tmp3_;
		void* _tmp3__target;
		_tmp3_ = self->expectedPrefix;
		_tmp3__target = self->expectedPrefix_target;
		g_assert (_tmp3_ == NULL);
	}
	_tmp4_ = solicitedCompleted;
	_tmp4__target = solicitedCompleted_target;
	if (_tmp4_ != NULL) {
		FsoFrameworkParserSolicitedCompletedFunc _tmp5_;
		void* _tmp5__target;
		_tmp5_ = self->solicitedCompleted;
		_tmp5__target = self->solicitedCompleted_target;
		g_assert (_tmp5_ == NULL);
	}
	_tmp6_ = unsolicitedCompleted;
	_tmp6__target = unsolicitedCompleted_target;
	if (_tmp6_ != NULL) {
		FsoFrameworkParserUnsolicitedCompletedFunc _tmp7_;
		void* _tmp7__target;
		_tmp7_ = self->unsolicitedCompleted;
		_tmp7__target = self->unsolicitedCompleted_target;
		g_assert (_tmp7_ == NULL);
	}
	_tmp8_ = haveCommand;
	_tmp8__target = haveCommand_target;
	(self->haveCommand_target_destroy_notify == NULL) ? NULL : (self->haveCommand_target_destroy_notify (self->haveCommand_target), NULL);
	self->haveCommand = NULL;
	self->haveCommand_target = NULL;
	self->haveCommand_target_destroy_notify = NULL;
	self->haveCommand = _tmp8_;
	self->haveCommand_target = _tmp8__target;
	self->haveCommand_target_destroy_notify = NULL;
	_tmp9_ = expectedPrefix;
	_tmp9__target = expectedPrefix_target;
	(self->expectedPrefix_target_destroy_notify == NULL) ? NULL : (self->expectedPrefix_target_destroy_notify (self->expectedPrefix_target), NULL);
	self->expectedPrefix = NULL;
	self->expectedPrefix_target = NULL;
	self->expectedPrefix_target_destroy_notify = NULL;
	self->expectedPrefix = _tmp9_;
	self->expectedPrefix_target = _tmp9__target;
	self->expectedPrefix_target_destroy_notify = NULL;
	_tmp10_ = solicitedCompleted;
	_tmp10__target = solicitedCompleted_target;
	(self->solicitedCompleted_target_destroy_notify == NULL) ? NULL : (self->solicitedCompleted_target_destroy_notify (self->solicitedCompleted_target), NULL);
	self->solicitedCompleted = NULL;
	self->solicitedCompleted_target = NULL;
	self->solicitedCompleted_target_destroy_notify = NULL;
	self->solicitedCompleted = _tmp10_;
	self->solicitedCompleted_target = _tmp10__target;
	self->solicitedCompleted_target_destroy_notify = NULL;
	_tmp11_ = unsolicitedCompleted;
	_tmp11__target = unsolicitedCompleted_target;
	(self->unsolicitedCompleted_target_destroy_notify == NULL) ? NULL : (self->unsolicitedCompleted_target_destroy_notify (self->unsolicitedCompleted_target), NULL);
	self->unsolicitedCompleted = NULL;
	self->unsolicitedCompleted_target = NULL;
	self->unsolicitedCompleted_target_destroy_notify = NULL;
	self->unsolicitedCompleted = _tmp11_;
	self->unsolicitedCompleted_target = _tmp11__target;
	self->unsolicitedCompleted_target_destroy_notify = NULL;
}


static gint fso_framework_base_parser_real_feed (FsoFrameworkBaseParser* self, void* data, gint len) {
	gint result = 0;
	g_assert_not_reached ();
	return result;
}


gint fso_framework_base_parser_feed (FsoFrameworkBaseParser* self, void* data, gint len) {
	g_return_val_if_fail (self != NULL, 0);
	return FSO_FRAMEWORK_BASE_PARSER_GET_CLASS (self)->feed (self, data, len);
}


FsoFrameworkBaseParser* fso_framework_base_parser_construct (GType object_type) {
	FsoFrameworkBaseParser * self = NULL;
	self = (FsoFrameworkBaseParser*) g_object_new (object_type, NULL);
	return self;
}


FsoFrameworkBaseParser* fso_framework_base_parser_new (void) {
	return fso_framework_base_parser_construct (FSO_FRAMEWORK_TYPE_BASE_PARSER);
}


static void fso_framework_base_parser_class_init (FsoFrameworkBaseParserClass * klass) {
	fso_framework_base_parser_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_BASE_PARSER_CLASS (klass)->feed = fso_framework_base_parser_real_feed;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_base_parser_finalize;
}


static void fso_framework_base_parser_fso_framework_parser_interface_init (FsoFrameworkParserIface * iface) {
	fso_framework_base_parser_fso_framework_parser_parent_iface = g_type_interface_peek_parent (iface);
	iface->setDelegates = (void (*)(FsoFrameworkParser*, FsoFrameworkParserHaveCommandFunc, void*, FsoFrameworkParserExpectedPrefixFunc, void*, FsoFrameworkParserSolicitedCompletedFunc, void*, FsoFrameworkParserUnsolicitedCompletedFunc, void*)) fso_framework_base_parser_real_setDelegates;
	iface->feed = (gint (*)(FsoFrameworkParser*, void*, gint)) fso_framework_base_parser_feed;
}


static void fso_framework_base_parser_instance_init (FsoFrameworkBaseParser * self) {
}


static void fso_framework_base_parser_finalize (GObject* obj) {
	FsoFrameworkBaseParser * self;
	self = FSO_FRAMEWORK_BASE_PARSER (obj);
	(self->haveCommand_target_destroy_notify == NULL) ? NULL : (self->haveCommand_target_destroy_notify (self->haveCommand_target), NULL);
	self->haveCommand = NULL;
	self->haveCommand_target = NULL;
	self->haveCommand_target_destroy_notify = NULL;
	(self->expectedPrefix_target_destroy_notify == NULL) ? NULL : (self->expectedPrefix_target_destroy_notify (self->expectedPrefix_target), NULL);
	self->expectedPrefix = NULL;
	self->expectedPrefix_target = NULL;
	self->expectedPrefix_target_destroy_notify = NULL;
	(self->solicitedCompleted_target_destroy_notify == NULL) ? NULL : (self->solicitedCompleted_target_destroy_notify (self->solicitedCompleted_target), NULL);
	self->solicitedCompleted = NULL;
	self->solicitedCompleted_target = NULL;
	self->solicitedCompleted_target_destroy_notify = NULL;
	(self->unsolicitedCompleted_target_destroy_notify == NULL) ? NULL : (self->unsolicitedCompleted_target_destroy_notify (self->unsolicitedCompleted_target), NULL);
	self->unsolicitedCompleted = NULL;
	self->unsolicitedCompleted_target = NULL;
	self->unsolicitedCompleted_target_destroy_notify = NULL;
	G_OBJECT_CLASS (fso_framework_base_parser_parent_class)->finalize (obj);
}


/**
 * Base Parser Class
 **/
GType fso_framework_base_parser_get_type (void) {
	static volatile gsize fso_framework_base_parser_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_base_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkBaseParserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_base_parser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkBaseParser), 0, (GInstanceInitFunc) fso_framework_base_parser_instance_init, NULL };
		static const GInterfaceInfo fso_framework_parser_info = { (GInterfaceInitFunc) fso_framework_base_parser_fso_framework_parser_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fso_framework_base_parser_type_id;
		fso_framework_base_parser_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoFrameworkBaseParser", &g_define_type_info, 0);
		g_type_add_interface_static (fso_framework_base_parser_type_id, FSO_FRAMEWORK_TYPE_PARSER, &fso_framework_parser_info);
		g_once_init_leave (&fso_framework_base_parser_type_id__volatile, fso_framework_base_parser_type_id);
	}
	return fso_framework_base_parser_type_id__volatile;
}


static gint fso_framework_null_parser_real_feed (FsoFrameworkBaseParser* base, void* data, gint len) {
	FsoFrameworkNullParser * self;
	gint result = 0;
	self = (FsoFrameworkNullParser*) base;
	result = 0;
	return result;
}


FsoFrameworkNullParser* fso_framework_null_parser_construct (GType object_type) {
	FsoFrameworkNullParser * self = NULL;
	self = (FsoFrameworkNullParser*) fso_framework_base_parser_construct (object_type);
	return self;
}


FsoFrameworkNullParser* fso_framework_null_parser_new (void) {
	return fso_framework_null_parser_construct (FSO_FRAMEWORK_TYPE_NULL_PARSER);
}


static void fso_framework_null_parser_class_init (FsoFrameworkNullParserClass * klass) {
	fso_framework_null_parser_parent_class = g_type_class_peek_parent (klass);
	FSO_FRAMEWORK_BASE_PARSER_CLASS (klass)->feed = fso_framework_null_parser_real_feed;
}


static void fso_framework_null_parser_instance_init (FsoFrameworkNullParser * self) {
}


/**
 * @class FsoFramework.NullParser
 *
 * The NullParser swallows everything.
 **/
GType fso_framework_null_parser_get_type (void) {
	static volatile gsize fso_framework_null_parser_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_null_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkNullParserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_null_parser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkNullParser), 0, (GInstanceInitFunc) fso_framework_null_parser_instance_init, NULL };
		GType fso_framework_null_parser_type_id;
		fso_framework_null_parser_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_PARSER, "FsoFrameworkNullParser", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_null_parser_type_id__volatile, fso_framework_null_parser_type_id);
	}
	return fso_framework_null_parser_type_id__volatile;
}


static void fso_framework_line_by_line_parser_resetLine (FsoFrameworkLineByLineParser* self) {
	gchar* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_new0 (gchar, 0);
	self->priv->curline = (g_free (self->priv->curline), NULL);
	self->priv->curline = _tmp0_;
	self->priv->curline_length1 = 0;
	self->priv->_curline_size_ = self->priv->curline_length1;
	self->priv->index = (guint) 0;
	self->priv->matched = (guint) 0;
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static void _vala_array_add1 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void _vala_array_add2 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void fso_framework_line_by_line_parser_feedCharacter (FsoFrameworkLineByLineParser* self, gchar c) {
	gchar _tmp0_;
	const gchar* _tmp1_;
	guint _tmp2_;
	gchar _tmp3_ = '\0';
	g_return_if_fail (self != NULL);
	_tmp0_ = c;
	_tmp1_ = self->priv->termination;
	_tmp2_ = self->priv->index;
	_tmp3_ = string_get (_tmp1_, (glong) _tmp2_);
	if (_tmp0_ == _tmp3_) {
		gboolean _tmp4_;
		guint _tmp7_;
		guint _tmp8_;
		guint _tmp9_;
		const gchar* _tmp10_;
		gint _tmp11_;
		gint _tmp12_;
		_tmp4_ = self->priv->swallow;
		if (!_tmp4_) {
			gchar* _tmp5_;
			gint _tmp5__length1;
			gchar _tmp6_;
			_tmp5_ = self->priv->curline;
			_tmp5__length1 = self->priv->curline_length1;
			_tmp6_ = c;
			_vala_array_add1 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, _tmp6_);
		}
		_tmp7_ = self->priv->index;
		self->priv->index = _tmp7_ + 1;
		_tmp8_ = self->priv->matched;
		self->priv->matched = _tmp8_ + 1;
		_tmp9_ = self->priv->matched;
		_tmp10_ = self->priv->termination;
		_tmp11_ = strlen (_tmp10_);
		_tmp12_ = _tmp11_;
		if (_tmp9_ == ((guint) _tmp12_)) {
			fso_framework_line_by_line_parser_endofline (self);
		}
	} else {
		gchar* _tmp13_;
		gint _tmp13__length1;
		gchar _tmp14_;
		self->priv->index = (guint) 0;
		self->priv->matched = (guint) 0;
		_tmp13_ = self->priv->curline;
		_tmp13__length1 = self->priv->curline_length1;
		_tmp14_ = c;
		_vala_array_add2 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, _tmp14_);
	}
}


static void _vala_array_add3 (gchar** array, int* length, int* size, gchar value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar, *array, *size);
	}
	(*array)[(*length)++] = value;
}


static void fso_framework_line_by_line_parser_endofline (FsoFrameworkLineByLineParser* self) {
	gchar* _tmp0_;
	gint _tmp0__length1;
	FsoFrameworkParserHaveCommandFunc _tmp1_;
	void* _tmp1__target;
	gboolean _tmp2_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->curline;
	_tmp0__length1 = self->priv->curline_length1;
	_vala_array_add3 (&self->priv->curline, &self->priv->curline_length1, &self->priv->_curline_size_, (gchar) 0x0);
	_tmp1_ = ((FsoFrameworkBaseParser*) self)->haveCommand;
	_tmp1__target = ((FsoFrameworkBaseParser*) self)->haveCommand_target;
	_tmp2_ = _tmp1_ (_tmp1__target);
	if (!_tmp2_) {
		FsoFrameworkParserUnsolicitedCompletedFunc _tmp3_;
		void* _tmp3__target;
		gchar* _tmp4_;
		gint _tmp4__length1;
		gchar* _tmp5_;
		gchar** _tmp6_ = NULL;
		gchar** _tmp7_;
		gint _tmp7__length1;
		_tmp3_ = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted;
		_tmp3__target = ((FsoFrameworkBaseParser*) self)->unsolicitedCompleted_target;
		_tmp4_ = self->priv->curline;
		_tmp4__length1 = self->priv->curline_length1;
		_tmp5_ = g_strdup ((const gchar*) _tmp4_);
		_tmp6_ = g_new0 (gchar*, 1 + 1);
		_tmp6_[0] = _tmp5_;
		_tmp7_ = _tmp6_;
		_tmp7__length1 = 1;
		_tmp3_ (_tmp7_, 1, _tmp3__target);
		_tmp7_ = (_vala_array_free (_tmp7_, _tmp7__length1, (GDestroyNotify) g_free), NULL);
	} else {
		FsoFrameworkParserSolicitedCompletedFunc _tmp8_;
		void* _tmp8__target;
		gchar* _tmp9_;
		gint _tmp9__length1;
		gchar* _tmp10_;
		gchar** _tmp11_ = NULL;
		gchar** _tmp12_;
		gint _tmp12__length1;
		_tmp8_ = ((FsoFrameworkBaseParser*) self)->solicitedCompleted;
		_tmp8__target = ((FsoFrameworkBaseParser*) self)->solicitedCompleted_target;
		_tmp9_ = self->priv->curline;
		_tmp9__length1 = self->priv->curline_length1;
		_tmp10_ = g_strdup ((const gchar*) _tmp9_);
		_tmp11_ = g_new0 (gchar*, 1 + 1);
		_tmp11_[0] = _tmp10_;
		_tmp12_ = _tmp11_;
		_tmp12__length1 = 1;
		_tmp8_ (_tmp12_, 1, _tmp8__target);
		_tmp12_ = (_vala_array_free (_tmp12_, _tmp12__length1, (GDestroyNotify) g_free), NULL);
	}
	fso_framework_line_by_line_parser_resetLine (self);
}


FsoFrameworkLineByLineParser* fso_framework_line_by_line_parser_construct (GType object_type, const gchar* termination, gboolean swallow) {
	FsoFrameworkLineByLineParser * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gboolean _tmp2_;
	g_return_val_if_fail (termination != NULL, NULL);
	self = (FsoFrameworkLineByLineParser*) fso_framework_base_parser_construct (object_type);
	_tmp0_ = termination;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->termination);
	self->priv->termination = _tmp1_;
	_tmp2_ = swallow;
	self->priv->swallow = _tmp2_;
	fso_framework_line_by_line_parser_resetLine (self);
	return self;
}


FsoFrameworkLineByLineParser* fso_framework_line_by_line_parser_new (const gchar* termination, gboolean swallow) {
	return fso_framework_line_by_line_parser_construct (FSO_FRAMEWORK_TYPE_LINE_BY_LINE_PARSER, termination, swallow);
}


static gint fso_framework_line_by_line_parser_real_feed (FsoFrameworkBaseParser* base, gchar* data, gint len) {
	FsoFrameworkLineByLineParser * self;
	gint result = 0;
	self = (FsoFrameworkLineByLineParser*) base;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				gint _tmp3_;
				gint _tmp4_;
				gchar* _tmp5_;
				gchar c;
				gchar _tmp6_;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = i;
				_tmp4_ = len;
				if (!(_tmp3_ < _tmp4_)) {
					break;
				}
				_tmp5_ = data;
				data = _tmp5_ + 1;
				c = *_tmp5_;
				_tmp6_ = c;
				fso_framework_line_by_line_parser_feedCharacter (self, _tmp6_);
			}
		}
	}
	result = 0;
	return result;
}


static void fso_framework_line_by_line_parser_class_init (FsoFrameworkLineByLineParserClass * klass) {
	fso_framework_line_by_line_parser_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkLineByLineParserPrivate));
	FSO_FRAMEWORK_BASE_PARSER_CLASS (klass)->feed = fso_framework_line_by_line_parser_real_feed;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_line_by_line_parser_finalize;
}


static void fso_framework_line_by_line_parser_instance_init (FsoFrameworkLineByLineParser * self) {
	self->priv = FSO_FRAMEWORK_LINE_BY_LINE_PARSER_GET_PRIVATE (self);
}


static void fso_framework_line_by_line_parser_finalize (GObject* obj) {
	FsoFrameworkLineByLineParser * self;
	self = FSO_FRAMEWORK_LINE_BY_LINE_PARSER (obj);
	_g_free0 (self->priv->termination);
	self->priv->curline = (g_free (self->priv->curline), NULL);
	G_OBJECT_CLASS (fso_framework_line_by_line_parser_parent_class)->finalize (obj);
}


/**
 * @class FsoFramework.LineByLineParser
 *
 * The LineByLineParser reads data byte-by-byte until it encounters the terminal symbol.
 **/
GType fso_framework_line_by_line_parser_get_type (void) {
	static volatile gsize fso_framework_line_by_line_parser_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_line_by_line_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkLineByLineParserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_line_by_line_parser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkLineByLineParser), 0, (GInstanceInitFunc) fso_framework_line_by_line_parser_instance_init, NULL };
		GType fso_framework_line_by_line_parser_type_id;
		fso_framework_line_by_line_parser_type_id = g_type_register_static (FSO_FRAMEWORK_TYPE_BASE_PARSER, "FsoFrameworkLineByLineParser", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_line_by_line_parser_type_id__volatile, fso_framework_line_by_line_parser_type_id);
	}
	return fso_framework_line_by_line_parser_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}




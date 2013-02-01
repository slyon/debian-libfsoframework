/* filehandling.c generated by valac 0.16.1, the Vala compiler
 * generated from filehandling.vala, do not modify */

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
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <glib/gstdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


#define FSO_FRAMEWORK_TYPE_LOGGER (fso_framework_logger_get_type ())
#define FSO_FRAMEWORK_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_TYPE_LOGGER, FsoFrameworkLogger))
#define FSO_FRAMEWORK_IS_LOGGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_TYPE_LOGGER))
#define FSO_FRAMEWORK_LOGGER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), FSO_FRAMEWORK_TYPE_LOGGER, FsoFrameworkLoggerIface))

typedef struct _FsoFrameworkLogger FsoFrameworkLogger;
typedef struct _FsoFrameworkLoggerIface FsoFrameworkLoggerIface;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _closedir0(var) ((var == NULL) ? NULL : (var = (closedir (var), NULL)))

typedef gchar* (*ReprDelegate) (void* user_data);
struct _FsoFrameworkLoggerIface {
	GTypeInterface parent_iface;
	void (*setLevel) (FsoFrameworkLogger* self, GLogLevelFlags level);
	void (*setDestination) (FsoFrameworkLogger* self, const gchar* destination);
	void (*setReprDelegate) (FsoFrameworkLogger* self, ReprDelegate repr, void* repr_target);
	GLogLevelFlags (*getLevel) (FsoFrameworkLogger* self);
	gchar* (*getDestination) (FsoFrameworkLogger* self);
	gboolean (*debug) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*info) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*warning) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*error) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*critical) (FsoFrameworkLogger* self, const gchar* message);
	gboolean (*data) (FsoFrameworkLogger* self, guint8* message, int message_length1, gboolean in, GLogLevelFlags when);
};


extern FsoFrameworkLogger* fso_framework_theLogger;

#define READ_BUF_SIZE ((guint) (1024 * 1024))
gboolean fso_framework_file_handling_createDirectory (const gchar* filename, mode_t mode);
gboolean fso_framework_file_handling_removeTree (const gchar* path);
GType fso_framework_logger_get_type (void) G_GNUC_CONST;
gboolean fso_framework_logger_debug (FsoFrameworkLogger* self, const gchar* message);
gboolean fso_framework_logger_error (FsoFrameworkLogger* self, const gchar* message);
gboolean fso_framework_file_handling_isPresent (const gchar* filename);
gchar* fso_framework_file_handling_readIfPresent (const gchar* filename);
gchar* fso_framework_file_handling_read (const gchar* filename);
gchar** fso_framework_file_handling_listDirectory (const gchar* dirname, int* result_length1);
static void _vala_array_add11 (gchar*** array, int* length, int* size, gchar* value);
gboolean fso_framework_logger_warning (FsoFrameworkLogger* self, const gchar* message);
void fso_framework_file_handling_write (const gchar* contents, const gchar* filename, gboolean create);
guint8* fso_framework_file_handling_readContentsOfFile (const gchar* filename, int* result_length1, GError** error);
void fso_framework_file_handling_writeContentsToFile (guint8* buffer, int buffer_length1, const gchar* filename, GError** error);
void fso_framework_file_handling_writeBuffer (void* buffer, gulong length, const gchar* filename, gboolean create);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


gboolean fso_framework_file_handling_createDirectory (const gchar* filename, mode_t mode) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	mode_t _tmp1_;
	gint _tmp2_ = 0;
	g_return_val_if_fail (filename != NULL, FALSE);
	_tmp0_ = filename;
	_tmp1_ = mode;
	_tmp2_ = mkdir (_tmp0_, _tmp1_);
	result = _tmp2_ != (-1);
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


gboolean fso_framework_file_handling_removeTree (const gchar* path) {
	gboolean result = FALSE;
	FsoFrameworkLogger* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gboolean _tmp5_ = FALSE;
	const gchar* _tmp6_;
	DIR* _tmp7_ = NULL;
	DIR* dir;
	DIR* _tmp8_;
	const gchar* _tmp60_;
	gint _tmp61_ = 0;
	g_return_val_if_fail (path != NULL, FALSE);
	_tmp0_ = fso_framework_theLogger;
	_tmp1_ = path;
	_tmp2_ = string_to_string (_tmp1_);
	_tmp3_ = g_strconcat ("removeTree: ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = fso_framework_logger_debug (_tmp0_, _tmp4_);
	g_assert (_tmp5_);
	_g_free0 (_tmp4_);
	_tmp6_ = path;
	_tmp7_ = opendir (_tmp6_);
	dir = _tmp7_;
	_tmp8_ = dir;
	if (_tmp8_ == NULL) {
		FsoFrameworkLogger* _tmp9_;
		const gchar* _tmp10_;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		gboolean _tmp14_ = FALSE;
		_tmp9_ = fso_framework_theLogger;
		_tmp10_ = path;
		_tmp11_ = string_to_string (_tmp10_);
		_tmp12_ = g_strconcat ("can't open dir: ", _tmp11_, NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = fso_framework_logger_debug (_tmp9_, _tmp13_);
		g_assert (_tmp14_);
		_g_free0 (_tmp13_);
		result = FALSE;
		_closedir0 (dir);
		return result;
	}
	{
		DIR* _tmp15_;
		struct dirent* _tmp16_ = NULL;
		struct dirent* entry;
		_tmp15_ = dir;
		_tmp16_ = readdir (_tmp15_);
		entry = _tmp16_;
		{
			gboolean _tmp17_;
			_tmp17_ = TRUE;
			while (TRUE) {
				gboolean _tmp18_;
				struct dirent* _tmp21_;
				const gchar* _tmp22_;
				struct dirent* _tmp23_;
				gchar* _tmp24_ = NULL;
				gchar* current_path;
				gboolean _tmp25_ = FALSE;
				struct dirent* _tmp26_;
				gboolean _tmp28_;
				FsoFrameworkLogger* _tmp34_;
				const gchar* _tmp35_;
				const gchar* _tmp36_ = NULL;
				gchar* _tmp37_ = NULL;
				gchar* _tmp38_;
				gboolean _tmp39_ = FALSE;
				const gchar* _tmp40_;
				gboolean _tmp41_ = FALSE;
				_tmp18_ = _tmp17_;
				if (!_tmp18_) {
					DIR* _tmp19_;
					struct dirent* _tmp20_ = NULL;
					_tmp19_ = dir;
					_tmp20_ = readdir (_tmp19_);
					entry = _tmp20_;
				}
				_tmp17_ = FALSE;
				_tmp21_ = entry;
				if (!(_tmp21_ != NULL)) {
					break;
				}
				_tmp22_ = path;
				_tmp23_ = entry;
				_tmp24_ = g_strdup_printf ("%s/%s", _tmp22_, (const gchar*) _tmp23_->d_name);
				current_path = _tmp24_;
				_tmp26_ = entry;
				if (g_strcmp0 (".", (const gchar*) _tmp26_->d_name) == 0) {
					_tmp25_ = TRUE;
				} else {
					struct dirent* _tmp27_;
					_tmp27_ = entry;
					_tmp25_ = g_strcmp0 ("..", (const gchar*) _tmp27_->d_name) == 0;
				}
				_tmp28_ = _tmp25_;
				if (_tmp28_) {
					FsoFrameworkLogger* _tmp29_;
					const gchar* _tmp30_;
					const gchar* _tmp31_ = NULL;
					gchar* _tmp32_ = NULL;
					gchar* _tmp33_;
					_tmp29_ = fso_framework_theLogger;
					_tmp30_ = current_path;
					_tmp31_ = string_to_string (_tmp30_);
					_tmp32_ = g_strconcat ("skipping ", _tmp31_, NULL);
					_tmp33_ = _tmp32_;
					fso_framework_logger_debug (_tmp29_, _tmp33_);
					_g_free0 (_tmp33_);
					_g_free0 (current_path);
					continue;
				}
				_tmp34_ = fso_framework_theLogger;
				_tmp35_ = current_path;
				_tmp36_ = string_to_string (_tmp35_);
				_tmp37_ = g_strconcat ("processing ", _tmp36_, NULL);
				_tmp38_ = _tmp37_;
				_tmp39_ = fso_framework_logger_debug (_tmp34_, _tmp38_);
				g_assert (_tmp39_);
				_g_free0 (_tmp38_);
				_tmp40_ = current_path;
				_tmp41_ = g_file_test (_tmp40_, G_FILE_TEST_IS_REGULAR | G_FILE_TEST_IS_SYMLINK);
				if (_tmp41_) {
					const gchar* _tmp42_;
					gint _tmp43_ = 0;
					gint _result_;
					gint _tmp44_;
					_tmp42_ = current_path;
					_tmp43_ = g_remove (_tmp42_);
					_result_ = _tmp43_;
					_tmp44_ = _result_;
					if (_tmp44_ == 0) {
						FsoFrameworkLogger* _tmp45_;
						const gchar* _tmp46_;
						const gchar* _tmp47_ = NULL;
						gchar* _tmp48_ = NULL;
						gchar* _tmp49_;
						gboolean _tmp50_ = FALSE;
						_tmp45_ = fso_framework_theLogger;
						_tmp46_ = current_path;
						_tmp47_ = string_to_string (_tmp46_);
						_tmp48_ = g_strconcat (_tmp47_, " removed", NULL);
						_tmp49_ = _tmp48_;
						_tmp50_ = fso_framework_logger_debug (_tmp45_, _tmp49_);
						g_assert (_tmp50_);
						_g_free0 (_tmp49_);
						_g_free0 (current_path);
						continue;
					} else {
						FsoFrameworkLogger* _tmp51_;
						const gchar* _tmp52_;
						const gchar* _tmp53_ = NULL;
						gchar* _tmp54_ = NULL;
						gchar* _tmp55_;
						_tmp51_ = fso_framework_theLogger;
						_tmp52_ = current_path;
						_tmp53_ = string_to_string (_tmp52_);
						_tmp54_ = g_strconcat ("Failed to remove ", _tmp53_, NULL);
						_tmp55_ = _tmp54_;
						fso_framework_logger_error (_tmp51_, _tmp55_);
						_g_free0 (_tmp55_);
						result = FALSE;
						_g_free0 (current_path);
						_closedir0 (dir);
						return result;
					}
				} else {
					const gchar* _tmp56_;
					gboolean _tmp57_ = FALSE;
					_tmp56_ = current_path;
					_tmp57_ = g_file_test (_tmp56_, G_FILE_TEST_IS_DIR);
					if (_tmp57_) {
						const gchar* _tmp58_;
						gboolean _tmp59_ = FALSE;
						_tmp58_ = current_path;
						_tmp59_ = fso_framework_file_handling_removeTree (_tmp58_);
						if (!_tmp59_) {
							result = FALSE;
							_g_free0 (current_path);
							_closedir0 (dir);
							return result;
						}
						_g_free0 (current_path);
						continue;
					}
				}
				result = FALSE;
				_g_free0 (current_path);
				_closedir0 (dir);
				return result;
			}
		}
	}
	_tmp60_ = path;
	_tmp61_ = g_remove (_tmp60_);
	result = _tmp61_ == 0;
	_closedir0 (dir);
	return result;
}


gboolean fso_framework_file_handling_isPresent (const gchar* filename) {
	gboolean result = FALSE;
	struct stat structstat = {0};
	const gchar* _tmp0_;
	struct stat _tmp1_ = {0};
	gint _tmp2_ = 0;
	g_return_val_if_fail (filename != NULL, FALSE);
	_tmp0_ = filename;
	_tmp2_ = stat (_tmp0_, &_tmp1_);
	structstat = _tmp1_;
	result = _tmp2_ != (-1);
	return result;
}


gchar* fso_framework_file_handling_readIfPresent (const gchar* filename) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (filename != NULL, NULL);
	_tmp1_ = filename;
	_tmp2_ = fso_framework_file_handling_isPresent (_tmp1_);
	if (_tmp2_) {
		const gchar* _tmp3_;
		gchar* _tmp4_ = NULL;
		_tmp3_ = filename;
		_tmp4_ = fso_framework_file_handling_read (_tmp3_);
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp4_;
	} else {
		gchar* _tmp5_;
		_tmp5_ = g_strdup ("");
		_g_free0 (_tmp0_);
		_tmp0_ = _tmp5_;
	}
	result = _tmp0_;
	return result;
}


static void _vala_array_add11 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


gchar** fso_framework_file_handling_listDirectory (const gchar* dirname, int* result_length1) {
	gchar** result = NULL;
	gchar** _tmp0_ = NULL;
	gchar** _result_;
	gint _result__length1;
	gint __result__size_;
	const gchar* _tmp1_;
	DIR* _tmp2_ = NULL;
	DIR* dir;
	DIR* _tmp3_;
	gchar** _tmp12_;
	gint _tmp12__length1;
	g_return_val_if_fail (dirname != NULL, NULL);
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	_result_ = _tmp0_;
	_result__length1 = 0;
	__result__size_ = _result__length1;
	_tmp1_ = dirname;
	_tmp2_ = opendir (_tmp1_);
	dir = _tmp2_;
	_tmp3_ = dir;
	if (_tmp3_ != NULL) {
		DIR* _tmp4_;
		struct dirent* _tmp5_ = NULL;
		struct dirent* dirent;
		_tmp4_ = dir;
		_tmp5_ = readdir (_tmp4_);
		dirent = _tmp5_;
		while (TRUE) {
			struct dirent* _tmp6_;
			gchar** _tmp7_;
			gint _tmp7__length1;
			struct dirent* _tmp8_;
			gchar* _tmp9_;
			DIR* _tmp10_;
			struct dirent* _tmp11_ = NULL;
			_tmp6_ = dirent;
			if (!(_tmp6_ != NULL)) {
				break;
			}
			_tmp7_ = _result_;
			_tmp7__length1 = _result__length1;
			_tmp8_ = dirent;
			_tmp9_ = g_strdup ((const gchar*) _tmp8_->d_name);
			_vala_array_add11 (&_result_, &_result__length1, &__result__size_, _tmp9_);
			_tmp10_ = dir;
			_tmp11_ = readdir (_tmp10_);
			dirent = _tmp11_;
		}
	}
	_tmp12_ = _result_;
	_tmp12__length1 = _result__length1;
	if (result_length1) {
		*result_length1 = _tmp12__length1;
	}
	result = _tmp12_;
	_closedir0 (dir);
	return result;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


gchar* fso_framework_file_handling_read (const gchar* filename) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* buf;
	gint buf_length1;
	gint _buf_size_;
	const gchar* _tmp1_;
	gint _tmp2_ = 0;
	gint fd;
	gint _tmp3_;
	gchar* _tmp28_;
	g_return_val_if_fail (filename != NULL, NULL);
	_tmp0_ = g_new0 (gchar, READ_BUF_SIZE);
	buf = _tmp0_;
	buf_length1 = READ_BUF_SIZE;
	_buf_size_ = buf_length1;
	_tmp1_ = filename;
	_tmp2_ = open (_tmp1_, O_RDONLY, (mode_t) 0);
	fd = _tmp2_;
	_tmp3_ = fd;
	if (_tmp3_ == (-1)) {
		FsoFrameworkLogger* _tmp4_;
		const gchar* _tmp5_;
		const gchar* _tmp6_ = NULL;
		gint _tmp7_;
		const gchar* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_;
		_tmp4_ = fso_framework_theLogger;
		_tmp5_ = filename;
		_tmp6_ = string_to_string (_tmp5_);
		_tmp7_ = errno;
		_tmp8_ = strerror (_tmp7_);
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = g_strconcat ("Can't read-open ", _tmp6_, ": ", _tmp9_, NULL);
		_tmp11_ = _tmp10_;
		fso_framework_logger_warning (_tmp4_, _tmp11_);
		_g_free0 (_tmp11_);
	} else {
		gint _tmp12_;
		gchar* _tmp13_;
		gint _tmp13__length1;
		gssize _tmp14_ = 0L;
		gssize count;
		gssize _tmp15_;
		_tmp12_ = fd;
		_tmp13_ = buf;
		_tmp13__length1 = buf_length1;
		_tmp14_ = read (_tmp12_, _tmp13_, (gsize) READ_BUF_SIZE);
		count = _tmp14_;
		_tmp15_ = count;
		if (_tmp15_ < ((gssize) 1)) {
			FsoFrameworkLogger* _tmp16_;
			const gchar* _tmp17_;
			const gchar* _tmp18_ = NULL;
			gint _tmp19_;
			const gchar* _tmp20_ = NULL;
			const gchar* _tmp21_ = NULL;
			gchar* _tmp22_ = NULL;
			gchar* _tmp23_;
			gint _tmp24_;
			_tmp16_ = fso_framework_theLogger;
			_tmp17_ = filename;
			_tmp18_ = string_to_string (_tmp17_);
			_tmp19_ = errno;
			_tmp20_ = strerror (_tmp19_);
			_tmp21_ = string_to_string (_tmp20_);
			_tmp22_ = g_strconcat ("Couldn't read anything from ", _tmp18_, ": ", _tmp21_, NULL);
			_tmp23_ = _tmp22_;
			fso_framework_logger_warning (_tmp16_, _tmp23_);
			_g_free0 (_tmp23_);
			_tmp24_ = fd;
			close (_tmp24_);
		} else {
			gint _tmp25_;
			gchar* _tmp26_;
			gint _tmp26__length1;
			gchar* _tmp27_ = NULL;
			_tmp25_ = fd;
			close (_tmp25_);
			_tmp26_ = buf;
			_tmp26__length1 = buf_length1;
			_tmp27_ = string_strip ((const gchar*) _tmp26_);
			result = _tmp27_;
			buf = (g_free (buf), NULL);
			return result;
		}
	}
	_tmp28_ = g_strdup ("");
	result = _tmp28_;
	buf = (g_free (buf), NULL);
	return result;
}


void fso_framework_file_handling_write (const gchar* contents, const gchar* filename, gboolean create) {
	mode_t mode;
	gint flags;
	gboolean _tmp0_;
	const gchar* _tmp2_;
	gint _tmp3_;
	mode_t _tmp4_;
	gint _tmp5_ = 0;
	gint fd;
	gint _tmp6_;
	g_return_if_fail (contents != NULL);
	g_return_if_fail (filename != NULL);
	mode = (mode_t) 0;
	flags = O_WRONLY;
	_tmp0_ = create;
	if (_tmp0_) {
		gint _tmp1_;
		mode = ((S_IRUSR | S_IWUSR) | S_IRGRP) | S_IROTH;
		_tmp1_ = flags;
		flags = _tmp1_ | (O_CREAT | O_TRUNC);
	}
	_tmp2_ = filename;
	_tmp3_ = flags;
	_tmp4_ = mode;
	_tmp5_ = open (_tmp2_, _tmp3_, _tmp4_);
	fd = _tmp5_;
	_tmp6_ = fd;
	if (_tmp6_ == (-1)) {
		FsoFrameworkLogger* _tmp7_;
		const gchar* _tmp8_;
		const gchar* _tmp9_ = NULL;
		gint _tmp10_;
		const gchar* _tmp11_ = NULL;
		const gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		_tmp7_ = fso_framework_theLogger;
		_tmp8_ = filename;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = errno;
		_tmp11_ = strerror (_tmp10_);
		_tmp12_ = string_to_string (_tmp11_);
		_tmp13_ = g_strconcat ("Can't write-open ", _tmp9_, ": ", _tmp12_, NULL);
		_tmp14_ = _tmp13_;
		fso_framework_logger_warning (_tmp7_, _tmp14_);
		_g_free0 (_tmp14_);
	} else {
		const gchar* _tmp15_;
		gint _tmp16_;
		gint _tmp17_;
		gint length;
		gint _tmp18_;
		const gchar* _tmp19_;
		gint _tmp20_;
		gssize _tmp21_ = 0L;
		gssize written;
		gssize _tmp22_;
		gint _tmp23_;
		gint _tmp35_;
		_tmp15_ = contents;
		_tmp16_ = strlen (_tmp15_);
		_tmp17_ = _tmp16_;
		length = _tmp17_;
		_tmp18_ = fd;
		_tmp19_ = contents;
		_tmp20_ = length;
		_tmp21_ = write (_tmp18_, _tmp19_, (gsize) _tmp20_);
		written = _tmp21_;
		_tmp22_ = written;
		_tmp23_ = length;
		if (_tmp22_ != ((gssize) _tmp23_)) {
			FsoFrameworkLogger* _tmp24_;
			const gchar* _tmp25_;
			const gchar* _tmp26_ = NULL;
			gssize _tmp27_;
			gchar* _tmp28_ = NULL;
			gchar* _tmp29_;
			gint _tmp30_;
			gchar* _tmp31_ = NULL;
			gchar* _tmp32_;
			gchar* _tmp33_ = NULL;
			gchar* _tmp34_;
			_tmp24_ = fso_framework_theLogger;
			_tmp25_ = filename;
			_tmp26_ = string_to_string (_tmp25_);
			_tmp27_ = written;
			_tmp28_ = g_strdup_printf ("%" G_GSSIZE_FORMAT, _tmp27_);
			_tmp29_ = _tmp28_;
			_tmp30_ = length;
			_tmp31_ = g_strdup_printf ("%i", _tmp30_);
			_tmp32_ = _tmp31_;
			_tmp33_ = g_strconcat ("Couldn't write all bytes to ", _tmp26_, " (", _tmp29_, " of ", _tmp32_, ")", NULL);
			_tmp34_ = _tmp33_;
			fso_framework_logger_warning (_tmp24_, _tmp34_);
			_g_free0 (_tmp34_);
			_g_free0 (_tmp32_);
			_g_free0 (_tmp29_);
		}
		_tmp35_ = fd;
		close (_tmp35_);
	}
}


guint8* fso_framework_file_handling_readContentsOfFile (const gchar* filename, int* result_length1, GError** error) {
	guint8* result = NULL;
	struct stat structstat = {0};
	const gchar* _tmp0_;
	struct stat _tmp1_ = {0};
	gint _tmp2_ = 0;
	gint ok;
	gint _tmp3_;
	const gchar* _tmp7_;
	gint _tmp8_ = 0;
	gint fd;
	gint _tmp9_;
	struct stat _tmp13_;
	gsize _tmp14_;
	guint8* _tmp15_ = NULL;
	guint8* buf;
	gint buf_length1;
	gint _buf_size_;
	gint _tmp16_;
	struct stat _tmp17_;
	gsize _tmp18_;
	gssize _tmp19_ = 0L;
	gssize bread;
	struct stat _tmp20_;
	gsize _tmp21_;
	gint _tmp33_;
	guint8* _tmp34_;
	gint _tmp34__length1;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (filename != NULL, NULL);
	_tmp0_ = filename;
	_tmp2_ = stat (_tmp0_, &_tmp1_);
	structstat = _tmp1_;
	ok = _tmp2_;
	_tmp3_ = ok;
	if (_tmp3_ == (-1)) {
		gint _tmp4_;
		const gchar* _tmp5_ = NULL;
		GError* _tmp6_;
		_tmp4_ = errno;
		_tmp5_ = strerror (_tmp4_);
		_tmp6_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_FAILED, _tmp5_);
		_inner_error_ = _tmp6_;
		if (_inner_error_->domain == G_FILE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp7_ = filename;
	_tmp8_ = open (_tmp7_, O_RDONLY, (mode_t) 0);
	fd = _tmp8_;
	_tmp9_ = fd;
	if (_tmp9_ == (-1)) {
		gint _tmp10_;
		const gchar* _tmp11_ = NULL;
		GError* _tmp12_;
		_tmp10_ = errno;
		_tmp11_ = strerror (_tmp10_);
		_tmp12_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_FAILED, _tmp11_);
		_inner_error_ = _tmp12_;
		if (_inner_error_->domain == G_FILE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp13_ = structstat;
	_tmp14_ = _tmp13_.st_size;
	_tmp15_ = g_new0 (guint8, _tmp14_);
	buf = _tmp15_;
	buf_length1 = _tmp14_;
	_buf_size_ = buf_length1;
	_tmp16_ = fd;
	_tmp17_ = structstat;
	_tmp18_ = _tmp17_.st_size;
	_tmp19_ = read (_tmp16_, buf, _tmp18_);
	bread = _tmp19_;
	_tmp20_ = structstat;
	_tmp21_ = _tmp20_.st_size;
	if (((gsize) bread) != _tmp21_) {
		gint _tmp22_;
		gchar* _tmp23_ = NULL;
		gchar* _tmp24_;
		struct stat _tmp25_;
		gsize _tmp26_;
		gchar* _tmp27_ = NULL;
		gchar* _tmp28_;
		gchar* _tmp29_ = NULL;
		gchar* _tmp30_;
		GError* _tmp31_;
		GError* _tmp32_;
		_tmp22_ = fd;
		close (_tmp22_);
		_tmp23_ = g_strdup_printf ("%" G_GSSIZE_FORMAT, bread);
		_tmp24_ = _tmp23_;
		_tmp25_ = structstat;
		_tmp26_ = _tmp25_.st_size;
		_tmp27_ = g_strdup_printf ("%" G_GSIZE_FORMAT, _tmp26_);
		_tmp28_ = _tmp27_;
		_tmp29_ = g_strconcat ("Short read; got only ", _tmp24_, " of ", _tmp28_, NULL);
		_tmp30_ = _tmp29_;
		_tmp31_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_FAILED, _tmp30_);
		_tmp32_ = _tmp31_;
		_g_free0 (_tmp30_);
		_g_free0 (_tmp28_);
		_g_free0 (_tmp24_);
		_inner_error_ = _tmp32_;
		if (_inner_error_->domain == G_FILE_ERROR) {
			g_propagate_error (error, _inner_error_);
			buf = (g_free (buf), NULL);
			return NULL;
		} else {
			buf = (g_free (buf), NULL);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp33_ = fd;
	close (_tmp33_);
	_tmp34_ = buf;
	_tmp34__length1 = buf_length1;
	if (result_length1) {
		*result_length1 = _tmp34__length1;
	}
	result = _tmp34_;
	return result;
}


/**
     * Write buffer to file, supports partial writes.
     **/
void fso_framework_file_handling_writeContentsToFile (guint8* buffer, int buffer_length1, const gchar* filename, GError** error) {
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	gint fd;
	gint _tmp2_;
	gint written;
	guint8* _tmp6_;
	gint _tmp6__length1;
	guint8* pointer;
	gint _tmp26_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (filename != NULL);
	_tmp0_ = filename;
	_tmp1_ = open (_tmp0_, O_WRONLY, (mode_t) 0);
	fd = _tmp1_;
	_tmp2_ = fd;
	if (_tmp2_ == (-1)) {
		gint _tmp3_;
		const gchar* _tmp4_ = NULL;
		GError* _tmp5_;
		_tmp3_ = errno;
		_tmp4_ = strerror (_tmp3_);
		_tmp5_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_FAILED, _tmp4_);
		_inner_error_ = _tmp5_;
		if (_inner_error_->domain == G_FILE_ERROR) {
			g_propagate_error (error, _inner_error_);
			return;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	written = 0;
	_tmp6_ = buffer;
	_tmp6__length1 = buffer_length1;
	pointer = _tmp6_;
	while (TRUE) {
		gint _tmp7_;
		guint8* _tmp8_;
		gint _tmp8__length1;
		gint _tmp9_;
		guint8* _tmp10_;
		gint _tmp11_;
		guint8* _tmp12_;
		gint _tmp12__length1;
		gint _tmp13_;
		gssize _tmp14_ = 0L;
		gssize wrote;
		gssize _tmp15_;
		gint _tmp24_;
		gssize _tmp25_;
		_tmp7_ = written;
		_tmp8_ = buffer;
		_tmp8__length1 = buffer_length1;
		if (!(_tmp7_ < _tmp8__length1)) {
			break;
		}
		_tmp9_ = fd;
		_tmp10_ = pointer;
		_tmp11_ = written;
		_tmp12_ = buffer;
		_tmp12__length1 = buffer_length1;
		_tmp13_ = written;
		_tmp14_ = write (_tmp9_, _tmp10_ + _tmp11_, (gsize) (_tmp12__length1 - _tmp13_));
		wrote = _tmp14_;
		_tmp15_ = wrote;
		if (_tmp15_ <= ((gssize) 0)) {
			gint _tmp16_;
			gint _tmp17_;
			gchar* _tmp18_ = NULL;
			gchar* _tmp19_;
			gchar* _tmp20_ = NULL;
			gchar* _tmp21_;
			GError* _tmp22_;
			GError* _tmp23_;
			_tmp16_ = fd;
			close (_tmp16_);
			_tmp17_ = written;
			_tmp18_ = g_strdup_printf ("%i", _tmp17_);
			_tmp19_ = _tmp18_;
			_tmp20_ = g_strconcat ("Short write; aborting after writing ", _tmp19_, " of buffer.length", NULL);
			_tmp21_ = _tmp20_;
			_tmp22_ = g_error_new_literal (G_FILE_ERROR, G_FILE_ERROR_FAILED, _tmp21_);
			_tmp23_ = _tmp22_;
			_g_free0 (_tmp21_);
			_g_free0 (_tmp19_);
			_inner_error_ = _tmp23_;
			if (_inner_error_->domain == G_FILE_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_tmp24_ = written;
		_tmp25_ = wrote;
		written = _tmp24_ + ((gint) _tmp25_);
	}
	_tmp26_ = fd;
	close (_tmp26_);
}


void fso_framework_file_handling_writeBuffer (void* buffer, gulong length, const gchar* filename, gboolean create) {
	mode_t mode;
	gint flags;
	gboolean _tmp0_;
	const gchar* _tmp2_;
	gint _tmp3_;
	mode_t _tmp4_;
	gint _tmp5_ = 0;
	gint fd;
	gint _tmp6_;
	g_return_if_fail (filename != NULL);
	mode = (mode_t) 0;
	flags = O_WRONLY;
	_tmp0_ = create;
	if (_tmp0_) {
		gint _tmp1_;
		mode = ((S_IRUSR | S_IWUSR) | S_IRGRP) | S_IROTH;
		_tmp1_ = flags;
		flags = _tmp1_ | (O_CREAT | O_EXCL);
	}
	_tmp2_ = filename;
	_tmp3_ = flags;
	_tmp4_ = mode;
	_tmp5_ = open (_tmp2_, _tmp3_, _tmp4_);
	fd = _tmp5_;
	_tmp6_ = fd;
	if (_tmp6_ == (-1)) {
		FsoFrameworkLogger* _tmp7_;
		const gchar* _tmp8_;
		const gchar* _tmp9_ = NULL;
		gint _tmp10_;
		const gchar* _tmp11_ = NULL;
		const gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		_tmp7_ = fso_framework_theLogger;
		_tmp8_ = filename;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = errno;
		_tmp11_ = strerror (_tmp10_);
		_tmp12_ = string_to_string (_tmp11_);
		_tmp13_ = g_strconcat ("Can't write-open ", _tmp9_, ": ", _tmp12_, NULL);
		_tmp14_ = _tmp13_;
		fso_framework_logger_warning (_tmp7_, _tmp14_);
		_g_free0 (_tmp14_);
	} else {
		gint _tmp15_;
		void* _tmp16_;
		gulong _tmp17_;
		gssize _tmp18_ = 0L;
		gssize written;
		gssize _tmp19_;
		gulong _tmp20_;
		gint _tmp32_;
		_tmp15_ = fd;
		_tmp16_ = buffer;
		_tmp17_ = length;
		_tmp18_ = write (_tmp15_, _tmp16_, (gsize) _tmp17_);
		written = _tmp18_;
		_tmp19_ = written;
		_tmp20_ = length;
		if (((gulong) _tmp19_) != _tmp20_) {
			FsoFrameworkLogger* _tmp21_;
			const gchar* _tmp22_;
			const gchar* _tmp23_ = NULL;
			gssize _tmp24_;
			gchar* _tmp25_ = NULL;
			gchar* _tmp26_;
			gulong _tmp27_;
			gchar* _tmp28_ = NULL;
			gchar* _tmp29_;
			gchar* _tmp30_ = NULL;
			gchar* _tmp31_;
			_tmp21_ = fso_framework_theLogger;
			_tmp22_ = filename;
			_tmp23_ = string_to_string (_tmp22_);
			_tmp24_ = written;
			_tmp25_ = g_strdup_printf ("%" G_GSSIZE_FORMAT, _tmp24_);
			_tmp26_ = _tmp25_;
			_tmp27_ = length;
			_tmp28_ = g_strdup_printf ("%lu", _tmp27_);
			_tmp29_ = _tmp28_;
			_tmp30_ = g_strconcat ("Couldn't write all bytes to ", _tmp23_, " (", _tmp26_, " of ", _tmp29_, ")", NULL);
			_tmp31_ = _tmp30_;
			fso_framework_logger_warning (_tmp21_, _tmp31_);
			_g_free0 (_tmp31_);
			_g_free0 (_tmp29_);
			_g_free0 (_tmp26_);
		}
		_tmp32_ = fd;
		close (_tmp32_);
	}
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



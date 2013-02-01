/* filesystem.c generated by valac 0.16.1, the Vala compiler
 * generated from filesystem.vala, do not modify */

/*
 * Copyright (C) 2011-2012 Simon Busch <morphis@gravedo.de>
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
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <linux/fs.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define _g_free0(var) (var = (g_free (var), NULL))



gboolean fso_framework_file_system_isPresent (const gchar* filename);
gboolean fso_framework_file_system_createDirectory (const gchar* filename, mode_t mode);
gboolean fso_framework_file_system_mountFilesystem (const gchar* source, const gchar* target, const gchar* type, unsigned long int flags);
gboolean fso_framework_file_system_mountFilesystemAt (mode_t mode, const gchar* source, const gchar* target, const gchar* type, unsigned long int flags);
void fso_framework_file_system_write (const gchar* contents, const gchar* filename, gboolean create);


gboolean fso_framework_file_system_isPresent (const gchar* filename) {
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


gboolean fso_framework_file_system_createDirectory (const gchar* filename, mode_t mode) {
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


gboolean fso_framework_file_system_mountFilesystem (const gchar* source, const gchar* target, const gchar* type, unsigned long int flags) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	unsigned long int _tmp3_;
	gint _tmp4_ = 0;
	g_return_val_if_fail (source != NULL, FALSE);
	g_return_val_if_fail (target != NULL, FALSE);
	g_return_val_if_fail (type != NULL, FALSE);
	_tmp0_ = source;
	_tmp1_ = target;
	_tmp2_ = type;
	_tmp3_ = flags;
	_tmp4_ = mount (_tmp0_, _tmp1_, _tmp2_, _tmp3_, "");
	result = _tmp4_ != (-1);
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


gboolean fso_framework_file_system_mountFilesystemAt (mode_t mode, const gchar* source, const gchar* target, const gchar* type, unsigned long int flags) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gboolean _tmp1_ = FALSE;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	const gchar* _tmp18_;
	unsigned long int _tmp19_;
	gboolean _tmp20_ = FALSE;
	g_return_val_if_fail (source != NULL, FALSE);
	g_return_val_if_fail (target != NULL, FALSE);
	g_return_val_if_fail (type != NULL, FALSE);
	_tmp0_ = target;
	_tmp1_ = fso_framework_file_system_isPresent (_tmp0_);
	if (!_tmp1_) {
		const gchar* _tmp2_;
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_;
		const gchar* _tmp6_;
		mode_t _tmp7_;
		gboolean _tmp8_ = FALSE;
		_tmp2_ = target;
		_tmp3_ = string_to_string (_tmp2_);
		_tmp4_ = g_strconcat (_tmp3_, " is not present, trying to create...", NULL);
		_tmp5_ = _tmp4_;
		g_debug ("filesystem.vala:42: %s", _tmp5_);
		_g_free0 (_tmp5_);
		_tmp6_ = target;
		_tmp7_ = mode;
		_tmp8_ = fso_framework_file_system_createDirectory (_tmp6_, _tmp7_);
		if (!_tmp8_) {
			const gchar* _tmp9_;
			const gchar* _tmp10_ = NULL;
			gint _tmp11_;
			const gchar* _tmp12_ = NULL;
			const gchar* _tmp13_ = NULL;
			gchar* _tmp14_ = NULL;
			gchar* _tmp15_;
			_tmp9_ = target;
			_tmp10_ = string_to_string (_tmp9_);
			_tmp11_ = errno;
			_tmp12_ = g_strerror (_tmp11_);
			_tmp13_ = string_to_string (_tmp12_);
			_tmp14_ = g_strconcat ("Can't create ", _tmp10_, ": ", _tmp13_, NULL);
			_tmp15_ = _tmp14_;
			g_warning ("filesystem.vala:45: %s", _tmp15_);
			_g_free0 (_tmp15_);
			result = FALSE;
			return result;
		}
	}
	_tmp16_ = source;
	_tmp17_ = target;
	_tmp18_ = type;
	_tmp19_ = flags;
	_tmp20_ = fso_framework_file_system_mountFilesystem (_tmp16_, _tmp17_, _tmp18_, _tmp19_);
	result = _tmp20_;
	return result;
}


/**
     * FIXME: This method is currently available in both libfsobasics and libfsosystem;
     * We need to fix this as fast as possible!
     */
void fso_framework_file_system_write (const gchar* contents, const gchar* filename, gboolean create) {
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
		const gchar* _tmp7_;
		const gchar* _tmp8_ = NULL;
		gint _tmp9_;
		const gchar* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_;
		_tmp7_ = filename;
		_tmp8_ = string_to_string (_tmp7_);
		_tmp9_ = errno;
		_tmp10_ = strerror (_tmp9_);
		_tmp11_ = string_to_string (_tmp10_);
		_tmp12_ = g_strconcat ("Can't write-open ", _tmp8_, ": ", _tmp11_, NULL);
		_tmp13_ = _tmp12_;
		g_warning ("filesystem.vala:68: %s", _tmp13_);
		_g_free0 (_tmp13_);
	} else {
		const gchar* _tmp14_;
		gint _tmp15_;
		gint _tmp16_;
		gint length;
		gint _tmp17_;
		const gchar* _tmp18_;
		gint _tmp19_;
		gssize _tmp20_ = 0L;
		gssize written;
		gssize _tmp21_;
		gint _tmp22_;
		gint _tmp33_;
		_tmp14_ = contents;
		_tmp15_ = strlen (_tmp14_);
		_tmp16_ = _tmp15_;
		length = _tmp16_;
		_tmp17_ = fd;
		_tmp18_ = contents;
		_tmp19_ = length;
		_tmp20_ = write (_tmp17_, _tmp18_, (gsize) _tmp19_);
		written = _tmp20_;
		_tmp21_ = written;
		_tmp22_ = length;
		if (_tmp21_ != ((gssize) _tmp22_)) {
			const gchar* _tmp23_;
			const gchar* _tmp24_ = NULL;
			gssize _tmp25_;
			gchar* _tmp26_ = NULL;
			gchar* _tmp27_;
			gint _tmp28_;
			gchar* _tmp29_ = NULL;
			gchar* _tmp30_;
			gchar* _tmp31_ = NULL;
			gchar* _tmp32_;
			_tmp23_ = filename;
			_tmp24_ = string_to_string (_tmp23_);
			_tmp25_ = written;
			_tmp26_ = g_strdup_printf ("%" G_GSSIZE_FORMAT, _tmp25_);
			_tmp27_ = _tmp26_;
			_tmp28_ = length;
			_tmp29_ = g_strdup_printf ("%i", _tmp28_);
			_tmp30_ = _tmp29_;
			_tmp31_ = g_strconcat ("Couldn't write all bytes to ", _tmp24_, " (", _tmp27_, " of ", _tmp30_, ")", NULL);
			_tmp32_ = _tmp31_;
			g_warning ("filesystem.vala:76: %s", _tmp32_);
			_g_free0 (_tmp32_);
			_g_free0 (_tmp30_);
			_g_free0 (_tmp27_);
		}
		_tmp33_ = fd;
		close (_tmp33_);
	}
}



/* testsmartkeyfile.c generated by valac 0.16.1, the Vala compiler
 * generated from testsmartkeyfile.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <fsobasics.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free__g_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_free0_ (var), NULL)))



#define TEST_FILE_NAME "testsmartkeyfile.ini"
void test_smartkeyfile_values (void);
void test_smartkeyfile_values_generics (void);
void test_smartkeyfile_sections (void);
static void _g_free0_ (gpointer var);
static void _g_list_free__g_free0_ (GList* self);
void test_smartkeyfile_keys (void);
void _vala_main (gchar** args, int args_length1);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


void test_smartkeyfile_values (void) {
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* smk;
	gboolean _tmp1_ = FALSE;
	gboolean ok;
	gchar* _tmp2_ = NULL;
	gchar* stringvar;
	gchar* _tmp3_ = NULL;
	gchar* stringvar2;
	gint _tmp4_ = 0;
	gint intvar;
	gint _tmp5_ = 0;
	gint intvar2;
	gboolean _tmp6_ = FALSE;
	gboolean boolvar;
	gboolean _tmp7_ = FALSE;
	gboolean boolvar2;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar** _tmp11_ = NULL;
	gchar** _tmp12_;
	gint _tmp12__length1;
	gint _tmp13_ = 0;
	gchar** _tmp14_ = NULL;
	gchar** _tmp15_;
	gint _tmp15__length1;
	gchar** stringlistvar;
	gint stringlistvar_length1;
	gint _stringlistvar_size_;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	const gchar* _tmp18_;
	const gchar* _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	gchar** _tmp23_ = NULL;
	gchar** _tmp24_;
	gint _tmp24__length1;
	gint _tmp25_ = 0;
	gchar** _tmp26_ = NULL;
	gchar** _tmp27_;
	gint _tmp27__length1;
	gchar** stringlistvar2;
	gint stringlistvar2_length1;
	gint _stringlistvar2_size_;
	const gchar* _tmp28_;
	const gchar* _tmp29_;
	const gchar* _tmp30_;
	gint _tmp31_ = 0;
	gchar** _tmp32_ = NULL;
	gchar** stringlistvar3;
	gint stringlistvar3_length1;
	gint _stringlistvar3_size_;
	_tmp0_ = fso_framework_smart_key_file_new ();
	smk = _tmp0_;
	_tmp1_ = fso_framework_smart_key_file_loadFromFile (smk, TEST_FILE_NAME);
	ok = _tmp1_;
	g_assert (ok);
	_tmp2_ = fso_framework_smart_key_file_stringValue (smk, "section1", "keypresent", "defaultvalue");
	stringvar = _tmp2_;
	g_assert (g_strcmp0 (stringvar, "present") == 0);
	_tmp3_ = fso_framework_smart_key_file_stringValue (smk, "section1", "notpresent", "defaultvalue");
	stringvar2 = _tmp3_;
	g_assert (g_strcmp0 (stringvar2, "defaultvalue") == 0);
	_tmp4_ = fso_framework_smart_key_file_intValue (smk, "section2", "keypresent", 123456789);
	intvar = _tmp4_;
	g_assert (intvar == 42);
	_tmp5_ = fso_framework_smart_key_file_intValue (smk, "section2", "notpresent", 123456789);
	intvar2 = _tmp5_;
	g_assert (intvar2 == 123456789);
	_tmp6_ = fso_framework_smart_key_file_boolValue (smk, "section3", "keypresent", FALSE);
	boolvar = _tmp6_;
	g_assert (boolvar);
	_tmp7_ = fso_framework_smart_key_file_boolValue (smk, "section3", "notpresent", TRUE);
	boolvar2 = _tmp7_;
	g_assert (boolvar2);
	_tmp8_ = g_strdup ("these");
	_tmp9_ = g_strdup ("values");
	_tmp10_ = g_strdup ("irrelevant");
	_tmp11_ = g_new0 (gchar*, 3 + 1);
	_tmp11_[0] = _tmp8_;
	_tmp11_[1] = _tmp9_;
	_tmp11_[2] = _tmp10_;
	_tmp12_ = _tmp11_;
	_tmp12__length1 = 3;
	_tmp14_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "keypresent", _tmp12_, 3, &_tmp13_);
	_tmp15_ = _tmp14_;
	_tmp15__length1 = _tmp13_;
	_tmp12_ = (_vala_array_free (_tmp12_, _tmp12__length1, (GDestroyNotify) g_free), NULL);
	stringlistvar = _tmp15_;
	stringlistvar_length1 = _tmp15__length1;
	_stringlistvar_size_ = stringlistvar_length1;
	g_assert (stringlistvar_length1 == 4);
	_tmp16_ = stringlistvar[0];
	g_assert (g_strcmp0 (_tmp16_, "foo") == 0);
	_tmp17_ = stringlistvar[1];
	g_assert (g_strcmp0 (_tmp17_, "bar") == 0);
	_tmp18_ = stringlistvar[2];
	g_assert (g_strcmp0 (_tmp18_, "yo") == 0);
	_tmp19_ = stringlistvar[3];
	g_assert (g_strcmp0 (_tmp19_, "kurt") == 0);
	_tmp20_ = g_strdup ("these");
	_tmp21_ = g_strdup ("values");
	_tmp22_ = g_strdup ("default");
	_tmp23_ = g_new0 (gchar*, 3 + 1);
	_tmp23_[0] = _tmp20_;
	_tmp23_[1] = _tmp21_;
	_tmp23_[2] = _tmp22_;
	_tmp24_ = _tmp23_;
	_tmp24__length1 = 3;
	_tmp26_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "notpresent", _tmp24_, 3, &_tmp25_);
	_tmp27_ = _tmp26_;
	_tmp27__length1 = _tmp25_;
	_tmp24_ = (_vala_array_free (_tmp24_, _tmp24__length1, (GDestroyNotify) g_free), NULL);
	stringlistvar2 = _tmp27_;
	stringlistvar2_length1 = _tmp27__length1;
	_stringlistvar2_size_ = stringlistvar2_length1;
	g_assert (stringlistvar2_length1 == 3);
	_tmp28_ = stringlistvar2[0];
	g_assert (g_strcmp0 (_tmp28_, "these") == 0);
	_tmp29_ = stringlistvar2[1];
	g_assert (g_strcmp0 (_tmp29_, "values") == 0);
	_tmp30_ = stringlistvar2[2];
	g_assert (g_strcmp0 (_tmp30_, "default") == 0);
	_tmp32_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "stillNotPresent", NULL, 0, &_tmp31_);
	stringlistvar3 = _tmp32_;
	stringlistvar3_length1 = _tmp31_;
	_stringlistvar3_size_ = stringlistvar3_length1;
	g_assert (stringlistvar3 == NULL);
	stringlistvar3 = (_vala_array_free (stringlistvar3, stringlistvar3_length1, (GDestroyNotify) g_free), NULL);
	stringlistvar2 = (_vala_array_free (stringlistvar2, stringlistvar2_length1, (GDestroyNotify) g_free), NULL);
	stringlistvar = (_vala_array_free (stringlistvar, stringlistvar_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (stringvar2);
	_g_free0 (stringvar);
	_g_object_unref0 (smk);
}


void test_smartkeyfile_values_generics (void) {
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* smk;
	gboolean _tmp1_ = FALSE;
	gboolean ok;
	gchar* _tmp2_ = NULL;
	gchar* stringvar2;
	gint _tmp3_ = 0;
	gint intvar;
	gint _tmp4_ = 0;
	gint intvar2;
	gboolean _tmp5_ = FALSE;
	gboolean boolvar;
	gboolean _tmp6_ = FALSE;
	gboolean boolvar2;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar** _tmp10_ = NULL;
	gchar** _tmp11_;
	gint _tmp11__length1;
	gint _tmp12_ = 0;
	gchar** _tmp13_ = NULL;
	gchar** _tmp14_;
	gint _tmp14__length1;
	gchar** stringlistvar;
	gint stringlistvar_length1;
	gint _stringlistvar_size_;
	const gchar* _tmp15_;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	const gchar* _tmp18_;
	gchar* _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar** _tmp22_ = NULL;
	gchar** _tmp23_;
	gint _tmp23__length1;
	gint _tmp24_ = 0;
	gchar** _tmp25_ = NULL;
	gchar** _tmp26_;
	gint _tmp26__length1;
	gchar** stringlistvar2;
	gint stringlistvar2_length1;
	gint _stringlistvar2_size_;
	const gchar* _tmp27_;
	const gchar* _tmp28_;
	const gchar* _tmp29_;
	gint _tmp30_ = 0;
	gchar** _tmp31_ = NULL;
	gchar** stringlistvar3;
	gint stringlistvar3_length1;
	gint _stringlistvar3_size_;
	_tmp0_ = fso_framework_smart_key_file_new ();
	smk = _tmp0_;
	_tmp1_ = fso_framework_smart_key_file_loadFromFile (smk, TEST_FILE_NAME);
	ok = _tmp1_;
	g_assert (ok);
	_tmp2_ = fso_framework_smart_key_file_stringValue (smk, "section1", "notpresent", "defaultvalue");
	stringvar2 = _tmp2_;
	g_assert (g_strcmp0 (stringvar2, "defaultvalue") == 0);
	_tmp3_ = fso_framework_smart_key_file_intValue (smk, "section2", "keypresent", 123456789);
	intvar = _tmp3_;
	g_assert (intvar == 42);
	_tmp4_ = fso_framework_smart_key_file_intValue (smk, "section2", "notpresent", 123456789);
	intvar2 = _tmp4_;
	g_assert (intvar2 == 123456789);
	_tmp5_ = fso_framework_smart_key_file_boolValue (smk, "section3", "keypresent", FALSE);
	boolvar = _tmp5_;
	g_assert (boolvar);
	_tmp6_ = fso_framework_smart_key_file_boolValue (smk, "section3", "notpresent", TRUE);
	boolvar2 = _tmp6_;
	g_assert (boolvar2);
	_tmp7_ = g_strdup ("these");
	_tmp8_ = g_strdup ("values");
	_tmp9_ = g_strdup ("irrelevant");
	_tmp10_ = g_new0 (gchar*, 3 + 1);
	_tmp10_[0] = _tmp7_;
	_tmp10_[1] = _tmp8_;
	_tmp10_[2] = _tmp9_;
	_tmp11_ = _tmp10_;
	_tmp11__length1 = 3;
	_tmp13_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "keypresent", _tmp11_, 3, &_tmp12_);
	_tmp14_ = _tmp13_;
	_tmp14__length1 = _tmp12_;
	_tmp11_ = (_vala_array_free (_tmp11_, _tmp11__length1, (GDestroyNotify) g_free), NULL);
	stringlistvar = _tmp14_;
	stringlistvar_length1 = _tmp14__length1;
	_stringlistvar_size_ = stringlistvar_length1;
	g_assert (stringlistvar_length1 == 4);
	_tmp15_ = stringlistvar[0];
	g_assert (g_strcmp0 (_tmp15_, "foo") == 0);
	_tmp16_ = stringlistvar[1];
	g_assert (g_strcmp0 (_tmp16_, "bar") == 0);
	_tmp17_ = stringlistvar[2];
	g_assert (g_strcmp0 (_tmp17_, "yo") == 0);
	_tmp18_ = stringlistvar[3];
	g_assert (g_strcmp0 (_tmp18_, "kurt") == 0);
	_tmp19_ = g_strdup ("these");
	_tmp20_ = g_strdup ("values");
	_tmp21_ = g_strdup ("default");
	_tmp22_ = g_new0 (gchar*, 3 + 1);
	_tmp22_[0] = _tmp19_;
	_tmp22_[1] = _tmp20_;
	_tmp22_[2] = _tmp21_;
	_tmp23_ = _tmp22_;
	_tmp23__length1 = 3;
	_tmp25_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "notpresent", _tmp23_, 3, &_tmp24_);
	_tmp26_ = _tmp25_;
	_tmp26__length1 = _tmp24_;
	_tmp23_ = (_vala_array_free (_tmp23_, _tmp23__length1, (GDestroyNotify) g_free), NULL);
	stringlistvar2 = _tmp26_;
	stringlistvar2_length1 = _tmp26__length1;
	_stringlistvar2_size_ = stringlistvar2_length1;
	g_assert (stringlistvar2_length1 == 3);
	_tmp27_ = stringlistvar2[0];
	g_assert (g_strcmp0 (_tmp27_, "these") == 0);
	_tmp28_ = stringlistvar2[1];
	g_assert (g_strcmp0 (_tmp28_, "values") == 0);
	_tmp29_ = stringlistvar2[2];
	g_assert (g_strcmp0 (_tmp29_, "default") == 0);
	_tmp31_ = fso_framework_smart_key_file_stringListValue (smk, "section4", "stillNotPresent", NULL, 0, &_tmp30_);
	stringlistvar3 = _tmp31_;
	stringlistvar3_length1 = _tmp30_;
	_stringlistvar3_size_ = stringlistvar3_length1;
	g_assert (stringlistvar3 == NULL);
	stringlistvar3 = (_vala_array_free (stringlistvar3, stringlistvar3_length1, (GDestroyNotify) g_free), NULL);
	stringlistvar2 = (_vala_array_free (stringlistvar2, stringlistvar2_length1, (GDestroyNotify) g_free), NULL);
	stringlistvar = (_vala_array_free (stringlistvar, stringlistvar_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (stringvar2);
	_g_object_unref0 (smk);
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_list_free__g_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_free0_, NULL);
	g_list_free (self);
}


void test_smartkeyfile_sections (void) {
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* smk;
	FsoFrameworkSmartKeyFile* _tmp1_;
	gboolean _tmp2_ = FALSE;
	gboolean ok;
	gboolean _tmp3_;
	FsoFrameworkSmartKeyFile* _tmp4_;
	gboolean _tmp5_ = FALSE;
	FsoFrameworkSmartKeyFile* _tmp6_;
	gboolean _tmp7_ = FALSE;
	FsoFrameworkSmartKeyFile* _tmp8_;
	GList* _tmp9_ = NULL;
	GList* sections;
	GList* _tmp10_;
	guint _tmp11_ = 0U;
	GList* _tmp12_;
	gconstpointer _tmp13_ = NULL;
	GList* _tmp14_;
	gconstpointer _tmp15_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp16_;
	GList* _tmp17_ = NULL;
	GList* foosections;
	GList* _tmp18_;
	GList* _tmp22_;
	guint _tmp23_ = 0U;
	GList* _tmp24_;
	gconstpointer _tmp25_ = NULL;
	GList* _tmp26_;
	gconstpointer _tmp27_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp28_;
	GList* _tmp29_ = NULL;
	GList* nosections;
	guint _tmp30_ = 0U;
	_tmp0_ = fso_framework_smart_key_file_new ();
	smk = _tmp0_;
	_tmp1_ = smk;
	_tmp2_ = fso_framework_smart_key_file_loadFromFile (_tmp1_, TEST_FILE_NAME);
	ok = _tmp2_;
	_tmp3_ = ok;
	g_assert (_tmp3_);
	_tmp4_ = smk;
	_tmp5_ = fso_framework_smart_key_file_hasSection (_tmp4_, "section0");
	g_assert (_tmp5_);
	_tmp6_ = smk;
	_tmp7_ = fso_framework_smart_key_file_hasSection (_tmp6_, "this.section.not.there");
	g_assert (!_tmp7_);
	_tmp8_ = smk;
	_tmp9_ = fso_framework_smart_key_file_sectionsWithPrefix (_tmp8_, NULL);
	sections = _tmp9_;
	_tmp10_ = sections;
	_tmp11_ = g_list_length (_tmp10_);
	g_assert (_tmp11_ == ((guint) 9));
	_tmp12_ = sections;
	_tmp13_ = g_list_nth_data (_tmp12_, (guint) 0);
	g_assert (g_strcmp0 ((const gchar*) _tmp13_, "section0") == 0);
	_tmp14_ = sections;
	_tmp15_ = g_list_nth_data (_tmp14_, (guint) 8);
	g_assert (g_strcmp0 ((const gchar*) _tmp15_, "foo.bar") == 0);
	_tmp16_ = smk;
	_tmp17_ = fso_framework_smart_key_file_sectionsWithPrefix (_tmp16_, "foo");
	foosections = _tmp17_;
	_tmp18_ = foosections;
	{
		GList* section_collection = NULL;
		GList* section_it = NULL;
		section_collection = _tmp18_;
		for (section_it = section_collection; section_it != NULL; section_it = section_it->next) {
			gchar* _tmp19_;
			gchar* section = NULL;
			_tmp19_ = g_strdup ((const gchar*) section_it->data);
			section = _tmp19_;
			{
				const gchar* _tmp20_;
				gboolean _tmp21_ = FALSE;
				_tmp20_ = section;
				_tmp21_ = g_str_has_prefix (_tmp20_, "foo");
				g_assert (_tmp21_);
				_g_free0 (section);
			}
		}
	}
	_tmp22_ = foosections;
	_tmp23_ = g_list_length (_tmp22_);
	g_assert (_tmp23_ == ((guint) 4));
	_tmp24_ = foosections;
	_tmp25_ = g_list_nth_data (_tmp24_, (guint) 0);
	g_assert (g_strcmp0 ((const gchar*) _tmp25_, "foo.1") == 0);
	_tmp26_ = foosections;
	_tmp27_ = g_list_nth_data (_tmp26_, (guint) 3);
	g_assert (g_strcmp0 ((const gchar*) _tmp27_, "foo.bar") == 0);
	_tmp28_ = smk;
	_tmp29_ = fso_framework_smart_key_file_sectionsWithPrefix (_tmp28_, "this.section.not.present");
	nosections = _tmp29_;
	_tmp30_ = g_list_length (nosections);
	g_assert (_tmp30_ == ((guint) 0));
	__g_list_free__g_free0_0 (nosections);
	__g_list_free__g_free0_0 (foosections);
	__g_list_free__g_free0_0 (sections);
	_g_object_unref0 (smk);
}


void test_smartkeyfile_keys (void) {
	FsoFrameworkSmartKeyFile* _tmp0_;
	FsoFrameworkSmartKeyFile* smk;
	FsoFrameworkSmartKeyFile* _tmp1_;
	gboolean _tmp2_ = FALSE;
	gboolean ok;
	gboolean _tmp3_;
	FsoFrameworkSmartKeyFile* _tmp4_;
	gboolean _tmp5_ = FALSE;
	FsoFrameworkSmartKeyFile* _tmp6_;
	gboolean _tmp7_ = FALSE;
	FsoFrameworkSmartKeyFile* _tmp8_;
	gboolean _tmp9_ = FALSE;
	FsoFrameworkSmartKeyFile* _tmp10_;
	GList* _tmp11_ = NULL;
	GList* keys;
	GList* _tmp12_;
	guint _tmp13_ = 0U;
	GList* _tmp14_;
	gconstpointer _tmp15_ = NULL;
	GList* _tmp16_;
	gconstpointer _tmp17_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp18_;
	GList* _tmp19_ = NULL;
	GList* yokeys;
	GList* _tmp20_;
	GList* _tmp24_;
	guint _tmp25_ = 0U;
	GList* _tmp26_;
	gconstpointer _tmp27_ = NULL;
	GList* _tmp28_;
	gconstpointer _tmp29_ = NULL;
	FsoFrameworkSmartKeyFile* _tmp30_;
	GList* _tmp31_ = NULL;
	GList* nokeys;
	guint _tmp32_ = 0U;
	_tmp0_ = fso_framework_smart_key_file_new ();
	smk = _tmp0_;
	_tmp1_ = smk;
	_tmp2_ = fso_framework_smart_key_file_loadFromFile (_tmp1_, TEST_FILE_NAME);
	ok = _tmp2_;
	_tmp3_ = ok;
	g_assert (_tmp3_);
	_tmp4_ = smk;
	_tmp5_ = fso_framework_smart_key_file_hasKey (_tmp4_, "section1", "keypresent");
	g_assert (_tmp5_);
	_tmp6_ = smk;
	_tmp7_ = fso_framework_smart_key_file_hasKey (_tmp6_, "section.not.present", "this.key.not.there");
	g_assert (!_tmp7_);
	_tmp8_ = smk;
	_tmp9_ = fso_framework_smart_key_file_hasKey (_tmp8_, "section1", "this.key.not.there");
	g_assert (!_tmp9_);
	_tmp10_ = smk;
	_tmp11_ = fso_framework_smart_key_file_keysWithPrefix (_tmp10_, "section4", NULL);
	keys = _tmp11_;
	_tmp12_ = keys;
	_tmp13_ = g_list_length (_tmp12_);
	g_assert (_tmp13_ == ((guint) 5));
	_tmp14_ = keys;
	_tmp15_ = g_list_nth_data (_tmp14_, (guint) 0);
	g_assert (g_strcmp0 ((const gchar*) _tmp15_, "keypresent") == 0);
	_tmp16_ = keys;
	_tmp17_ = g_list_nth_data (_tmp16_, (guint) 4);
	g_assert (g_strcmp0 ((const gchar*) _tmp17_, "yo4") == 0);
	_tmp18_ = smk;
	_tmp19_ = fso_framework_smart_key_file_keysWithPrefix (_tmp18_, "section4", "yo");
	yokeys = _tmp19_;
	_tmp20_ = yokeys;
	{
		GList* key_collection = NULL;
		GList* key_it = NULL;
		key_collection = _tmp20_;
		for (key_it = key_collection; key_it != NULL; key_it = key_it->next) {
			gchar* _tmp21_;
			gchar* key = NULL;
			_tmp21_ = g_strdup ((const gchar*) key_it->data);
			key = _tmp21_;
			{
				const gchar* _tmp22_;
				gboolean _tmp23_ = FALSE;
				_tmp22_ = key;
				_tmp23_ = g_str_has_prefix (_tmp22_, "yo");
				g_assert (_tmp23_);
				_g_free0 (key);
			}
		}
	}
	_tmp24_ = yokeys;
	_tmp25_ = g_list_length (_tmp24_);
	g_assert (_tmp25_ == ((guint) 4));
	_tmp26_ = yokeys;
	_tmp27_ = g_list_nth_data (_tmp26_, (guint) 0);
	g_assert (g_strcmp0 ((const gchar*) _tmp27_, "yo1") == 0);
	_tmp28_ = yokeys;
	_tmp29_ = g_list_nth_data (_tmp28_, (guint) 3);
	g_assert (g_strcmp0 ((const gchar*) _tmp29_, "yo4") == 0);
	_tmp30_ = smk;
	_tmp31_ = fso_framework_smart_key_file_keysWithPrefix (_tmp30_, "this.key.not.present", NULL);
	nokeys = _tmp31_;
	_tmp32_ = g_list_length (nokeys);
	g_assert (_tmp32_ == ((guint) 0));
	__g_list_free__g_free0_0 (nokeys);
	__g_list_free__g_free0_0 (yokeys);
	__g_list_free__g_free0_0 (keys);
	_g_object_unref0 (smk);
}


void _vala_main (gchar** args, int args_length1) {
	g_test_init (&args_length1, &args, NULL);
	g_test_run ();
}


int main (int argc, char ** argv) {
	g_thread_init (NULL);
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
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



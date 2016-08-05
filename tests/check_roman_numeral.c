#include "config.h"
#include <check.h>
#include <stdlib.h>
#include "../src/roman_numeral.h"

static char *teststring[] = {
	"IVXLCDM", "ivxlcdm", "abcdefghi", "MCMLXVII", "MCMXLIIII", "MCMXLIII",
	"CLXXXXIX", "CDXXXIX", "MCCCCMLVII", "MCCCLVIII", "MCMVVIII",
	"MCMLVII", "LLLVD", "MCMLXIII", "MCDDDDD", "MCDLVIII"
};

START_TEST(check_null_ptr)
{
	char *ptr, *ptrtest = NULL;

	ptr = getstring(ptrtest);
	ck_assert_ptr_eq(ptr, ptrtest);
}
END_TEST

START_TEST(check_nonnull_ptr)
{
	char *ptr;

	ptr = getstring(*(&teststring[0]));
	ck_assert_ptr_ne(ptr, &teststring[0]);
}
END_TEST

START_TEST(check_roman_numeral_character)
{
	int strlength, len = 0;

	strlength = all_roman_numeral_character(*(&teststring[0]));
	ck_assert_int_gt(strlength, len);
}
END_TEST

START_TEST(check_I_substring_in_roman_numeral)
{
	char *rtstr, *tstring = "IIII";
	
	rtstr = (char *)is_substring_in_roman_numeral(*(&teststring[5]), tstring);
	ck_assert_ptr_eq(rtstr, NULL);
}
END_TEST

START_TEST(check_X_substring_in_roman_numeral)
{
	char *rtstr, *tstring = "XXXX";
	
	rtstr = (char *)is_substring_in_roman_numeral(*(&teststring[7]), tstring);
	ck_assert_ptr_eq(rtstr, NULL);
}
END_TEST

START_TEST(check_C_substring_in_roman_numeral)
{
	char *rtstr, *tstring = "CCCC";
	
	rtstr = (char *)is_substring_in_roman_numeral(*(&teststring[9]), tstring);
	ck_assert_ptr_eq(rtstr, NULL);
}
END_TEST

START_TEST(check_V_character_frequency)
{
	int ncount;
	char tstchar = 'V';

	ncount = roman_numeral_character_frequency(*(&teststring[11]), tstchar);
	ck_assert_int_le(ncount, 1);
}
END_TEST

START_TEST(check_L_character_frequency)
{
	int ncount;
	char tstchar = 'L';

	ncount = roman_numeral_character_frequency(*(&teststring[13]), tstchar);
	ck_assert_int_le(ncount, 1);
}
END_TEST
		
START_TEST(check_D_character_frequency)
{
	int ncount;
	char tstchar = 'D';

	ncount = roman_numeral_character_frequency(*(&teststring[15]), tstchar);
	ck_assert_int_le(ncount, 1);
}
END_TEST
		
		
Suite *roman_numeral_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Roman_Numeral");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, check_null_ptr);
	tcase_add_test(tc_core, check_nonnull_ptr);
	tcase_add_test(tc_core, check_roman_numeral_character);
	tcase_add_test(tc_core, check_I_substring_in_roman_numeral);
	tcase_add_test(tc_core, check_X_substring_in_roman_numeral);
	tcase_add_test(tc_core, check_C_substring_in_roman_numeral);
	tcase_add_test(tc_core, check_V_character_frequency);
	tcase_add_test(tc_core, check_L_character_frequency);
	tcase_add_test(tc_core, check_D_character_frequency);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = roman_numeral_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

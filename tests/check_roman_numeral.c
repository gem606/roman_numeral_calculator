#include "config.h"
#include <check.h>
#include <stdlib.h>
#include "../src/roman_numeral.h"

static const char *teststring[] = {
	"IVXLCDM", "ivxlcdm", "abcdefghi", "MCMLXVII"
};

START_TEST(check_null_ptr)
{
	char *ptr, *ptrtest = NULL;
	int len;

	ptr = getstring(ptrtest);
	ck_assert_ptr_eq(ptr, ptrtest);
}
END_TEST

START_TEST(check_nonnull_ptr)
{
	char *ptr;
	int len;

	ptr = getstring(&teststring[0]);
	ck_assert_ptr_ne(ptr, teststring[0]);
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

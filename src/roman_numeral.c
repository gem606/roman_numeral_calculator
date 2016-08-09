#include "roman_numeral.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

char *getstring(char *ptr_roman_numeral)
{
	/* Get Input character string
	 * 
	 * The intent of getstring() is to retrieve user information
	 * - i.e., roman numeral strings. It is not clear how one might
	 * effectively incorporate user interactions into the testing
	 * model.
	 *
	 * I've chosen to incorporate data strings into my test suite for
	 * this function rather than have the tests timeout.
	 *
	 * The following code segment might appear in this function:
	 *	
	 *	 printf("/nPlease Enter a Roman Number string - ");
	 *
	 *	 fgets(ptr_roman_numeral, MAX_STRING_LENGTH, stdin);
         *	 return ptr_roman_numeral;
	 *	 ...
	 */

	return ptr_roman_numeral;
}

int all_roman_numeral_character(char *ptr)
{
	int slen, i, j;
	bool roman;

	assert(ptr != NULL);
	if ((slen = strlen(ptr)) == 0)
		return 0;
	
	/* Verify each character is roman numeral */
	for (i = 0; i < slen; i++, ptr + i) {
		roman = FALSE;
		for (j = 0; j < MAX_NUMBER_ROMAN_CHARACTERS; j++) {
			if (*(ptr) != roman_char[j]) {
				roman = false;
				continue;
			} else {
				roman = TRUE;
				break;
			}
		}
		if (!roman)
			return 0;	/* None roman numeral string */
	}
	return slen;
}

char *is_substring_in_roman_numeral(char *ptr, char *tstr)
{
	char *str;

	assert(ptr != NULL);
	assert(tstr != NULL);

	/* Search for this string in the roman numeral */
	str = strstr(ptr, tstr);

	return str;
}

int roman_numeral_character_frequency(char *strptr, char tchar)
{
	int slen, nchar = 0, i;
	char *ptr;

	assert(strptr != NULL);

	/* Get string length */
	if ((slen = strlen(strptr)) == 0)
		return 0;

	ptr = strptr;

	/* Seaarch for character in string */
	for (i = 0; i < slen; i++) {
		if (*ptr == tchar)
			++nchar;
		ptr += 1;
	}

	return nchar;
}

int roman_numeral_token_indexer(char *pstr, int *rlen)
{
	char *sparse;
	int len, i, ntoken;

	assert(pstr != NULL);
	assert(rlen != NULL);
	
	/* Get string length */
	if ((len = strlen(pstr)) > 3) {
		*rlen = len;
		printf("Roman Numeral token does not exist.\nToken sought = %s\n", pstr);
		return -1;
	}

	/* Determine Number of Roman Numeral Tokens */
	ntoken = sizeof(roman_numeral_token) / sizeof(*roman_numeral_token);

	if ((sparse = (char *)calloc(3 + 1, sizeof(char))) == NULL) {
		printf("roman_numeral_token_indexer: No Memory\n");
		return -ENOMEM;
	}
	while (len > 0) {
		strncpy(sparse, pstr, len);

		/* Search for this token */
		for (i = 0; i < ntoken; i++) {
			if (strcmp(sparse,
			     ((&(roman_numeral_token[i]))->roman_char_string)) == 0) {
				*rlen = len;		
				free(sparse);
				return i;	/* Index into roman numeral table */
			}
		}
		memset(sparse, 0, len);
		len--;
	}	
	free(sparse);

	/* Token not found */
	printf("Roman Numeral token not found.\nToken sought = %s\n", pstr);
	return -1;	/* shouldn't happen */
}

int roman_numeral_parser(char *pstr, int *parsed_str, int parsed_length)
{
	char *sparse;
	int len, indx, res = 0, slide = 3;
	int ntoken = 0;

	assert(pstr != NULL);
	assert(parsed_str != NULL);

	/* Get string length */
	len = strlen(pstr);

	/* Search string for its tokens */
	if ((sparse = (char *)calloc(slide + 1, sizeof(char))) == NULL) {
		printf("roman_numeral_parser: Error No Memory\n");
		return -ENOMEM;
	}

	while (len != 0) {
		if (len >= slide)
			slide = 3;	/* String of 3 */
		else
			slide = len;	/* String < 3 */

		/* Search for this token */
		strncpy(sparse, pstr, slide);
		indx = roman_numeral_token_indexer(sparse, &res);
		if (indx >= 0) {

			if (ntoken > parsed_length) {
				printf("roman_numeral_parser: Failed - Array - too small\n");
				goto failure;				
			}

			/* Save token index */
			*parsed_str = indx;
			parsed_str += 1;
			ntoken++;

			/* Update sting pointer */
			pstr += res;
			len -= res;
			continue;
		} else {
			printf("roman_numeral_parser: Token not found\n");
			goto failure;
		}
	}
	free(sparse);
	return ntoken;

failure:
	free(sparse);
	return -1;
}

int compute_value_roman_numeral_string(int *parsed, int nelem)
{
	int sum = 0, i, j, ntoken;

	assert(parsed != NULL);

	/* Determine Number of Roman Numeral Tokens */
	ntoken = sizeof(roman_numeral_token) / sizeof(*roman_numeral_token);

	/* Compute the value of this string */
	for (i = 0; i < nelem; i++) {
		sum += (&roman_numeral_token[*parsed])->roman_char_stringvalue;
		parsed += 1;
	}
	return sum;
}

int roman_numeral_value_to_string_conversion(char *results, int value, int nelem)
{
	int i, j, ntoken, nl = 0, nloop;

	assert(results != NULL);

	/* Determine Number of Roman Numeral Tokens */
	ntoken = sizeof(roman_numeral_token) / sizeof(*roman_numeral_token);

	/* Build roman numeral string */
	if (value <= 0) {
		printf("roman_numeral_value_to_string_conversion: Improper value\n");
		return -1;
	}

	for (i = ntoken - 1; i >= 0; i--) {
		if (!value)
			return 0;

		nloop = value / (&roman_numeral_token[i])->roman_char_stringvalue;
		while (nloop && (nl <= nelem)) {
			strcat(results, (&roman_numeral_token[i])->roman_char_string);
			value -= (&roman_numeral_token[i])->roman_char_stringvalue;
			nloop -= 1;
			nl += strlen(results);
		}
	}		
	return 0;
}

long int numerical_adder(int value_1, int value_2)
{
	long int adder = 0;

	adder = value_1 + value_2;
	return adder;
}

long int numerical_subtractor(int value_1, int value_2)
{
	long int subtractor = -1;

	if (value_1 < value_2)
		return subtractor;

	subtractor = value_1 - value_2;
	return subtractor;
}

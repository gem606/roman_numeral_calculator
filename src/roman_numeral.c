#include "roman_numeral.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

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

	/* Search for this string in the roman numeral */
	str = strstr(ptr, tstr);

	return str;
}

int roman_numeral_character_frequency(char *strptr, char tchar)
{
	int slen, nchar = 0, i;
	char *ptr;

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

	
	/* Get string length */
	if ((len = strlen(pstr)) > 3) {
		*rlen = len;
		printf("Roman Numeral token does not exist.\nToken sought = %s\n", pstr);
		return -1;
	}

	/* Determine Number of Roman Numeral Tokens */
	ntoken = sizeof(roman_numeral_token) / sizeof(*roman_numeral_token);

	sparse = (char *)calloc(3 + 1, sizeof(char));
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
		len--;
	}	
	free(sparse);

	/* Token not found */
	printf("Roman Numeral token not found.\nToken sought = %s\n", pstr);
	return -1;	/* shouldn't happen */
}

int roman_numeral_parser(char *pstr, int *parsed_str, int mlength)
{
	char *sparse;
	int len, indx, res = 0, slide;
	int ntoken, *ptoken, tindex = 0;
	bool token;

	/* Get string length */
	len = strlen(pstr);
	ptoken = parsed_str;

	while (len != 0) {
		if (len >= slide)
			slide = 3;	/* String of 3 */
		else
			slide = len;	/* String < 3 */

		/* Search for this token */
		strncpy(sparse, pstr, slide);
		indx = roman_numeral_token_indexer(sparse, &res);
		if (indx >= 0) {
			/* Set token index */
			*parsed_str = indx;
			parsed_str += 1;

			/* Update sting pointer */
			pstr += res;
			len -= res;
			continue;
		}
		/* String parsing failure */
		return -1;
	}
	return 0;
}

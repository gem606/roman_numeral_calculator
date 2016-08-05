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

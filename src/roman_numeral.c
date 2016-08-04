#include "roman_numeral.h"
#include <stdlib.h>
#include <string.h>

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

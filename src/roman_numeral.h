#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

struct roman_numeral_table {
	char *roman_char_string;
	int roman_char_stringvalue;
};

static const struct roman_numeral_table roman_number_table[] = {
	{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10},
	{"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400},
	{"D", 500}, {"DM", 900}, {"M", 1000}
};

static const char roman_char[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

#define MAX_NUMBER_ROMAN_CHARACTERS 7
#define MAX_STRING_LENGTH 256
#define TRUE 1
#define FALSE 0

char *getstring(char *);
int is_roman_numeral_character(char *);

#endif /* ROMAN_NURERAL_H */

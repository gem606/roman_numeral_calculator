#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

struct roman_numeral_table {
	char *roman_char_string;
	int roman_char_stringvalue;
};

static const struct roman_numeral_table roman_numeral_token[] = {
	{"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, {"IX", 9},
	{"X", 10}, {"XX", 20}, {"XXX", 30},{"XL", 40}, {"L", 50}, {"XC", 90},
	{"C", 100}, {"CC", 200}, {"CCC", 300}, {"CD", 400},
	{"D", 500}, {"DM", 900}, {"M", 1000}
};

static const char roman_char[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

#define MAX_NUMBER_ROMAN_CHARACTERS 7
#define MAX_STRING_LENGTH 256
#define MAX_ARRAY_ELEMENT 50
#define TRUE 1
#define FALSE 0

char *getstring(char *);
int all_roman_numeral_character(char *);
char *is_substring_in_roman_numeral(char *, char *);
int roman_numeral_character_frequency(char *, char);
int roman_numeral_token_indexer(char *, int *);
int roman_numeral_parser(char *, int *, int);
int compute_value_roman_numeral_string(int *, int);
int roman_numeral_value_to_string_conversion(char *, int , int);

#endif /* ROMAN_NURERAL_H */

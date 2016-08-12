/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "roman_numeral.h"

int main(void)
{
	struct calculator_register *pregister, *pptr;
	int nreg = 0, request, strl, *reg, token;
	char *rn_string;

	/* Allocate storage */
	rn_string = (char *)calloc(MAX_STRING_LENGTH + 1, sizeof(char));
	assert(rn_string != NULL);

	pptr = (struct calculator_register *)calloc(MAX_NUMBER_REGISTERS,
			sizeof(struct calculator_register));
	assert(pptr != NULL);

	while (TRUE) {
		/* Display User Interface */
		request = roman_numeral_calculator_interface();

		switch(request) {
		case 1:
			if (nreg >= MAX_NUMBER_REGISTERS) {
				printf("Calculator Registers - FULL\n");
				continue;
			}

			/* Get Roman Numeral String */
			memset(rn_string, 0, MAX_STRING_LENGTH);
			getstring(rn_string);

			/* Validate String */
			if ((valid_roman_numeral_string(rn_string)) != SUCCESS) {
				printf("Invalid Roman Numeral- String = %s\n", rn_string);
				continue;
			}

			/* Parse Roman Numeral String */
			strl = strlen(rn_string);
			reg = (int *)calloc(strl, sizeof(int));

			assert(reg != NULL);

			if ((token = roman_numeral_parser(rn_string, reg, strl)) <= 0) {
				free(reg);
				continue;
			}

			pptr->register_token = token;

			/* Compute value or Roman Numeral String */
			pptr->register_value = compute_value_roman_numeral_string(reg, token);

			/* Update register indeces */
			pptr += 1;
			nreg++;
			free(reg);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			goto out;
		default:
			printf("\nUnsupported Operational Request\n\n");
			break;
		}
	}
out:
	pptr -= nreg;
	free(pptr);
	free(rn_string);

	return 0;
}

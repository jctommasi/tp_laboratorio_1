/*
 ============================================================================
 Name        : calculat0r.c
 Author      : juan cruz tommasi
 Version     : v1
 Copyright   : 
 Description : very basic calculator
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stuff.c"
#include "math.c"

int main(void)
{
	int num1;
	int num2;
	int operationNumber;
	int resultado;
	int factNum1;
	int factNum2;

	stuff_clearScreen();
	stuff_displayBanner();
	math_getIntNumbers(&num1,&num2);
	stuff_clearScreen();
	stuff_displayBanner();
	math_showOperations(&operationNumber,&num1,&num2);
	math_executeOperationChoosed(&operationNumber, num1, num2, &resultado, &factNum1, &factNum2);

	return EXIT_SUCCESS;
}

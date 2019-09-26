/*
 ============================================================================
 Name        : TRABAJO PRACTICO N-2
 Author      : Juan Cruz Tommasi
 Version     : 1.0 beta
 ============================================================================
 */

#include "global.h"

int main(void)
{

	int opNumber;
	int id_autoinc = 0;

	Employee arrayEmployee[QTY_TIPO];
	employee_clear_all(arrayEmployee,QTY_TIPO);

	do
	{
		stuff_displayBanner();
		stuff_showMenu();
		utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);
		switch (opNumber)
		{
			case 1:
				employee_signup(arrayEmployee, QTY_TIPO, &id_autoinc);
				break;
			case 2:
				employee_destroy(arrayEmployee, QTY_TIPO);
				break;
			case 3:
				employee_modify(arrayEmployee, QTY_TIPO);
				break;
			case 4:
				employee_paginate(arrayEmployee, QTY_TIPO);
				break;
			case 5:
				employee_sortByString(arrayEmployee,QTY_TIPO);
				break;
			case 6:
				break;
			default:
				printf(MSG_ERROR);
				break;
		}
	}	while (opNumber != 6);

	return EXIT_SUCCESS;
}

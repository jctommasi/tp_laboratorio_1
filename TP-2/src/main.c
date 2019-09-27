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

	//Employee arrayEmployee[QTY_TIPO];
	//employee_clear_all(arrayEmployee,QTY_TIPO);

	Employee arrayEmployee[QTY_TIPO]=
	{
		{ 0, 0, 44, 456.000, "Gabriel", "Peter"},
		{ 1, 0, 51, 36.000, "Bond", "James"},
		{ 2, 0, 44, 133.000, "Doe", "John"},
		{ 3, 0, 13, 405.000, "Patton", "Mike"},
		{ 4, 0, 420, 5.000, "Marley", "Bob"},
		{5, 0, 1, 4445.000, "Presley", "Elvis"},
	};

	do
	{
		stuff_displayMainBanner();
		stuff_showMenu();
		utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);
		switch (opNumber)
		{
			case 1:
				stuff_clearScreen();
				stuff_showSignUpBanner();
				employee_signup(arrayEmployee, QTY_TIPO, &id_autoinc);
				break;
			case 2:
				stuff_clearScreen();
				stuff_showDestroyBanner();
				employee_destroy(arrayEmployee, QTY_TIPO);
				break;
			case 3:
				stuff_clearScreen();
				stuff_showModifyBanner();
				employee_modify(arrayEmployee, QTY_TIPO);
				break;
			case 4:
				stuff_clearScreen();
				stuff_showPaginateBanner();
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

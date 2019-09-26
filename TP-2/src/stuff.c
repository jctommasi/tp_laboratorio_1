#include "stuff.h"

void stuff_clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void stuff_displayBanner()
{
	printf(	"\033[0;32m"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT"
			"\n\n\n"
			"\t\t_______  __   __  _______  ___      _______  __   __  _______  _______                   \n"
			"\t\t|       ||  |_|  ||       ||   |    |       ||  | |  ||       ||       |                  \n"
			"\t\t|    ___||       ||    _  ||   |    |   _   ||  |_|  ||    ___||    ___|                  \n"
			"\t\t|   |___ |       ||   |_| ||   |    |  | |  ||       ||   |___ |   |___                   \n"
			"\t\t|    ___||       ||    ___||   |___ |  |_|  ||_     _||    ___||    ___|                  \n"
			"\t\t|   |___ | ||_|| ||   |    |       ||       |  |   |  |   |___ |   |___                   \n"
			"\t\t|_______||_|   |_||___|    |_______||_______|  |___|  |_______||_______|                  \n"
			"\t\t__   __  _______  __    _  _______  _______  _______  __   __  _______  __    _  _______ \n"
			"\t\t|  |_|  ||   _   ||  |  | ||   _   ||       ||       ||  |_|  ||       ||  |  | ||       |\n"
			"\t\t|       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___||       ||    ___||   |_| ||_     _|\n"
			"\t\t|       ||       ||       ||       ||   | __ |   |___ |       ||   |___ |       |  |   |  \n"
			"\t\t|       ||       ||  _    ||       ||   ||  ||    ___||       ||    ___||  _    |  |   |  \n"
			"\t\t| ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ | ||_|| ||   |___ | | |   |  |   |  \n"
			"\t\t|_|   |_||__| |__||_|  |__||__| |__||_______||_______||_|   |_||_______||_|  |__|  |___|  \n\n\n"
			"\033[0m");

}

void stuff_showMenu()
{
	printf("\033[0;31m");
	printf("\t\tBienvenidx al sistema administrativo de empleados, que operacion desea realizar?\n"
			"\n\t\t\t\t\t\t1. Alta"
			"\n\t\t\t\t\t\t2. Baja"
			"\n\t\t\t\t\t\t3. Modificar"
			"\n\t\t\t\t\t\t4. Listar"
			"\n\t\t\t\t\t\t5. Ordenar"
			"\n\t\t\t\t\t\t6. Salir\n\n");
	printf("\033[0m");
}

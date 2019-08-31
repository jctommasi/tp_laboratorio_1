/*
 * stuff.c
 *
 *  Created on: Aug 31, 2019
 *      Author: root
 */

#include <unistd.h>

void stuff_clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void stuff_displayBanner()
{
	printf("\033[0;32m");
	printf("	                                                                                   \n");
	printf("	 ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗ \n");
	printf("	██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═████╗██╔══██╗\n");
	printf("	██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║██╔██║██████╔╝\n");
	printf("	██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ████╔╝██║██╔══██╗\n");
	printf("	╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║\n");
	printf("	 ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n");
	printf("	                                                                                   \n");
	printf("\033[0;31m");
	printf("TRABAJO PRACTICO N1 - UTN - PROGRAMACION I \n\n"
			"AUTHOR:		juan cruz tommasi \n"
			"DATE:		31 aug 2019\n"
			"DESC:		very basic calculat0r \n\n");
	printf("\033[0m");
}

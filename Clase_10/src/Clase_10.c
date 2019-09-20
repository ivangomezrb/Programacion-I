/*
 ============================================================================
 Name        : Clase_10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	int option;
	do{
		printf("1) Alta.\n");
		printf("2) Baja.\n");
		printf("3) Modificar.\n");
		printf("4) Listar.\n");
		printf("5) Salir.\n");
		getInt(&option,"Ingrese una opcion.\n","Error. Opcion inválida\n",1,5,3);
		switch (option)
		{
			case 1:
					break;
			case 2:
					break;
			case 3:
					break;
			case 4:
					break;
			case 5:
					break;
		}
	}while(option!=5);
}

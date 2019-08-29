/*
 ============================================================================
 Name        : Clase_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main(void)
{
	char continuar;
	int r; // Respuesta
	r = getChar (&continuar,"Ingrese Opcion [A][B][C]","Error",'A','C',2);
	if(r == 0)
	printf("Continuar: %c",continuar);
	return EXIT_SUCCESS;
}

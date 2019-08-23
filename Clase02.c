/*
 ============================================================================
 Name        : Clase02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 64537

int sumaEnteros(int, int, int*);


int main(void) {

	int primerValor;
	int segundoValor;
	int resultado=0;
	printf("Ingrese el primer valor: ");
	scanf("%d", &primerValor);
	printf("Ingrese el segundo valor: ");
	scanf("%d", &segundoValor);
	if(sumaEnteros(primerValor,segundoValor,&resultado)==0)
	{
		printf("El resultado es: %d", resultado);
	}
	else
	{
		printf("Error.");
	}

}


int sumaEnteros(int primerValorSumar, int segundoValorSumar, int *resultado )
{
	int retorno=-1;
	long resultadoLong;
	resultadoLong = primerValorSumar+segundoValorSumar;
	if (resultadoLong <= MAX_INT)
	{
		retorno = 0;
		*resultado = (int)resultadoLong; // (int) hace que trate a la variable como entero.

	}
	return retorno;
}

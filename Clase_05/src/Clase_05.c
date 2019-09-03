/*
 ============================================================================
 Name        : Clase_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define QTY_EMPLEADOS 1000

int initArrayInt(int*,int,int);
int imprimirArray(int*, int);

int main(void) {

	int edadesEmpleados[QTY_EMPLEADOS];

	if(initArrayInt(edadesEmpleados,QTY_EMPLEADOS,521) == 0)
	{
		imprimirArray(edadesEmpleados,QTY_EMPLEADOS);
	}
	return EXIT_SUCCESS;
}

int initArrayInt(int *array,int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor;
		}

	}
	return retorno;
}
int imprimirArray(int *array, int limite){
	int i;
	int retorno = -1;
	if (array != NULL && limite > 0)
	{
		retorno = 0;
		for (i=0;i<limite;i++)
		{
			printf("%d",array[i]);
		}
	}
	return retorno;
}

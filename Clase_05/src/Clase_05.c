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
#include <stdio_ext.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

int initArrayInt(int*,int,int);
int imprimirArrayInt(int*, int);
int getArrayInt(int*,int,char*,char*,int,int,int);
int maximoArrayInt(int*,int,int*);
int minimoArrayInt(int*,int,int*);
int promedioArrayInt(int*,int,float*);

int main(void) {
	int edadesEmpleados[QTY_EMPLEADOS];
	int cantidadDatos = getArrayInt(edadesEmpleados,QTY_EMPLEADOS,"Edad?\n","Error\n",0,200,2);
	if(cantidadDatos > 0){
		imprimirArrayInt(edadesEmpleados,cantidadDatos);
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
int imprimirArrayInt(int *array, int limite){
	int i;
	int retorno = -1;
	if (array != NULL && limite > 0)
	{
		retorno = 0;
		for (i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}
	}
	return retorno;
}
int getArrayInt(int *array,
				int limite,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos){
	int retorno = -1;
	int i=0;
	int buffer;
	char respuesta = 's';
	if(array != NULL && limite > 0)
	{
		do
		{
		if(getInt(&buffer,pMensaje,pMensajeError,minimo,maximo,reintentos)==0){
			array[i] = buffer;
			i++;
			limite--;
		}
		printf("Continuar? (s/n) \n");
		__fpurge(stdin);
		scanf("%s",&respuesta);
		}while(respuesta == 's' && limite < 0);

		retorno = i;
	}
	return retorno;
}


int maximoArrayInt(int *array, int limite, int *pResultado){
	int i;
	int retorno = -1;
	int bufferMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		bufferMaximo = array[0];
		for (i=0;i<limite;i++){
			if (array[i]>bufferMaximo){
				bufferMaximo = array[i];
			}
		}
	}
	*pResultado = bufferMaximo;
	return retorno;
}
int minimoArrayInt(int *array, int limite, int *pResultado){
	int i;
	int retorno = -1;
	int bufferMinimo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		bufferMinimo = array[0];
		for (i=0;i<limite;i++){
			if (array[i]<bufferMinimo){
				bufferMinimo = array[i];
			}
		}
	}
	*pResultado = bufferMinimo;
	return retorno;
}
int promedioArrayInt(int *array, int limite,float *pResultado){
	int i;
	int retorno = -1;
	float bufferPromedio;
	int bufferAcumulador = 0;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++){
			bufferAcumulador = bufferAcumulador + array[i];
		}
	}
	bufferPromedio = (float)bufferAcumulador/(float)limite;
	*pResultado = bufferPromedio;
	return retorno;
}





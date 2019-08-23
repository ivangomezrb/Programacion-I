/*
 ============================================================================
 Name        : Clase02_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int obtenerNumerosCalcularYDevolver (int, int*, int*, float*, int*);


int main(void) {
	// maximo minimo promedio cuantos numeros - hasta que quiera el usuario

	int numero;
	int maximo;
	int minimo;
	float promedio;
	int contadorNumeros = 0;
	printf("Ingrese un numero: ");
	scanf("%d",&numero);
	if (contadorNumeros==0)
	{
		maximo=numero;
		minimo=numero;
	}
	if(obtenerNumerosCalcularYDevolver(numero,&maximo,&minimo,&promedio,&contadorNumeros)==0)
	{
		printf("Máximo %d, Mínimo %d,Promedio %.2f Cantidad de Numeros %d.",maximo,minimo,promedio,contadorNumeros);
	}
	else
	{
		printf("Error.");
	}

	return EXIT_SUCCESS;

}

int obtenerNumerosCalcularYDevolver(int numero, int *maximo, int *minimo, float *promedio, int *contadorNumeros)
{
	int retorno = 0;
	char respuesta = 's';
	int maximoAux;
	int minimoAux;
	int contadorNumerosAux=1;
	int acumulador;
	acumulador = numero;
	maximoAux = *maximo;
	minimoAux = *minimo;

	printf("¿Desea ingresar otro numero?\n");
	scanf("%s", &respuesta);

	while(respuesta == 's')
	{
		printf("Ingrese un numero ");
		scanf("%d", &numero);
		contadorNumerosAux++;
		acumulador = acumulador + numero;
		if (numero > maximoAux)
		{
			maximoAux = numero;
		}
		if (numero < minimoAux)
		{
			minimoAux = numero;
		}
		printf("¿Desea ingresar otro numero?");
		scanf("%s", &respuesta);
	}
	*maximo = maximoAux;
	*minimo = minimoAux;
	*contadorNumeros=contadorNumerosAux;
	*promedio = (float)(acumulador) / (float)(contadorNumerosAux);


	return retorno;
}

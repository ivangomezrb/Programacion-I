/*
 ============================================================================
 Name        : Clase_03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_A_PEDIR 6
int pedirNumerosYCalcular(int*, int*, float*);

int main(void)
{	// yo decido la cantidad de numeros a pedir, maximo, minimo, promedio

	int maximo;
	int minimo;
	float promedio;

	if(pedirNumerosYCalcular(&maximo,&minimo,&promedio)==0)
	{
		printf("Maximo: %d, Minimo: %d, Promedio: %.2f",maximo,minimo,promedio);
	}else{
		printf("Error.");
	}

	return 0;
}


int pedirNumerosYCalcular(int *maximo, int *minimo, float *promedio )
{
	int retorno = 0;
	int	contador = 0;
	int numero;
	int acumulador=0;
	int auxiliarMaximo;
	int auxiliarMinimo;
	for(contador=0;contador < NUMEROS_A_PEDIR;contador++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		if (contador == 0)
		{
			auxiliarMaximo = numero;
			auxiliarMinimo = numero;
		} else if (numero > auxiliarMaximo){
			auxiliarMaximo = numero;
		} else if (numero < auxiliarMinimo){
			auxiliarMinimo = numero;
		}
		acumulador = acumulador + numero;
	}
	*maximo = auxiliarMaximo;
	*minimo = auxiliarMinimo;
	*promedio = (float) (acumulador) / (float) (contador);

	return retorno;
}

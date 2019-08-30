#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void)
{
	 // Maximo minimo promedio cuantos numeros - hasta que quiera el usuario.
	int numero;
	int maximo;
	int minimo;
	int promedio;
	int flag = 0;
	int acumulador = 0;
	int contador = 0;
	char respuesta = 's';
	while (respuesta == 's'){
		getInt(&numero,"Ingrese un numero.","Error, ingrese un numero entre -500 y 500.",-500,500,3);
		if (flag == 0){
			maximo = numero;
			minimo = numero;
			flag = 1;
		}
		calcularMaximoYMinimo(&numero,&maximo,&minimo);

	}



	return EXIT_SUCCESS;
}

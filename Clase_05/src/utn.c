#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin); // fflush
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


int getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin); // fflush
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


int getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin); // fflush
			if(scanf("%s",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int getString(	char *resultado,
				char *mensaje,
				char *mensajeError,
				int maximo,
				int minimo,
				int reintentos){
	int retorno = EXIT_ERROR;
	char buffer[100];
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin); // fflush
			if(scanf("%s",buffer)==1)
			{
				int longitudCadena = strlen(buffer);
				if(longitudCadena >= minimo && longitudCadena <= maximo)
				{
					strcpy(resultado,buffer);
					retorno = EXIT_SUCCESS;
					break;
				}
				}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
		}
		return retorno;
}

int calcularMaximoYMinimo (int *numero, int *maximo, int *minimo){
	int retorno = EXIT_ERROR;
	int bufferMaximo;
	int bufferMinimo;
	if(*numero > *maximo){
		bufferMaximo = *numero;
	}else if (*numero < *minimo){
		bufferMinimo = *numero;
	}
	*maximo = bufferMaximo;
	*minimo = bufferMinimo;

	return retorno;
}

int calcularPromedio (int *numero, int *acumulador, int *contador, int *promedio){
	int retorno = EXIT_ERROR;

	int bufferNumero = (int)(numero);
	int bufferAcumulador = (int)acumulador;
	bufferAcumulador = bufferNumero + bufferAcumulador;


	return retorno;
}


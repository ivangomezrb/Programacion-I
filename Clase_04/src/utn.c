#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

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

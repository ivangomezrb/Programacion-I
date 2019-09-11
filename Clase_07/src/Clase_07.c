#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 5
#define QTY_CARACTERES 50
int imprimeArrayInt(int array[],int limite);
int initArrayInt(int array[],int limite,int valor);
int getArrayInt(	int array[],
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos);
int maximoArrayInt(int array[],int limite,int *pResultado);
int minimoArrayInt(int array[],int limite,int *pResultado);
int promedioArrayInt(int array[],int limite,float *pResultado);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int ordenarArrayIntOld(int array[],int limite);
int ordenarArrayInt(int array[], int limite);
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int imprimirArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad);
int ordenarArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad);


int main(void)
{/*
	int edadesEmpleados[QTY_EMPLEADOS] =  {5,4,3,2,1};
	int cantidadDatos = 5 ;
	int test;
	//cantidadDatos = getArrayInt(edadesEmpleados,QTY_EMPLEADOS,"Edad?\n","Error\n",0,200,2);
	if(cantidadDatos > 0)
	{
		imprimeArrayInt(edadesEmpleados,cantidadDatos);
		ordenarArrayIntPrueba(edadesEmpleados,cantidadDatos);
		imprimeArrayInt(edadesEmpleados,cantidadDatos);
		maximoArrayInt(edadesEmpleados,cantidadDatos,&test);
	}*/
	/*
		if(initArrayInt(edadesEmpleados,QTY_EMPLEADOS,10) == 0)
		{
			imprimeArrayInt(edadesEmpleados,QTY_EMPLEADOS);
		}
	*/
	char aNombres[QTY_NOMBRES][QTY_CARACTERES];
	char nombre[50];
	char dni[QTY_NOMBRES][500];
	char bufferDni[500];
	int i;
	for(i=0;i<5;i++){
		getString(nombre,"Nombre?: ","Error\n",2,50,3);
		strcpy(aNombres[i],nombre);
		getString(bufferDni,"DNI?: ","Error\n",2,50,3);
		strcpy(dni[i],bufferDni);
	}
	ordenarArrayString(aNombres,dni,QTY_NOMBRES);
	imprimirArrayString(aNombres,dni,QTY_NOMBRES);
	return EXIT_SUCCESS;
}

int initArrayInt(int array[],int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}

int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}

int maximoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultado = posMaximo;
	}
	return retorno;
}

int ordenarArrayIntOld(int array[],int limite)
{
	int i;
	int retorno = -1;
	int posMaximo;
	int auxiliar;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			maximoArrayInt(array+i,limite-i,&posMaximo);
			auxiliar = array[i];
			array[i]=array[posMaximo+i];
			array[posMaximo+i] = auxiliar;
		}
	}
	return retorno;
}

int ordenarArrayInt(int array[], int limite){
	int i;
	int retorno = -1;
	int auxiliar = 0;;
	int swap;
	do{
		swap = 0;
		for(i = 0;i<limite-1;i++){
			if(array[i]>array[i+1]){
				swap = 1;
				auxiliar = array[i+1];
				array[i+1] = array[i];
				array[i] = auxiliar;
			}
		}
	}while(swap == 1);
	return retorno;
	}

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if 			(pResultado != NULL &&
				 pMensaje != NULL &&
				 pMensajeError != NULL &&
				 minimo<=maximo &&
				 reintentos >= 0)
{
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		fgets(buffer,sizeof(buffer),stdin);
		buffer[strlen(buffer)-1] = '\0';
		if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
		{
			strncpy(pResultado,buffer,maximo+1);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
}else {
	printf("%s",pMensajeError);
}
	return retorno;
}

int imprimirArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad){
	int retorno = -1;
	int i;
	if(nombres != NULL && cantidad>0){
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("%s %s\n",nombres[i],dni[i]);
		}
	}
	return retorno;
}
int ordenarArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad){
	int retorno = -1;
	int i;
	int swap;
	char buffer[500];
	char bufferDni[500];
		do{
			swap = 0;
			for(i = 0;i<cantidad-1;i++){
			if(strcmp(nombres[i],nombres[i+1]) == 0){
					swap = 1;
					if(strcmp(dni[i],dni[i+1])>1){
						strcpy(buffer,nombres[i+1]);
						strcpy(bufferDni,dni[i+1]);
						strcpy(nombres[i+1],nombres[i]);
						strcpy(dni[i+1],dni[i]);
						strcpy(nombres[i],buffer);
						strcpy(dni[i],bufferDni);
					}
					} else if(strcmp(nombres[i],nombres[i+1])>1){
					swap = 1;
					strcpy(buffer,nombres[i+1]);
					strcpy(bufferDni,dni[i+1]);
					strcpy(nombres[i+1],nombres[i]);
					strcpy(dni[i+1],dni[i]);
					strcpy(nombres[i],buffer);
					strcpy(dni[i],bufferDni);
				}
			}
		}while(swap == 1);
	return retorno;
}









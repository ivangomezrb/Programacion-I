#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 5
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sEmpleado
{
	//********* OBLIGATORIOS
	int	 idEmpleado;
	int  status;
	//********* DATOS
	char nombre[50];
	char apellido[50];
};


int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int imprimirArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad);
int ordenarArrayString(char nombres[][QTY_CARACTERES],char dni[][500],int cantidad);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleados,int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleados,int cantidad,int orden);


int main(void)
{

	struct sEmpleado aEmpleados[1000];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado = 0;

	for(i=0;i<3;i++){

		getString(bEmpleado.nombre,"Ingrese el nombre",
				"ERROR", 1, 49, 2);

		getString(bEmpleado.apellido,"Ingrese el apellido",
						"ERROR", 1, 49, 2);

		bEmpleado.idEmpleado = idEmpleado;
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY;

		aEmpleados[i] = bEmpleado;
	}
	ordenarArrayEmpleados(aEmpleados,3,1);
	imprimirArrayEmpleados(aEmpleados,3);

	return EXIT_SUCCESS;
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
	int fSwap;
	char buffer[500];
	char bufferDni[500];
		do{
			fSwap = 0;
			for(i = 0;i<cantidad-1;i++){
					if(strcmp(nombres[i],nombres[i+1])>0){
					fSwap = 1;
					strcpy(buffer,nombres[i+1]);
					strcpy(bufferDni,dni[i+1]);
					strcpy(nombres[i+1],nombres[i]);
					strcpy(dni[i+1],dni[i]);
					strcpy(nombres[i],buffer);
					strcpy(dni[i],bufferDni);
				}
			}
		}while(fSwap);
	return retorno;
}
int imprimirArrayEmpleados(struct sEmpleado *aEmpleados,int cantidad){
	int retorno = -1;
	int i;
	if(aEmpleados != NULL && cantidad>0){
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("Id: %d  -Nombre: %s  -Apellido %s \n",aEmpleados[i].idEmpleado,aEmpleados[i].nombre,aEmpleados[i].apellido);
		}
	}
	return retorno;
}
int ordenarArrayEmpleados(struct sEmpleado *aEmpleados,int cantidad,int orden){
	int retorno = -1;
	int i;
	int fSwap;
	struct sEmpleado bBuffer;
	if (orden == 0){
		do{
			fSwap = 0;
			for(i = 0;i<cantidad-1;i++){
				if(strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,50)==0){
					if(strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,50)>0){
						fSwap = 1;
						bBuffer= aEmpleados[i+1];
						aEmpleados[i+1] = aEmpleados[i];
						aEmpleados[i]= bBuffer;}
				}else if(strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,50)>0){
					fSwap = 1;
					bBuffer= aEmpleados[i+1];
					aEmpleados[i+1] = aEmpleados[i];
					aEmpleados[i]= bBuffer;
				}
			}
		}while(fSwap);
	} else if (orden == 1){
		do{
			fSwap = 0;
			for(i = 0;i<cantidad-1;i++){
				if(strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,50)==0){
					if(strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,50)<0){
						fSwap = 1;
						bBuffer= aEmpleados[i+1];
						aEmpleados[i+1] = aEmpleados[i];
						aEmpleados[i]= bBuffer;}
				}else if(strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,50)<0){
					fSwap = 1;
					bBuffer= aEmpleados[i+1];
					aEmpleados[i+1] = aEmpleados[i];
					aEmpleados[i]= bBuffer;
				}
			}
		}while(fSwap);
	}

	return retorno;
}

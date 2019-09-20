#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"

int ordenarArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	struct sEmpleado bEmpleado;
	int fSwap;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bEmpleado = aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleado;
				}
				else if(strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)==0)
				{
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						bEmpleado = aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=bEmpleado;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].nombre,aEmpleado[i].apellido);
		}
	}
	return retorno;
}
int initLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			aArray[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
int buscarLugarLibreEmpleado(struct sEmpleado *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int compararEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado)
{ // Cambiar nombre a existeIdDisponible o algo parecido
	int retorno = -1;
	int i;
	int idPosicion;
	if(aArray!=NULL && cantidad>0){
		idPosicion = buscarLugarLibreEmpleado(aArray,cantidad);
		for(i=0;i<cantidad;i++){
			if(aArray[idPosicion].idEmpleado==empleado.idEmpleado){
				retorno = 1;
			}
		}
	}
	return retorno;
}

int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado)
{
	// Falta comparar si el id ingresado ya existe.
	int retorno = -1;
	int posicion;
	if(aArray!=NULL && cantidad>0){
	posicion = buscarLugarLibreEmpleado(aArray,cantidad);
	// if(compararEmpleadoPorId(aArray,cantidad,empleado)==-1){
		if(posicion>=0){
			retorno = 0;
			aArray[posicion] = empleado;
			aArray[posicion].status = STATUS_NOT_EMPTY;
		//}
	}
	}
	return retorno;
}
int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,int id)
{
	//Falta preguntar "Esta seguro?"
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(buscarLugarLibreEmpleado(aArray,cantidad)<0){
				retorno = 0;
				aArray[i].status = STATUS_EMPTY;
			}
		}
	}
	return retorno;
}
int modificarEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado)
{
	int retorno = -1;
	if(aArray!=NULL && cantidad>0){


	}
	return retorno;
}


/*
 * pantalla.c
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "publicidad.h"
#include "utn.h"

static int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}
int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad)
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
int ordenarArrayPublicidad(struct sPublicidad *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sPublicidad bPantalla;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].cuit,aArray[i+1].cuit,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bPantalla = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=bPantalla;
				}
			}
		}while(fSwap);
	}
	return retorno;
}
int imprimirArrayPublicidad(struct sPublicidad *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("Publicidades:\n");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				printf("Id: %d - Cuit: %s - Dias de duracion: %d - Nombre del archivo: %s - Id Pantalla: %d\n",aArray[i].id,aArray[i].cuit,aArray[i].dias,aArray[i].nombreArchivo,aArray[i].idPantalla);
			}
		}
	}
	return retorno;
}
int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad)
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
int buscarPublicidadPorId(struct sPublicidad *aArray,int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].idPantalla==id && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i; // Devuelvo la posicion
				break;
			}
		}
	}
	return retorno;
}
int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad pantalla,int index)
{
	int retorno = -1;
	pantalla.id = generarId();
	if(aArray!=NULL && cantidad>0){
		if(index>=0){
				retorno = 0;
				aArray[index] = pantalla;
				aArray[index].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int verificarBajaPublicidad(void){
	int retorno = -1;
	char respuesta;
	getChar(&respuesta,"Esta seguro que desea dar la baja? s/n \n","Error\n",'a','z',0);
	if(respuesta=='s'){
		retorno = 0;
		}else if (respuesta=='n'){
			retorno = 1;
		} else {
			retorno = -1;
		}
	return retorno;
	}

int bajaPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id)
{
	int retorno = -1;
	int indice = buscarPublicidadPorId(aArray,cantidad,id);
	if(verificarBajaPublicidad()==0){
		if(aArray!=NULL && cantidad>0){
			if(indice>=0){
				retorno = 0;
				aArray[indice].status = STATUS_EMPTY;
			}
		}
	}
	return retorno;
}
int modificarPublicidadPorId(struct sPublicidad *aArray,int cantidad,struct sPublicidad publicidad)
{
	int retorno = -1;
	if(aArray!=NULL && cantidad > 0){

	int posicion =buscarPublicidadPorId(aArray,cantidad,publicidad.id);
		if (posicion >= 0){
			aArray[posicion] = publicidad;
			aArray[posicion].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int pedirDatosPublicidad(struct sPublicidad* pPublicidad)
{
	int retorno = -1;
	struct sPublicidad bPublicidad;
	getString(bPublicidad.cuit,"Ingrese cuit: \n","Error",0,50,2);
	getInt(&bPublicidad.dias,"Ingrese dias de duracion :\n","Error",1,500,2);
	getString(bPublicidad.nombreArchivo,"Ingrese nombre del archivo: \n","Error",0,50,2);
	getInt(&bPublicidad.idPantalla,"Ingrese id de la pantalla :\n","Error",1,500,2);
	*pPublicidad = bPublicidad;
	return retorno;
}
void altaForzadaPublicidad(struct sPublicidad* pPublicidad)
{
	struct sPublicidad bPublicidad;
	strncpy(bPublicidad.cuit,"123456",40);
	strncpy(bPublicidad.nombreArchivo,"Archivo",40);
	bPublicidad.dias = 5;
	bPublicidad.idPantalla = 1;
	*pPublicidad = bPublicidad;
}


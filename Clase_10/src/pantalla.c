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
#include "pantalla.h"
#include "utn.h"

static int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}


int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad)
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
int ordenarArrayPantalla(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sPantalla bPantalla;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].nombre,aArray[i+1].nombre,QTY_CARACTERES)>0)
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
int imprimirArrayPantalla(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Nombre: %s - Direccion: %s - Precio: %f \n ",aArray[i].idPantalla,aArray[i].nombre,aArray[i].direccion,aArray[i].precio);
		}
	}
	return retorno;
}
int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad)
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
int buscarPantallaPorId(struct sPantalla *aArray,int cantidad,int id){
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
int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla)
{

	int retorno = -1;
	int posicion;
	if(aArray!=NULL && cantidad>0){
	posicion = buscarLugarLibrePantalla(aArray,cantidad);
		if(posicion>=0){
				retorno = 0;
				aArray[posicion] = pantalla;
				aArray[posicion].idPantalla = generarId();
				aArray[posicion].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int verificarBajaPantalla(void){
	int retorno = -1;
	char respuesta;
	getChar(&respuesta,"Esta seguro que desea dar la baja? s/n \n","Error\n",'a','z',0);
	if(respuesta=='s'){
		retorno = 0;
		}else if (respuesta=='n'){
			retorno = 1;
		}
	return retorno;
	}

int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id)
{
	//Falta preguntar "Esta seguro?"
	int retorno = -1;
	int indice = buscarPantallaPorId(aArray,cantidad,id);
	if(verificarBajaPantalla()==0){
		if(aArray!=NULL && cantidad>0){
			if(indice>=0){
				retorno = 0;
				aArray[indice].status = STATUS_EMPTY;
			}
		}
	}
	return retorno;
}
int modificarPantallaPorId(struct sPantalla *aArray,int cantidad,struct sPantalla pantalla)
{
	int retorno = -1;
	if(aArray!=NULL && cantidad > 0){
	int posicion =buscarPantallaPorId(aArray,cantidad,pantalla.idPantalla);
		if (posicion >= 0){
			aArray[posicion] = pantalla;
		}
	}
	return retorno;
}
int pedirDatosPantalla(struct sPantalla* pPantalla)
{
	int retorno = -1;
	struct sPantalla bPantalla;
	getInt(&bPantalla.idPantalla,"Ingrese id: \n","Error\n",0,500,2);
	getString(bPantalla.nombre,"Ingrese nombre: \n","Error",0,50,2);
	getString(bPantalla.direccion,"Ingrese direccion: \n","Error",0,50,2);
	getFloat(&bPantalla.precio,"Ingrese precio","Error",0,100000000000,2);
	bPantalla.status = STATUS_NOT_EMPTY;
	*pPantalla = bPantalla;
	return retorno;
}

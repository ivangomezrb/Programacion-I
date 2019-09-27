/*
 * archivo.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"
#include "pantalla.h"
#include "publicidad.h"

int consultaFacturacion(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad,char *cuit)
{
	int retorno = -1;
	int i;
	int indexPantalla;
	float monto;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		retorno = 0;
		for(i=0;i<cantidadPublicidad;i++){
			if(aPublicidad[i].status == STATUS_NOT_EMPTY && strncmp(aPublicidad[i].cuit, cuit, 50) == 0 ){
				indexPantalla = buscarPantallaPorId(aPantallas, cantidadPantallas,aPublicidad[i].idPantalla);
				if(indexPantalla==-1){
					printf("referencia con pantalla rota\n");
				}else{
					monto = aPantallas[indexPantalla].precio * aPublicidad[i].dias;
					printf("id %d - nombre %s - monto %f\n", aPantallas[indexPantalla].idPantalla, aPantallas[indexPantalla].nombre,monto);
				}
			}
		}
	}
	return retorno;
}

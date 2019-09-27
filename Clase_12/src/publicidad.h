/*
 * pantalla.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define QTY_CARACTERES 50

// typedef permite renombrar un tipo de dato: ej
// typedef struct sPantalla Pantalla;
// reemplaza struct sPantalla por Pantalla
/* O haces directamente
 * typedef struct
 * {
	datos
 }Pantalla; -> Lo mismo que arriba pero en una sola linea
 * */

struct sPublicidad{
	int id;
	int status;

	char cuit[50];
	int dias;
	char nombreArchivo[50];
	int idPantalla;
};
int modificarPublicidadPorId(struct sPublicidad *aArray,int cantidad,struct sPublicidad publicidad);
int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);
int imprimirArrayPublicidad(struct sPublicidad *aArray, int cantidad);
int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);
int buscarPublicidadPorId(struct sPublicidad *aArray,int cantidad,int id);
int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad pantalla,int index);
int bajaPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id);
static int generarId(void);
void altaForzadaPublicidad(struct sPublicidad* pPublicidad);

#endif /* PANTALLA_H_ */

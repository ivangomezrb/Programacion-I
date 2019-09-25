/*
 * pantalla.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_
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

struct sPantalla{
	int idPantalla;
	int status;

	char nombre[50];
	char direccion[50];
	float precio;
};
int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int imprimirArrayPantalla(struct sPantalla *aArray, int cantidad);
int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int buscarPantallaPorId(struct sPantalla *aArray,int cantidad,int id);
int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla pantalla,int index);
int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id);
static int generarId(void);
void altaForzadaPantalla(struct sPantalla* pPantalla);
#endif /* PANTALLA_H_ */

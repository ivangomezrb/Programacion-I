#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#include "publicidad.h"
#include "archivo.h"
#define QTY_PANTALLAS 10
#define QTY_PUBLICIDADES 15

int main(void)
{
	int option;
	int bIdPantalla;
	int bIdPublicidad;
	char cuit[50];
	struct sPantalla aPantalla[QTY_PANTALLAS];
	struct sPantalla bPantalla;
	struct sPublicidad aPublicidad[QTY_PUBLICIDADES];
	struct sPublicidad bPublicidad;
	initLugarLibrePantalla(aPantalla,QTY_PANTALLAS);
	initLugarLibrePublicidad(aPublicidad,QTY_PUBLICIDADES);
	do{
		printf("1) Alta de pantallas.\n");
		printf("2) Baja de pantallas.\n");
		printf("3) Modificacion de pantallas.\n");
		printf("4) Alta de publicidades.\n");
		printf("5) Modificacion de publicidades\n");
		printf("6) Cancelar publicidades.\n");
		printf("7) Consultar facturacion.\n");
		printf("8) Listar publicidades.\n");
		printf("9) Listar pantallas.\n");
		printf("0) Salir.\n");
		getInt(&option,"Ingrese una opcion.\n","Error. Opcion inválida\n",0,10,3);
		switch (option)
		{
			case 1: if( buscarLugarLibrePantalla(aPantalla,QTY_PANTALLAS)>=0)
				{
					int index = buscarLugarLibrePantalla(aPantalla,QTY_PANTALLAS);
					// pedirDatosPantalla(&bPantalla);
					altaForzadaPantalla(&bPantalla);
					altaPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla,index);
				}else{
					printf("No hay mas lugar libre.");
				}
					break;
			case 2: imprimirArrayPantalla(aPantalla, QTY_PANTALLAS);
					getInt(&bIdPantalla,"Ingrese un ID para dar de baja:","Error",0,1000,2);
					if(bajaPantallaPorId(aPantalla,QTY_PANTALLAS,bIdPantalla) == -1)
					{
						printf("Opcion incorrecta.\n");
					}
					break;
			case 3:	imprimirArrayPantalla(aPantalla, QTY_PANTALLAS);
					getInt(&bIdPantalla,"Ingrese un ID para modificar:","Error",0,1000,2);
					pedirDatosPantalla(&bPantalla);
					bPantalla.idPantalla = bIdPantalla;
					modificarPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla);
					break;
			case 4:	imprimirArrayPantalla(aPantalla,QTY_PANTALLAS);
				if( buscarLugarLibrePantalla(aPublicidad,QTY_PUBLICIDADES)>=0)
					{
						int index = buscarLugarLibrePublicidad(aPublicidad,QTY_PANTALLAS);
						// pedirDatosPublicidad(&bPublicidad);
						getInt(&bIdPublicidad,"Ingrese ID Pantalla:","Error",0,1000,2);
						if(buscarPantallaPorId(aPantalla,QTY_PANTALLAS,bIdPublicidad)!= -1){
							altaForzadaPublicidad(&bPublicidad);
							bPublicidad.idPantalla=bIdPublicidad;
							altaPublicidadPorId(aPublicidad,QTY_PUBLICIDADES,bPublicidad,index);
						}else{
							printf("Id incorrecto.\n");
						}
					}else{
						printf("No hay mas lugar libre.");
					}
					break;
			case 5:	imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);
					getInt(&bIdPublicidad,"Ingrese un ID para modificar:","Error",0,1000,2);
					pedirDatosPublicidad(&bPublicidad);
					bPublicidad.id = bIdPublicidad;
					modificarPublicidadPorId(aPublicidad,QTY_PUBLICIDADES,bPublicidad);
					break;
			case 6:	imprimirArrayPantalla(aPantalla, QTY_PANTALLAS);
					getInt(&bIdPublicidad,"Ingrese un ID para dar de baja:","Error",0,1000,2);
					if(bajaPublicidadPorId(aPublicidad,QTY_PUBLICIDADES,bIdPublicidad) == -1)
					{
						printf("Opcion incorrecta");
					}
					break;
			case 7: getString(&cuit,"Ingrese Cuit","Error",0,99999999,2);
					consultaFacturacion(aPantalla,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDADES,&cuit);
					break;
			case 8:	imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);
					break;
			case 9:	imprimirArrayPantalla(aPantalla,QTY_PANTALLAS);
					break;
			case 0:
					break;
		}
	}while(option!=0);
	return EXIT_SUCCESS;
}

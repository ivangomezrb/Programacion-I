#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pantalla.h"
#define QTY_PANTALLAS 10

int main(void)
{
	int option;
	struct sPantalla aPantalla[QTY_PANTALLAS];
	struct sPantalla bPantalla;
	initLugarLibrePantalla(aPantalla,QTY_PANTALLAS);
	imprimirArrayPantalla(aPantalla,QTY_PANTALLAS);
	do{
		printf("1) Alta.\n");
		printf("2) Baja.\n");
		printf("3) Modificar.\n");
		printf("4) Listar.\n");
		printf("5) Salir.\n");
		getInt(&option,"Ingrese una opcion.\n","Error. Opcion inválida\n",1,5,3);
		switch (option)
		{
			case 1: if( buscarLugarLibrePantalla(aPantalla,QTY_PANTALLAS)>=0)
				{
					int index = buscarLugarLibrePantalla(aPantalla,QTY_PANTALLAS);
					// pedirDatosPantalla(&bPantalla);
					altaForzadaPantalla(&bPantalla);
					altaPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla,index);
					altaForzadaPantalla(&bPantalla);
					altaPantallaPorId(aPantalla,QTY_PANTALLAS,bPantalla,index);


				}
					break;
			case 2:
					break;
			case 3:
					break;
			case 4:		imprimirArrayPantalla(aPantalla,QTY_PANTALLAS);
					break;
			case 5:
					break;
		}
	}while(option!=5);
	return EXIT_SUCCESS;
}

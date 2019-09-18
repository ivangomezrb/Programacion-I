#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"

#define QTY_EMPLEADOS 10

int main(void)
{
	struct sEmpleado aEmpleados[1000];
	initLugarLibreEmpleado(aEmpleados,QTY_EMPLEADOS);

	struct sEmpleado unEmpleado = {5,STATUS_EMPTY,"Juan","Perez"};
	struct sEmpleado segundoEmpleado = {1,STATUS_EMPTY,"Juan","Suarez"};
	struct sEmpleado tercerEmpleado = {3,STATUS_EMPTY,"Juan","Gomez"};
	struct sEmpleado cuartoEmpleado = {3,STATUS_EMPTY,"Juan","Rodriguez"};
	altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,unEmpleado);
	altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,segundoEmpleado);
	altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,tercerEmpleado);
	altaEmpleadoPorId(aEmpleados,QTY_EMPLEADOS,cuartoEmpleado);
	imprimirArrayEmpleados(aEmpleados,QTY_EMPLEADOS);






/*
	int option;
	do{
		printf("1) Alta.\n");
		printf("2) Baja.\n");
		printf("3) Ordenar.\n");
		printf("4) Listar.\n");
		printf("5) Salir.\n");
		getInt(&option,"Ingrese una opcion.\n","Error. Opcion inválida\n",1,5,3);
		switch (option)
		{
			case 1:
					break;
			case 2:
					break;
			case 3:
					break;
			case 4:
					break;
			case 5:
					break;
		}
	}while(option!=5);*/


/*
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
	imprimirArrayEmpleados(aEmpleados,3);*/

	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void)
{
	char nombre[51];
	int r; // Respuesta
	r = getString(nombre,"Nombre: ","Error. El largo debe ser entre 2 y 50. \n", 50, 2,2);
	if(r == 0)
	printf("Nombre: %s",nombre);
	return EXIT_SUCCESS;
}

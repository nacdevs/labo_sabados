#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.c"
#include "Contratacion.c"
int main()
{
    //printf("Menu");



    Pantalla arrayPantallas[100];
    Contratacion arrayContrataciones [1000];
    pant_inicializarArray(&arrayPantallas,100);
    cont_inicializarArray(&arrayContrataciones,1000);
    //pant_pantallasLibre(arrayPantallas,100);
    pant_altaPantalla(&arrayPantallas,100);
    cont_contratarPantalla(&arrayContrataciones,1000,&arrayPantallas,100);



    return 0;
}

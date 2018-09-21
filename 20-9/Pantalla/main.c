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
    Contratacion contrataciones [100];
    pant_inicializarArray(&arrayPantallas,100);
    pant_altaPantalla(&arrayPantallas,100);
    cont_contratarPantalla()



    return 0;
}

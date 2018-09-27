#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.c"
#include "Contratacion.c"
int main()
{
    Pantalla arrayPantallas[100];
    Contratacion arrayContrataciones [1000];
    pant_inicializarArray(&arrayPantallas,100);
    pant_altaPantalla(&arrayPantallas,100);
   // cont_inicializarArray(&arrayContrataciones,1000);

    return 0; }

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.c"
#include "Contratacion.c"

int main()
{
    int option=0;
    Pantalla arrayPantallas[100];
    Contratacion arrayContrataciones [1000];
    pant_inicializarArray(&arrayPantallas,100);
    cont_inicializarArray(&arrayContrataciones,1000);

    while(option != 8){

    utn_getInt(&option,"Ingrese una opcion: \n1.Alta de Pantalla\n2.Modificar datos de pantalla\n3.Baja de Pantalla\n4.Contratar Pantalla\n5.Modificar condiciones publicacion\n","Ingrese opcion valida\n",0,8,1500);
        switch(option){
        case 1:
            pant_altaPantalla(&arrayPantallas,100);
            break;
        case 2:
            pant_modif(&arrayPantallas,100);
            break;
        case 3:
            pant_bajaPantalla(&arrayPantallas,100);
            break;
        case 4:
            cont_contratarPantalla(&arrayContrataciones,1000,&arrayPantallas,100);
            break;
        case 5:
            cont_modif(&arrayContrataciones,1000);
            break;

    }
    //system("clear");

    }



    return 0; }

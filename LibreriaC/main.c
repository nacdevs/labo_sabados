#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define tamanio 50
int main()
{
    char email[tamanio];

    if(utn_getMail(email,tamanio,3,"\ningrese direccion de mail\n","direccion de mail no valida\n")==0)
        {
            printf("\nCorrecto\n");
        }
        else{printf("\nNo se pudo cargar mail\n");}
    return 0;
}

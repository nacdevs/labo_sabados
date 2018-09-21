#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Contratacion.h"

void cont_contratarPantalla(Contratacion* array, int len, int id){
    int idSelect;
    pant_pantallasLibre(array,len);

    printf("Ingrese ID de pantalla\n");
    scanf("%d", idSelect);

     int i;
     int pos;
     for(i=0;i<len;i++){
        if(&array.id[i]==id){
            pos=i;
            break;
        }
      }

    if(&array[pos].isEmpty==0){
         printf("Ingrese cuit\n");
         scanf("%d", &array[pos].cuit) ;

         printf("Ingrese nombre de archivo\n");
         scanf("%s", array[pos].archivo) ;

         printf("Ingrese dias\n");
         scanf("%d", &array[pos].tipo) ;

    }else{
        printf("Esta pantalla no esta configurada\n");
    }
}

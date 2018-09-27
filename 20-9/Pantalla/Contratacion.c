#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Contratacion.h"

static int contratacionId=0;
static int posArray=0;


void cont_inicializarArray(Contratacion* array, int len){
      int i;
      int flag=0;
      for(i=0;i<len;i++){
          array[i].isEmpty=1;
            if(flag>0){
          array[i].id=contratacionId++;
          }else{
           array[i].id=contratacionId;
           flag=1;
          }

      }
        printf("array Cont init\n");
}


void cont_contratarPantalla(Contratacion* array, int len, Pantalla* arrayPantalla, int lenPant){
    int idSelect=0;


    pant_pantallasLibre(arrayPantalla,lenPant);

    printf("Ingrese ID de pantalla\n");
      __fpurge(stdin);
    scanf("%d", &idSelect) ;


    int pos=pant_buscarPantallaPorId(arrayPantalla,lenPant,idSelect);
    int i;

    if(arrayPantalla[pos].isEmpty==0 && posArray<1000){
         printf("\nIngrese cliente\n");
         scanf("%d", array[posArray].cliente) ;
          __fpurge(stdin);
         printf("Ingrese cuit\n");
         scanf("%d", &array[posArray].cuit) ;
         __fpurge(stdin);
         printf("Ingrese nombre de archivo\n");
         scanf("%s", array[posArray].video) ;
         __fpurge(stdin);
         printf("Ingrese dias\n");
         scanf("%d", &array[posArray].dias) ;
         __fpurge(stdin);


         printf("Id Contratacion:%d\n",array[posArray].id);
         printf("Video:%s\n",array[posArray].video);

    }else{
        printf("Esta pantalla no esta configurada o ya hay 1000 cliente\n");
    }
}

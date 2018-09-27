#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.h"

static int pantallaId=0;

void pant_inicializarArray(Pantalla* array, int len){
      int i;
      int flag=0;
      for(i=0;i<len;i++){
          array[i].isEmpty=1;
          if(flag>0){
          array[i].id=pantallaId++;
          }else{
           array[i].id=pantallaId;
           flag=1;
          }


      }
        printf("array init\n");
        printf("puntero array %d",array[99].isEmpty);

}

int pant_pantallasLibre(Pantalla* array, int len){
      int i;
      int ret=-1;
      printf("Pantallas libres\n");
      for(i=0;i<len;i++){
        if(array[i].isEmpty==0){
            printf("\n%d",array[i].id);

        }

      }
}

void pant_altaPantalla(Pantalla* array,int len){
     int i;
     int pos;
     char nombreAux[32];
     char direccionAux[32];
     int tipoAux;

     for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            pos=i;
            break;
        }
      }


      utn_getLetras(&nombreAux,32,3,"Ingrese Nombre\n","El nombre debe conter solo letras");


      utn_getLetras(&direccionAux,32,3,"Ingrese Direccion\n", "La direccion deben ser letras")  ;


      utn_getInt(&tipoAux,"Ingrese tipo de Pantalla 1/2\n","El numero debe ser un entero (1 o 2)",0,4,3) ;


      strcpy(array[pos].nombre, nombreAux);
      strcpy(array[pos].direccion, direccionAux);

      pantallaId+2;
      //array[pos].direccion=direccionAux ;
      array[pos].tipo=tipoAux;
      array[pos].id=pantallaId;
      array[pos].isEmpty =0;

      printf("Nombre:%s\n",array[pos].nombre);
      printf("ID:%d\n",array[pos].id);
      printf("empty:%d\n",array[pos].isEmpty);

}

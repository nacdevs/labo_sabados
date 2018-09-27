#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.h"


 int pantallaId=0;


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
        __fpurge(stdin);
}

void pant_pantallasLibre(Pantalla* array, int len){
      int i;
      printf("Pantallas libres\n");
      for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            printf("\n%d",array[i].id);
        }

      }
      __fpurge(stdin);

}

void pant_altaPantalla(Pantalla* array,int len){
     int i;
     int idPantalla;
     int pos;
     for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            pos=i;
            break;
        }
      }
     printf("Ingrese nombre\n");
     scanf("%s", array[pos].nombre) ;
     __fpurge(stdin);

     printf("Ingrese direccion\n");
     scanf("%s", array[pos].direccion) ;
         __fpurge(stdin);
     printf("Ingrese tipo\n");
     scanf("%d", array[pos].tipo) ;
      __fpurge(stdin);

     //array[pos].id= pantallaId+1;
     array[pos].isEmpty=0;
     printf("Nombre:%s\n",array[pos].direccion);
     printf("ID:%d\n",array[pos].id);
     printf("empty:%d\n",array[pos].isEmpty);
     __fpurge(stdin);
}

void pant_modif(Pantalla* array, int len,int id){
     int i;
     int pos=pant_buscarPantallaPorId(array,len,id);


     printf("Ingrese nuevo nombre\n");
     scanf("%s", array[pos].nombre) ;


     printf("Ingrese nuevo direccion\n");
     scanf("%s", array[pos].direccion) ;

     printf("Ingrese nuevo tipo\n");
     scanf("%d", &array[pos].tipo) ;

}

void pant_bajaPantalla(Pantalla* array, int len, int id){
     int i;
     int pos=pant_buscarPantallaPorId(array,len,id);

}



int pant_buscarPantallaPorId(Pantalla* array, int len, int id){
    int ret=-1;
    int i;
    for(i=0;i<len;i++){
        if(array[i].id ==id){
            ret=i;
            break;
        }
      }
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Pantalla.h"


static int pantallaId=0;


void pant_inicializarArray(Pantalla* array, int len){
      int i;
      for(i=0;i<len;i++){
          array[i].isEmpty=1;

      }
        printf("array init\n");
}

void pant_pantallasLibre(Pantalla* array, int len){
      int i;
      printf("Pantallas libres\n");
      for(i=0;i<len;i++){
        if(&array[i].isEmpty==1){
            printf("\n%d",array[i].id);
        }

      }
}

void pant_altaPantalla(Pantalla* array,int len){
     int i;
     int idPantalla;
     int pos;
     for(i=0;i<len;i++){
        if(&array[i].isEmpty==1){
            pos=i;
            break;
        }
      }
     printf("Ingrese nombre\n");
     scanf("%s", array[pos].nombre) ;


     printf("Ingrese direccion\n");
     scanf("%s", array[pos].direccion) ;

     printf("Ingrese tipo\n");
     scanf("%d", &array[pos].tipo) ;

     &array[pos].id=pantallaId+1;
     &array[pos].isEmpty=0;
     printf("Nombre:\n%s",array[pos].direccion);

}

void pant_modif(Pantalla* array, int len,int id){
     int i;
     int pos;
     for(i=0;i<len;i++){
        if(&array.id[i]==id){
            pos=i;
            break;
        }
      }

     printf("Ingrese nuevo nombre\n");
     scanf("%s", array[pos].nombre) ;


     printf("Ingrese nuevo direccion\n");
     scanf("%s", array[pos].direccion) ;

     printf("Ingrese nuevo tipo\n");
     scanf("%d", &array[pos].tipo) ;

}

void pant_bajaPantalla(Pantalla* array, int len, int id){
     int i;
     int pos;
     for(i=0;i<len;i++){
        if(&array.id[i]==id){
            &array.isEmpty=1;
            break;
        }
      }

}


static int buscarPantallaPorId(Pantalla* array, int len, int id){
    int ret=-1;

    for(i=0;i<len;i++){
        if(&array.id[i]==id){
            ret=i;
            break;
        }
      }
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Contratacion.h"

static int contratacionId=0;
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

void cont_contratarPantalla(Contratacion *array, int len, Pantalla* arrayPant, int lenPant){

    int pos;
    int idSelect;
    char clienteAux[32];
    char videoAux[32];
    int cuitAux;
    int diasAux;


    pant_pantallasLibre(arrayPant,lenPant);
    utn_getInt(&idSelect,"Ingrese ID de Pantalla","El ID debe ser un numero entero",0,100,3);
    pos=pant_buscarPantallaPorId(arrayPant, lenPant, idSelect);

    if(arrayPant[pos].isEmpty==0){

        utn_getLetras(&clienteAux,32,3,"Ingrese cliente","El cliente debe ser txt menor a 32 caract");
        utn_getLetras(&videoAux,32,3,"Ingrese archivo de video","El video debe ser txt menor a 32 caract");
        utn_getInt(&cuitAux,"Ingrese CUIT","El CUIT debe ser un numero entero sin guiones ni puntos",0,9999999999999,3);
        utn_getInt(&diasAux,"Ingrese la cantidad de dias", "Los dias deben ser un numero del 1 al 90",1,90,3);

       }

      strcpy(array[pos].cliente, &clienteAux);  /////SEGUIR DESDE ACA NO SE IMPRIME EL CLIENTE
      strcpy(array[pos].video, &videoAux);

      //array[pos].direccion=direccionAux ;
      array[pos].cuit=cuitAux;
      array[pos].idPantalla=idSelect;
      array[pos].isEmpty=0;

      printf("client: %d\n",array[pos].cliente);
}

void cont_modif(Contratacion* array, int len){
    int pos;
    int id;
    int dias;

    pos=cont_buscarPorCuit(array,len);
    utn_getInt(&id,"Ingrese ID de la pantalla seleccionada","El ID debe ser un numero entero",0,99,3);

    utn_getInt(&dias,"Ingrese nueva cantidad de dias","La cantidad de dias debe ser un numero entre 1 y 90",0,90,3);

    array[pos].dias=dias;




}

int cont_buscarPorCuit(Contratacion* array, int len){
            int ret=-1;
            int i;
            int cuit;
            //utn_getInt(&cuit,"Ingrese el CUIT del cliente","El numero debe ser un entero sin guiones ni puntos",0,999999999999,3);
            utn_getInt(&cuit,"Ingrese CUIT","Ingrese numero",0,9999999999,3);

            for(i=0;i<len;i++){
                if(array[i].cuit==cuit){
                    printf("Cliente:%c\n",array[i].cliente);
                    printf("Video:%c\n",array[i].video);
                    printf("CUIT: %d\n",array[i].cuit);
                    printf("Dias: %d\n",array[i].dias);
                    printf("Id de Contratacion: %d\n",array[i].id);
                    printf("Id de Pantalla: %d\n",array[i].idPantalla);
                    printf("\n");

                }
              }
            return ret;

}




#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "afiche.h"

static int aficheId=0;

void af_initArray(Afiche* array, int len){
      int i;
      for(i=0;i<len;i++){
          array[i].isEmpty=1;

      }
}

int af_ventAfiche(Afiche* array, int len,int id){
    int ret=-1;
    int i;

    for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            break;
        }
    }
    int idCliente=id;
    int cantidadAfiches;
    char nombreArchivo[52];
    int zona;


    utn_getInt(&cantidadAfiches,"Ingrese cantidad de afiches\n","La cantidad de afiches debe ser un numero entero\n",0,1500,5);
    utn_getLetras(&nombreArchivo,52,5,"Ingrese nombre de archivo\n","El archivo deben ser letras\n");
    utn_getInt(&zona,"Ingrese Zona (1,2,3 - CABA,ZONA SUR, ZONA OESTE respectivamente)\n","La zona debe ser un numero entero\n",1,3,5);

    array[i].idCliente=idCliente;
    array[i].cantidadAfiches=cantidadAfiches;
    strcpy(array[i].archivoImg, nombreArchivo);
    array[i].zona=zona;
    aficheId=aficheId+1;
    array[i].id=aficheId;
    array[i].idCliente=idCliente;
    array[i].statCobro=1;
    array[i].isEmpty=0;
    ret=aficheId;

    return ret;
}

int af_editVenta(Afiche* array, int len,int index){
    int ret=-1;

    if (index!=-1&&(array[index].isEmpty==0)){
        int cantidadAfiches;
        int zona;
        utn_getInt(&cantidadAfiches,"Ingrese cantidad de afiches\n","La cantidad de afiches debe ser un numero entero\n",0,1500,5);
        utn_getInt(&zona,"Ingrese Zona (1,2,3 - CABA,ZONA SUR, ZONA OESTE respectivamente)\n","La zona debe ser un numero entero\n",1,3,5);
        array[index].zona=zona;
        array[index].cantidadAfiches=cantidadAfiches;
        ret=0;
    }else{
        printf("\nLa venta no existe, id erroneo \n");
    }

    return ret;
}

void af_cobrar(Afiche* array,int len){

    af_ventas(array,len,1);
    int id;
    utn_getInt(&id,"Ingrese ID de venta a cobrar\n","El numero debe ser un entero de 0 a 1000\n",0,1000,3);
    int index;
    index=af_busId(array,len,id);
    if(index!=-1&&(array[index].isEmpty==0)){
        int confirma;
        utn_getInt(&confirma,"Seguro que quiere cobrar esta venta 1= si / 0=no\n","Ingrese un numero 0/1\n",0,1,5);
        if(confirma==1){
            array[index].statCobro=0;
            system("clear");
            printf("\nVenta Cobrada\n");
        }else{
            system("clear");
            printf("\nCobro cancelado\n");
        }


    }else{
        printf("\nEl afiche que desea cobrar no existe\n");
    }



}


void af_ventas(Afiche* array, int len, int data){
      int i;

      printf("Ventas\n");
      for(i=0;i<len;i++){
        if(array[i].isEmpty==0){
            if(data==1){
            int zonanum=array[i].zona;
            char zonaLet [52];
            switch(zonanum){
                case 1:
                strcpy(zonaLet,"CABA");
                break;

                case 2:
                strcpy(zonaLet,"Zona Sur");
                break;

                case 3:
                strcpy(zonaLet,"Zona Oeste");
                break;
            }
            printf("\nId de venta:%d\nArchivo:%s\nId cliente:%d\nCantidad afiches:%d\nZona:%s\n",array[i].id,array[i].archivoImg,array[i].idCliente,array[i].cantidadAfiches,zonaLet);
            }else{
            printf("\nId de venta:%d\n",array[i].id);
            }
        }

      }
      //return ret;
}

int af_busId(Afiche* array, int len, int id){
    int i;
    int ret=-1;
    for(i=0;i<len;i++){
        if(array[i].id ==id){
            ret=i;
            break;
        }
      }
    return ret;
}


void af_altaForzada(Afiche* array,int len,int zona,int cantAf,int idClient, char archivo[52]){
    int i;
    for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            break;
        }
    }
    if(i==1){
    array[i].statCobro=0;
    }else{
    array[i].statCobro=1;
    }
    array[i].idCliente=idClient;
    array[i].cantidadAfiches=cantAf;
    strcpy(array[i].archivoImg, archivo);
    array[i].zona=zona;
    aficheId=aficheId+1;
    array[i].id=aficheId;
    array[i].isEmpty=0;

}


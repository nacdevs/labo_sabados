#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "cliente.h"
#include "afiche.h"


static int clienteId=0;

void cl_initArray(Cliente* array, int len){
      int i;
      for(i=0;i<len;i++){
          array[i].isEmpty=1;

      }
}

int cl_altaCliente(Cliente* array, int len){
    int  ret=-1;
    int i;

    for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            break;
        }
      }

    char nombre[52];
    char apellido[52];
    int cuit;
    utn_getLetras(&nombre,50,5,"Ingrese nombre\n","El nombre deben ser letras\n");
    utn_getLetras(&apellido,50,5,"Ingrese apellido\n","El apellido deben ser letras\n");
    utn_getInt(&cuit,"Ingrese CUIT sin guiones\n","El cuit debe ser un numero entero sin guiones\n",0,9999999999999999,5);
    strcpy(array[i].nombre,nombre);
    strcpy(array[i].apellido,apellido);
    array[i].cuit=cuit;
    clienteId=clienteId+1;
    array[i].id=clienteId;
    array[i].isEmpty=0;
    ret=0;

    return ret;
}

int cl_busId(Cliente* array, int len, int id){

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

int cl_modif(Cliente* array, int len,int id){
    int ret=-1;
    int index;

    index=cl_busId(array,len,id);

    if(index!=-1&&(array[index].isEmpty==0)){
        char nombre[52];
        char apellido[52];
        int cuit;
        utn_getLetras(&nombre,50,5,"Ingrese nombre\n","El nombre deben ser letras\n");
        utn_getLetras(&apellido,50,5,"Ingrese apellido\n","El apellido deben ser letras\n");
        utn_getInt(&cuit,"Ingrese CUIT sin guiones\n","El cuit debe ser un numero entero sin guiones\n",0,9999999999999999,5);
        strcpy(array[index].nombre,nombre);
        strcpy(array[index].apellido,apellido);
        array[index].cuit=cuit;
        ret=0;
    }
    return ret;
}

int cl_bajaCliente(Cliente* array, int len){
     int ret=-1;
     int id;
     ret=utn_getInt(&id,"Ingrese ID de cliente a eliminar\n","El numero debe ser un entero\n",0,99,3);
     int pos=cl_busId(array,len,id);
     array[pos].isEmpty=1;
    return ret;
}


void cl_print(Cliente* array, int len,Afiche* arrayAf, int lenAf){
    int i;
    int j;
    system("clear");
    printf("Nombre\t\tApellido\tCUIT\t\tID\tVtas. a cobrar\n");
    for(i=0;i<len;i++){
        if(array[i].isEmpty==0){
            int clientSum=0;
            int idClient=array[i].id;
            for(j=0;j<lenAf;j++){
                if(arrayAf[j].idCliente==idClient && arrayAf[j].statCobro==1){
                    clientSum++;
                }
            }
            printf("%s\t\t%s\t\t%d\t\t%d\t%d\n",array[i].nombre,array[i].apellido,array[i].cuit,array[i].id,clientSum);

        }
      }
}




int cl_sumaCliente(Cliente* array,int len){
    int ret=-1;
    int contador=0;
    int i;
    for(i=0;i<len;i++){
       if(array[i].isEmpty==0 && array[i].id!=0){
            contador++;
       }

    }
    ret=contador;
    return ret;
}







void cl_altaForzada(Cliente* array, int len,char nombre[52], char apellido[52], int cuit){
    int i;

    for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            break;
        }
      }


    strcpy(array[i].nombre,nombre);
    strcpy(array[i].apellido,apellido);
    array[i].cuit=cuit;
    clienteId=clienteId+1;
    array[i].id=clienteId;
    array[i].isEmpty=0;

}

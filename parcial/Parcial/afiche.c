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
      int ret=-1;
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
            printf("\nid de venta:%d\n",array[i].id);
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

void calculaVentas(Afiche* array,int len ,int aCobrar){
    int i;
    int arrayDeud [1000][2];

    for(i=0;i<len;i++){

        int isEmpty= array[i].isEmpty;
        int actual=array[i].idCliente;
        int clienteSum=0;
        int j;
        for(j=0;j<len;j++){
            int idCliente=array[j].idCliente;
            int statCobro= array[j].statCobro;
            int isEmpty=array[j].isEmpty;
            if(idCliente==actual && statCobro==aCobrar && isEmpty==0){
            clienteSum++;
            }
        }

        arrayDeud[i][0]=actual;
        arrayDeud[i][1]=clienteSum;
        if(arrayDeud[i][1]!=0){
        printf("Id cliente:%d, cliente sum: %d\n",arrayDeud[i][0], arrayDeud[i][1]);

        }


    }
    int flagOrder=1;
    while(flagOrder==1){

        for(i=0;i<len;i++){
        flagOrder=0;
           int temp;
           int tempClient;
           int current=arrayDeud[i][1];
           int next =arrayDeud[i+1][1];
           int currentClient=arrayDeud[i][0];
           int nextClient =arrayDeud[i+1][0];
           if(current>next){
                temp=next;
                tempClient=nextClient;

                current=next;
                currentClient=nextClient;

                next=temp;
                nextClient=tempClient;
                flagOrder=1;
            }

        }

    }

    printf("El cliente con menos ventas a cobrar es el ID:%d\n",arrayDeud[0][1]);
}

/*void informaDeud(Afiche* array, int len){
    int i;
    int arrayDeud[1000][2];
    for(i=0;i<len;i++){

        if(actual==1 && isEmpty==0){
            int idCliente=array[i].idCliente;
            int statCobro=array[i].statCobro;
            arrayDeud[i][0]=idCliente;
            arrayDeud[i][1]=statCobro;
            arrayDeud[i][2]=2;
          //  printf("%d",arrayDeud[i][0]);
        }

    }
    int j;
    for(j=0;j<len;j++){
        if(arrayDeud[j][2]==2){
            printf("Idcliente:%d\tA cobrar:%d\n",arrayDeud[j][0],arrayDeud[j][1]);
        }

    }


}
*/





void af_zonaAfi(Afiche* array, int len){
    int mayor;
    int numeros[3];
    int i;
    for(i=0;i<len;i++){
        int zona=array[i].zona;
        switch(zona){
            case 1:
                numeros[0]=numeros[0]+1;
                break;
            case 2:
                numeros[1]=numeros[1]+1;
                break;
            case 3:
                numeros[2]=numeros[2]+1;
                break;

        }

    }

    for(int i=0;i<len;i++){
        int previous=0;
        if(numeros[i]>previous){
            previous=numeros[i];
            mayor=numeros[i];
        }
    }

    printf("La zona con mas afiches es la zona %d", mayor);
}
void af_altaForzada(Afiche* array,int len,int zona,int cantAf,int idClient, char archivo[52]){
    int i;
    for(i=0;i<len;i++){
        if(array[i].isEmpty==1){
            break;
        }
    }
    array[i].idCliente=idClient;
    array[i].cantidadAfiches=cantAf;
    strcpy(array[i].archivoImg, archivo);
    array[i].zona=zona;
    aficheId=aficheId+1;
    array[i].id=aficheId;
    array[i].statCobro=1;
    array[i].isEmpty=0;

}

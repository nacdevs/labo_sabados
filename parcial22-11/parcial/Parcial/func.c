#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"


int fn_ventaCsv(char* path, LinkedList* pLista){
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    if(parser_readCsv(pArchivo,pLista)==0){
        printf("Leyendo...");
        ret=0;
    }
    fclose(pArchivo);

    return ret;

}

int fn_sumaTotal(void* venta){

    int ret=0;
    if(venta!=NULL){
        Venta_getCantidad((Venta*)venta,&ret);
    }
    return ret;
}

int fn_sumaMayor1(void* venta){
    int ret=0;
    float precioUnitario;
    int cantidad;
    if(venta!=NULL){
        Venta_getPrecioUnit((Venta*) venta, &precioUnitario);
        Venta_getCantidad((Venta*) venta, &cantidad);
        int montoTotal=precioUnitario*cantidad;
        if(montoTotal>10000){
            ret=1;
        }
    }
    return ret;
}

int fn_sumaMayor2(void* venta){
    int ret=0;
    float precioUnitario;
    int cantidad;
    if(venta!=NULL){
        Venta_getPrecioUnit((Venta*) venta, &precioUnitario);
        Venta_getCantidad((Venta*) venta, &cantidad);
        int montoTotal=precioUnitario*cantidad;
        if(montoTotal>20000){
            ret=1;
        }
    }
    return ret;
}



int fn_LCD(void* venta){
    int ret=0;
    char* auxProd1[50];
    Venta_getCodigoProd((Venta*) venta,auxProd1);
    if(venta!= NULL && (strcmp(auxProd1,"LCD_TV")==0)){
        Venta_getCantidad((Venta*) venta, &ret);
    }
    return ret;
}




/*int fn_ventaAtxt(char*path,LinkedList* this){



}

int fn_unidadesTotal(LinkedList* this, Venta* venta){
    int ret=-1;
    ll_filter(this,fn_fCodigo(venta));

}


int fn_uniTotal(LinkedList* this){

}



int fn_LCD(Venta* pElement){
    int ret=-1;
    char* auxProd1;
    Venta_getCodigoProd(pElement,auxProd1);
    if(strcmp(auxProd1)=="LCD_TV"){
        ret=1;
    }

    return ret;

}



int fn_cLcd(Venta* pElement){
    char* codigo;
    Venta_getCodigoProd(pElement,codigo);
    int cantidad;
    if(srtcmp(codigo,"LCD_TV")){
         Venta_getCantidad(pElement,cantidad);
    }
    return cantidad;
}

ll_count(LinkedList this, fn_cLcd(pElement));

int fn_cCat(Venta* pElement){
    char*
}*/







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "parser2puntocero.h"
#include "Venta.h"

int fn_ventaCarga(char* path, LinkedList* this){
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    parser_ventaCsv(pArchivo,this);
        ret=0;

    fclose(pArchivo);

    return ret;

}

int fn_ventaAtxt(char*path,LinkedList* this){



}

/// Ojaldre con el retorno
int fn_unidadesTotal(LinkedList* this, Venta* venta){
    int ret=-1;
    //ll_filter(this,fn_fCodigo(venta));
    return 1;
}


int fn_uniTotal(LinkedList* this){

}



int fn_LCD(Venta* pElement){
    int ret=-1;
    char* auxProd1;
    Venta_getCodigoProd(pElement,auxProd1);
    if(strcmp(auxProd1,"LCD_TV")){
        ret=1;
    }

    return ret;

}

int fn_cLcd(Venta* pElement){
    char* codigo;
    Venta_getCodigoProd(pElement,codigo);
    int cantidad;
    if(strcmp(codigo,"LCD_TV")){
         Venta_getCantidad(pElement,cantidad);
        //ll_count(this, fn_cLcd);
    }
    return cantidad;
}

/*
int fn_cCat(Venta* pElement){
    char*
}*/







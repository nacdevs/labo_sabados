#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"


int fn_ventaCsv(char* path, LinkedList* this){
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    if(parser_VentaCSV(pArchivo, this)==0){
        ret=0;
    }
    fclose(pArchivo);

    return ret;

}

int fn_ventaAtxt(char*path,LinkedList* this){



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
}







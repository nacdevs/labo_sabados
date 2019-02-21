#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "Venta.h"
#include "Parser.h"

int func_readCSV(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(parser_Ventas(pFile,list)==0){
        ret=0;
    }
    fclose(pFile);
    return ret;
}



int func_cantidadTotal(void* venta){
    int ret=0;
    if(venta!=NULL){
        Venta_getCantidad((Venta*) venta,&ret);
    }
    return ret;
}

int func_ventaMayor10k(void* venta){
    int ret=0;
    float precio;
    int cantidad;
    int montoTotal;
    if(venta!=NULL){
        Venta_getCantidad((Venta*)venta,&cantidad);
        Venta_getPrecioUnitario((Venta*)venta,&precio);
        montoTotal=precio*cantidad;
        if(montoTotal>10000){
            ret=1;
        }
    }
    return ret;
}

int func_ventaMayor20k(void* venta){
    int ret=0;
    float precio;
    int cantidad;
    int montoTotal;
    if(venta!=NULL){
        Venta_getCantidad((Venta*)venta,&cantidad);
        Venta_getPrecioUnitario((Venta*)venta,&precio);
        montoTotal=precio*cantidad;
        if(montoTotal>20000){
            ret=1;
        }
    }
    return ret;
}

int func_ventaLCD(void* venta){
    int ret=0;
    char* codigoProd[50];
    if(venta!=NULL){
        Venta_getCodigoProd((Venta*)venta,codigoProd);
        if(strcmp(codigoProd,"LCD_TV")==0){
        Venta_getCantidad((Venta*)venta,&ret);
        }
    }


    return ret;

}

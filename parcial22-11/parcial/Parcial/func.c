#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
/** \brief Llama al parser encargado de leer la lista
 *
 * \param char* path Ubicacion de la lista a leer
 * \param LinkedList* lista Lista
 * \return Person* Retorna -1 en error o en caso contrario 0
 *
 */

int fn_ventaCsv(char* path, LinkedList* pLista){
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    if(parser_readCsv(pArchivo,pLista)==0){
        ret=0;
    }
    fclose(pArchivo);

    return ret;

}

/** \brief Retorna la cantidad de una venta
 *
 * \param void* venta Venta de la cual se obtiene la cantidad
 * \return Person* Retorna 0 en caso de error y en caso contrario el numero de cantidad
 *
 */

int fn_sumaTotal(void* venta){

    int ret=0;
    if(venta!=NULL){
        Venta_getCantidad((Venta*)venta,&ret);
    }
    return ret;
}

/** \brief Verifica que la venta sea por un precio mayor de $10000
 *
 * \param void* venta Venta a analizar
 * \return Person* Retorna 0 en error o en caso contrario 1
 *
 */
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


/** \brief Verifica que la venta sea por un precio mayor de $20000
 *  
 * \param void* venta Venta a analizar
 * \return Person* Retorna 0 en error o en caso contrario 1
 *
 */
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

/** \brief Verifica que sea una venta de LCD_TV
 *
 * \param void* venta Venta a analizar
 * \return Person* Retorna 0en error o en caso contrario la cantidad
 *
 */
int fn_LCD(void* venta){
    int ret=0;
    char* auxProd1[50];
    Venta_getCodigoProd((Venta*) venta,auxProd1);
    if(venta!= NULL && (strcmp(auxProd1,"LCD_TV")==0)){
        Venta_getCantidad((Venta*) venta, &ret);
    }
    return ret;
}










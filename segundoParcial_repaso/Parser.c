#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Venta.h"


int parser_Ventas(FILE* pFile , LinkedList* pList)
{
    int ret=-1;

    char auxBufferIdVenta[50];
    int bufferIdVenta;


    char auxBufferIdProd[50];


    char bufferFecha[125];

    char bufferCodProducto[50];


    char auxBufferCantidad[50];
    int bufferCantidad;

    char auxBufferPrecioUnitario[50];
    float bufferPrecioUnitario;

    char bufferCUIT[50];

    int flagFirstLine=0;
    Venta* venta;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxBufferIdVenta,bufferFecha,auxBufferIdProd,auxBufferCantidad,auxBufferPrecioUnitario,bufferCUIT)==6 && flagFirstLine!=0)
            {

                bufferIdVenta = atoi(auxBufferIdVenta);
                bufferCantidad = atoi(auxBufferCantidad);
                bufferPrecioUnitario=atof(auxBufferPrecioUnitario);
                venta=Venta_newConParametros(bufferIdVenta,bufferFecha,auxBufferIdProd,bufferCantidad,bufferPrecioUnitario, bufferCUIT);
                ll_add(pList,(Venta*)venta);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}

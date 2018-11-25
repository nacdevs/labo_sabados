#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"

int parser_readCsv(FILE* pFile , LinkedList* pArrayListVenta)
{
    int ret=-1;
    char bufferId[50];
    int id;

    char bufferFecha[50];
    char fecha[50];

    char bufferCodigo[70];
    char codigo[70];

    char bufferCantidad[25];
    int cantidad;

    char bufferPrecio[25];
    float precio;

    char bufferCuit[50];
    int cuit;

    int flagFirstLine=0;
    Venta* auxVenta;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFecha,bufferCodigo,bufferCantidad,bufferPrecio,bufferCuit)==6 && flagFirstLine!=0)
            {
                id= atoi(bufferId);
                strcpy(fecha,bufferFecha);
                strcpy(codigo,bufferCodigo);
                cantidad=atoi(bufferCantidad);
                precio=atof(bufferPrecio);
                cuit=atoi(bufferCuit);

                auxVenta=Venta_newConParametros(id,fecha,codigo,cantidad,precio,cuit);
                char* prod;
                Venta_getCodigoProd(auxVenta,prod);
                printf("%d \n",id);
                ll_add(pArrayListVenta,auxVenta);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));

    }
    return ret;
}

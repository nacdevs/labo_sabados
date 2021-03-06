#include <stdio.h>
#include <stdlib.h>

int parser_readCsv(FILE* pFile , LinkedList* pArrayListVenta)
{
    int ret=-1;
    char bufferId;
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
                id= atoi(auxBufferId);
                strcpy(fecha,bufferFecha);
                strcpy(codigo,bufferCodigo);
                cantidad=atoi(bufferCantidad);
                precio=atof(bufferPrecio);
                cuit=atoi(bufferCuit);

                auxVenta=Venta_newConParametros(id,fecha,codigo,cantidad,precio,cuit);
                char* prod;
                Venta_getCodigoProd(auxVenta,prod);
                printf(prod);
                ll_add(pArrayListVenta,(Venta*)auxVenta);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));

    }
    return ret;
}

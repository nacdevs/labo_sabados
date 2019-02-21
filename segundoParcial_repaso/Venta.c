#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Venta_delete(Venta* this)
{
    free(this);
}

Venta* Venta_newConParametros(int idVenta,char* fecha,char* codigoProd,int cantidad,float precioUnitario,char* CUIT)
{
    Venta* this;
    this=Venta_new();

    if(
    !Venta_setIdVenta(this,idVenta)&&
    !Venta_setFecha(this,fecha)&&
    !Venta_setCodigoProd(this,codigoProd)&&
    !Venta_setCantidad(this,cantidad)&&
    !Venta_setPrecioUnitario(this,precioUnitario)&&
    !Venta_setCUIT(this,CUIT))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoProd(Venta* this,char* codigoProd)
{
    int retorno=-1;
    if(this!=NULL && codigoProd!=NULL)
    {
        strcpy(this->codigoProd,codigoProd);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoProd(Venta* this,char* codigoProd)
{
    int retorno=-1;
    if(this!=NULL && codigoProd!=NULL)
    {
        strcpy(codigoProd,this->codigoProd);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCUIT(Venta* this,char* CUIT)
{
    int retorno=-1;
    if(this!=NULL && CUIT!=NULL)
    {
        strcpy(this->CUIT,CUIT);
        retorno=0;
    }
    return retorno;
}

int Venta_getCUIT(Venta* this,char* CUIT)
{
    int retorno=-1;
    if(this!=NULL && CUIT!=NULL)
    {
        strcpy(CUIT,this->CUIT);
        retorno=0;
    }
    return retorno;
}


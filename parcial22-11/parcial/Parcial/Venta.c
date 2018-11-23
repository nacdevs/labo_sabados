
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 Venta* Venta_new()
{
     Venta* this;
    this=malloc(sizeof( Venta));
    return this;
}

void Venta_delete( Venta* this)
{
    free(this);
}

 Venta* Venta_newConParametros(int idVenta,char* fechaVenta,char* codigoProd,int cantidad,float precioUnit,int CUIT)
{
     Venta* this;
    this=Venta_new();

    if(
    !Venta_setIdVenta(this,idVenta)&&
    !Venta_setFechaVenta(this,fechaVenta)&&
    !Venta_setCodigoProd(this,codigoProd)&&
    !Venta_setCantidad(this,cantidad)&&
    !Venta_setPrecioUnit(this,precioUnit)&&
    !Venta_setCUIT(this,CUIT))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta( Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta( Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaVenta( Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaVenta( Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoProd( Venta* this,char* codigoProd)
{
    int retorno=-1;
    if(this!=NULL && codigoProd!=NULL)
    {
        strcpy(this->codigoProd,codigoProd);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoProd( Venta* this,char* codigoProd)
{
    int retorno=-1;
    if(this!=NULL && codigoProd!=NULL)
    {
        strcpy(codigoProd,this->codigoProd);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad( Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad( Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnit( Venta* this,float precioUnit)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnit=precioUnit;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnit( Venta* this,float* precioUnit)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnit=this->precioUnit;
        retorno=0;
    }
    return retorno;
}

int Venta_setCUIT( Venta* this,int CUIT)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->CUIT=CUIT;
        retorno=0;
    }
    return retorno;
}

int Venta_getCUIT( Venta* this,int* CUIT)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *CUIT=this->CUIT;
        retorno=0;
    }
    return retorno;
}


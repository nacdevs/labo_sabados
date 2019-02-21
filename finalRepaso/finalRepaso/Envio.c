#include "Envio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Envio* Envio_new()
{
    Envio* this;
    this=malloc(sizeof(Envio));
    return this;
}

void Envio_delete(Envio* this)
{
    free(this);
}

Envio* Envio_newConParametros(int idEnvio,char* nombreProducto ,int idCamion,char* zonaDestino ,int kmRecorridos,int tipoEntrega,int costoEnvio)
{
    Envio* this;
    this=Envio_new();

    if(
    !Envio_setIdEnvio(this,idEnvio)&&
    !Envio_setNombreProducto (this,nombreProducto )&&
    !Envio_setIdCamion(this,idCamion)&&
    !Envio_setZonaDestino (this,zonaDestino )&&
    !Envio_setKmRecorridos(this,kmRecorridos)&&
    !Envio_setTipoEntrega(this,tipoEntrega)&&
    !Envio_setCostoEnvio(this,costoEnvio))
        return this;

    Envio_delete(this);
    return NULL;
}

int Envio_setIdEnvio(Envio* this,int idEnvio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idEnvio=idEnvio;
        retorno=0;
    }
    return retorno;
}

int Envio_getIdEnvio(Envio* this,int* idEnvio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idEnvio=this->idEnvio;
        retorno=0;
    }
    return retorno;
}

int Envio_setNombreProducto (Envio* this,char* nombreProducto )
{
    int retorno=-1;
    if(this!=NULL && nombreProducto !=NULL)
    {
        strcpy(this->nombreProducto ,nombreProducto );
        retorno=0;
    }
    return retorno;
}

int Envio_getNombreProducto (Envio* this,char* nombreProducto )
{
    int retorno=-1;
    if(this!=NULL && nombreProducto !=NULL)
    {
        strcpy(nombreProducto ,this->nombreProducto );
        retorno=0;
    }
    return retorno;
}

int Envio_setIdCamion(Envio* this,int idCamion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idCamion=idCamion;
        retorno=0;
    }
    return retorno;
}

int Envio_getIdCamion(Envio* this,int* idCamion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idCamion=this->idCamion;
        retorno=0;
    }
    return retorno;
}

int Envio_setZonaDestino (Envio* this,char* zonaDestino )
{
    int retorno=-1;
    if(this!=NULL && zonaDestino !=NULL)
    {
        strcpy(this->zonaDestino ,zonaDestino );
        retorno=0;
    }
    return retorno;
}

int Envio_getZonaDestino (Envio* this,char* zonaDestino )
{
    int retorno=-1;
    if(this!=NULL && zonaDestino !=NULL)
    {
        strcpy(zonaDestino ,this->zonaDestino );
        retorno=0;
    }
    return retorno;
}

int Envio_setKmRecorridos(Envio* this,int kmRecorridos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->kmRecorridos=kmRecorridos;
        retorno=0;
    }
    return retorno;
}

int Envio_getKmRecorridos(Envio* this,int* kmRecorridos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *kmRecorridos=this->kmRecorridos;
        retorno=0;
    }
    return retorno;
}

int Envio_setTipoEntrega(Envio* this,int tipoEntrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->tipoEntrega=tipoEntrega;
        retorno=0;
    }
    return retorno;
}

int Envio_getTipoEntrega(Envio* this,int* tipoEntrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tipoEntrega=this->tipoEntrega;
        retorno=0;
    }
    return retorno;
}

int Envio_setCostoEnvio(Envio* this,int costoEnvio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->costoEnvio=costoEnvio;
        retorno=0;
    }
    return retorno;
}

int Envio_getCostoEnvio(Envio* this,int* costoEnvio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *costoEnvio=this->costoEnvio;
        retorno=0;
    }
    return retorno;
}


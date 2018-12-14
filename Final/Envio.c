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

Envio* Envio_newConParametros(int idEnvio,char* nombre,int idCamion,char* zona,int km,int tipoentrega)
{
    Envio* this;
    this=Envio_new();

    if(
    !Envio_setIdEnvio(this,idEnvio)&&
    !Envio_setNombre(this,nombre)&&
    !Envio_setIdCamion(this,idCamion)&&
    !Envio_setZona(this,zona)&&
    !Envio_setKm(this,km)&&
    !Envio_setTipoentrega(this,tipoentrega))
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

int Envio_setNombre(Envio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Envio_getNombre(Envio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
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

int Envio_setZona(Envio* this,char* zona)
{
    int retorno=-1;
    if(this!=NULL && zona!=NULL)
    {
        strcpy(this->zona,zona);
        retorno=0;
    }
    return retorno;
}

int Envio_getZona(Envio* this,char* zona)
{
    int retorno=-1;
    if(this!=NULL && zona!=NULL)
    {
        strcpy(zona,this->zona);
        retorno=0;
    }
    return retorno;
}

int Envio_setKm(Envio* this,int km)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->km=km;
        retorno=0;
    }
    return retorno;
}

int Envio_getKm(Envio* this,int* km)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *km=this->km;
        retorno=0;
    }
    return retorno;
}

int Envio_setTipoentrega(Envio* this,int tipoentrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->tipoentrega=tipoentrega;
        retorno=0;
    }
    return retorno;
}

int Envio_getTipoentrega(Envio* this,int* tipoentrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tipoentrega=this->tipoentrega;
        retorno=0;
    }
    return retorno;
}


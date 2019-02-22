
#include "fichajes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fichajes* fichajes_new()
{
    Fichajes* this;
    this=malloc(sizeof(Fichajes));
    return this;
}

void fichajes_delete(Fichajes* this)
{
    free(this);
}

Fichajes* fichajes_newConParametros(int idFicha,int idEmp,int hora,int minutos,int dia,int mes,int anio,char* IO )
{
    Fichajes* this;
    this=fichajes_new();

    if(
    !fichajes_setIdFicha(this,idFicha)&&
    !fichajes_setIdEmp(this,idEmp)&&
    !fichajes_setHora(this,hora)&&
    !fichajes_setMinutos(this,minutos)&&
    !fichajes_setDia(this,dia)&&
    !fichajes_setMes(this,mes)&&
    !fichajes_setAnio(this,anio)&&
    !fichajes_setIO (this,IO ))
        return this;

    fichajes_delete(this);
    return NULL;
}

int fichajes_setIdFicha(Fichajes* this,int idFicha)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idFicha=idFicha;
        retorno=0;
    }
    return retorno;
}

int fichajes_getIdFicha(Fichajes* this,int* idFicha)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idFicha=this->idFicha;
        retorno=0;
    }
    return retorno;
}

int fichajes_setIdEmp(Fichajes* this,int idEmp)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idEmp=idEmp;
        retorno=0;
    }
    return retorno;
}

int fichajes_getIdEmp(Fichajes* this,int* idEmp)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idEmp=this->idEmp;
        retorno=0;
    }
    return retorno;
}

int fichajes_setHora(Fichajes* this,int hora)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->hora=hora;
        retorno=0;
    }
    return retorno;
}

int fichajes_getHora(Fichajes* this,int* hora)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *hora=this->hora;
        retorno=0;
    }
    return retorno;
}

int fichajes_setMinutos(Fichajes* this,int minutos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->minutos=minutos;
        retorno=0;
    }
    return retorno;
}

int fichajes_getMinutos(Fichajes* this,int* minutos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *minutos=this->minutos;
        retorno=0;
    }
    return retorno;
}

int fichajes_setDia(Fichajes* this,int dia)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->dia=dia;
        retorno=0;
    }
    return retorno;
}

int fichajes_getDia(Fichajes* this,int* dia)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dia=this->dia;
        retorno=0;
    }
    return retorno;
}

int fichajes_setMes(Fichajes* this,int mes)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->mes=mes;
        retorno=0;
    }
    return retorno;
}

int fichajes_getMes(Fichajes* this,int* mes)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *mes=this->mes;
        retorno=0;
    }
    return retorno;
}

int fichajes_setAnio(Fichajes* this,int anio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->anio=anio;
        retorno=0;
    }
    return retorno;
}

int fichajes_getAnio(Fichajes* this,int* anio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *anio=this->anio;
        retorno=0;
    }
    return retorno;
}

int fichajes_setIO (Fichajes* this,char* IO )
{
    int retorno=-1;
    if(this!=NULL && IO !=NULL)
    {
        strcpy(this->IO ,IO );
        retorno=0;
    }
    return retorno;
}

int fichajes_getIO (Fichajes* this,char* IO )
{
    int retorno=-1;
    if(this!=NULL && IO !=NULL)
    {
        strcpy(IO ,this->IO );
        retorno=0;
    }
    return retorno;
}


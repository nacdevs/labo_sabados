
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre ,char* apellido ,int dni,char* clave )
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,id)&&
    !Empleado_setNombre (this,nombre )&&
    !Empleado_setApellido (this,apellido )&&
    !Empleado_setDni(this,dni)&&
    !Empleado_setClave (this,clave ))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre (Empleado* this,char* nombre )
{
    int retorno=-1;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(this->nombre ,nombre );
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre (Empleado* this,char* nombre )
{
    int retorno=-1;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre ,this->nombre );
        retorno=0;
    }
    return retorno;
}

int Empleado_setApellido (Empleado* this,char* apellido )
{
    int retorno=-1;
    if(this!=NULL && apellido !=NULL)
    {
        strcpy(this->apellido ,apellido );
        retorno=0;
    }
    return retorno;
}

int Empleado_getApellido (Empleado* this,char* apellido )
{
    int retorno=-1;
    if(this!=NULL && apellido !=NULL)
    {
        strcpy(apellido ,this->apellido );
        retorno=0;
    }
    return retorno;
}

int Empleado_setDni(Empleado* this,int dni)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->dni=dni;
        retorno=0;
    }
    return retorno;
}

int Empleado_getDni(Empleado* this,int* dni)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dni=this->dni;
        retorno=0;
    }
    return retorno;
}

int Empleado_setClave (Empleado* this,char* clave )
{
    int retorno=-1;
    if(this!=NULL && clave !=NULL)
    {
        strcpy(this->clave ,clave );
        retorno=0;
    }
    return retorno;
}

int Empleado_getClave (Empleado* this,char* clave )
{
    int retorno=-1;
    if(this!=NULL && clave !=NULL)
    {
        strcpy(clave ,this->clave );
        retorno=0;
    }
    return retorno;
}


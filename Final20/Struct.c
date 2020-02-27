
#include "Struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Struct* Struct_new()
{
    Struct* this;
    this=malloc(sizeof(Struct));
    return this;
}

void Struct_delete(Struct* this)
{
    free(this);
}

Struct* Struct_newConParametros(int id,char* nombre ,char* apellido ,int dni,char* clave )
{
    Struct* this;
    this=Struct_new();

    if(
    !Struct_setId(this,id)&&
    !Struct_setNombre (this,nombre )&&
    !Struct_setApellido (this,apellido )&&
    !Struct_setDni(this,dni)&&
    !Struct_setClave (this,clave ))
        return this;

    Struct_delete(this);
    return NULL;
}

int Struct_setId(Struct* this,int id)
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

int Struct_getId(Struct* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Struct_setNombre (Struct* this,char* nombre )
{
    int retorno=-1;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(this->nombre ,nombre );
        retorno=0;
    }
    return retorno;
}

int Struct_getNombre (Struct* this,char* nombre )
{
    int retorno=-1;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre ,this->nombre );
        retorno=0;
    }
    return retorno;
}

int Struct_setApellido (Struct* this,char* apellido )
{
    int retorno=-1;
    if(this!=NULL && apellido !=NULL)
    {
        strcpy(this->apellido ,apellido );
        retorno=0;
    }
    return retorno;
}

int Struct_getApellido (Struct* this,char* apellido )
{
    int retorno=-1;
    if(this!=NULL && apellido !=NULL)
    {
        strcpy(apellido ,this->apellido );
        retorno=0;
    }
    return retorno;
}

int Struct_setDni(Struct* this,int dni)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->dni=dni;
        retorno=0;
    }
    return retorno;
}

int Struct_getDni(Struct* this,int* dni)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dni=this->dni;
        retorno=0;
    }
    return retorno;
}

int Struct_setClave (Struct* this,char* clave )
{
    int retorno=-1;
    if(this!=NULL && clave !=NULL)
    {
        strcpy(this->clave ,clave );
        retorno=0;
    }
    return retorno;
}

int Struct_getClave (Struct* this,char* clave )
{
    int retorno=-1;
    if(this!=NULL && clave !=NULL)
    {
        strcpy(clave ,this->clave );
        retorno=0;
    }
    return retorno;
}


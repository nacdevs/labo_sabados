#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* Cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

void Cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* Cliente_newConParametros(char* id,char* nombre,char* apellido)
{
    Cliente* this;
    this=Cliente_new();

    if(
    !Cliente_setId(this,id)&&
    !Cliente_setNombre(this,nombre)&&
    !Cliente_setApellido(this,apellido))
        return this;

    Cliente_delete(this);
    return NULL;
}

int Cliente_setId(Cliente* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        strcpy(this->id,id);
        retorno=0;
    }
    return retorno;
}

int Cliente_getId(Cliente* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        strcpy(id,this->id);
        retorno=0;
    }
    return retorno;
}

int Cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char* nombre){

    return 1;
}



int Cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && isValidApellido(apellido))
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

void Cliente_mostrar(Cliente* arrayClientes[],int size){
    int i;
    char auxId[75];
    char auxNombre [75];

    for(i=0;i<size;i++){
        Cliente_getId(arrayClientes[i],&auxId);
        Cliente_getNombre(arrayClientes[i],auxNombre);
        printf("\n ID: %s - Nombre: %s", auxId,auxNombre);
    }
}

int isValidApellido(char* apellido){

    return 1;
}

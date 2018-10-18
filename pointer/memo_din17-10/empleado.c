#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

Empleado* empleado_new(){


    return (Empleado*) malloc(sizeof(Empleado));



}


Empleado* empleado_newParametros(char* nombre, char* apellido, float altura){


    Empleado* pEmpleado = NULL;
    pEmpleado = empleado_new();

    if(pEmpleado==NULL ||
        empleado_setNombre(pEmpleado,nombre) ||
        empleado_setApellido(pEmpleado,apellido)||
        empleado_setAltura(pEmpleado,&altura)){
        empleado_delete(pEmpleado);
        pEmpleado=NULL;

    }

    return pEmpleado;


}

void empleado_delete(Empleado* this){

    free(this);

}

int empleado_setNombre(Empleado* this, char* nombre){
    int retorno=-1;
    if(this!=NULL && nombre != NULL){

        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}


int empleado_getNombre(Empleado* this, char* nombre){
    int retorno=-1;
    if(this!=NULL && nombre != NULL){

        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}


static int isValidNombre(char* nombre){

    return 1;
}

int empleado_compareNombre(Empleado* thisA, Empleado* thisB){
    int retorno = 0;

    retorno=strcmp(thisA->nombre,thisB->nombre);



    return retorno;
}


//////////////////


int empleado_setApellido(Empleado* this, char* apellido){
    int retorno=-1;
    if(this!=NULL && isValidApellido(apellido)){

        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}


int empleado_getApellido(Empleado* this, char* apellido){
    int retorno=-1;
    if(this!=NULL && apellido != NULL){

        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}


int isValidApellido(char* apellido){

    return 1;
}

///////////////////ALTURA



int empleado_setAltura(Empleado* this, float* altura){
    int retorno=-1;
    if(this!=NULL && altura != NULL){

        this->altura=*altura;
        retorno=0;
    }
    return retorno;
}


int empleado_getAltura(Empleado* this, float* altura){
    int retorno=-1;
    if(this!=NULL && altura != NULL){

        *altura=this->altura;
        retorno=0;
    }
    return retorno;
}


static int isValidAltura(float* altura){

    return 1;
}



void empleado_print(Empleado* this){
    printf("\n%s - %s - %.2f - %d",this->nombre, this->apellido ,this->altura, this->idEmpleado);
}

void ordenar(Empleado* listaEmpleado[], int limite){
    int flagswap;
    int i;
    Empleado* auxiliar;



}

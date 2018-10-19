#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

Cliente* cli_newCliente(void){

    return (Cliente*)malloc(sizeof(Cliente));

}

int cli_setNombre(Cliente* this, char* nombre){
    int retorno=-1;
    if(this!=NULL && nombre != NULL){

        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;

}
///

int cli_getNombre(Cliente* this , char* nom){

    if(this!=NULL && nom!=NULL){
        strcpy(nom,this->nombre);

    }


}

int cli_setApellido(Cliente* this, char* apellido){
       int retorno=-1;
    if(this!=NULL && this != NULL){

        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;

}

int cli_buscarLugarVacio(Cliente* array[], int len){

    int i;
    int ret=-1;
    if(array!=NULL){
        for(i=0; i<len; i++){
        if(array[i]==NULL){
            ret=i;
            break;

        }
      }

    }

    return ret;
}

int cli_inicializarArray(Cliente* array[], int len){
    int ret=-1;
    int i;
     if(array!=NULL){
        ret=0;
        for(i=0; i<len; i++){
            array[i]=NULL;

        }
      }

    return ret;


}

int cli_buscarPorId(Cliente* array[],int len, int id){
    int ret=-1;
    int i;
    Cliente* aux;
    for(i=0; i<len; i++){
        aux=array[i];
        if(aux!=NULL && aux->id==id){
            ret=i;
            break;
        }

    }
    return ret;
}

int cli_deleteCliente(Cliente* this){
    int ret=-1;
    if(this!=NULL){
        free(this);
        ret=0;

    }
    return ret;
}


Cliente* cli_newClienteParametros(char* nom, char* ape,int* id){
    Cliente* p;
    p= cli_newCliente();
    if(p!=NULL){
        if(cli_setNombre(p,nom)==-1 ||
            cli_setApellido(p,ape)==-1||
            cli_setId(p,id)==-1){

            cli_deleteCliente(p);
            p=NULL;
            }
    }


}

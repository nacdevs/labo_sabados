#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "service.h"


Service* service_new(){
    return (Service*) malloc(sizeof(Service));
}

Service* service_newParametros(char* mensaje, char* apellido, int gravedad){

    Serivce* pService = NULL;
    pService = service_new();

    if(pService==NULL ||
        service_setNombre(pService,nombre) ||
        service_setApellido(pService,apellido)||
        service_setAltura(pService,&altura)){
        service_delete(pService);
        pService=NULL;

    }

    return pService;
}

void service_delete(Service* this){

    free(this);
}

int service_setMensaje(Service* this, char* mensaje){
    int retorno=-1;
    if(this!=NULL && mensaje != NULL){

        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}
int service_getMensaje(Service* this, char* mensaje){
    int retorno=-1;
    if(this!=NULL && nombre != NULL){
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }
    return retorno;



}
int service_compareMensaje(Service* thisA, Service* thisB){
     int retorno = 0;

    retorno=strcmp(thisA->nombre,thisB->nombre);

    return retorno;
}

int service_setServiceId(Service* this, int* serviceId){
      int retorno=-1;
    if(this!=NULL && serviceId != NULL){

        this->serviceId=*serviceId;
        retorno=0;
    }
    return retorno;


}

int service_getServiceId(Service* this, int* serviceId){
  int retorno=-1;
    if(this!=NULL && serviceId != NULL){

        *serviceId=this->serviceId;
        retorno=0;
    }
    return retorno;

}




int service_setGravedad(Service* this, int* gravedad){
     int retorno=-1;
    if(this!=NULL && gravedad != NULL){

        this->gravedad=*gravedad;
        retorno=0;
    }
    return retorno;
}


int service_getGravedad(Service* this, int* gravedad){
      int retorno=-1;
    if(this!=NULL && gravedad != NULL){

        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;


}

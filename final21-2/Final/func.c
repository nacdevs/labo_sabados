#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Empleado.h"
#include "fichajes.h"

int currentEmp;
Empleado* currentEmpleado;
int thisId;
int dia;
int mes;

int func_readCSV(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(parser_Empleados(pFile,list)==0){
        ret=0;
    }
    fclose(pFile);
    return ret;
}


int func_readCSVF(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(parser_Fichaje(pFile,list)==0){
        ret=0;
    }
    fclose(pFile);
    return ret;
}

void fn_setId(int* ids){
    thisId= ids;

}

void fn_setDia(int* ids){
    dia= ids;

}
void fn_setMes(int* ids){
    mes= ids;

}

int fn_filterById(void* empleado){
    int ret =-1;
    char zona [75];
    int currentId;
    Empleado_getId((Empleado*)empleado,&currentId);
    if(currentId==thisId){
        currentEmpleado=((Empleado*)empleado);
        ret=1;
    }

    return ret;

}

void fn_setEmpleado(Empleado* emp){
    currentEmpleado=emp;
}

void fn_delete(){
    free(currentEmpleado);
}



int fn_filtrarFecha(void* fichaje){
    int ret =-1;
    int adia;
    int smes;
    int fIdEmp;
    char apellido [100];
    char zona [75];


    fichajes_getDia((Fichajes*)fichaje,&adia);
    fichajes_getMes((Fich   ajes*)fichaje,&smes);
    fichajes_getIdEmp((Fichajes*)fichaje,&fIdEmp);
    if(adia==dia && smes==mes){
        printf("%d\n",&fIdEmp);
        ret=1;
    }


    return ret;

}





























/*



int func_writeCSV(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"w");
    Envio* envio;
    int len=ll_len(list);
    int idEnvio;
    char nombreProd [100];
    int idCamion;
    char zona[100];
    int km;
    int tipo;
    int costo;
    if(list!=NULL){
     for(int i=0; i<len; i++){
        envio=ll_get(list,i);
        Envio_getIdEnvio(envio,&idEnvio);
        Envio_getNombreProducto(envio,&nombreProd);
        Envio_getIdCamion(envio,&idCamion);
        Envio_getZonaDestino(envio,&zona);
        Envio_getKmRecorridos(envio,&km);
        Envio_getTipoEntrega(envio,&tipo);
        Envio_getCostoEnvio(envio,&costo);

        fprintf(pFile,"%d - %s - %d - %s - %d - %d --%d \n",idEnvio,nombreProd,idCamion,zona,km,tipo,costo);
        ret=0;
        }
        fclose(pFile);
    }
    return ret;
}

int fn_printEnvios(LinkedList* pList){
    int ret=-1;
    Envio* envio;
    int len=ll_len(pList);
    int idEnvio;
    char nombreProd [100];
    int idCamion;
    char zona[100];
    int km;
    int tipo;

    for(int i=0; i<len; i++){
        envio=ll_get(pList,i);
        Envio_getIdEnvio(envio,&idEnvio);
        Envio_getNombreProducto(envio,&nombreProd);
        Envio_getIdCamion(envio,&idCamion);
        Envio_getZonaDestino(envio,&zona);
        Envio_getKmRecorridos(envio,&km);
        Envio_getTipoEntrega(envio,&tipo);

        printf("%d - %s - %d - %s - %d - %d \n",idEnvio,nombreProd,idCamion,zona,km,tipo);
        ret=0;

    }

    return ret;
}



int fn_printEnviosConCosto(LinkedList* pList){
    int ret=-1;
    Envio* envio;
    int len=ll_len(pList);
    int idEnvio;
    char nombreProd [100];
    int idCamion;
    char zona[100];
    int km;
    int tipo;
    int costo;

    for(int i=0; i<len; i++){
        envio=ll_get(pList,i);
        Envio_getIdEnvio(envio,&idEnvio);
        Envio_getNombreProducto(envio,&nombreProd);
        Envio_getIdCamion(envio,&idCamion);
        Envio_getZonaDestino(envio,&zona);
        Envio_getKmRecorridos(envio,&km);
        Envio_getTipoEntrega(envio,&tipo);
        Envio_getCostoEnvio(envio,&costo);

        printf("%d - %s - %d - %s - %d - %d -- %d \n",idEnvio,nombreProd,idCamion,zona,km,tipo,costo);
        ret=0;

    }

    return ret;
}

int fn_calCosto(void* envio){
    int ret=-1;
    if(envio!=NULL){
        int km;
        int tipoEntrega;
        int costoFijo;
        Envio_getKmRecorridos((Envio*)envio,&km);
        Envio_getTipoEntrega((Envio*)envio,&tipoEntrega);
        if(km<50){
            switch(tipoEntrega){
                case 0:
                costoFijo=250;
                break;

                case 1:
                costoFijo=420;
                break;

                case 2:
                costoFijo=75;
                break;
            }
            int costo=km*100;
            Envio_setCostoEnvio(envio,(costo+costoFijo));
            ret=0;
        }else{
             switch(tipoEntrega){
                case 0:
                costoFijo=250;
                break;

                case 1:
                costoFijo=420;
                break;

                case 2:
                costoFijo=75;
                break;
            }
            int costo=km*100;
            Envio_setCostoEnvio(envio,(costo+costoFijo));
            ret=0;
        }
    }


    return ret;
}

char*zonaABuscar [75];

void setZona(char* zona){
    strcpy(zonaABuscar,zona);
}
int fn_filtraZona(void* envio){
    int ret =-1;
    char zona [75];
    Envio_getZonaDestino((Envio*)envio,zona);
    if(ret=strcmp(zona,zonaABuscar)==0){
        ret=1;
    }


    return ret;

}*/

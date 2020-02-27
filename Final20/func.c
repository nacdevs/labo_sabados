#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Struct.h"
#include "fichajes.h"

int currentEmp;
Struct* currentEmpleado;
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
    thisId= *ids;

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
    Struct_getId((Struct*)empleado,&currentId);
    printf("%d\n",currentId);
    printf("%d\n",thisId);
    if(currentId==thisId){
        //currentEmpleado=((Struct*)empleado);
       Struct_setNombre((Struct*)empleado,currentEmpleado->nombre);
       Struct_setApellido((Struct*)empleado,currentEmpleado->apellido);
       Struct_setClave((Struct*)empleado,currentEmpleado->clave);
       int dni2;
       Struct_setDni((Struct*)empleado,currentEmpleado->dni);
        ret=1;
    }

    return ret;

}


void fn_setEmpleado(Struct* emp){
    currentEmpleado=emp;
    //thisId = *emp.id
}

void fn_delete(){
    free(currentEmpleado);
}

LinkedList* auxPList;


int fn_clearPointer(void* pElement){
    int ret = 1;
    int currentId;
    Struct_getId((Struct*)pElement,&currentId);
    if(currentId == thisId){
        int i = ll_indexOf(auxPList,pElement);
        ll_remove(auxPList,i);
        ret = 0;
    }
    return ret;
}

void fn_removeStruct(LinkedList* pList, int id){
    thisId = id;
    auxPList = pList;
    ll_map(pList,fn_clearPointer);
}



//HACER BORRADO LOGICO


void fn_printStruct(LinkedList* pList){
    int i;
    int len = ll_len(pList);
    Struct* aux;
    int auxid;
    char auxnombre [75];
    char auxapellido [75];
    int auxdni;
    char auxclave [75];
    for(i=0; i<len;i++){
        aux=ll_get(pList,i);
        Struct_getId(aux,&auxid);
        Struct_getNombre(aux,&auxnombre);
        Struct_getApellido(aux,&auxapellido);
        Struct_getDni(aux,&auxdni);
        Struct_getClave(aux,&auxclave);

        printf(" %d - %s - %s - %d- %s \n",auxid,auxnombre,auxapellido,auxdni,auxclave);


    }
    return 1;
}

int fn_filtrarFecha(void* fichaje){
    int ret =-1;
    int adia;
    int smes;
    int fIdEmp;
    char apellido [100];
    char zona [75];


    //fichajes_getDia((Fichajes*)fichaje,&adia);
    //fichajes_getMes((Fich   ajes*)fichaje,&smes);
    //fichajes_getIdEmp((Fichajes*)fichaje,&fIdEmp);
    if(adia==dia && smes==mes){
        printf("%d\n",&fIdEmp);
        ret=1;
    }


    return ret;

}




int fn_writeCSV(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"w");
    Struct* emp;
    int len=ll_len(list);
    int auxid;
    char auxnombre [75];
    char auxapellido [75];
    int auxdni;
    char auxclave [75];
    if(list!=NULL){
     for(int i=0; i<len; i++){
        emp=ll_get(list,i);
        Struct_getId(emp,&auxid);
        Struct_getNombre(emp,&auxnombre);
        Struct_getApellido(emp,&auxapellido);
        Struct_getDni(emp,&auxdni);
        Struct_getClave(emp,&auxclave);

        fprintf(pFile,"%d - %s - %s - %d - %s \n",auxid,auxnombre,auxapellido,auxdni,auxclave);
        ret=0;
        }
        fclose(pFile);
    }
    return ret;
}



int fn_loadFromBinary(char* path , LinkedList* pList)
{
    int ret=-1;
    FILE* pArchivo= fopen(path,"rb");
    Struct* pStruct;
    if(parser_FromBinary(pArchivo,pList)==0){
        ret=0;
    }

    return ret;
}


int fn_saveBinary(char* path , LinkedList* pList)
{
    int ret=-1;
    FILE* pArchivo= fopen(path,"wb");
    Struct* pStruct;
    int i;
    int lenArray=ll_len(pList);
    if(pArchivo != NULL){
        for(i=0;i<lenArray;i++){
                pStruct = ll_get(pList,i);
                fwrite(pStruct,sizeof(Struct),1,pArchivo);
                }
        if(i>5){
            ret=0;
            }
     }
    fclose(pArchivo);
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

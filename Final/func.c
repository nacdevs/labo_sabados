#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"
#include "LinkedList.h"


char zona[125];
int costo2;
char path[125];

int fn_setZona(char* zona)
{
    int ret=-1;
    ret = utn_getLetras(&zona,120,3," \n","Maximo 120");
    return ret;
}
int fn_listEnvio(LinkedList* pList)
{

    int i;
    int len = ll_len(pList);
    Envio* auxEnvio;
    int  bufferId;
    char bufferNombre[128];
    int  bufferIdCamion;
    char bufferZona [75];
    int  bufferkm;
    int  bufferTipo;
    for(i=0; i<len;i++){
        auxEnvio=ll_get(pList,i);
        Envio_getIdEnvio(auxEnvio,&bufferId);
        Envio_getNombre(auxEnvio,&bufferZona);
        Envio_getIdCamion(auxEnvio,&bufferIdCamion);
        Envio_getZona(auxEnvio,&bufferZona);
        Envio_getKm(auxEnvio,&bufferkm);
        Envio_getTipoentrega(auxEnvio,&bufferTipo);

        printf("%d - %s - %d - %s- %d- %d \n",bufferId,bufferNombre,bufferIdCamion,bufferZona,bufferkm,bufferTipo);


    }
    return 1;
}

int fn_calcEnvio(void* envio){
    int ret=0;
    int km;
    int idEnv;
    int tipoEntrega;
    if(envio!=NULL){
        Envio_getKm((Envio*)envio, &km);
        Envio_getIdEnvio((Envio*)envio,&idEnv);
        Envio_getTipoentrega((Envio*)envio,&tipoEntrega);
        int costo;
        if(km>50){
            costo=50*km;
        }else{
            costo=100*km;
        }
            switch(tipoEntrega){
                case 0:
                costo=costo+250;
                break;

                case 1:
                costo=costo+420;
                break;

                case 2:
                costo=costo+75;
                break;
            }
        costo2=costo;
        printf("Id de envio:%d, costo: %d \n",costo,idEnv);
        ret=1;
    }
    return ret;

}

int fn_filZona(void* envio){
    int ret=0;
    char* auxZona[120];
    Envio_getZona((Envio*)envio,auxZona);
    if(envio!= NULL && (strcmp(auxZona,zona)==0)){
        ret=1;
        fn_calcEnvio(envio);
        //cont_saveCsv("data.csv", envio, costo2);
        costo2;
    }
    return ret;



}

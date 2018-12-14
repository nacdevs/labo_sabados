#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"


int cont_loadCsv(char* path , LinkedList* pList)
{
    int ret=-1;
    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    if(parser_Envios(pArchivo, pList)==0){
        ret=0;
    }
    fclose(pArchivo);

    return ret;
}

int cont_saveCsv(char* path , Envio* envio,int costo)
{
    int ret=-1;
    FILE*pArchivo;
    pArchivo=fopen(path,"a");
    Envio* auxEnvio= envio;
    char auxNombre[128];
    char auxZona[128];
    int auxId;
    int auxIdCamion;
    int auxKm;
    int auxTipo;
    int i;

    if(pArchivo!=NULL){

                Envio_getIdEnvio(auxEnvio,&auxId);
                Envio_getNombre(auxEnvio,&auxNombre);
                Envio_getIdCamion(auxEnvio,&auxIdCamion);
                Envio_getKm(auxEnvio,&auxKm);
                Envio_getTipoentrega(auxEnvio,&auxTipo);

                fprintf(pArchivo,"\n%d,%s,%d,%d,%d,%d\n",auxId,auxNombre,auxIdCamion,auxKm,auxTipo,costo);



            ret=0;

        }
        fclose(pArchivo);
    return ret;

}

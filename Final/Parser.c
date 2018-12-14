#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"

int parser_Envios(FILE* pFile , LinkedList* pList)
{
    int ret=-1;
    char auxBufferId[50];
    int bufferId;

    char bufferNombre[125];

    char auxBufferIdCamion[50];
    int bufferIdCamion;

    char auxBufferKm[50];
    int bufferKm;

    char auxBufferTipoEntrega[50];
    int bufferTipoEntrega;

    char bufferZona[50];

    int flagFirstLine=0;
    Envio* auxEnvio;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxBufferId,bufferNombre,auxBufferIdCamion,bufferZona,auxBufferKm,auxBufferTipoEntrega)==4 && flagFirstLine!=0)
            {
                bufferId= atoi(auxBufferId);
                bufferIdCamion = atoi(auxBufferIdCamion);
                bufferKm= atoi(auxBufferKm);
                bufferTipoEntrega= atoi(auxBufferTipoEntrega);
                auxEnvio=Envio_newConParametros(bufferId,bufferNombre,auxBufferIdCamion,bufferZona,bufferKm,bufferTipoEntrega);
                ll_add(pList,(Envio*)auxEnvio);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}

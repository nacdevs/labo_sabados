#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Envio.h"

int parser_Envios(FILE* pFile , LinkedList* pList){
    int ret=-1;

    char auxBufferIdEnvio[100];
    int bufferIdEnvio;


    char bufferNombreProd[100];

    char auxBufferIdCam [100];
    int bufferIdCam;

    char bufferZona[100];

    char auxBufferKm[25];
    int bufferKm;

    char auxBufferTipo [25];
    int bufferTipo;


    int flagFirstLine=0;
    Envio* envio;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxBufferIdEnvio, bufferNombreProd,auxBufferIdCam,bufferZona,auxBufferKm,auxBufferTipo)==6 && flagFirstLine!=0)
            {

                bufferIdEnvio=atoi(auxBufferIdEnvio);
                bufferIdCam=atoi(auxBufferIdCam);
                bufferKm=atoi(auxBufferKm);
                bufferTipo=atoi(auxBufferTipo);

                envio=Envio_newConParametros(bufferIdEnvio,bufferNombreProd,bufferIdCam,bufferZona,bufferKm,bufferTipo,0);
                ll_add(pList,envio);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}

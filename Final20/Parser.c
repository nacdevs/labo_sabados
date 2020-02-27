#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Struct.h"
#include "fichajes.h"

int parser_Empleados(FILE* pFile , LinkedList* pList){
    int ret=-1;

    char auxBufferId[50];
    int bufferId;


    char bufferNombre[50];

    char bufferApellido[50];


    char auxBufferDNI [50];
    int bufferDNI;



    char auxBufferClave[50];



    int flagFirstLine=0;
    Struct* empleado;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxBufferId, bufferNombre, bufferApellido,auxBufferDNI,auxBufferClave)==5 && flagFirstLine!=0)
            {

                bufferId=atoi(auxBufferId);
                bufferDNI=atoi(auxBufferDNI);

                empleado=Struct_newConParametros(bufferId,bufferNombre,bufferApellido,bufferDNI,auxBufferClave);

                ll_add(pList,empleado);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}




int parser_Fichaje(FILE* pFile , LinkedList* pList){
    int ret=-1;

    char auxBufferIdFic[50];
    int bufferIdFic;


    char auxBufferIdEmp[50];
    int bufferIdEmp;


    char auxBufferhora [50];
    int bufferhora;


    char auxBufferminutos [50];
    int bufferminutos;


    char auxBufferdia [50];
    int bufferdia;


    char auxBufferMes [50];
    int bufferMes;


    char auxBufferAnio [50];
    int bufferAnio;


    char auxBufferIO[50];



    int flagFirstLine=0;
    Fichajes* fichaje;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxBufferIdFic,auxBufferIdEmp,auxBufferhora,auxBufferminutos,auxBufferdia,auxBufferMes,auxBufferAnio,auxBufferIO)==8 && flagFirstLine!=0)
            {

                bufferIdEmp=atoi(auxBufferIdEmp);
                bufferIdFic=atoi(auxBufferIdFic);
                bufferhora=atoi(auxBufferhora);
                bufferminutos=atoi(auxBufferminutos);
                bufferdia=atoi(auxBufferdia);
                bufferMes=atoi(auxBufferMes);
                bufferAnio=atoi(auxBufferAnio);




                fichaje=fichajes_newConParametros(bufferIdFic,bufferIdEmp,bufferhora,bufferminutos,bufferdia,bufferMes,bufferAnio,auxBufferIO);

                //empleado=Empleado_newConParametros(bufferId,bufferNombre,bufferApellido,bufferDNI,auxBufferClave);

                ll_add(pList,fichaje);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
                ret=0;
            }

        } while(!feof(pFile));




    }
    return ret;
}

int parser_FromBinary(FILE* pFile , LinkedList* pList)
{   int ret=-1;
     Struct* pStruct;
     if(pList!=NULL){

    do{
        pStruct = Struct_new();
        if(pStruct!=NULL){
            fread(pStruct,sizeof(Struct),1,pFile);
            ll_add(pList, pStruct);
            ret=0;
        }

    }while(!feof(pFile));
    }
    return ret;

}

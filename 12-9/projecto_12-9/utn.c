#include <stdio.h>
#include <stdlib.h>


int utn_getFloat(float* pFloat, char* pMsg, float min, float max, int reintentos );

int isFloat(char* pBuffer){

    return 1;
}



static int getFloat(float* pBuffer){
    char bufferString [4096];
    int retorno= -1;
    __fpurge(stdin);
    fgets(bufferString,sizeof(bufferString), stdin);

    if(scanf("%s",bufferString)==1 && isFloat(bufferString)){

        *pBuffer = atof(bufferString);
        retorno=0;

    }

    return scanf("%f",pBuffer);
}


int utn_getFloat(float* pFloat, char* pMsg, float min, float max, int reintentos ){

    int retorno=-1;
    int buffer;
    if(pFloat != NULL && msg!= NULL &&  min<=max && reintentos>=0){

        do{
            reintentos--;
            printf("%s",msg);
            if(getFloat(&buffer)==0 && buffer>=min && buffer<= max ){
                retorno=0;
                *pFloat=buffer;
                break;

            }else{
            printf(msg);
            }


        }while(reintentos>=0);

    }

    return retorno;

}

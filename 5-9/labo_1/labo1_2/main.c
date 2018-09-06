#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int edad;
    int valorMaximo;
    char nombre[20]={'\0'};
    int edades[CANTIDAD_EMPLEADOS];
    int i=0;

    for(i=0; i< CANTIDAD_EMPLEADOS; i++){

    if(utn_getEntero(&edades[i],2,"\nEdad?:","\nEdad fuera de rango",1,99)){

        }

    }

    mostrarArray(&edades, CANTIDAD_EMPLEADOS);
    mostrarMaximo(&valorMaximo,&edades,CANTIDAD_EMPLEADOS);
    printf("El valor maximo es %d\n",valorMaximo);
    if(initArray(&edades,CANTIDAD_EMPLEADOS,0)==0){
        printf("Array cargado....\n%d",edades[2]);

    }

    return 0;
}
    int mostrarMaximo(int* pMax, int* pArray, int limite){
        int i;
        int maximo;

        //Chuequea que no sea -1

        for(i=0; i<limite;i++){
            int valor= pArray[i];

            if(maximo<valor){
                maximo=valor;
            }
        }
        *pMax=maximo;

    }



    int initArray(int* pArray, int limite, int valor){
        int retorno=-1;
        int j;
        if(pArray != NULL && limite >0){

            for(j=0; j<limite;j++){
                pArray[j]=valor+1;
            }

            retorno=0;
        }

        return retorno;

    }





    int mostrarArray (int* pArray, int limite){

        int i=0;

        for(i=0; i<limite; i++){
          int valor=pArray[i];

          printf("La edad es %d\n", valor);
        }

    }

    /*if((utn_getEntero(&edad,3, "Edad?", "Error",0,199)==0) && (utn_getNombre(&nombre,3)==0)){
        printf("La edad es %d",edad);
        printf("\nEl nombre es %s",nombre);
        printf(&nombre+1);
        printf(&nombre+2);
    }*/

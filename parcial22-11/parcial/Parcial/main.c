#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "func.h"
#include "Informe.h"

int main()
{
    LinkedList* lista= ll_newLinkedList();
    printf("--Generador Informe--\n\n");
    if(fn_ventaCsv("data.csv",lista)==0){
        printf("->Lista cargada\n");
    }else{
        printf("No se pudo cargar la lista\n");
    }

    int sumaCantidades=ll_count(lista,fn_sumaTotal);
    int mayor10=ll_count(lista,fn_sumaMayor1);
    int mayor20=ll_count(lista,fn_sumaMayor2);
    int sumaLCD=ll_count(lista,fn_LCD);
    printf("Cantidades: %d \n",sumaCantidades);
    printf("Ventas mas de 10k: %d \n",mayor10);
    printf("Ventas mas de 20k: %d \n",mayor20);
    printf("Cantidad de LCD: %d \n",sumaLCD);
    if(inf_aTxt("informe.txt",lista)==0){
        printf("\nGenerado --> 'informe.txt'");
    }else{
        printf("No se pudo generar el archivo de informe");
    }



    return 0;
}

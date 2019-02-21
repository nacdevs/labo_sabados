#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "func.h"

int inf_aTxt(char* path, LinkedList* list){
    int ret=-1;
    FILE* pFile;
    pFile=fopen(path,"w");

    if(list!=NULL&&ll_len>0&&pFile!=NULL){
    fprintf(pFile,"*******Informe de Ventas********\n");
    fprintf(pFile,"Cantidad de unidades vendidas totales: %d\n",ll_count(list,func_cantidadTotal));
    fprintf(pFile,"Cantidad de ventas por monto mayor a $10000:%d\n",ll_count(list,func_ventaMayor10k));
    fprintf(pFile,"Cantidad de ventas por monto mayor a $20000:%d\n",ll_count(list,func_ventaMayor20k));
    fprintf(pFile,"Cantidad de TVs LCD vendidas:%d",ll_count(list,func_ventaLCD));

    }


    return ret;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "func.h"

/** \brief Genera el archivo informe.txt con los datos de la lista
 *
 * \param chra* path Ubicacion donde guardar el archivo
 * \param LinkedList* lista Lista
 * \return Person* Retorna -1 en error o en caso contrario 0
 *
 */

int inf_aTxt(char* path, LinkedList* lista){
    int ret=-1;
    int len= ll_len(lista);
    FILE* pFile;
    pFile=fopen(path,"w");

    if(lista!=NULL&& len>0 && pFile!=NULL){
    fprintf(pFile,"*************************\nInforme de ventas\n*************************\n\n");
    fprintf(pFile,"Cantidad de unidades vendidas totales: %d\n",ll_count(lista,fn_sumaTotal));
    fprintf(pFile,"Cantidad de ventas por un monto mayor a $10000: %d\n",ll_count(lista,fn_sumaMayor1));
    fprintf(pFile,"Cantidad de ventas por un monto mayor a $20000: %d\n",ll_count(lista,fn_sumaMayor2));
    fprintf(pFile,"Cantidad de TVs LCD vendidas:%d\n\n",ll_count(lista,fn_LCD));
    fprintf(pFile,"********************");
    ret=0;
    }
    fclose(pFile);
    return ret;

}

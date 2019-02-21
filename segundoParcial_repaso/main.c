#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Informe.h"
#include "func.h"


int main()
{
    LinkedList* list = ll_newLinkedList();
    func_readCSV("data.csv",list);
    if(inf_aTxt("informe.txt",list)==0){
        printf("Informe generado");
    }
    return 0;
}

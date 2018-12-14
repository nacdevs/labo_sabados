#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.c"
#include "Parser.c"


int main()
{

    int option = 0;
    char path[80];
    LinkedList* listaEnvios = ll_newLinkedList();
    do{
    utn_getInt(&option,"Menu: \n1. Cargar Archivo.\n2. Imprimir envios.\n3. Calcular costos \n4. Generar Archivos de costos para zona\n 5.Imprimir lista de zonas \n6. Salir","Ingrese opcion valida\n",0,6,1500);
        switch(option)
        {
            case 1:
                //utn_getLetras(&path,140,3,"Ingrese ruta\n","Ingrese otra ruta");
                if(cont_loadCsv("DATA_2F.csv",listaEnvios)==0){
                    system("clear");
                    printf("Lista cargada correctamente\n");
                }else{
                    system("clear");
                    printf("Error\n");
                }
                break;


           case 2:
                fn_listEnvio(listaEnvios);
                break;


           case 3:

                break;

           case 4:

                break;

           case 5:

                 break;

           case 6:

                break;

        }
    }while(option != 6);


    return 0;
}

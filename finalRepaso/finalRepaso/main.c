#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "func.h"
int main()
{
    int option = 0;
    char path[80];
    char txt [75];
    char ext [50];
    LinkedList* listaEnvios = ll_newLinkedList();
    do{
    utn_getInt(&option,"Menu: \n1. Cargar Archivo.\n2. Imprimir envios.\n3. Calcular costos \n4. Generar Archivos de costos para zona\n 5.Imprimir lista de zonas \n6. Salir","Ingrese opcion valida\n",0,6,1500);
        switch(option)
        {
            case 1:
                //utn_getLetras(&path,140,3,"Ingrese ruta\n","Ingrese otra ruta");
                if(func_readCSV("DATA_2F.csv",listaEnvios)==0){
                    system("clear");
                    printf("Lista cargada correctamente\n");
                }else{
                    system("clear");
                    printf("Error\n");
                }
                break;


           case 2:
                fn_printEnvios(listaEnvios);
                break;


           case 3:
                ll_map(listaEnvios,fn_calCosto);
                fn_printEnviosConCosto(listaEnvios);
                break;

           case 4:

                utn_getLetras(&txt,50,3,"Ingrese zona:","La zona deben ser letras hasta 50 caracteres");
                setZona(&txt);
                LinkedList* listafiltrada=ll_filter(listaEnvios,fn_filtraZona);
                fn_printEnviosConCosto(listafiltrada);
                strcpy(&ext,".csv");
                strcat(&txt,&ext);
                func_writeCSV(&txt,listafiltrada);
                break;

           case 5:

                 break;

           case 6:

                break;

        }
    }while(option != 6);



    return 0;
}

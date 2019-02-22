#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "func.h"


int main()
{

    int option = 0;
    char path[80];
    char txt [75];
    char ext [50];
    char nombre[50];
    char apellido[50];
    int dni;
    int id;
    int dia;
    int mes;

    char clave [50];
    Empleado* emp;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFichajes = ll_newLinkedList();
    if(func_readCSV("empleados.csv",listaEmpleados)==0){
         printf("lista cargada\n");
    }
    if(func_readCSVF("fichajes.csv",listaFichajes)==0){
        printf("lista cargada\n");
    }

     do{
    utn_getInt(&option,"Menu: \n1. Alta empleado.\n2. Modificacion empleado.\n3. Baja empleado\n4.Listar empleado\n 5.Fichaje empleados \n6. Informar empleados","Ingrese opcion valida\n",0,6,1500);
        switch(option)
        {
            case 1:
                utn_getLetras(&nombre,140,3,"Ingrese nombre\n","Debe ser letras");
                utn_getLetras(&apellido,140,3,"Ingrese apellido\n","Debe ser letras");
                utn_getLetras(&clave,140,3,"Ingrese clave\n","Debe ser letras");
                utn_getInt(&dni,"Ingrese un dni\n","Ingrese opcion valida\n",0,99999999,1500);
                Empleado* empleado= Empleado_newConParametros(-1,&nombre,&apellido,dni,&clave);
                ll_add(listaEmpleados,empleado);

                break;


           case 2:
                utn_getInt(&id,"Ingrese un ID\n","Ingrese opcion valida\n",0,999999999,1500);
                 fn_setId(&id);
                 utn_getLetras(emp->nombre,140,3,"Ingrese nombre\n","Debe ser letras");
                utn_getLetras(emp->apellido,140,3,"Ingrese apellido\n","Debe ser letras");
                utn_getLetras(emp->clave,140,3,"Ingrese clave\n","Debe ser letras");
                utn_getInt(emp->dni,"Ingrese un dni\n","Ingrese opcion valida\n",0,99999999,1500);
                //FILTER


                ll_map(listaEmpleados,fn_filterById);
                fn_setEmpleado(emp);

                break;


           case 3:
                 utn_getInt(&id,"Ingrese un ID\n","Ingrese opcion valida\n",0,999999999,1500);
                 fn_setId(&id);
                 ll_map(listaEmpleados,fn_filterById);
                 fn_delete();
                /*ll_map(listaEnvios,fn_calCosto);
                fn_printEnviosConCosto(listaEnvios);*/
                break;

           case 4:
                 utn_getInt(&dia,"Ingrese un dia\n","Ingrese opcion valida\n",0,999999999,1500);
                 utn_getInt(&mes,"Ingrese un mes\n","Ingrese opcion valida\n",0,999999999,1500);

                 fn_setDia(&dia);
                 fn_setMes(&mes);

                 ll_map(listaFichajes,fn_filtrarFecha);

                break;

           case 5:

                 break;

           case 6:

                break;

        }
    }while(option != 6);




    return 0;
}

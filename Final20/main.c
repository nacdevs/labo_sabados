#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
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
    int mes,salary;

    char clave [50];
    Struct* emp;
    LinkedList* lista1 = ll_newLinkedList();//Emp
    LinkedList* lista2 = ll_newLinkedList();//Fichaje
    if(func_readCSV("empleados.csv",lista1)==0){
         printf("lista cargada\n");
    }
    if(func_readCSVF("fichajes.csv",lista2)==0){
        printf("lista cargada\n");
    }

     do{
    utn_getInt(&option,"Menu: \n1. Alta empleado.\n2. Modificacion empleado.\n3. Baja empleado\n4.Listar empleado\n 5.Fichaje empleados \n6. Informar empleados","Ingrese opcion valida\n",0,6,1500);
        switch(option)
        {
            case 1:
            utn_getLetras(&nombre,50,15,"Ingrese nombre:\n","Error");
            utn_getLetras(&apellido,50,15,"Ingrese apellido:\n","Error");
            //utn_getInt(&sector,"Ingrese sector:\n","Error\n",1,99999,15);
            utn_getInt(&dni,"Ingrese un dni\n","Ingrese opcion valida\n",0,99999999,1500);
            utn_getLetras(&clave,50,15,"Ingrese clave:\n","Error");

            //utn_getFloat(&salary,"Ingrese salario en numero con punto (ej 4.5)\n","Error\n",1,999999999,5);
            Struct* empleado= Struct_newConParametros(-1,&nombre,&apellido,dni,&clave);
            ll_add(lista1,empleado);


            break;

            case 2:
            utn_getInt(&id,"Ingrese Id:\n","Error\n",1,99999,15);

            utn_getLetras(&nombre,50,15,"Ingrese nombre:\n","Error");
            utn_getLetras(&apellido,50,15,"Ingrese apellido:\n","Error");
            //utn_getInt(emp.sector,"Ingrese sector:\n","Error\n",1,99999,15);
            //utn_getFloat(&salary,"Ingrese salario en numero con punto (ej 4.5)\n","Error\n",1,999999999,5);
            utn_getInt(&dni,"Ingrese un dni\n","Ingrese opcion valida\n",0,99999999,1500);
            utn_getLetras(&clave,50,15,"Ingrese clave:\n","Error");

            Struct* empleado2= Struct_newConParametros(-1,&nombre,&apellido,dni,&clave);
            fn_setId(&id);
            fn_setEmpleado(empleado2);
            ll_map(lista1,fn_filterById);


            break;

            case 3:
            utn_getInt(&id,"Ingrese Id:\n","Error\n",1,99999,15);

            fn_removeStruct(lista1,id);

            break;


           case 4:
                 utn_getInt(&dia,"Ingrese un dia\n","Ingrese opcion valida\n",0,999999999,1500);
                 utn_getInt(&mes,"Ingrese un mes\n","Ingrese opcion valida\n",0,999999999,1500);

                 fn_setDia(&dia);
                 fn_setMes(&mes);

                 //ll_map(listaFichajes,fn_filtrarFecha);

                break;

           case 5:
                fn_printStruct(lista1);
                fn_writeCSV("emp2.csv",lista1);
                 break;

           case 6:

                break;

        }
    }while(option != 6);




    return 0;
}

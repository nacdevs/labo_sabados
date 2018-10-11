#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "cliente.c"
#include "afiche.c"
#include "Funciones.h"

int main()
{
    int option=0;
    Cliente arrayCliente[100];
    Afiche arrayAfiche[1000];
    cl_initArray(&arrayCliente,100);
    af_initArray(&arrayAfiche,1000);
    cl_altaForzada(&arrayCliente,100,"Carlos","Ocampo",234345);
    cl_altaForzada(&arrayCliente,100,"Enrique","Perez",323232);
    cl_altaForzada(&arrayCliente,100,"joey","Lopez",332235);
    cl_altaForzada(&arrayCliente,100,"Juan","Perez",9989796);
    cl_altaForzada(&arrayCliente,100,"Pepe","Palazzo",6656556);

    af_altaForzada(&arrayAfiche,1000,1,24,1,"img1");
    af_altaForzada(&arrayAfiche,1000,3,65,2,"afiche");
    af_altaForzada(&arrayAfiche,1000,2,43,3,"public");
    af_altaForzada(&arrayAfiche,1000,1,20,4,"imagen");
    af_altaForzada(&arrayAfiche,1000,1,10,4,"prop");

    //informaDeud(&arrayAfiche,1000);
    calculaVentas(&arrayAfiche,1000,0);
    af_zonaAfi(&arrayAfiche,1000);

    while(option != 8){
    int id;
    int index;

    utn_getInt(&option,"Ingrese una opcion: \n1.Alta Cliente\n2.Modificar datos de cliente\n3.Baja de Cliente\n4.Vender afiches\n5.Editar venta\n6.Cobrar Venta\n7.Imprimir Clientes\n8.Salir\n","Ingrese opcion valida\n",0,8,1500);
        switch(option){
        case 1:
            if(cl_altaCliente(&arrayCliente,100)==0){
                system("clear");
                printf("Alta con exito\n\n");
                }else{
                system("clear");
                printf("Error en el alta\n\n");
                }
            break;
        case 2:
            utn_getInt(&id,"Ingrese ID de cliente a modificar\n","El numero debe ser un entero\n",0,99,3);
            if(cl_modif(&arrayCliente,100,id)==0){
                system("clear");
                printf("Modificacion exitosa\n\n");
                }else{
                system("clear");
                printf("Error al modificar\n\n");
                }
            break;
        case 3:
            if(cl_bajaCliente(&arrayCliente,100)==0){
                system("clear");
                printf("Baja con exito\n\n");
                }else{
                system("clear");
                printf("Error en el baja\n\n");
                }
            break;
        case 4:
            utn_getInt(&id,"Ingrese ID cliente\n","El cliente debe ser un numero entero (0-100)\n",0,100,5);
            int verif=cl_busId(&arrayCliente,100,id);
            if(verif!=-1){
                system("clear");
                id=af_ventAfiche(&arrayAfiche,1000,verif);
                printf("\nID de venta:%d\n",id);
            }else{
                system("clear");
                printf("\nEl cliente no existe\n");
            }
            break;
        case 5:
            af_ventas(&arrayAfiche,1000,1);
            utn_getInt(&id,"Ingrese ID de venta a modificar\n","El numero debe ser un entero de 0 a 1000\n",0,1000,3);
            index=af_busId(&arrayAfiche,1000,id);
             if( af_editVenta(&arrayAfiche,1000,index)==0){
                system("clear");
                printf("Modificacion exitosa\n\n");
                }else{
                system("clear");
                printf("Error al modificar\n\n");
                }
            break;
        case 6:
            af_cobrar(&arrayAfiche,1000);
            break;
        case 7:
            cl_print(&arrayCliente,100,&arrayAfiche,1000);
            break;
        case 8:
            system("clear");
            printf("Programa terminado");

    }
    //system("clear");

    }




    return 0;
}

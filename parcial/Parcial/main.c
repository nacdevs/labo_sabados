#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "cliente.c"
#include "afiche.c"
#include "Informes.c"


int main()
{
    int option=0;
    Cliente arrayCliente[100];
    Afiche arrayAfiche[1000];
    cl_initArray(arrayCliente,100);
    af_initArray(arrayAfiche,1000);
    cl_altaForzada(arrayCliente,100,"Carlos","Ocampo",234345);
    cl_altaForzada(arrayCliente,100,"Enrique","Perez",323232);
    cl_altaForzada(arrayCliente,100,"joey","Lopez",332235);
    cl_altaForzada(arrayCliente,100,"Juan","Perez",9989796);
    cl_altaForzada(arrayCliente,100,"Pepe","Palazzo",6656556);
//
    af_altaForzada(arrayAfiche,1000,1,524,1,"img1");
    af_altaForzada(arrayAfiche,1000,3,65,2,"afiche");
    af_altaForzada(arrayAfiche,1000,2,53,4,"public");
    af_altaForzada(arrayAfiche,1000,1,20,4,"imagen");
    af_altaForzada(arrayAfiche,1000,1,510,4,"prop");


    while(option != 9){
    int id;
    int index;
    char nombre[52];
    char apellido[52];
    int cuit;
    int clienteMenosVentasACobrar;
    int clientesMenosVentasCobradas;
    int clienteConMenosAf;
    int clientConMasAfACobrar;
    int cantidadMas500;
    int clienteMenosVentas;
    int promedio;

    utn_getInt(&option,"Ingrese una opcion: \n1.Alta Cliente\n2.Modificar datos de cliente\n3.Baja de Cliente\n4.Vender afiches\n5.Editar venta\n6.Cobrar Venta\n7.Imprimir Clientes\n8.Informe\n9.Salir\n","Ingrese opcion valida\n",0,9,1500);
        switch(option){
        //Alta de cliente
        case 1:

            if(cl_altaCliente(arrayCliente,100)==0){
                system("clear");
                printf("Alta con exito\n\n");
                }else{
                system("clear");
                printf("Error en el alta\n\n");
                }
            break;
        //Modificar datos cliente
        case 2:

            utn_getInt(&id,"Ingrese ID de cliente a modificar\n","El numero debe ser un entero\n",0,99,3);
            if(cl_modif(arrayCliente,100,id)==0){
                system("clear");
                printf("Modificacion exitosa\n\n");
                }else{
                system("clear");
                printf("Error al modificar\n\n");
                }
            break;
        //Dar de baja cliente
        case 3:

            if(cl_bajaCliente(arrayCliente,100)==0){
                system("clear");
                printf("Baja con exito\n\n");
                }else{
                system("clear");
                printf("Error en el baja\n\n");
                }
            break;
        //Vender Afiches
        case 4:

            utn_getInt(&id,"Ingrese ID cliente\n","El cliente debe ser un numero entero (0-100)\n",0,100,5);
            int verif=cl_busId(arrayCliente,100,id);
            if(verif!=-1){
                system("clear");
                id=af_ventAfiche(arrayAfiche,1000,verif);
                printf("\nID de venta:%d\n",id);
            }else{
                system("clear");
                printf("\nEl cliente no existe\n");
            }
            break;
        //Editar Venta
        case 5:
            system("clear");
            af_ventas(arrayAfiche,1000,1);
            utn_getInt(&id,"Ingrese ID de venta a modificar\n","El numero debe ser un entero de 0 a 1000\n",0,1000,3);
            index=af_busId(arrayAfiche,1000,id);
             if( af_editVenta(arrayAfiche,1000,index)==0){
                system("clear");
                printf("Modificacion exitosa\n\n");
                }else{
                system("clear");
                printf("Error al modificar\n\n");
                }
            break;

        //Cobra venta
        case 6:
            system("clear");
            af_cobrar(arrayAfiche,1000);
            break;

        //Imprime Clientes
        case 7:
            system("clear");
            cl_print(arrayCliente,100,arrayAfiche,1000);
            break;

        //Imprime Informe
        case 8:

            system("clear");
            clienteMenosVentasACobrar=inf_calculaVentas(arrayAfiche,1000,0);
            if(clienteMenosVentas!=-1){
                inf_idToName(arrayCliente,100,nombre,apellido,&cuit,clienteMenosVentasACobrar);
                printf("a.El cliente con menos ventas a cobrar es:\nNombre:%s\nApellido:%s\nCUIT:%d\nID Cliente:%d\n\n",nombre,apellido,cuit,clienteMenosVentasACobrar);
            }else{
                printf("Error\n");
            }


            clientesMenosVentasCobradas=inf_calculaVentas(arrayAfiche,1000,1);
            if(clientesMenosVentasCobradas!=-1){
                 inf_idToName(arrayCliente,100,nombre,apellido,&cuit, clientesMenosVentasCobradas);
                 printf("b.El cliente con menos ventas cobradas es:\nNombre:%s\nApellido:%s\nCUIT:%d\nID Cliente:%d\n\n",nombre,apellido,cuit, clientesMenosVentasCobradas);
            }else{
                printf("Error\n");
            }


            clienteMenosVentas=inf_clienteMenosVentas(arrayAfiche,1000);
             if(clienteMenosVentas!=-1){
                inf_idToName(arrayCliente,100,nombre,apellido,&cuit,clienteMenosVentas);
                printf("c.El cliente con menos ventas es:\nNombre:%s\nApellido:%s\nCUIT:%d\nID Cliente:%d\n\n",nombre,apellido,cuit,clienteMenosVentas);
            }else{
                printf("Error\n");
            }


            inf_zonaAfi(arrayAfiche,1000);


            clienteConMenosAf = inf_menosAfiches(arrayAfiche,1000);
            if(clienteConMenosAf!=-1){
                inf_idToName(arrayCliente,100,nombre,apellido,&cuit,clienteConMenosAf);
                printf("e.El cliente que compró menos afiche es:\nNombre:%s\nApellido:%s\nCUIT:%d\nID Cliente:%d\n\n",nombre,apellido,cuit,clienteConMenosAf);
            }else{
                printf("Error\n");
            }

            clientConMasAfACobrar=inf_masAfACobrar(arrayAfiche,1000);
            if(clientConMasAfACobrar!=-1){
                inf_idToName(arrayCliente,100,nombre,apellido,&cuit,clientConMasAfACobrar);
                printf("f.El cliente con mas afiches a cobrar es:\nNombre:%s\nApellido:%s\nCUIT:%d\nID Cliente:%d\n\n",nombre,apellido,cuit,clientConMasAfACobrar);
            }else{
                printf("Error\n"); }


            cantidadMas500=inf_compranMas500(arrayAfiche,1000);
             if(cantidadMas500!=-1){
                printf("g.La cantidad de clientes que compraron mas de 500 afiches es %d\n\n",cantidadMas500);
            }else{
                printf("Error\n");}

            inf_cantAfichePorZona(arrayAfiche,1000);


            promedio=inf_getSumaAfiches()/cl_sumaCliente(arrayCliente,100);
             if(promedio!=-1){
                printf("i.El promedio de afiches por cliente es %d\n\n",promedio);
            }else{
                printf("Error\n"); }


            inf_listaVentasPorZona(arrayAfiche,1000);


            break;

        case 9:
        printf("Programa terminado");
        break;
    }
    //system("clear");

    }




    return 0;
}




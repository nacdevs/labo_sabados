#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Cliente.c"
#define CLIENTES 100

int main()
{
    printf("Hello world!\n");
    Cliente* aux;
    Cliente* arrayClientes[CLIENTES];
    char auxNombre[100];

    cli_inicializarArray(arrayClientes,CLIENTES);
    aux=cli_newCliente();
    int indexVacio=cli_buscarLugarVacio(arrayClientes,CLIENTES);

    if(aux!=NULL){
        cli_setNombre(aux,"Juan");
        arrayClientes[indexVacio]=aux;


    }
        cli_getNombre(aux,auxNombre);
        printf("%s",auxNombre);


    /*int i;
    for(i=0;i<CLIENTES;i++){
        arrayClientes[i]=NULL;
        cli_setApellido(arrayClientes[i],"Apellidoooooo");
    }

     for(i=0;i<CLIENTES;i++){
        char aux[100];
        strcpy(aux,arrayClientes[i]->apellido);
        printf("%s",aux);

    }
*/

    return 0;
}

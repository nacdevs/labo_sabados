#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

void prod_inicializar (Producto* productos, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        productos[i].isEmpty=1;

    }

}

/*int prod_alta(Producto* productos, int index, int len)

{
    char nombreAux[32];
    char descAux[128];
    float precioAux;

    if(utn_getNombre(nombreAux))
    {
        if(utn_getString(descAux))
        {
            if(utn_getFloat(precioAux))
            {
                // copio a campos
                strncpy(productos[index].nombre,nombreAux,32);
                strncpy(productos[index].descripcion,descAux,128);
                productos[index].precio=precioAux;
                productos[index].isEmpty=0;
            }
        }
    }

}

void prod_print(Producto* ps, int index)
{
    printf("%s %s %f\n", ps[index].nombre, ps[index].descripcion, ps[index].precio);
}

int prod_getEmptyIndex(Producto* productos)
{

}*/ //FALTAN LAS BIBLIOTECAS


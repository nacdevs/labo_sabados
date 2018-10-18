#include <stdio.h>
#include <stdlib.h>
#include "empleado.c"
int main()
{
    Empleado* listaEmpleados[1000];
    int qtyEmpleados=0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++){
        sprintf(auxiliar,"Juan_%d",i);
        listaEmpleados[i] = empleado_newParametros(auxiliar,"Perez",1.45);
        qtyEmpleados++;

    }

    for(i=0;i<qtyEmpleados;i++){
        empleado_print(listaEmpleados[i]);

    }

    /*Empleado* auxiliar;
    float alt = 1.45;
    auxiliar= empleado_newParametros("Juan","Perez",alt);
    empleado_print(auxiliar);*/
    return 0;
}

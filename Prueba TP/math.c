#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

/*
Funcionalidad: Funcion encargada de pedir un numero y almacenarlo.
Parametros: Recibe una direcciòn de memoria (pNumero) donde va a
almacenar el numero ingresado.
Retorno: No hay retorno.
*/

void ingresarNumero(float* pNumero)
{
    printf("Ingrese un numero: ");
    __fpurge(stdin);
    scanf("%f", pNumero);
}

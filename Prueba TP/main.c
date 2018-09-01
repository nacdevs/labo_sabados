#include <stdio.h>
#include <stdlib.h>
#include "math.h"


int main()
{
    int flagSalida = 1, opcion, flagA = 0, flagB = 0;
    float numA, numB;

    do
    {
        if (flagA == 1)
        {
            printf("1. Ingresar 1er operando (A=%.2f)\n", numA);
        } else
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }
        if (flagB == 1)
        {
            printf("2. Ingresar 2do operando (B=%.2f)\n", numB);
        } else
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }
        printf("3. Calcular\n");
        printf("4. Informar\n");
        printf("5. Salir\n");
        printf("\nIngrese una opcion del menu:");
        __fpurge(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarNumero(&numA);
            flagA = 1;
            break;
        case 2:
            ingresarNumero(&numB);
            flagB = 1;
            break;
        case 3:
            if (flagA == 1 && flagB == 1)
            {
                printf("Calculado..");
            } else
            {
                printf("Ingrese los numeros!");
            }
            break;
        case 4:
            printf("RESULTADOS");
            break;
        case 5:
            printf("Saliendo...");
            flagSalida = 0;
            break;
        default:
            printf("Ingrese una opcion valida!\n");
        }

        __fpurge(stdin);
        printf("\nIngrese ENTER para continuar...");
        getchar();
        system("clear");
    }
    while(flagSalida != 0);

    return 0;
}


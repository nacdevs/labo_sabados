#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int primerOperando;
    int segundoOperando;

    printf("Ingresar 1er operando\n");
    scanf("%d", &primerOperando);
    printf("Ingresar 2do operando\n");
    scanf("%d", &segundoOperando);

    dividir(&primerOperando,&segundoOperando);
    //restar(&primerOperando,&segundoOperando);
    //multiplicar(&primerOperando,&segundoOperando);
    //dividir(&primerOperando,&segundoOperando);

    //printf("%d",primerOperando);
    //printf("\n%d",segundoOperando);

    ////system("clear") al final del codigo para limpiar la pantalla


    return 0;
}

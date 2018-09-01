#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
void sumar(int* pOperador1, int* pOperador2);
void restar(float* pOperador1, float* pOperador2);
void multiplicar(float* pOperador1, float* pOperador2);
void dividir(float* pOperador1, float* pOperador2);

/*

/////NO TE OLVIDES DE HACER EL ARCHIVO CON LOS HEADERSSSS!!!!//

*/
void sumar(int* pOperador1, int* pOperador2){
 int operador1 = *pOperador1;
 int operador2 = *pOperador2;
 int suma = operador1+operador2;
 printf("La suma es %d \n", suma);
}

void restar(float* pOperador1, float* pOperador2){
    float operador1 = *pOperador1;
    float operador2 = *pOperador2;

    float resta = operador1-operador2;
    printf("La resta es %f \n", resta);

}

void multiplicar(float* pOperador1, float* pOperador2){

    float operador1 = *pOperador1;
    float operador2 = *pOperador2;

    float multiplicar = operador1*operador2;
    printf("La multiplicacion es %f \n", multiplicar);
}

void dividir(float* pOperador1, float* pOperador2){

    int retorno;
    float operador1 = *pOperador1;
    float operador2 = *pOperador2;

    if(operador2==0){
        printf("El segundo operador no pueden ser cero");
        retorno=-1;
    }else{
        float dividir = operador1/operador2;
       printf("La division es %.2f \n", dividir);
    }



}

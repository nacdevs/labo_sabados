#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    //int numeroDos;
    //int numeroTres;//
    int numeroMin;
    int numeroMax;
    int numeroMedio;
    int numeroActual;
    int suma=0;
    float promedio;
    int i;
    int j;
    int arrayTodos [10];
    for(i=0;i<10;i++)
    {
        printf("\nNumero %d ?",i+1);
        scanf("%d",&numeroUno);

        arrayTodos[i] = numeroUno;
        }

    for(j=0;j<10;j++){
    numeroActual=arrayTodos[j];

    if(j==0){
        numeroMax = numeroActual;
        numeroMin = numeroActual;
    }else{
        if(numeroActual>numeroMax){
            numeroMax=numeroActual;
            }
        if(numeroActual<numeroMin){
            numeroMin=numeroActual;
            }
        if((numeroActual>numeroMin) && (numeroActual<numeroMax) )
           numeroMedio=numeroActual;
        }
        suma=suma+numeroActual;
    }
    promedio= suma/10;
    printf("El mayor es %d, el menor es %d, el del medio es %d \n", numeroMax,numeroMin,numeroMedio);
    printf("El promedio ess:%2f batmanes", promedio);

        /*numeroMin = numeroUno;
        numeroMax = numeroUno; 332

        printf("Numero 2?");
        scanf("%d",&numeroDos);
        if(numeroDos < numeroMin)
        {
            numeroMin = numeroDos;
        }
        else if(numeroDos > numeroMax)
        {
            numeroMax = numeroDos;
        }

        printf("Numero 3?");
        scanf("%d",&numeroTres);
        if(numeroTres < numeroMin)
        {
            numeroMin = numeroTres;
        }
        else if(numeroTres > numeroMax)
        {
            numeroMax = numeroTres;
        }

        printf("MIN: %d - MAX: %d",numeroMin,numeroMax);

        if(numeroUno > numeroMin && numeroUno < numeroMax)
        {
            printf("El numero del medio es: %d",numeroUno);
        }
        else if(numeroDos > numeroMin && numeroDos < numeroMax)
        {
            printf("El numero del medio es: %d",numeroDos);
        }
        else if(numeroTres > numeroMin && numeroTres < numeroMax)
        {
            printf("El numero del medio es: %d",numeroTres);
        }

*/
   // }
    return 0;
}

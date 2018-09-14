#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Persona{

    char nombre[70];
    int edad;
    int dni;
    float altura;


};

typedef struct S_Persona Persona;

int main()
{
    Persona p;


    int numeros[25];
    for(int i=0; i<25 ; i++){
        if(i/3==0 && i/5==0){
           numeros[i]=i+3;
        }else{
            numeros[i]=i;
        }
    }
    for(int z=0; z<25 ; z++){

        printf("Numero: %d\n",numeros[z]);

    }

    insertion(numeros,25);

    AltaPersona(&p);

/*    p.edad=9;
    strncpy(p.nombre,"CACHO",70);
    p.altura=1.85;
    p.dni=4000000;
    /*printf("Persona edad:%d \n",p.edad);
    printf("Persona Nombre:%s \n",p.nombre);*/

    printPersona(&p);

    return 0;


}

void insertion(int data [], int len){
    int i;
    int j;
    int temp;

    for(i=1;i<len;i++){
    temp=data[i];
    j=i-1;
    while(j>=0 && temp<data[j]){ //

        data[j+1] = data [j];
        j--;

    }

     data[j+1]=temp;//insercion
    }
     printf("\n\nOrdenados\n");
     for(int z=0; z<25 ; z++){

        printf("Numero: %d\n",data[z]);

    }
}

void AltaPersona(Persona* p){

    int auxDni;
    int auxEdad;
    float auxAlt;


    printf("Ingrese nombre\n");
    fgets(p->nombre,25,stdin);
    printf("Ingrese DNI\n");
    scanf("%d",&auxDni);
    printf("Ingrese edad\n");
    scanf("%d",&auxEdad);
    printf("Ingrese altura\n");
    scanf("%f",&auxAlt);

    p->dni=auxDni;
    p->altura=auxAlt;
    p->edad=auxEdad;
}

void printPersona(Persona* p){
//    printf("Nombre:%s \n Edad: %d\n DNI: %d\n Altura: %.2f\n",p.nombre,p.edad,p.dni,p.altura);
      printf("Nombre:%s \n Edad: %d\n DNI: %d\n Altura: %.2f\n",p->nombre,p->edad,p->dni,p->altura);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

static int sumaAfiches;


/*Devuelve el ID tanto del cliente con menos ventas a cobrar y el cliente con mas ventas cobradas dependiendo de la
 variable aCobrar (1-0)*/
int inf_calculaVentas(Afiche* array,int len ,int aCobrar){  //a) b)
    int i;
    int ret=-1;
    int clienteVentaSum=0;
    int idVentasCliente=0;
    for(i=0;i<len;i++){
        //int isEmpty= array[i].isEmpty;
        int actual=array[i].idCliente;
        int clienteSum=0;
        int j;
        for(j=0;j<len;j++){
            int idCliente=array[j].idCliente;
            int statCobro= array[j].statCobro;
            int isEmpty=array[j].isEmpty;
            if(idCliente==actual && statCobro==aCobrar && isEmpty==0){
            clienteSum++;
            }
        }
        if(clienteSum>clienteVentaSum){
            clienteVentaSum=clienteSum;
            idVentasCliente=actual;
        }
    }
    ret=idVentasCliente;
    return ret;

}

//Devuelve el Id del cliente con menos ventas
int inf_clienteMenosVentas(Afiche* array, int len){ //c)
    int ret=-1;
    int i;
    int clienteVentaSuma=9999;
    int idVentasCliente=0;
    for(i=0;i<len;i++){
        int actual=array[i].idCliente;
        int clienteSum=0;
        int j;
        for(j=0;j<len;j++){
            int idCliente=array[j].idCliente;
            int isEmpty=array[j].isEmpty;
            if(idCliente==actual && isEmpty==0){
            clienteSum++;
            }
        }

        if(clienteSum!=0 && clienteSum<clienteVentaSuma){
            clienteVentaSuma=clienteSum;
            idVentasCliente=actual;
        }


    }
    ret=idVentasCliente;
    return ret;

}

//Devuelve el ID del cliente que compro menos afiches
int inf_menosAfiches(Afiche* array, int len){ //e)
    int ret=-1;
    int i;
    int cantidadAfichesMenorSum=9999;
    int idClienteMenorAfiches;

    for(i=1;i<len;i++){
        int actual=i;
        int clienteSum=0;
        int j;
        for(j=0;j<len;j++){
            int idCliente=array[j].idCliente;
            int cantAfiches= array[j].cantidadAfiches;
            int isEmpty=array[j].isEmpty;
            if(idCliente==actual && isEmpty==0){
            clienteSum=clienteSum+cantAfiches;
            }
        }
         if(clienteSum<cantidadAfichesMenorSum){
            cantidadAfichesMenorSum=clienteSum;
            idClienteMenorAfiches=actual;
        }

    }
    ret=idClienteMenorAfiches;
    return ret;
}


// Devuelve el id del cliente con mas afiches a cobrar
int inf_masAfACobrar(Afiche* array, int len){ //f)
    int ret=-1;
    int i;
    int cantidadAfichesACobrar=0;
    int idClienteAfichesACobrar;

    for(i=0;i<len;i++){
        int actual=array[i].idCliente;
        int clienteSum=0;
        int j;
        for(j=0;j<len;j++){
            int idCliente=array[j].idCliente;
            int cantAfiches= array[j].cantidadAfiches;
            int statCobro= array[j].statCobro;
            int isEmpty=array[j].isEmpty;
            if(idCliente==actual && statCobro==1 && isEmpty==0){
            clienteSum=clienteSum+cantAfiches;
            }
        }
         if(clienteSum>cantidadAfichesACobrar){
            cantidadAfichesACobrar=clienteSum;
            idClienteAfichesACobrar=actual;
        }

    }
    ret=idClienteAfichesACobrar;
    return ret;
}

//Devuelve int con la cantidad de clientes que compraron mas de 500 afiches
int inf_compranMas500(Afiche* array , int len){ //g)
    int ret=-1;
    int i;
    int suma500=0;
    for(i=0;i<len;i++){
        int actual=i;
        int breakthis=0;
        for(int j=0;j<len;j++){
            int idClient= array[j].idCliente;
            int cantAf=array[j].cantidadAfiches;
            int empty=array[j].isEmpty;
            if(actual==idClient && breakthis==0 && cantAf>500 && empty==0){
            suma500++;
            breakthis=1;
            }
        }


    }

    ret=suma500;
    return ret;
}

// Suma cantidad de afiches en cada zona y crea la variable de suma total para realizar el promedio
void inf_cantAfichePorZona (Afiche* array, int len){ //h) i) crear variable globales para suma de afiches y clientes
    int i;
    int contador1=0;
    int contador2=0;
    int contador3=0;

    for(i=0;i<len;i++){
        int isEmpty= array[i].isEmpty;
        int zona=array[i].zona;
        int cantAfiches= array[i].cantidadAfiches;
        if(isEmpty==0){
            switch(zona){
                case 1:
                    contador1=contador1+cantAfiches;
                    break;

                case 2:
                    contador2=contador2+cantAfiches;
                    break;

                case 3:
                    contador3=contador3+cantAfiches;
                    break;
            }
        }

    }
    sumaAfiches=contador1+contador2+contador3;
    printf("h.Cantidad de afiches por zona, CABA: %d, Zona Sur: %d, Zona Oeste: %d\n\n",contador1,contador2,contador3);

}
//Devuelve la suma de afiches
int inf_getSumaAfiches(){
    return sumaAfiches;
}

//Lista en columnas, las ventas separadas por zona
int inf_listaVentasPorZona(Afiche* array, int len){ //j)
    int i;
    int ret=-1;
    int zonaActual=1;
    printf("j.---Ventas por Zona---:\n");
    for(zonaActual;zonaActual<=3;zonaActual++){
         switch(zonaActual){
                    case 1:
                    printf("\nCiudad de Buenos Aires:\n");
                    break;

                    case 2:
                    printf("\nZona Sur:\n");
                    break;

                    case 3:
                    printf("\nZona Oeste:\n");
                    break;
                }
         for(i=0;i<len;i++){
            int isEmpty= array[i].isEmpty;
            int actual=array[i].idCliente;
            int cantAfiches= array[i].cantidadAfiches;
            int idVenta=array[i].id;
            int zona=array[i].zona;
            if(isEmpty==0 && zona==zonaActual){
                printf("Id Venta: %d\tCant. Afiches: %d\tId Clente: %d\n",idVenta,cantAfiches,actual);
             }

           }
        ret=0;
      }
      return ret;
}


//Imprime zona con mas afiches vendidos
void inf_zonaAfi(Afiche* array, int len){ //d)
    int mayor;
    int numeros[3];
    int i;
    for(i=0;i<len;i++){
        int zona=array[i].zona;
        switch(zona){
            case 1:
                numeros[0]=numeros[0]+1;
                break;
            case 2:
                numeros[1]=numeros[1]+1;
                break;
            case 3:
                numeros[2]=numeros[2]+1;
                break;

        }

    }

    for(int i=0;i<len;i++){
        int previous=0;
        if(numeros[i]>previous){
            previous=numeros[i];
            mayor=numeros[i];
        }
    }

    char zonaLet[150];
    zonaALetras(&zonaLet,mayor);

    printf("d.La zona con mas afiches es la %s\n\n", &zonaLet);
}

//Recibe numero de Zona y devuelve el nombre
void zonaALetras (char* pLZona,int zona){

    switch(zona){
        case 1:
        //*pLZona="Ciudad de Buenos Aires";
        strcpy(pLZona, "Ciudad de Buenos Aires");
        break;

        case 2:
        //*pLZona="Zona Sur";
        strcpy(pLZona, "Zona Sur");
        break;

        case 3:
        //*pLZona="Zona Oeste";
        strcpy(pLZona, "Zona Oeste");
        break;
    }

}

//Setea las variables nombre y apellido en pasandole el Id
void inf_idToName(Cliente* array, int len, char* nombre,char* apellido,int* cuit, int idParam){
        int index=cl_busId(array,len,idParam);
        strcpy(nombre,array[index].nombre);
        strcpy(apellido,array[index].apellido);
        int auxCuit=array[index].cuit;
        *cuit=auxCuit;


}



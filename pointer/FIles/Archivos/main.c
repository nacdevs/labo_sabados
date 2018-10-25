#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.c"

int main()
{
    char bufferNombre[150] = "Juan";
    char bufferApellido[50]= "Lopez";
    int id=100;
    char bufferId[1024]="";
    FILE *pArchivo;
    pArchivo = fopen("archivo.ext","w"); // w escribe --- r lee
    Cliente* arrayCliente[1000];
    int contCliente=0;

    int i;
    char auxiliar[50];

    if(pArchivo != NULL){
        //Llena el archivo
        for(int i=0;i<5;i++){
        id++;
        fprintf(pArchivo,"%s,%s, %d \n",bufferNombre,bufferApellido,id);
                }
        fclose(pArchivo);

        pArchivo = fopen("archivo.ext","r");


        /*[^,] Quiero hasta (^) la coma ","
        (pero no la coma por que le estoy aclarando cuando le escribo la misma variable despues del corchete)
        en el txt que traigo*/

        ///////////
        while(!feof(pArchivo)){
        strcpy(bufferApellido,"-----*-----");
        fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferNombre,bufferApellido,bufferId);
        //printf("%s - %s - %s\n",bufferNombre ,bufferApellido, bufferId);
        arrayCliente[contCliente]=Cliente_newConParametros(bufferId,bufferNombre,bufferApellido);
        contCliente++;
        }
        fclose(pArchivo);//Termina de copiar y cierra conexion al archivo, siempre llamar fclose
    }else{
        printf("El archivo no existe");
    }

    //printf("Nombre: %s - Apellido: %s - ID: %s\n",arrayCliente[0]->nombre,arrayCliente[0]->apellido,arrayCliente[0]->id);
    Cliente_mostrar(arrayCliente,5);
    return 0;
}

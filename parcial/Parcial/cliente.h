#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct S_Cliente{
    char nombre[52];
    char apellido[52];
    int cuit;
    int isEmpty;
    int id;
    };

typedef struct S_Cliente Cliente;

void cl_initArray(Cliente* array, int len);

int cl_altaCliente(Cliente* array, int len);

int cl_busId(Cliente* array, int len, int id);

int cl_modif(Cliente* array, int len,int id);

int cl_bajaCliente(Cliente* array, int len);

int cl_sumaCliente(Cliente* array,int len);

void cl_altaForzada(Cliente* array, int len,char nombre[52], char apellido[52], int cuit);

#endif // CLIENTE_H_INCLUDED

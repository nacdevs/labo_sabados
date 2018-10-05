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


#endif // CLIENTE_H_INCLUDED

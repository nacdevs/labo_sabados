#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    char nombre[64];
    char apellido[64];
    int id;


}Cliente;

int cli_setApellido(Cliente* this, char* apellido);

#endif // CLIENTE_H_INCLUDED

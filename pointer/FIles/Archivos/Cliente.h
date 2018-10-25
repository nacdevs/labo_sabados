#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    char id[75];
    char nombre[75];
    char apellido[75];
}Cliente;


Cliente* Cliente_new();
void Cliente_delete();
Cliente* Cliente_newConParametros(char* id,char* nombre,char* apellido);

int Cliente_setId(Cliente* this,char* id);
int Cliente_getId(Cliente* this,char* id);

int Cliente_setNombre(Cliente* this,char* nombre);
int Cliente_getNombre(Cliente* this,char* nombre);

int Cliente_setApellido(Cliente* this,char* apellido);
int Cliente_getApellido(Cliente* this,char* apellido);

static int isValidNombre(char* nombre);

#endif // CLIENTE_H_INCLUDED

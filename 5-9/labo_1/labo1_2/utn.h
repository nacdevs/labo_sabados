#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1

/**
    utn_getEntero: pideun entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
    */




int utn_getEntero(int* pEdad, int reintentos, char* msg, char* msgErr, int min, int max);
char utn_getNombre(char* pNombre, int reintentos);


#endif // UTN_H_INCLUDED

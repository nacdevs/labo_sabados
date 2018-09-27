#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED


struct S_Pantalla{
    char nombre[32];
    char direccion[32];
    int tipo;
    int isEmpty;
    float precio;
    int id;


};

typedef struct S_Pantalla Pantalla;



#endif // PANTALLA_H_INCLUDED

#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED


struct S_Contratacion{
    char cliente[32];
    char publicidad[32];
    char video[32];
    int cuit;
    int dias;



};

typedef struct S_Contratacion Contratacion;

#endif // CONTRATACION_H_INCLUDED

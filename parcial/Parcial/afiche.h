#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED


struct S_Afiche{
    int zona;
    char archivoImg[52];
    int cuit;
    int isEmpty;
    int idCliente;
    int cantidadAfiches;
    int statCobro;
    int id;
};

typedef struct S_Afiche Afiche;

#endif // AFICHE_H_INCLUDED

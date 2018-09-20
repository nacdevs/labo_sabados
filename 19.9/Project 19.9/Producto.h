#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct S_Producto
{
    char nombre [32];
    char descripcion [128];
    float precio;
    int isEmpty;

};

typedef struct S_Producto Producto;

#endif // PRODUCTO_H_INCLUDED



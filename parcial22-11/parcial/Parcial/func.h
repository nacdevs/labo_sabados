#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include "Venta.h"

int fn_ventaCsv(char* path, LinkedList* this);
int fn_sumaTotal(Venta* venta);
int fn_sumaMayor1(void* venta);
int fn_sumaMayor2(void* venta);
int fn_LCD(void* venta);

#endif // FUNC_H_INCLUDED

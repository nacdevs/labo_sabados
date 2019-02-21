#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include "LinkedList.h"
int func_readCSV(char* path, LinkedList* list);
int func_cantidadTotal(void* venta);
int func_ventaMayor10k(void* venta);
int func_ventaMayor20k(void* venta);
int func_ventaLCD(void* venta);


#endif // FUNC_H_INCLUDED

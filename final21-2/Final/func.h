#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
int func_readCSV(char* path, LinkedList* list);

void fn_setId(int* ids);


int fn_filterById(void* empleado);

void fn_setEmpleado(Empleado* emp);

void fn_delete();


void fn_setDia(int* ids);
void fn_setMes(int* ids);


void fn_setId(int* ids);


void fn_delete();



int fn_filtrarFecha(void* fichaje);

#endif // FUNC_H_INCLUDED

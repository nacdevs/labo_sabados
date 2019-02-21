#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

int func_readCSV(char* path, LinkedList* list);
int fn_printEnvios(LinkedList* pList);
int fn_calCosto(void* envio);
int fn_printEnviosConCosto(LinkedList* pList);
int fn_filtraZona(void* envio);
int func_writeCSV(char* path, LinkedList* list);

#endif // FUNC_H_INCLUDED

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int cont_loadCsv(char* path , LinkedList* pList);
int cont_saveCsv(char* path , Envio* auxEnvio,int costo);

#endif // CONTROLLER_H_INCLUDED

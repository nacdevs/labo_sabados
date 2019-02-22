#ifndef FICHAJE_H_INCLUDED
#define FICHAJE_H_INCLUDED

typedef struct{
    int idFicha;
    int idEmp;
    int hora;
    int minutos;
    int dia;
    int mes;
    int anio;
    char IO [30];
}Fichajes;


Fichajes* fichajes_new();
void fichajes_delete();
Fichajes* fichajes_newConParametros(int idFicha,int idEmp,int hora,int minutos,int dia,int mes,int anio,char* IO );

int fichajes_setIdFicha(Fichajes* this,int idFicha);
int fichajes_getIdFicha(Fichajes* this,int* idFicha);

int fichajes_setIdEmp(Fichajes* this,int idEmp);
int fichajes_getIdEmp(Fichajes* this,int* idEmp);

int fichajes_setHora(Fichajes* this,int hora);
int fichajes_getHora(Fichajes* this,int* hora);

int fichajes_setMinutos(Fichajes* this,int minutos);
int fichajes_getMinutos(Fichajes* this,int* minutos);

int fichajes_setDia(Fichajes* this,int dia);
int fichajes_getDia(Fichajes* this,int* dia);

int fichajes_setMes(Fichajes* this,int mes);
int fichajes_getMes(Fichajes* this,int* mes);

int fichajes_setAnio(Fichajes* this,int anio);
int fichajes_getAnio(Fichajes* this,int* anio);

int fichajes_setIO (Fichajes* this,char* IO );
int fichajes_getIO (Fichajes* this,char* IO );

#endif // FICHAJES_H_INCLUDED

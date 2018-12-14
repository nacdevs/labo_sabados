#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED
typedef struct{
    int idEnvio;
    char nombre[75];
    int idCamion;
    char zona[75];
    int km;
    int tipoentrega;
}Envio;


Envio* Envio_new();
void Envio_delete();
Envio* Envio_newConParametros(int idEnvio,char* nombre,int idCamion,char* zona,int km,int tipoentrega);

int Envio_setIdEnvio(Envio* this,int idEnvio);
int Envio_getIdEnvio(Envio* this,int* idEnvio);

int Envio_setNombre(Envio* this,char* nombre);
int Envio_getNombre(Envio* this,char* nombre);

int Envio_setIdCamion(Envio* this,int idCamion);
int Envio_getIdCamion(Envio* this,int* idCamion);

int Envio_setZona(Envio* this,char* zona);
int Envio_getZona(Envio* this,char* zona);

int Envio_setKm(Envio* this,int km);
int Envio_getKm(Envio* this,int* km);

int Envio_setTipoentrega(Envio* this,int tipoentrega);
int Envio_getTipoentrega(Envio* this,int* tipoentrega);

#endif // ENVIO_H_INCLUDED

#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED

typedef struct {
    int idEnvio;
    char nombreProducto[100];
    int idCamion;
    char zonaDestino[100];
    int kmRecorridos;
    int tipoEntrega;
    int costoEnvio;
}Envio;


Envio* Envio_new();
void Envio_delete();
Envio* Envio_newConParametros(int idEnvio,char* nombreProducto ,int idCamion,char* zonaDestino ,int kmRecorridos,int tipoEntrega,int costoEnvio);

int Envio_setIdEnvio(Envio* this,int idEnvio);
int Envio_getIdEnvio(Envio* this,int* idEnvio);

int Envio_setNombreProducto (Envio* this,char* nombreProducto );
int Envio_getNombreProducto (Envio* this,char* nombreProducto );

int Envio_setIdCamion(Envio* this,int idCamion);
int Envio_getIdCamion(Envio* this,int* idCamion);

int Envio_setZonaDestino (Envio* this,char* zonaDestino );
int Envio_getZonaDestino (Envio* this,char* zonaDestino );

int Envio_setKmRecorridos(Envio* this,int kmRecorridos);
int Envio_getKmRecorridos(Envio* this,int* kmRecorridos);

int Envio_setTipoEntrega(Envio* this,int tipoEntrega);
int Envio_getTipoEntrega(Envio* this,int* tipoEntrega);

int Envio_setCostoEnvio(Envio* this,int costoEnvio);
int Envio_getCostoEnvio(Envio* this,int* costoEnvio);

#endif // ENVIO_H_INCLUDED

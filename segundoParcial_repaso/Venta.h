#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct{
    int idVenta;
    char fecha[50];
    char codigoProd[50];
    int cantidad;
    float precioUnitario;
    char CUIT[75];
}Venta;


Venta* Venta_new();
void Venta_delete();
Venta* Venta_newConParametros(int idVenta,char* fecha,char* codigoProd,int cantidad,float precioUnitario,char* CUIT);

int Venta_setIdVenta(Venta* this,int idVenta);
int Venta_getIdVenta(Venta* this,int* idVenta);

int Venta_setFecha(Venta* this,char* fecha);
int Venta_getFecha(Venta* this,char* fecha);

int Venta_setCodigoProd(Venta* this,char* codigoProd);
int Venta_getCodigoProd(Venta* this,char* codigoProd);

int Venta_setCantidad(Venta* this,int cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

int Venta_setPrecioUnitario(Venta* this,float precioUnitario);
int Venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int Venta_setCUIT(Venta* this,char* CUIT);
int Venta_getCUIT(Venta* this,char* CUIT);

#endif // VENTA_H_INCLUDED

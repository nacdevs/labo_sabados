#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
typedef struct
{
    int idVenta;
    char fechaVenta[50];
    char codigoProd[70];
    int cantidad;
    float precioUnit;
    int CUIT;
} Venta;


 Venta* Venta_new();
void Venta_delete();
 Venta* Venta_newConParametros(int idVenta,char* fechaVenta,char* codigoProd,int cantidad,float precioUnit,int CUIT);

int Venta_setIdVenta( Venta* this,int idVenta);
int Venta_getIdVenta( Venta* this,int* idVenta);

int Venta_setFechaVenta( Venta* this,char* fechaVenta);
int Venta_getFechaVenta( Venta* this,char* fechaVenta);

int Venta_setCodigoProd( Venta* this,char* codigoProd);
int Venta_getCodigoProd( Venta* this,char* codigoProd);

int Venta_setCantidad( Venta* this,int cantidad);
int Venta_getCantidad( Venta* this,int* cantidad);

int Venta_setPrecioUnit( Venta* this,float precioUnit);
int Venta_getPrecioUnit( Venta* this,float* precioUnit);

int Venta_setCUIT( Venta* this,int CUIT);
int Venta_getCUIT( Venta* this,int* CUIT);

#endif // VENTA_H_INCLUDED

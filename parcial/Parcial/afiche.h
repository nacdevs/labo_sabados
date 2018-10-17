#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED


struct S_Afiche{
    int zona;
    char archivoImg[52];
    int cuit;
    int isEmpty;
    int idCliente;
    int cantidadAfiches;
    int statCobro;
    int id;
};

typedef struct S_Afiche Afiche;


void af_initArray(Afiche* array, int len);
int af_ventAfiche(Afiche* array, int len,int id);
int af_editVenta(Afiche* array, int len,int index);
void af_cobrar(Afiche* array,int len);
void af_ventas(Afiche* array, int len, int data);
int af_busId(Afiche* array, int len, int id);
void af_altaForzada(Afiche* array,int len,int zona,int cantAf,int idClient, char archivo[52]);




#endif // AFICHE_H_INCLUDED

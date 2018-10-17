#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int inf_calculaVentas(Afiche* array,int len ,int aCobrar);
int inf_clienteMenosVentas(Afiche* array, int len);
int inf_menosAfiches(Afiche* array, int len);
int inf_masAfACobrar(Afiche* array, int len);
int inf_compranMas500(Afiche* array , int len);
void inf_cantAfichePorZona (Afiche* array, int len);
int inf_getSumaAfiches();
int inf_listaVentasPorZona(Afiche* array, int len);
void inf_zonaAfi(Afiche* array, int len);
void zonaALetras (char* pLZona,int zona);
void inf_idToName(Cliente* array, int len, char* nombre,char* apellido,int* cuit, int idParam);

#endif // INFORMES_H_INCLUDED

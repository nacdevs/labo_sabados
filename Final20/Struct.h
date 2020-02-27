#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct {
    int id;
    char nombre [75];
    char apellido [75];
    int dni;
    char clave [75];
}Struct;



Struct* Struct_new();
void Struct_delete();
Struct* Struct_newConParametros(int id,char* nombre ,char* apellido ,int dni,char* clave );

int Struct_setId(Struct* this,int id);
int Struct_getId(Struct* this,int* id);

int Struct_setNombre (Struct* this,char* nombre );
int Struct_getNombre (Struct* this,char* nombre );

int Struct_setApellido (Struct* this,char* apellido );
int Struct_getApellido (Struct* this,char* apellido );

int Struct_setDni(Struct* this,int dni);
int Struct_getDni(Struct* this,int* dni);

int Struct_setClave (Struct* this,char* clave );
int Struct_getClave (Struct* this,char* clave );

#endif // STRUCT_H_INCLUDED

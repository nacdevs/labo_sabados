#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct {
    int id;
    char nombre [75];
    char apellido [75];
    int dni;
    char clave [75];
}Empleado;


Empleado* Empleado_new();
void Empleado_delete();
Empleado* Empleado_newConParametros(int id,char* nombre ,char* apellido ,int dni,char* clave );

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre (Empleado* this,char* nombre );
int Empleado_getNombre (Empleado* this,char* nombre );

int Empleado_setApellido (Empleado* this,char* apellido );
int Empleado_getApellido (Empleado* this,char* apellido );

int Empleado_setDni(Empleado* this,int dni);
int Empleado_getDni(Empleado* this,int* dni);

int Empleado_setClave (Empleado* this,char* clave );
int Empleado_getClave (Empleado* this,char* clave );

#endif // EMPLEADO_H_INCLUDED

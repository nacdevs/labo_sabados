#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    FILE *pArchivo;
    pArchivo = fopen(path,"r");
    parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    fclose(pArchivo);




    return 1;
}




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo= fopen(path,"rb");
    Employee* pEmpleado;
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    char bufferNombre[128];
    int  bufferHoras;
    int  bufferSueldo;
    int bufferId;
    for(i=0; i<len;i++){
        auxEmployee=ll_get(pArrayListEmployee,i);
        Employee_getNombre(auxEmployee,&bufferNombre);
        Employee_getSueldo(auxEmployee,&bufferHoras);
        Employee_getHorasTrabajadas(auxEmployee,&bufferSueldo);
        Employee_getId(auxEmployee,&bufferId);
        printf("%d - %s - %d - %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);


    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo= fopen(path,"wb");
    Employee* pEmpleado;
    int i;
    int lenArray=ll_len(pArrayListEmployee);
    if(pArchivo != NULL){
        for(i=0;i<lenArray;i++){
                pEmpleado = ll_get(pArrayListEmployee,i);
                fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
                }
        }
    fclose(pArchivo);
    return 1;

}


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char auxBufferId[50];
    int bufferId;
    char bufferNombre[125];

    char auxBufferHoras[50];
    int bufferHoras;

    char auxBufferSueldo[50];
    int bufferSueldo;
    int flagFirstLine=0;
    Employee* auxEmployee;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxBufferId,bufferNombre,auxBufferHoras,auxBufferSueldo)==4 && flagFirstLine!=0)
            {
                bufferId= atoi(auxBufferId);
                bufferHoras = atoi(auxBufferHoras);
                bufferSueldo= atoi(auxBufferSueldo);
                auxEmployee=Employee_newConParametros(bufferNombre,bufferId,bufferHoras,bufferSueldo);
                ll_add(pArrayListEmployee,(Employee*)auxEmployee);

            }
            if(flagFirstLine==0){
                flagFirstLine++;
            }

        } while(!feof(pFile));




    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
     Employee* pEmpleado;
    do{
        pEmpleado = Employee_new();
        fread(pEmpleado,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee, pEmpleado);
    }while(!feof(pFile));

    return 1;
    return 1;
}

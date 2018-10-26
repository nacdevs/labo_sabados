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
    Employee auxEmployee;


     if(pFile != NULL)
    {
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxBufferId,bufferNombre,auxBufferHoras,auxBufferSueldo)==4 && flagFirstLine!=0)
            {
                bufferId= atoi(auxBufferId);
                bufferHoras = atoi(auxBufferHoras);
                bufferSueldo= atoi(auxBufferSueldo);
                //printf("%d - %s - %d - %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
                strcpy(auxEmployee.nombre,bufferNombre);
                auxEmployee.id=bufferId;
                auxEmployee.horas=bufferHoras;
                auxEmployee.sueldo=bufferSueldo;
                ll_add(pArrayListEmployee,auxEmployee);
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

    return 1;
}

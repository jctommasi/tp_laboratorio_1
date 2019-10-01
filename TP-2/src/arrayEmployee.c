#include "arrayEmployee.h"

int employee_clear_all(Employee array[], int size)
{
    int retorno=-1;
    if(array != NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int employee_findEmpty(Employee array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_findId(Employee array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_searchInt(Employee array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].sector==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_searchString(Employee array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lastName,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int employee_signup(Employee array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(employee_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tSector: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].sector);
            utn_getName("\t\t\t\t\t\tApellido: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].lastName);
            utn_getTexto("\t\t\t\t\t\tNombre: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].name);
            utn_getFloat("\t\t\t\t\t\tSalario: ",MSG_DEFAULT_ERROR,1,sizeof(float),0,1,1,&array[posicion].salary);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\tSector: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idUnico,
				   array[posicion].lastName,
				   array[posicion].name,
				   array[posicion].sector,
				   array[posicion].salary);
            stuff_sleep(3);
            retorno=0;
        }
    }
    return retorno;
}

int employee_destroy(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(employee_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n");
            stuff_sleep(2);
        }
        else
        {
        	//antes del borrado, copio los datos para luego mostrar que es lo que se borro
        	Employee arrayAux[sizeArray];
        	arrayAux[posicion].idUnico = array[posicion].idUnico;
        	arrayAux[posicion].sector = array[posicion].sector;
        	arrayAux[posicion].salary = array[posicion].salary;
        	strcpy(arrayAux[posicion].lastName,array[posicion].lastName);
        	strcpy(arrayAux[posicion].name,array[posicion].name);

        	//inicio borrado
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].sector=0;
            array[posicion].salary=0;
            strcpy(array[posicion].lastName,"");
            strcpy(array[posicion].name,"");
            retorno=0;

            //informe de borrado
            stuff_clearScreen();
            stuff_employeeGoneAway();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tBORRADO SATISFACTORIO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\tSector: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   arrayAux[posicion].idUnico,
				   arrayAux[posicion].lastName,
				   arrayAux[posicion].name,
				   arrayAux[posicion].sector,
				   arrayAux[posicion].salary);
            stuff_sleep(6);
        }
    }
    return retorno;
}

int employee_destroyMatchedInt(Employee array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].sector=0;
                array[i].salary=0;
                strcpy(array[i].lastName,"");
                strcpy(array[i].name,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

int employee_modify(Employee array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\t\t\t\t\t Ingrese el ID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(employee_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\033[0;31m"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n"
            		"\033[0m");
            stuff_sleep(2);
        }
        else
        {
            do
            {
            	stuff_clearScreen();
            	stuff_showModifyBanner();

                printf( "\n\t\t\t\t\tSE HA ENCONTRADO EL EMPLEADO:"
                		"\033[0;31m"
                		"\n\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tPosicion: %d"
                		"\n\t\t\t\t\t\tID: %d"
                		"\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tA - Sector: %d"
                		"\n\t\t\t\t\t\tB - Salario: %f"
                		"\n\t\t\t\t\t\tC - Apellido: %s"
                		"\n\t\t\t\t\t\tD - Nombre: %s\n"
                		"\033[0m",
                       posicion,
					   array[posicion].idUnico,
					   array[posicion].sector,
					   array[posicion].salary,
					   array[posicion].lastName,
					   array[posicion].name);

                utn_getChar(MSG_MODIFY_CHOOSE, MSG_ERROR_MODIFY_CHOOSE,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt(MSG_MODIFY_SECTOR,MSG_ERROR_MODIFY_SECTOR,1,sizeof(int),1,sizeArray,1,&array[posicion].sector);
                        break;
                    case 'B':
                        utn_getFloat(MSG_MODIFY_SALARY,MSG_ERROR_MODIFY_SALARY,1,sizeof(float),0,1,1,&array[posicion].salary);
                        break;
                    case 'C':
                        utn_getName(MSG_MODIFY_SURNAME,MSG_ERROR_MODIFY_SURNAME,1,TEXT_SIZE,1,array[posicion].lastName);
                        break;
                    case 'D':
                        utn_getTexto(MSG_MODIFY_NAME,MSG_ERROR_MODIFY_NAME,1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'S':
                        break;
                    default:
                        printf(MSG_DEFAULT_ERROR);
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int employee_sortByString(Employee array[],int size)
{
    int retorno=-1;
    int i, j;

    char lastnameAux[TEXT_SIZE];
    int idAux;
    int isemptyAux;
    int sectorAux;
    float salaryAux;
    char nameAux[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].lastName);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].sector;
            salaryAux=array[i].salary;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && strcmp(lastnameAux,array[j].lastName)<0)
            {
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].lastName,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].sector=sectorAux;
            array[j + 1].salary=salaryAux;
            strcpy(array[j + 1].name,nameAux);
        }

        for (i = 1; i < size; i++)
        {
            strcpy(lastnameAux,array[i].lastName);
            idAux=array[i].idUnico;
            isemptyAux=array[i].isEmpty;

            sectorAux=array[i].sector;
            salaryAux=array[i].salary;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && sectorAux < array[j].sector)
            {
                strcpy(array[j + 1].lastName,array[j].lastName);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].lastName,lastnameAux);
            array[j + 1].idUnico=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].sector=sectorAux;
            array[j + 1].salary=salaryAux;
            strcpy(array[j + 1].name,nameAux);
        }
        retorno=0;
    }
    return retorno;
}

int employee_paginate(Employee array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|\tID\t|\tSECTOR\t|\t\tSALARIO\t\t\t|\tAPELLIDO\t|\tNOMBRE\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%f\t\t|\t%s\t\t|\t%s\t\t|\n",
                       array[i].idUnico,
					   array[i].sector,
					   array[i].salary,
					   array[i].lastName,
					   array[i].name);
        }
        retorno=0;
        stuff_sleep(5);
    }
    return retorno;
}


/*
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
FUNCIONES DE INFORMES *
 */


/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int employee_info_listarPorCriterio(Employee arrayA[], Employee arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(arrayA[i].lastName,criterio)==0)
            {
                employee_findId(arrayB,sizeJ,arrayA[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
            }

        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int employee_info_listarCriterioContadorAcumulado(Employee arrayA[], Employee arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            employee_searchString(arrayA,i,arrayA[i].lastName,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].lastName);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].lastName,arrayA[i].lastName)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        employee_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].sector*arrayB[j].sector);

                        printf("\nID A: %d\nID B: %d",
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int employee_info_maxContadorAcumulado(Employee arrayA[], Employee arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            employee_searchString(arrayA,i,arrayA[i].lastName,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].lastName);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].lastName,arrayA[i].lastName)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        employee_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[k].sector*arrayB[j].sector);

                        printf("\nID A: %d\nID B: %d",                                         //imprimo datos que haya que mostrar
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].lastName);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].lastName);
            }
        }

        retorno=0;
    }
    return retorno;
}

/** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tama�o del arrayA
* \param sizeJ int Tama�o del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarAuxiliarOrdenar(Employee arrayA[], Employee arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Employee arrayAux[sizeI];                                                           //cambiar Fantasma y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            employee_searchString(arrayA,i,arrayA[i].lastName,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].lastName,arrayA[i].lastName);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].lastName,arrayA[i].lastName)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        employee_findId(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].sector*arrayB[j].sector);

                    }
                }
                arrayAux[i].sector=contador;                                    //completo el resto de los campos
                arrayAux[i].sector=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}


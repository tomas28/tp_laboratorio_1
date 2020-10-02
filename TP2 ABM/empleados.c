#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "sector.h"
#define TAM 1000
#define TS 3

void inicializarEmpleados(employee* empleado,int tam)
{

    for(int i=0; i < tam; i++)
    {
        empleado[i].isEmpty = 1;
    }
}
int buscarLibre(employee* empleado, int tam){
    int i;
    int index=-1;

        for(i=0; i<tam; i++){
            if(empleado[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}

void altaEmpleado(employee* empleado, int tam){
    int i;
    i= buscarLibre(empleado,tam);
    if(i!=-1){
        printf("ingrese el nombre: ");
        fflush(stdin);
        gets(empleado[i].name);
        printf("ingrese el apellido: ");
        fflush(stdin);
        gets(empleado[i].lastName);
        printf("ingrese el salario: ");
        fflush(stdin);
        scanf("%f",&empleado[i].salary);
        printf("ingrese el sector:\n\n 1-Administracion\n 2-Comunicaciones\n 3-Comercio\n\n ");
        fflush(stdin);
        scanf("%d",&empleado[i].sector);
        empleado[i].id=i+1;

        empleado[i].isEmpty=0;

    }
    else
    {
        printf("No hay espacio");
    }

}

int estudiante_buscarID(employee empleado[], int tam, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(empleado!= NULL && tam>=0)
    {
        for(i=0;i<tam;i++)
        {
            if(empleado[i].isEmpty==1)
                continue;
            else if(empleado[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int estudiante_baja(employee empleado[], int tam)
{
    int retorno=-1;
    int posicion;
    int idEst;
    if(empleado!=NULL && tam>0)
    {
        printf("ingrese la id que se busca");
        scanf("%d",&idEst);
        if(estudiante_buscarID(empleado,tam,idEst,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            empleado[posicion].isEmpty=1;
            empleado[posicion].id=0;
            empleado[posicion].sector=0;
            empleado[posicion].salary=0;
            strcpy(empleado[posicion].name,"");
            strcpy(empleado[posicion].lastName,"");
            retorno=0;
            printf("se elimino correctamente");
        }
    }
    return retorno;
}
int estudiante_modificar(employee empleado[], int tam)
{
    int retorno=-1;
    int posicion;
    int idEst;
    char opcion;
    if(empleado!=NULL && tam>0)
    {
        printf("ingrese la id del estudiante a modificar");
        scanf("%d",&idEst);
        if(estudiante_buscarID(empleado,tam,idEst,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("ingrese una opcion:\n a)- cambiar combre\n b)- cambiar apellido\n c)- cambiar salario\n d)- ingresar nuevo sector\n s)- salir\n");
                fflush(stdin);
                scanf("%c",&opcion);
                switch(opcion)
                {
                    case 'a':
                        printf("ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(empleado[posicion].name);
                        system("pause");
                        break;
                    case 'b':
                        printf("ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(empleado[posicion].lastName);
                        system("pause");
                        break;
                    case 'c':
                        printf("ingrese el salario: ");
                        scanf("%f",&empleado[posicion].salary);
                        system("pause");
                        break;
                    case 'd':
                        printf("ingrese el nuevo sector:\n\n 1-Administracion\n 2-Comunicaciones\n 3-Comercio\n\n ");
                        fflush(stdin);
                        scanf("%d",&empleado[posicion].sector);
                        system("pause");
                        break;
                    case 's':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
                system("cls");
            }while(opcion!='s');
            retorno=0;
        }
    }
    return retorno;
}

int estudiante_listar(employee empleado[], int tam)
{
    int retorno=-1;
    int i;
    if(empleado!=NULL && tam>=0)
    {
        ordenarPorNombreYSector(empleado,TAM);
         printf("ID |Nombre |Apellido |Sueldo |ID Sector \n");
        for(i=0;i<tam;i++)
        {
            if(empleado[i].isEmpty!=1)
            {
                printf("\n %2d|  %5s| %5s| %.2f| %2d| \n",empleado[i].id, empleado[i].name, empleado[i].lastName,empleado[i].salary , empleado[i].sector);

            }
        }
        retorno=0;
    }
    return retorno;
}

int ordenarDescendente(employee empleado[], int tam){

    int respuesta=-1;
    int flagSwap;
    employee buffer;
    int aux;

    if(empleado!=NULL && tam>=0){


    do{

        flagSwap=0;

        for(int i=0; i<tam-1;i++){
            aux=stricmp(empleado[i].lastName,empleado[i+1].lastName);
            if(aux >0 || (aux==0 && empleado[i].sector < empleado[i+1].sector)) {
                flagSwap=1;
                buffer=empleado[i];
                empleado[i]=empleado[i+1];
                empleado[i+1]=buffer;
            }
        }tam--;
    }while(flagSwap);
}else{
    printf("no hay nada que ordenar\n");
}
    return respuesta;
}

void ordenAscendente(employee empleado[], int tam){
    int flagSwap;
    employee buffer;
    int aux;

    if(empleado!=NULL && tam>=0){

    do{
        flagSwap=0;
        for(int i=0; i<tam-1;i++){
            aux=stricmp(empleado[i].lastName,empleado[i+1].lastName);
            if(aux <0 || (aux==0 && empleado[i].sector > empleado[i+1].sector)) {
                flagSwap=1;
                buffer=empleado[i];
                empleado[i]=empleado[i+1];
                empleado[i+1]=buffer;
            }
        }tam--;
    }while(flagSwap);
}else{
    printf("no hay nada que ordenar\n");
}
}

void ordenarPorNombreYSector(employee empleado[], int tam){
int opcion;
printf("ingrese una opcion:\n 1) Ordenar ascendente\n 2) Ordenar descendente\n ");
scanf("%d",&opcion);

switch(opcion){

case 1:
    ordenAscendente(empleado,TAM);
    break;
case 2:
    ordenarDescendente(empleado,TAM);
    break;
default:
    printf("opcion incorrecta ");
}
}

float promedioSalarios(employee empleado[],int tam){
    float promedio=0;
    float acumulador=0;
    int contador=0;

    if(empleado!=NULL && tam>=0){
            for(int i=0; i<tam;i++){
                if(empleado[i].isEmpty!=1){
                    acumulador+=empleado[i].salary;
                    contador++;
                }
            }
            promedio=acumulador/contador;
        }else{
            printf("no hay salarios que promediar");
        }

    return promedio;
}

float totalSalarios(employee empleado[],int tam){

    float acumulador=0;

    if(empleado!=NULL && tam>=0){
        for(int i=0; i<tam;i++){
            if(empleado[i].isEmpty!=1){
                acumulador+=empleado[i].salary;
            }
        }
    }else{
        printf("no hay salarios que sumar");
    }
    return acumulador;
}

int empleadosSuperanPromedio(employee empleado[],int tam){
    int contEmpSupPromedio=0;
    float promedio=promedioSalarios(empleado,TAM);

    if(empleado!=NULL && tam>=0){

        for(int i=0; i<tam;i++){
           if(empleado[i].isEmpty!=1){
                if(empleado[i].salary>promedio){
                contEmpSupPromedio++;
                }
           }
        }
    }else{
        printf("no hay empleados que comparar");
    }
    return contEmpSupPromedio;
}

void mostrarSalarios(employee empleado[], int tam){

    float total=0;
    float promedio=0;
    int empleadosSuperan=0;

    total= totalSalarios(empleado,TAM);
    promedio= promedioSalarios(empleado,TAM);
    empleadosSuperan= empleadosSuperanPromedio(empleado,TAM);

    printf("Total |Promedio  |Cantidad que superan el promedio| \n");

    printf("\n %.2f|  %.2f| %d| \n",total,promedio,empleadosSuperan);

}
void imprimir(employee empleado[], int tam){

    int opcion;
    printf("ingrese una opcion:\n 1) Mostrar empleados \n 2) mostrar salarios\n ");
    scanf("%d",&opcion);

    switch(opcion){

    case 1:
            estudiante_listar(empleado,TAM);
        break;
    case 2:
            mostrarSalarios(empleado,TAM);
        break;
    default:
        printf("opcion incorrecta ");
    }
}




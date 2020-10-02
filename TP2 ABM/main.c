#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "sector.h"
#include <string.h>
#define TAM 1000
#define TS 3
int main()
{
    char seguir;
    employee empleado[TAM];
    int flag=0;

    inicializarEmpleados(empleado,TAM);

    /*eSector arraySector[TS]={
    {1,"Administracion"},
    {2,"Comunicaciones"},
    {3,"Comercio"}
    };*/


    while(seguir != 's'){
        printf("\n 1-Alta empleado\n 2-Baja empleado\n 3-Modificar empleados\n 4-Ordenar\n 5-Listar empleados\n 6-Salir \n\n");
        fflush(stdin);
        scanf("%c",&seguir);


        system("cls");

        switch(seguir)
            {
            case '1':

                printf("\nAlta empleado\n\n");
                altaEmpleado(empleado,TAM);
                system("pause");
                flag=1;
                break;

            case '2':
                if (flag==1){
                    printf("\nBaja empleado\n\n");
                    estudiante_baja(empleado,TAM);
                }else{
                    printf("no se puede dar de baja sin antes dar de alta un empleado\n");
                }
                system("pause");
                break;

            case '3':
                if (flag==1){
                    printf("\nModificacion empleado\n\n");
                    estudiante_modificar(empleado,TAM);
                }else{
                    printf("no se puede modificar sin antes dar de alta un empleado\n");
                }
                system("pause");
                break;

            case '5':
                if (flag==1){
                    printf("\nListar empleados\n\n");
                    imprimir(empleado,TAM);
                    //estudiante_listar(empleado,TAM);

                }else{
                    printf("no se puede listar sin antes dar de alta un empleado\n");
                }
                system("pause");
                break;
            case '4':
                if (flag==1){
                    //ordenarPorNombreYSector(empleado,TAM);

                }else{
                    printf("no se puede ordenar sin antes dar de alta un empleado\n");
                }
                system("pause");
                break;

            case '6':
                printf("usted salio del programa\n");
                seguir='s';
                break;

            default:
                printf("\n Opcion invalida\n\n");
                system("pause");
                system("break");

        }
        system("cls");

    }
    return 0;
}

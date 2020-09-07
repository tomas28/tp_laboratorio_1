#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
char menu(){

    char opciones;
    printf("***Menu de Opciones***\n\n");
    printf("a) ingresar numero 1\n");
    printf("b) ingresar numero 2\n");
    printf("c) operaciones\n");
    printf("d) mosrar resultados\n");
    printf("e) salir\n");
    printf("Ingrese opcion: \n\n");
    fflush(stdin);
    scanf("%c", &opciones);
    return opciones;
}

double sumar(double x,double y)
{
    double result;
    result= x+y;
    return result;
}
double restar(double x,double y)
{
    double result;
    result= x-y;
    return result;
}
double multiplicar(double x,double y)
{
    double result;
    result= x*y;
    return result;
}
double dividir(double x,double y)
{
    double result;
    if(y==0)
    {
        return 0;
    }
    else
    {
        result= x/y;
        return result;
    }
}
int factorial(double x)
{
    int resp;
    if(x<0){
        return 0;
    }else{
        if(x==1){
            return 1;
        }
        resp=(int)x* factorial(x-1);
        return (resp);
    }



}


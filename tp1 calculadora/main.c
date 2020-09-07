#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
   double num1=0;
   double num2=0;
   int result1;
   int result2;
   double rSuma;
   double rResta;
   double rDivicion;
   double rMultiplicacion;
   char rta = 's';
   char confirma;
   int flagMostrar=0;

   do{
 printf("x= %.2lf \n",num1);
 printf("y= %.2lf \n",num2);

    switch(menu())
    {
        case 'a':
            printf("Ingrese el primer numero  \n");
            scanf("%lf",&num1);

        break;
        case 'b':
            printf("Ingrese el segundo numero  \n");
            scanf("%lf",&num2);

        break;
        case 'c':

            rSuma =sumar(num1,num2);
            rResta = restar(num1,num2);
            rDivicion =dividir(num1,num2);
            rMultiplicacion =multiplicar(num1,num2);
            result1= factorial(num1);
            result2= factorial(num2);
            flagMostrar =1;

        break;
        case 'd':
           if(flagMostrar==1){
            printf("El resultado de X+Y es: %lf\n",rSuma);
            printf("El resultado de X-Y es: %lf\n",rResta);
            if(rDivicion==0){
                printf("Error, no es posible dividir por cero\n");
            }else{
                printf("El resultado de X/Y es: %lf\n",rDivicion);
            }
            printf("El resultado de X*Y es: %lf\n",rMultiplicacion);

            if(result1==0 && result2==0){
               printf("Los dos numeros menores o iguales a 0\n");
           }else if(result2==0){
                printf("El segundo numero menor o igual a 0\n");
                }else if(result1==0){
                    printf("El primer numero menor o igual a 0\n");
                }else{
                    printf("El factorial de X es: %d y El factorial de Y es: %d\n",result1,result2);
                }
           }else{
            printf("no se puede mostar sin antes hacer las operaciones\n");
           }

        break;

        case 'e'://salir
            printf("Queres salir?, pulsa s si asi lo desea: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
                {
                    rta='n';
                }
        break;

        default:
            printf("opcion invalida, ingrese una opcion correcta");
    }

    system("pause");
    system("cls");

   }while(rta == 's');
    return 0;
}




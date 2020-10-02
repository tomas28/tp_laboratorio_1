
typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}employee;


void inicializarEmpleados(employee*,int );
void altaEmpleado(employee* empleado, int tam);
int buscarLibre(employee* empleado, int tam);
int estudiante_buscarID(employee empleado[], int tam, int valorBuscado, int* posicion);
int estudiante_baja(employee empleado[], int tam);
int estudiante_modificar(employee empleado[], int tam);
int estudiante_listar(employee empleado[], int tam);
int ordenarDescendente(employee empleado[], int tam);
void ordenAscendente(employee empleado[], int tam);
void ordenarPorNombreYSector(employee empleado[], int tam);
float promedioSalarios(employee empleado[],int tam);
float totalSalarios(employee empleado[],int tam);
int empleadosSuperanPromedio(employee empleado[],int tam);
void mostrarSalarios(employee empleado[], int tam);
void imprimir(employee empleado[], int tam);


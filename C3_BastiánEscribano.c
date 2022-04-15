// Nombre: Bastián Escribano
// Rut: 20.202.091-7
// Carrera: Ingeniería de Ejecución en Computación e Informática
// Asignatura: Análisis de Algoritmos y Estructura de Datos
// Sección: C-3

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

// Descripción: Función que se encarga de leer la primera linea de un archivo
// Dominio: 
// Recorrido: 
// Complejidad Algorítmica de la Función: O(n)
int leerCantidad(char *nombre){
    FILE *fp;
    fp = fopen(nombre, "r");
    char buffer[100];
    fscanf(fp, "%s", buffer); // Esto solo lee la primera linea
    int valor = atoi(buffer); // Esto transforma la primera linea de str a int
    fclose(fp);
    return valor;}

// Descripción: Función que exporta un arreglo a una línea de archivo.
// Dominio: arreglo (puntero), largo (entero), nombre (carácter)
// Recorrido: vacío
// Complejidad Algorítmica de la Función: O(n)
void exportarArreglo(int *arreglo, int largo, char *nombre){
    FILE *fp;
    int i;
    fp = fopen(nombre, "w");
    for (i = 0; i < largo; i++){
        fprintf(fp, "%d ", arreglo[i]);}
    fclose(fp);}

// Descripción: Función que realiza la escritura de la segunda línea de un archivo en un arreglo.
// Dominio: arregloPizzas (puntero-entero), nombre (puntero-carácter)
// Recorrido: arregloPizzas (puntero)
// Complejidad Algorítmica de la Función: O(n)
int *importarArreglo(int *arreglo, char *nombre){
    int i = 0;
    int f = 0;
    FILE *in_file = fopen(nombre, "r");
    if (!in_file){
        perror("fopen");
        exit(EXIT_FAILURE);}
    struct stat sb;
    if (stat(nombre, &sb) == -1){
        perror("stat");
        exit(EXIT_FAILURE);}
    char *file_contents = malloc(sb.st_size);
    while (fscanf(in_file, "%[^\n ] ", file_contents) != EOF){
        if (f == 0)
            f++;
        else{
            arreglo[i] = atoi(file_contents);
            i++;}}
    fclose(in_file);
    return arreglo;}

// Descripción: Función que realiza la voltereta de las pizzas
// Dominio: arreglo (puntero), largo (entero), pivote (entero)
// Recorrido: vacío
// Complejidad Algorítmica de la Función: O(n)
void voltearPizzas(int *arreglo, int largo, int pivote){
    int pizzaTemporal;
    for (int i = pivote; i < largo; i++){
        pizzaTemporal = arreglo[largo - 1];
        arreglo[largo - 1] = arreglo[i];
        arreglo[i] = pizzaTemporal;
        largo = largo - 1;}} 

// Descripción: Función que encuentra el diámero mayor de una pizza desde una posición
// Dominio: arreglo (puntero), largo (entero), pivote (entero)
// Recorrido: índice mayor (entero)
// Complejidad Algorítmica de la Función: O(n)
int pizzaMayor(int *arreglo, int largo, int pivote){
    int mayor = arreglo[pivote];
    int indiceMayor = pivote;
    for (int i = pivote; i < largo; i++){
        if (arreglo[i] > mayor){
            mayor = arreglo[i];
            indiceMayor = i;}}
    return indiceMayor;}

// Descripción: Función principal
// Dominio: argc, argv
// Recorrido: 0
int main(int argc, char *argv[]){
    // DEFINICIÓN DE VARIABLES
    clock_t cInit, cEnd;
    int largo, mayor, i;
    int cantidadVolteretas = 0;
    char nombreEntrada[30];
    char nombreSalida[30];

    // VERIFICACIÓN DE PARÁMETROS DE ENTRADA
    if (argc == 3){
        strcpy(nombreEntrada, argv[1]);
        strcpy(nombreSalida, argv[2]);}
    else if (argc == 1){
        strcpy(nombreEntrada, "Entrada.in");
        strcpy(nombreSalida, "Salida.out");}
    else if (argc == 2){
        strcpy(nombreEntrada, argv[1]);
        strcpy(nombreSalida, "Salida.out");}
    else{
        printf("Error de entradas. Reinicie el programa.\n");}   

    largo = leerCantidad(nombreEntrada);
    int *arreglo = (int *)malloc(sizeof(int) * largo); // Se reserva la memoria para la cantidad de datos
    arreglo = importarArreglo(arreglo, nombreEntrada);
    int *volteretas = (int *)malloc(sizeof(int)); // Se reserva la memoria para la cantidad de datos

    cInit = clock(); // Inicio de tiempo para el algoritmo
    
    for (i = 0; i <=largo; i++){
        mayor = pizzaMayor(arreglo, largo, i);
        if (i == largo){
            volteretas[cantidadVolteretas-1] = 0;
            exportarArreglo(volteretas, cantidadVolteretas, nombreSalida);}
        else{
            if (mayor == largo-1){
                voltearPizzas(arreglo,largo,i);
                cantidadVolteretas++;
                volteretas[cantidadVolteretas - 1] = i+1;}
            else if (mayor != i){
                voltearPizzas(arreglo, largo, mayor);
                cantidadVolteretas++;
                volteretas[cantidadVolteretas - 1] = mayor + 1;
                voltearPizzas(arreglo, largo, i);
                cantidadVolteretas++;
                volteretas[cantidadVolteretas - 1] = i + 1;}}}
    cEnd = clock(); // Fin de tiempo para el algoritmo
    printf("Tiempo de Ejec:  %f\n", (double)(cEnd - cInit) / CLOCKS_PER_SEC);

    free(arreglo);
    free(volteretas);

    return 0;
}
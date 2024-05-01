/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO
	ALUMNO: TEJEDA MOYAO LEON FRANCISCO
	GRUPO:3CV12
	MATERIA:ANALISIS DE ALGORITMOS
	PROFESOR: BENJAMIN LUNA BENOSO
	FECHA:7/SEP/2022
	PRACTICA 1:ALGORITMO DE BUSQUEDA ENTRE SUBARREGLOS
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generar_arreglo(int pasos, int tam);
int analizar_arreglo(int * arreglo, int tam, int pasos);
void graficar(int pasos, int tam);


int main (void)
{
    int pasos;

    for(int i = 1; i <= 100 ; i++)
    {
        pasos = generar_arreglo(0, i*10);
        printf("Número de pasos: %d \n", pasos);
    }
}

int generar_arreglo(int pasos, int tam)
{
    int * arreglo;
    int numero;
    int limite;
    pasos++;

    srand(time(NULL));
    pasos++;

    /*
    printf("Ingrese el tamaño del arreglo \n");
    scanf("%d", &tam);
    pasos += 2;
    */

    //Se genera arreglo del tamaño indicado
    arreglo = (int *) malloc(tam * sizeof (int));
    pasos++;

    limite = (3*tam) + 1;
    pasos++;

    pasos++;
    for(int i = 0; i < tam; i++)
    {
        pasos++;

        numero = rand() % limite;
        pasos++;

        //printf("Numero: %d generado \n", numero);
        arreglo[i] = numero;
        pasos++;
        printf("--Número: %d ingresado --\n", arreglo[i]);
        pasos++;
    }
    pasos++;

    pasos = pasos + analizar_arreglo(arreglo, tam, pasos);

    pasos++;
    //Se libera memoria
    free(arreglo);

    graficar(tam, pasos);

    pasos++;
    return pasos;
}

int analizar_arreglo(int * arreglo, int tam, int pasos)
{
    pasos++;
    //Se analiza la primera mitad del arreglo
    for(int x = 0; x < tam/2; x++)
    {
        pasos++;

        pasos++;
        //Se analiza la segunda mitad del arreglo
        for(int y = tam/2; y < tam; y++)
        {
            pasos++;

            if(arreglo[x] == arreglo[y])
            {
                pasos++;

                pasos++;
                printf("\nDato: %d encontrado en posiciones: %d y %d \n", arreglo[x], x, y );

                pasos++;
                return pasos;
            }    
        }
        pasos++;
    }
    pasos++;

    pasos++;
    printf("\nNo se encontró ningun dato repetido \n");

    pasos++;
    return pasos;
}

void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);
}
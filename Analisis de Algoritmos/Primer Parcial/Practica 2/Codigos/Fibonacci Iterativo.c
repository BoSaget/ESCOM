/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO
	ALUMNO: TEJEDA MOYAO LEON FRANCISCO
	GRUPO:3CV12
	MATERIA:ANALISIS DE ALGORITMOS
	PROFESOR: BENJAMIN LUNA BENOSO
	FECHA:19/OCT/2022
	PRACTICA 2:Complejidades Temporales Polinomiales y No Polinomiales
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int pasos, int digito);
void graficar(int pasos, int tamanio);


int main (void)
{
    int pasos;

    for(int i = 1; i <= 40 ; i++)
    {
        //Sacará los primeros 20 valores de Fibonacci
        pasos = fibonacci(0, i);
        printf("Número de pasos: %d \n", pasos);
    }
}

int fibonacci(int pasos, int digito)
{
    int * serie = (int*) malloc (digito * sizeof(int));
    pasos++;

    serie[0] = 0;
    pasos++;

    serie[1] = 1;
    pasos++;

    pasos++;
    for(int i = 2; i<digito; i++)
    {
        pasos++;
        serie[i] = serie[i-2] + serie[i-1];
        pasos++;
    }
    pasos++;

    printf("%d \n",serie[digito-1]);

    free(serie);
    graficar(digito, pasos);
    return pasos;
}


void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1Iterativo.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);
}
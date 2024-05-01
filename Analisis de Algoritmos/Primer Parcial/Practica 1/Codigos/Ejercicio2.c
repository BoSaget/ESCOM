/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO
	ALUMNO: TEJEDA MOYAO LEON FRANCISCO
	GRUPO:3CV12
	MATERIA:ANALISIS DE ALGORITMOS
	PROFESOR: BENJAMIN LUNA BENOSO
	FECHA:7/SEP/2022
	PRACTICA 1:ALGORITMO DE EUCLIDES
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euclides(int a, int b);
void graficar(int pasos, int tam);


int main (void)
{
    int pasos;
    int a;
    int b;
    int mayor;

    srand(time(NULL));

    for(int i = 1; i <= 100 ; i++)
    {
        a = rand() % 999;
        b = rand() % 999;

        if(a > b)
        {
            mayor = a;
        }

        else if( b > a)
        {
            mayor = b;
        }

        else
        {
            mayor = a;
        }

        printf("Numeros asignados %d y %d \n", a, b);
        pasos = euclides(a, b);
        printf("Número de pasos: %d \n", pasos);
        graficar(mayor, pasos);
    }
}

int euclides(int a, int b)
{
    int pasos;
    
    pasos++;
    int mcd;

    pasos++;
    while(b != 0)
    {
        mcd = a % b;
        a = b;
        b = mcd;
        pasos+=3;
    }

    pasos++;
    printf("El mcd fue: %d\n", a);

    pasos++;


    return pasos;  
}

void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ejercicio2.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);
}
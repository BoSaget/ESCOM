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

int perfecto(int pasos, int digito);
void graficar(int pasos, int tamanio);


int main (void)
{
    int pasos;
    int numero;

    for(int i = 2; i<=500 ; i++)
    {
        //Sacará los primeros 20 números perfectos
        pasos = 0;
        perfecto(pasos, i);
        //printf("Número de pasos: %d \n", numero);
        graficar(numero, pasos);
        
    }
}

int perfecto(int pasos, int digito)
{
    int aux=0;
	for(int i= 1; i< digito; i++)
    {
    	if(digito % i == 0)
    	{
    		aux = aux + i;
		}
	}
	
	if(aux == digito)
	{
		printf("Es perfecto %d \n", digito);
		return 1;
	}
//printf("No es perfecto %d \n", digito);
return 0;
}


void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1Recursivo.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);
}
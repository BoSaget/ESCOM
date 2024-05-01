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

int fibonacci(int *pasos, int digito);
void graficar(int pasos, int tamanio);


int main (void)
{
    int pasos;
    int numero;

    for(int i = 20; i>=1 ; i--)
    {
        //Sacará los primeros 20 valores de Fibonacci
        pasos = 0;
        numero = fibonacci(&pasos, i);
        printf("Número de pasos:%d %d \n", pasos ,numero);
        graficar(numero, pasos);
    }
}

int fibonacci(int *pasos, int digito)
{
    (*pasos)++;
	if(digito > 0)
    {	
		(*pasos)++;
		if(digito == 1)
    	{
    		(*pasos)++;
    		//printf("%d ", pasos);
			return 1;
		}
		
		(*pasos)++;
		//printf("%d ", pasos);
		return fibonacci(pasos, digito-1) + fibonacci(pasos, digito-2);
	}
	(*pasos)++;
	//printf("%d ", pasos);
	return 0;
	
}


void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ejercicio1Recursivo.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);;
}
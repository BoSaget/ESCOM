#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int img[500][500];
int repetidos[256];
int pasos;

void funcion(int fil, int col)
{
	int aux = 0;
	pasos++;
	
	pasos++;
	for(int i=0; i< col; i++)
	{
		pasos++;
		
		aux = img[fil-1][i];
		pasos++;
		
		repetidos[aux]++;
		pasos++;
	}
	pasos++;
	
	pasos++;
	if(fil > 1)
	{
		funcion(fil-1, col);
		pasos++;
	}
}

void graficar(int x, int y)
{
    FILE * archivo;

    archivo = fopen("Ej2-5.csv", "a+");

    fprintf(archivo, "%d, %d \n", x, y);

    fclose(archivo);
}

int main (void)
{
	int numero;
	int aux = 0;
	srand(time(NULL));
	
	for(int i= 0; i < 256; i++)
	{
		repetidos[i] = 0;
	}
	
	for(int i=0; i<=500; i++)
	{
		for(int j=0; j<=500; j++)
		{
			numero=rand() % 256;
			
			img[i][j]=numero;
			
			//printf("%d ", numero);
		}
		//printf("\n");
	}
	
	for(int i = 10; i<= 500; i+=10)
	{
		pasos=0;
		funcion(i, i);
		graficar(i, pasos);
	}
	
	/*
	for(int i =0; i<256; i++)
	{
		if(repetidos[i] > 0)
		{
			printf ("\n El valor %d est� repetido: %d", i, repetidos[i]);
			aux++;
		}
	}
	printf("\n%d", aux);
	*/
	printf("Archivo creado");
return 0;
}

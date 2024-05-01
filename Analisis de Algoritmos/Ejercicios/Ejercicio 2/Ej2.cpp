#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int img[500][500];
int pasos;

void funcion(int fil, int col)
{
	int repetidos [256];
	int aux;
	aux = 0;
	pasos = 3;
	
	pasos++;
	for(int i = 0; i<256; i++)
	{
		pasos++;
		
		repetidos[i] = 0;
		pasos++;
		
		pasos++;
	}
	
	pasos++;
	for(int i=0; i<=fil; i++)
	{
		pasos++;
		
		pasos++;
		for(int j=0; j<=col; j++)
		{
			pasos++;
			
			aux=img[i][j];
			pasos++;
			
			repetidos[aux]++;
			pasos++;
			
			pasos++;
		}
		pasos++;
	}
	
	/*
	for(int i =0; i<256; i++)
	{
		printf("El número %d se repitio %d\n", i, repetidos[i]);
	}
	*/
}

int main (void)
{
	int numero;
	int aux = 0;
	srand(time(NULL));
	
	
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
		printf("%d;%d\n", i, pasos);
	}
	
return 0;
}

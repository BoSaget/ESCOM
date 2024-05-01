#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int pasos;

void funcion(int lista[], int n)
{
    int numeros[n];
    pasos++;
    
    pasos++;
    for(int i =0; i<n; i++)
    {
    	pasos++;
    	
		numeros[i]=lista[i];
		pasos++;
		
		pasos++;
	}
    
    pasos++;
    for(int i = 0; i<n; i++)
    {
		pasos++;
		
		pasos++;
		for(int j =0; j< n; j++)
    	{
    		pasos++;
    		
    		pasos++;
			if(lista[i] == numeros[j] && i!=j)
    		{
    			//printf("Se repite el  numero %d en la posicion %d y %d\n",lista[i], i, j);
    			pasos++;
			}
			pasos++;
		}
		pasos++;
	}
    
}

int main (void)
{
    int lista[1000];
    int *repetidos;

    srand(time(NULL));

    pasos = 0;

    for(int i=0; i<1000; i++)
    {
        lista[i]=rand() % 100;
        //lista[i]=10;
    }
    
    
    
    for(int i=10; i<1000; i+=10)
    {
    	funcion(lista, i);
    	printf("%d;%d \n", i, pasos);
    	pasos = 0;
	}

    

return 0;
}

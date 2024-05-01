#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int*** llenar(int cubo[][][])
{
	//Se crea lo necesario para generar números aleatorios
	int numero, x, y, z;
    srand(time(NULL));
	
	for(x=0; x<5; x++)
	{
		for(y=0; y<5; y++)
		{
			for(z=0; z<5; z++)
			{
				//Como se creará de 1 a 100
				numero = (rand() % 99) + 1;
				cubo[x][y][z] = numero;
			}
		}
	}
	
return cubo;
}

int main (void)
{
    //Se inicializa el cubo de 5x5x5
	int cubo[5][5][5];
	 
	cubo=llenar(cubo);
    
    printf("%d y %d", cubo[0][0][0], cubo[4][4][4]);

return 0;
}

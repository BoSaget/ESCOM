#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int pasos;

int funcion(int cx[], int cy[], int len)
{
    int m, aux;
    m=0;
    pasos = 3;

	pasos ++;
    for(int i=0; i<len; i++)
    {
		pasos++;
		
		aux=cy[i]/cx[i];
		pasos++;
        
        //printf("%d / %d = %d \n", cy[i], cx[i], aux);
	
		pasos++;
        if(aux>m)
        {
            m=aux;
            pasos++;
            //printf("Nueva pendiente mayor hasta el momento: %d \n", m);
        }
        pasos++;
    }
    
return m;
}

int main (void)
{
    int cx[1000];
    int cy[1000];
    int m;
    srand(time(NULL));

    pasos = 0;

    for(int i=0; i<1000; i++)
    {
        cx[i]=rand();
        cy[i]=rand();
    }
    
    for(int i=10; i<1000; i+=10)
    {
    	m=funcion(cx,cy, i);
    	//printf("Mayor pendiente encontrada es: %d \n", m);
    	//printf("");
    	printf("%d;%d\n", i, pasos);
    	pasos = 0;
	}

    

return 0;
}

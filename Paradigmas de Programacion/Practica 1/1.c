/*
Practica 1 Programaci√≥n Funcional - Progama 1.
Paradigmas de programaci√≥n
Autor: Tejeda Moyao Leon Francisco

*/

#include <stdio.h>
#include <math.h>


int esPrimo(int numero)
{
	int numeroActual;
	numeroActual = numero-1;

	while (numeroActual > 1)
	{
		if(numero % numeroActual == 0)
		{
			return 0;
		}
		numeroActual--;
	}
return 1;
}

void ListadoPrimos (char numero[], int listaPrimos[])
{
	int numeroEntero;
	numeroEntero=0;
	int contador;
	contador = 0;
	int numeroActual;
	
	int i;
	int aux;
	aux = 4;
	
	for(i=0; i<5; i++)
	{
		numeroEntero = numeroEntero + ((numero[i] - '0')*pow(10,aux));
		aux--;
	}
	
	numeroActual = numeroEntero + 1;
	
	while(contador < 5)
	{
		if(esPrimo(numeroActual) == 1)
		{
			listaPrimos[contador] = numeroActual;
			contador++;
		}
		numeroActual++;
	}
}

int main (void)
{
	//Se declara un arrelgo de largo 5 para almacenar el numero
    char numeroIngresado[5];
    int listaPrimos [5];
    int suma;
    suma = 0;
    int resta;
    resta = 0;
    long long multi;
    multi=0;
    double division;
    division = 0;
    long long  sumaPotencia;
    sumaPotencia=0;
    
    int menu;
    menu =0;
    int i;
    
    while(menu == 0)
    {
    	printf("Ingrese sus numeros\n");
	    for(i=0; i<5; i++)
	    {
	        //Se lee como cadena para que se pueda leer de una mismas linea.
			scanf("%c",&numeroIngresado[i]);
			if(numeroIngresado[i] == '0')
			{
				printf("Error: Ningun digito del numero puede ser 0\n");
			}	
	    }
		
		printf("--Primera operaciÛn (Listado de Primos)\n");
		ListadoPrimos(numeroIngresado, listaPrimos);
		
		for(i=0; i<5; i++)
	    {
	        printf("%d ", listaPrimos[i]);
	    }
		
		printf("\n");
		
		printf("--Segunda operaciÛn (Suma)\n");
		for(i=0; i<5; i++)
	    {
	        suma += listaPrimos[i];
	    }
	    printf("El resultado de la suma de cada numero es: %d", suma);
		
		printf("\n");
		
		printf("--Tercera operaciÛn(Resta)\n");
		resta = listaPrimos[0];
		for(i=1; i<5; i++)
	    {
	        resta -= listaPrimos[i];
	    }
		
		printf("El resultado de la resta de cada numero es: %d", resta);
		
		printf("\n");
		
		printf("--Cuarta operaciÛn (Suma acumulada de la multiplicaciÛn)\n");
		for(i=0; i<4; i++)
	    {
	        multi += listaPrimos[i] * listaPrimos[i+1];
	    }
		printf("El resultado de la multiplicaciÛn de cada numero es: %lld", multi);
		
		printf("\n");
		
		printf("--Quinta operaciÛn (Suma acumulada de la division)\n");
		for(i=0; i<4; i++)
	    {
	        division += (double)listaPrimos[i] / listaPrimos[i+1];
	    }
		
		printf("El resultado de la division de cada numero es: %lf", division);
		
		printf("\n");
		
		printf("--Sexta operaciÛn (Suma acumulada n^3)\n");
		for(i=0; i<5; i++)
	    {
	        sumaPotencia += pow(listaPrimos[i],3);
	    }
		
		printf("El resultado de la division de cada numero es: %lld", sumaPotencia);
	    
	    printf("\n");
	    menu++;
	}

    

		
    
    
	
return 0;
}

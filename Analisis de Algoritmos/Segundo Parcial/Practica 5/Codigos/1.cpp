/*
	INSTITUTO POLITECNICO NACIONAL
	ESCUELA SUPERIOR DE COMPUTO
	ALUMNO: TEJEDA MOYAO LEON FRANCISCO
	GRUPO:3CV12
	MATERIA:ANALISIS DE ALGORITMOS
	PROFESOR: BENJAMIN LUNA BENOSO
	FECHA:20/DIC/2022
	PRACTICA 5:ALGORITMOS GREEDY
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>

using namespace std;

int * ordenarArreglo(int* C, int tamArreglo)
{
    int aux;
    for(int i=0; i< tamArreglo; i++)
    {
        for(int j=0; j<tamArreglo; j++)
        {
            if(C[j] > C[i])
            {
                aux = C[j];
                C[j] = C[i];
                C[i] = aux;
            }
        }
    }
return C;
}

int *  greedy(int* C, int r, int tamArreglo)
{
    int * S;
    int f, pos, bandera, tamS, aux;
    f = r;
    bandera=0;
    pos = 0;
    tamS = 0;
    aux = 0;
    
    //Crea un arreglo de 2 posiciones
    S = (int *) malloc(2 * sizeof (int));

    //Guarda el tamaño en la primera posición
    S[tamS] = 0;
    tamS++;
    
    //La variable auxiliar indica que ya se recorrió todo el arrelo C
    for(int i =0 ; i < tamArreglo; i++)
    {   
        if(C[i] >= f)
        {
            if(i > 0)
            {
                //si un número cumple la condición, se cambiará a un nueov espacio mas un arreglo
				S = (int *) realloc (S, (tamS+1) * sizeof (int));
                
                //Condicionales para cuando es igual a f o menor
	            if(C[i] == f)
	            {
	            	S[tamS] = C[i];
	                f = r + S[tamS];
	                cout << "---Nueva f. :" << f << " ---" << endl; 
	                tamS++;
				}
				
				else if(C[i-1] < f )
	            {
	            	S[tamS] = C[i-1];
	                f = r + S[tamS];
	                cout << "---Nueva f. :" << f << " ---" << endl; 
	                tamS++;
				}
            }

            else 
            {
                cout << "No es encontró una solución" << endl;
                S = (int *) malloc(sizeof (int));

                //Guarda el tamaño en la primera posición
                S[0] = 0;
                return S;
            }
        }
        
    }
    //Condicional para checar si el ultimo valor cumplia la condición y no entró
    if(S[tamS-1] != C[tamArreglo-1] && C[tamArreglo-1] < f && tamS > 2)
    {
        S[tamS] = C[tamArreglo-1];
        tamS++;
    }
    
	//Condicional en donde la f es mayor a todos lo números del arreglo
    if(tamS == 1 && C[tamArreglo-1] < f)
    {
		S[tamS] = C[tamArreglo-1];
		tamS++;
	}
    
    S[0] = tamS;
return S;
}

int main()
{
    /*
    Crea la r, que es el número de días en el que va a resurtir de fertlizante.
    El rango de este, se encontrará entre 1 y 100
    */
    int r, tamArreglo, d, tamArregloS;
    int *C, *S;
    
    //El tamaño del arreglo será de 10
    tamArreglo = 10;
    C = (int *) malloc(tamArreglo * sizeof (int));
    
    //Caso inicial del problema
    int C2 [] = {0,29,36,50,52,66,71,85,100,117,127,129};
    int r2=150;
    int tamArreglo2 = 12;
    
    srand(time(NULL));
    
    for(int i=0; i<1;i++)
    {

        r = rand() % 100;
        //cout << "r: " << r << endl;
        for(int j = 0; j<tamArreglo ;j++)
        {
            //Se generan número aleatorios para llenar el arreglo C
            d = rand()%200;
            C[j]=d;
        }
    
       
        
        
        //Se manda a ordenar el arreglo y lo imprime
        /*
		C=ordenarArreglo(C, tamArreglo);
        cout << "Arreglo C" << endl;
        for(int j = 0; j <  tamArreglo; j++)
        {
            cout << C[j] << endl;
        }
        */
        
        //S=greedy(C, r, tamArreglo);
        S=greedy(C2, r2, tamArreglo2);
        
        if(S[0] != 0)
        {
            tamArregloS =  S[0];

            cout << "Arreglo solución" << endl;
            for(int j = 1; j < tamArregloS; j++)
            {
                cout << S[j] << endl;
            }
        } 
    }

    return 0;
}
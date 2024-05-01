#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * fibo (void * dato);

void main(int argc, char **argv)
{
    pthread_t * hilos;
    void * retorno;
    int * arreglo;
    int *serie;
    int tam;
    int aux;
    

    //Solicita por lo minimo 1 hilo
    if(argc < 2)
    {
        printf("Por favor ingrese los numeros que necesite \n");
        return;
    }

    tam = argc -1;

    //Se asigna el espacio a los hilos requeridos
    hilos = (pthread_t *) malloc(tam * sizeof (pthread_t));

    //Se asigna el tamaño del arreglo de manera dinamica
    arreglo = (int *) malloc(tam * sizeof (int));


    //Se pasan los valores al arreglo
    for(int i = 0; i < tam; i ++)
    {
        arreglo[i] = atoi(argv[i+1]);
    }

    //Se analiza dato por dato
    for(int i = 0; i<tam; i++)
    {
        //Se crea el hilo
        pthread_create(&hilos[i], NULL, fibo, &arreglo[i]);
    }

    for(int i = 0; i < tam; i++)
    {
        //Termina el hilo y recibe la serie
        pthread_join(hilos[i], &retorno);
        serie = (int *) retorno;


        //Imprime la serie
        printf("Serie Recibida:\n");
        aux = serie [0];

        //Imprime la serie
        for(int j = 0; j < aux; j++)
        {
            if(j == 0 || aux == 0)
            {
                printf("0 ");
            }

            else
            {
                printf("%d ", serie[j]);
            }
        }
        printf("\n");
    }
    
    //Se debe liberar memoria
    free(hilos);

    printf("\nFin \n");
}

void * fibo(void * datoVoid)
{
    int * serie;
    int dato = *((int *) datoVoid);
    int numActual = 0;
    int tam;

    //Si el valor ingresado es 0
    if(dato == 0)
    {
        //Se le asigna el valor del primer dato
        serie = (int *) malloc (1 * sizeof (int));
        serie[0] = 1;
    }
    
    //Si el valor ingresado es 1
    else if( dato == 1)
    {
        //Se asignan los primeros 2 valores para la serie
        serie = (int *) malloc (2 * sizeof (int));
        serie[0] = 2;
        serie[1] = 1;
    }
    
    //Si el valor es mayor
    else
    {
        //Se asignan los primeros 2 valores para la serie
        serie = (int *) malloc (2 * sizeof (int));
        serie[0] = 0;
        serie[1] = 1;

        //Delimita para los primeros 7 digitos
        if(dato < 8 && dato > 1)
        {
            tam = 8;
        }

        //Resto de los posibles npumeros
        else
        {
            tam = dato;
        }

        for(int i = 2; i < tam; i ++)
        {
            //Delimita la serie
            if(numActual >= dato)
            {
                tam = i;

                //Guarda el tamaño del arreglo en primera posicion
                serie[0] = i;
            }
            else
            {
                numActual = serie[i-2] + serie[i-1];

                //Se aumenta el valor de la memoria
                serie = (int *) realloc (serie, (i+1) * sizeof (int));
                serie[i] = numActual;
            }        
        }

    }

    pthread_exit((void *) serie);
    free(serie);
}

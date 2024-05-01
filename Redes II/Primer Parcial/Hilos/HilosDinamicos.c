#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void * funcion(void * argumento);

void main(int argc, char **argv){

    //Se Declara Hilo
    pthread_t * hilos;
    char * saludo = "Hola Mundo";
    void * var;

    //Se solicita cantidad de hilos
    if(argc != 2)
    {
        printf("No ha introducido el número de hilos a crear \n");
        exit(0);
    }
    printf("Iniciando hilos de manera dinamica \n");
    //Se obtiene cantidad de hilos a usar
    int numero_hilos = atoi(argv[1]);

    //Se guarda el espacio de manera dinamicaa
    hilos = (pthread_t *) malloc(numero_hilos * sizeof(pthread_t));

    for(int i = 0; i <numero_hilos; i++)
    {
        //Se crea el hilo
        pthread_create(&hilos[i], NULL, funcion, saludo);
    }

    for(int j = 0; j < numero_hilos; j++)
    {
        //Regresa del hilo terminado y obtiene el valor de retorno
        pthread_join(hilos[j], &var);
        //Mensaje de confirmación de regreso
        printf("Dato Recibido %s\n", (char * ) var);
    }
    
    //Se debe liberar memoria
    free(hilos);

    printf("Fin \n");
}

void * funcion (void * cadena)
{
    pthread_t  hilo_prueba = (pthread_t ) cadena;
    char* salida = "Ya salí";

    printf("Soy, el hilo %d dice: %s \n", pthread_self(),cadena);

    //Termina el hilo y manda el valor de retorno
    pthread_exit((void *) salida);
}

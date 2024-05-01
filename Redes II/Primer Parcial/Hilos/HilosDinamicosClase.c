#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <pthread.h>

typedef struct{
    char word[30];
    float nFloat;
    int nInt;
    int indice;
}ThreadP;

void * function(void *);

void main(int argc, char **argv){

    // _/ Paso 1: Creación de hilos \_
    pthread_t * idThread;
    ThreadP * dataThread;
    int nThread;

    void * var;

    if(argc != 2){
        printf("No ha introducido el número de hilos a crear\n");
        exit(0);
    }

    nThread = atoi(argv[1]);

    idThread = (pthread_t *) malloc(nThread * sizeof(pthread_t));
    dataThread = (ThreadP *) malloc(nThread * sizeof(ThreadP));

    for(int i = 0; i < nThread; i++){
        strcpy(dataThread[i].word, "ejemplo");
        dataThread[i].nFloat = 3.2*i;
        dataThread[i].nInt = 3*i;
        dataThread[i].indice = i;

        if(pthread_create(&idThread[i], NULL, function, &dataThread[i]) == -1){
            printf("Error al crear Hilo\n");
            exit(0);
        }
    }

    /*if(pthread_create(&idThread, NULL, function, NULL) == -1){
        printf("Error al crear Hilo\n");
        exit(0);
    }*/

    // _/ Paso 2: Espera del padre a los hijos \_
    for(int j = 0; j < nThread; j++){
        pthread_join(idThread[j], &var);

        // printf("Dato Recibido %f\n", *((float *) var));
        // printf("Dato Recibido %d\n", *((int *) var));
        printf("Dato Recibido %s\n", (char * ) var);
    }

    free(idThread);
    free(dataThread);
}

void * function(void * param){
    // _/ Obtención de Parametro \_
    ThreadP *dataThread = (ThreadP *) param;

    // _/ Paso 3: Crear función que se convertira en Hilo \_
    printf("Yo soy el Hilo: %ld con indice: %d mis datos son:\n Cadena: %s\n Numero Flotante: %f\n Numero Entero: %d\n\n", 
            pthread_self(), 
            dataThread->indice,
            dataThread->word,
            dataThread->nFloat,
            dataThread->nInt);

    // pthread_exit((void *) &dataThread->nFloat);
    // pthread_exit((void *) &dataThread->nInt);
    pthread_exit((void *) &dataThread->word);
}
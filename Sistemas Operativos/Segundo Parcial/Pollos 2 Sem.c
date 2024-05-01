/*
    Grupo 4VC2
    Integrantes:    TEJEDA MOYAO LEON FRANCISCO
                    TELLEZ PARTIDA MARIO IAHVEH
    Ejercicio 1: Pollos
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> //Contiene los tipos de variables para ocupar
#include <sys/ipc.h> //Contiene las estructuras para las subrutinas
#include <sys/shm.h> //Define estructuras que se utilizan para la memoria compartida
#include <semaphore.h> //Contiene las funciones necesarias para utilizar semaforos
#include <unistd.h> //Define las caracteristicas de implementación de POSIX
#include <fcntl.h>

#define NUM_POLLOS 20
#define MAX_COMIENDO 3

//Se define una estructura de semaforos para cada uno de los componentes de la jaula
typedef struct {
    sem_t sem_comida;
    sem_t sem_rueda;
} Jaula;

//Funcion del comportamiento de cada uno de los pollos
void pollo(int id, Jaula* jaula) {
    
    //Se imprime la cción que el pollo desea hacer
    printf("Pollo %d quiere comer.\n", id);
    //En caso de que el semaforo se encuentre disponible accesa
    sem_wait(&jaula->sem_comida); 
    //Cambia estado del pollo
    printf("Pollo %d está comiendo.\n", id);
    //Come en un tiempo aleatorio de entre 1 y 3 segundos
    sleep(rand() % 3 + 1); 
    //Libera el espacio para el plato de comida cambiando el status del semaforo
    sem_post(&jaula->sem_comida);
    //Cambia el estado del pollo 
    printf("Pollo %d dejó de comer \n", id);
    //Se cambia la acción a realizar del pollo
    printf("Pollo %d quiere correr.\n", id);
    //Checa el semaforo para disponer de la rueda
    sem_wait(&jaula->sem_rueda);
    //En el caso en el que la rueda este disponible, entra a correr
    printf("Pollo %d está corriendo.\n", id);
    //El pollo correrá entre 1 y 3 segundos
    sleep(rand() % 3 + 1); 
    //Libera la rueda para ser utilizada
    sem_post(&jaula->sem_rueda);
    //Cambia el estado del pollo
    printf("Pollo %d dejó de correr \n", id);
    //Muestra que el proceso del pollo ha terminado
    printf("Pollo %d ha terminado.\n", id);
    exit(0);
}

int main() {
    // Crear o abrir la memoria compartida
    //shmget devuelve el identificador de memoria compartida
    int shmid = shmget(IPC_PRIVATE, sizeof(Jaula), 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("Error al crear la memoria compartida");
        exit(1);
    }
    // Adjunta la memoria compartida al espacio de direcciones del proceso
    Jaula* jaula = shmat(shmid, NULL, 0);

    // Inicializa los semáforos.
    sem_init(&jaula->sem_comida, 1, MAX_COMIENDO);
    sem_init(&jaula->sem_rueda, 1, 1);

    //Ciclo que va a crear tantos procesos asi como pollos
    for (int i = 0; i < NUM_POLLOS; i++) {
        
        pid_t pid = fork();
        if (pid == 0) {
            pollo(i, jaula);
        } else if (pid < 0) {
            perror("Error en fork");
            exit(1);
        }
    }

    //Espera a que terminen todos los procesos
    for (int i = 0; i < NUM_POLLOS; i++) {
        wait(NULL);
    }

    //Destruye ambos semaforos
    sem_destroy(&jaula->sem_comida);
    sem_destroy(&jaula->sem_rueda);

    // Desvincular y eliminar la memoria compartida
    shmdt(jaula);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
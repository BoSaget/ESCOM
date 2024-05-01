#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

#define NUM_POLLOS 20
#define MAX_COMIENDO 3

typedef struct {
    sem_t sem_comida;
    sem_t sem_rueda;
    sem_t sem_orden; // Semáforo para mantener el orden de los pollos
} Jaula;

void pollo(int id, Jaula* jaula) {
    sem_wait(&jaula->sem_orden); // Espera su turno

    printf("Pollo %d quiere comer.\n", id);
    sem_wait(&jaula->sem_comida); 
    printf("Pollo %d está comiendo.\n", id);
    sleep(rand() % 3 + 1); 
    sem_post(&jaula->sem_comida);
    printf("Pollo %d dejó de comer \n", id);
    
    printf("Pollo %d quiere correr.\n", id);
    sem_wait(&jaula->sem_rueda);
    printf("Pollo %d está corriendo.\n", id);
    sleep(rand() % 3 + 1); 
    sem_post(&jaula->sem_rueda);
    printf("Pollo %d dejó de correr \n", id);
    
    printf("Pollo %d ha terminado.\n", id);

    sem_post(&jaula->sem_orden); // Libera el turno para el siguiente pollo
    exit(0);
}

int main() {
    int shmid = shmget(IPC_PRIVATE, sizeof(Jaula), 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("Error al crear la memoria compartida");
        exit(1);
    }
    Jaula* jaula = shmat(shmid, NULL, 0);

    // Inicializa los semáforos.
    sem_init(&jaula->sem_comida, 1, MAX_COMIENDO);
    sem_init(&jaula->sem_rueda, 1, MAX_COMIENDO);
    sem_init(&jaula->sem_orden, 1, 6);

    for (int i = 0; i < NUM_POLLOS; i++) {
        
        pid_t pid = fork();
        if (pid == 0) {
            pollo(i, jaula);
        } else if (pid < 0) {
            perror("Error en fork");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_POLLOS; i++) {
        wait(NULL);
    }

    sem_destroy(&jaula->sem_comida);
    sem_destroy(&jaula->sem_rueda);
    sem_destroy(&jaula->sem_orden);

    shmdt(jaula);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
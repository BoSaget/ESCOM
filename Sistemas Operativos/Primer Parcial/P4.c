/*
Programa hecho por: Leon Francisco Tejeda Moyao
Sistemas Operativos Grupo 4CV2
Practica 4: "Zonas de datos entre procesos vinculados"
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Define las caracteristicas de implementación de POSIX
#include <sys/types.h> //Contiene los tipos de variables para ocupar
#include <sys/ipc.h> //Contiene las estructuras para las subrutinas
#include <sys/shm.h> //Define estructuras que se utilizan para la memoria compartida

int main() 
{
    //Se crea una variable de tipo pid_t para crear el proceso hijo
    pid_t pid;
    pid = fork();

    int shm_id;

    //ftok() genera una clave basada en los parametros
    key_t key = ftok("shared_memory_example", 65); // Generar una clave única

    // Crear o abrir la memoria compartida
    //shmget devuelve el identificador de memoria compartida
    shm_id = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Adjunta la memoria compartida al espacio de direcciones del proceso
    int *shared_data = (int*)shmat(shm_id, NULL, 0);
    if (shared_data == (int*)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Escribir datos en la memoria compartida
    *shared_data = 20;

    //La funcion fork() regresa -1 si hubo algún problema al crear el proceso
    if (pid < 0) 
    {
        printf("Error al crear el proceso hijo\n");
        exit(1);
    }

    //La función fork() regresa 0 si es un proceso hijo
    else if (pid == 0)
    {
        printf("Proceso hijo (%d) - Variable compartida: %d\n", getpid(), *shared_data);

        //Se le suma uno para saber que el proceso hijo entró
        *shared_data = *shared_data + 1;

        //Leer los datos desde la memoria compartida
        printf("Valor en la memoria compartida: %d\n", *shared_data);

        //Esperar un poco antes de que otro proceso lea los datos
        sleep(2);
    }

    //La función fork regresa 1 si es un proceso padre
    else
    {
        printf("Proceso padre (%d)  del proceso (%d) - Variable compartida: %d\n", getpid(), pid, *shared_data);

        //Se le suma 10 para saber que el proceso padre entró
        *shared_data = *shared_data + 10;

        //Leer los datos desde la memoria compartida
        printf("Valor en la memoria compartida: %d\n", *shared_data);

        //Esperar un poco antes de que otro proceso lea los datos
        sleep(2);
    }

    //Se imprime el valor final
    printf("Valor final de la memoria: %d\n", *shared_data);
    
    // Desvincular y eliminar la memoria compartida
    shmdt(shared_data);
    shmctl(shm_id, IPC_RMID, NULL);

    //Se imprime el valor final despues de desvincular la memoria
    //printf("Valor agregado: %d\n", *shared_data); Esta linea está comentada porque la acceder a la memoria se muestra un segmentation fault

return 0;
}
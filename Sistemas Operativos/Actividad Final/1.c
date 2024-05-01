#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Define las caracteristicas de implementación de POSIX
#include <sys/types.h> //Contiene los tipos de variables para ocupar
#include <sys/ipc.h> //Contiene las estructuras para las subrutinas
#include <sys/shm.h> //Define estructuras que se utilizan para la memoria compartida
#include <sys/wait.h> // Para poder utilizar l afunción wait

int main() {
  int pid1, pid2;

  pid1 = fork();
  if (pid1 == 0)
  {
    for(int i = 0; i <= 9; i++)
    {
        printf("Proceso hijo 1: %d\n", i+1);
    }
    return 0;
  }

  pid2 = fork();
  if (pid2 == 0) 
  {
    for(int j = 0; j <= 9; j++)
    {
        printf("Proceso hijo 2: %d\n", j+1);
    }
    return 0;
  }

  // Espera a que los procesos hijos terminen
  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);

  printf("Proceso padre: Terminado\n");

  return 0;
}

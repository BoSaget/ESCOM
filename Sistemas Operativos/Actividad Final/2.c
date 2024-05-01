#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  // Variables para los semaforos
  sem_t sem_par, sem_impar;

  // Inicializar los semaforos
  sem_init(&sem_par, 0, 1);
  sem_init(&sem_impar, 0, 1);

  // Crear los procesos hijos
  pid_t pid_par, pid_impar;
  pid_par = fork();
  if (pid_par == 0) {
    // Proceso hijo que imprime los números pares
    for (int i = 2; i <= 10; i += 2) {
      // Esperar a que el proceso impar imprima su número
      sem_wait(&sem_impar);
      printf("%d ", i);
      // Liberar el semáforo para el proceso par
      sem_post(&sem_par);
    }
    exit(0);
  } else {
    // Proceso hijo que imprime los números impares
    for (int i = 1; i <= 9; i += 2) {
      // Esperar a que el proceso par imprima su número
      sem_wait(&sem_par);
      printf("%d ", i);
      // Liberar el semáforo para el proceso impar
      sem_post(&sem_impar);
    }
    exit(0);
  }

  // Esperar a que terminen los procesos hijos
  waitpid(pid_par, NULL, 0);
  waitpid(pid_impar, NULL, 0);

  // Liberar los semaforos
  sem_destroy(&sem_par);
  sem_destroy(&sem_impar);

  return 0;
}

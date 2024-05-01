//High Response Ratio Next (HRRN)
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESOS 5


//Se crea una estructura de datos para poder analizar el ID del proceso y sus unidades de timepo
typedef struct {
    int procesoID;
    int tiempoLlegada;
    int tiempoServicio;
} Proceso;

//Prototipo de la ufnción, donde se pasarás el arreglo de los procesos asi como el máximo de procesos
void HRRN(Proceso procesos[], int n);

int main() {
    
    //Se declara un arreglo de 5 procesos
	Proceso procesos[MAX_PROCESOS];
    int i;

	//Se solicitan e introducen tanto los tiempos de llegada como de servicio
    // Inicializar procesos
    for (i = 0; i < MAX_PROCESOS; i++) {
        procesos[i].procesoID = i + 1;
        printf("Introduce el tiempo de llegada para el proceso %d: ", i + 1);
        scanf("%d", &procesos[i].tiempoLlegada);
        printf("Introduce el tiempo de servicio para el proceso %d: ", i + 1);
        scanf("%d", &procesos[i].tiempoServicio);
    }

    // Llamar al algoritmo HRRN
    HRRN(procesos, MAX_PROCESOS);

    return 0;
}

void HRRN(Proceso procesos[], int n) {
    
    //Se crea una variable para marcar la unidad de tiempo actual
    int tiempoActual = 0;
    //Se crea un contador los procesos 
    int completados = 0;

    printf("\n----- Ejecución utilizando el algoritmo HRRN -----\n");


    //Se emplea un ciclo while que termina hasta el MAX__PROCESOS esté completado
    while (completados < n) {

        //Se almacena el id del proceso 
        int nextProceso = -1;
        //Se calcula la tasa de respuesta más alta para priorizar la cola de procesos a ejecutar
        float highestRatio = -1.0;

        for (int i = 0; i < n; i++) {
            if (procesos[i].tiempoLlegada <= tiempoActual && procesos[i].tiempoServicio > 0) {

                //Se calcula la tasa de respuesta
                //tiempoActual - procesos[i].tiempoLlegada =  tiempo de espera
                float ratio = (tiempoActual - procesos[i].tiempoLlegada + procesos[i].tiempoServicio) / procesos[i].tiempoServicio;
                
                //Se calcula la mayor tasa de respues y se compara con la tasa de respuesta del proceso actual y se guarda el ID del proceso con mayor tasa de respuesta
                if (ratio > highestRatio) {
                    highestRatio = ratio;
                    nextProceso = i;
                }
            }
        }
        
        if (nextProceso == -1) {
            tiempoActual++;
        } else {
            //Se van ejecutando los proesos dependiendo de cual es el que tiene la mayor tasa de respuesta
            printf("Ejecutando proceso %d\n", procesos[nextProceso].procesoID);
            //Al haber sido ejecutado se modifica el tiempo de servicio, para asi quitarlo del arreglo
            procesos[nextProceso].tiempoServicio = 0;

            //Se incrementa el tiempo actual y el contador de los procesos completados
            tiempoActual++;
            completados++;
        }
    }
}

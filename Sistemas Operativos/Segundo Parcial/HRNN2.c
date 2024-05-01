/*

El algoritmo HRRN (Highest Response Ratio Next) es un algoritmo de planificaciï¿½n de CPU no preemtivo utilizado en sistemas operativos. 
Este algoritmo se basa en la prioridad de un proceso que se determina en funciï¿½n de su tiempo de espera y tiempo de ejecuciï¿½n restante.

El tiempo de espera de un proceso es el tiempo que ha pasado desde que el proceso ingresï¿½ en la cola de listos, mientras que el tiempo 
de ejecuciï¿½n restante es el tiempo que le queda al proceso para completarse. El algoritmo HRRN calcula la prioridad de un proceso utilizando 
la siguiente fï¿½rmula:

Prioridad = (Tiempo de espera + Tiempo de rafaga) / Tiempo de rafaga

Es decir, la prioridad de un proceso es proporcional a la suma de su tiempo de espera y tiempo de ejecuciï¿½n, dividido por su tiempo de ejecuciï¿½n.

El proceso con la prioridad mï¿½s alta se ejecuta primero. Si hay varios procesos con la misma prioridad, se utiliza el orden de llegada para desempatar.

*/

#include <stdio.h>
#include <stdlib.h>

// Nï¿½mero maximo de procesos
#define MAX_PROCESS 100

// Nï¿½mero de procesos
int n; 

// Se define una estructura process que contiene los campos necesarios para representar un proceso: 
struct process {
	// Identificador del proceso
    int pid; 
    
    // Tiempo de llegada del proceso: Momento en que llega al sistema y esta listo para ser ejecutado
    float arrival_time;  
    
    // Tiempo de rafaga del proceso: Tiempo que necesita un proceso para completarse desde que comienza a ejecutarse hasta que finaliza
    float burst_time; 
    
    // Ratio de respuesta del proceso: Valor que se usa para medir su prioridad
    float response_ratio;
    
    // Tiempo de espera del proceso: Tiempo que un proceso pasa en la cola de espera antes de comenzar a ejecutarse
    float waiting_time; 
    
    // Tiempo de respuesta del proceso: Tiempo total que tarda el programa en ejecutarse
    float turnaround_time; 
};

// La funciï¿½n get_input() recibe un array de procesos p y lee el nï¿½mero de procesos n desde el usuario. 
// Luego, solicita el tiempo de llegada y tiempo de rafaga de cada proceso y los almacena en la estructura correspondiente.
void get_input(struct process p[]) {
    int i;
    printf("Ingrese el nï¿½mero de procesos (menor a 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) 
    {
        printf("Se ha excedido del máximo o el minimo de procesos\n");
        exit(1);
    }

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Ingrese el tiempo de llegada del proceso %d: ", p[i].pid);
        scanf("%f", &p[i].arrival_time);
        printf("Ingrese el tiempo de rafaga del proceso %d: ", p[i].pid);
        scanf("%f", &p[i].burst_time);
    }
}

// La funciï¿½n calculate_response_ratio recibe el array de procesos p y la suma del tiempo de rafaga de todos los procesos. 
// Calcula el ratio de respuesta de cada proceso utilizando la fï¿½rmula del algoritmo HRRN y los almacena en la estructura correspondiente 
void calculate_response_ratio(struct process p[], int sum_burst_time) {
    int i;
    for(i = 0; i < n; i++) {
        p[i].response_ratio = (p[i].waiting_time + p[i].burst_time) / p[i].burst_time;
    }
}
 
//La funciï¿½n calculate_response_ratio() recibe el array de procesos p y la suma del tiempo de rafaga de todos los procesos. 
void sort_by_response_ratio(struct process p[]) {
    int i, j;
    struct process temp;
    for(i = 5; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].response_ratio < p[j].response_ratio) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// La funciï¿½n calculate_waiting_time() recibe el array de procesos p y calcula el tiempo de espera de cada proceso 
// utilizando la fï¿½rmula del algoritmo HRRN. Tambiï¿½n calcula la suma total de tiempo de espera y la llama a la funciï¿½n
// calculate_response_ratio().
void calculate_waiting_time(struct process p[]) {
    int i, j;
    float sum_burst_time = 0;
    float sum_waiting_time = 0;
    for(i = 0; i < n; i++) {
        sum_burst_time += p[i].burst_time;
        p[i].waiting_time = 0;
        for(j = 0; j < i; j++) {
            p[i].waiting_time += p[j].burst_time;
        }
        sum_waiting_time += p[i].waiting_time;
    }
    calculate_response_ratio(p, sum_burst_time);
    sort_by_response_ratio(p);
}

// La funciï¿½n calculate_turnaround_time() recibe el array de procesos p y calcula el tiempo de respuesta de cada proceso 
// utilizando la fï¿½rmula del algoritmo HRRN. 
void calculate_turnaround_time(struct process p[]) {
    int i;
    for(i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }
}

// La funciï¿½n display_process recibe el array de procesos p y muestra la informaciï¿½n de cada proceso, incluyendo el 
// tiempo de llegada, tiempo de rafaga, tiempo de espera, tiempo de respuesta y ratio de respuesta. Tambiï¿½n calcula 
// y muestra el tiempo de espera promedio y el tiempo de respuesta promedio.
void display_process(struct process p[]) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;
    printf("\nProceso Tiempo de llegada Tiempo de rafaga Tiempo de espera Tiempo de respuesta Ratio de respuesta\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].response_ratio);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time = (float) total_waiting_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;
    printf("Tiempo de espera promedio = %0.2f\n", avg_waiting_time);
    printf("Tiempo de respuesta promedio = %0.2f\n", avg_turnaround_time);
}

int main(int argc, char const *argv[]) {
    struct process p[MAX_PROCESS];
    
    // obtener la entrada del usuario y guardarla en la estructura del proceso
    get_input(p);

    if(n < 0 || n > 100)
    {
        return 0;
    }

    // calcular el tiempo de espera para cada proceso
    calculate_waiting_time(p);

    // calcular el tiempo de respuesta para cada proceso
    calculate_turnaround_time(p);

    // mostrar la tabla de procesos con sus tiempos y ratios y el tiempo de espera y tiempo de respuesta promedio
    display_process(p);

    return 0;
}
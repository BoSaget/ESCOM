#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

char **Palabras;
int *pal, *hil;

struct nodo{
    int pos;
    char * nombre_archivo;

    int cant_palabras_archivo;
    int * resultado;
};

// numero de hilos, numero de palabras a contar

int contarPalabras(FILE *archivo)
{
    int cont = 0;
    char a[50];

    while (feof(archivo) == 0)
    {
        fscanf(archivo, "%s", a);
        cont++;
    }
    return cont;
}

int contadorDeRepeticiones(FILE *f, int *cuentas)
{
    while (!feof(f))
    {
        char palabra_actual[50];
        fscanf(f, "%s", palabra_actual);
        for (int i = 0; i < (*pal); ++i)
        {
            if (strcmp(palabra_actual, Palabras[i]) == 0)
            {
                cuentas[i]++;
            }
        }
    }
}

void *LeerArchivo(void *id)
{
    struct nodo *arch = (struct nodo *)id;
    int *rep = (int *)(malloc((*pal) * (sizeof(int))));
    FILE *f;
    f = fopen(arch->nombre_archivo, "r");
    if (f != NULL)
    {
        for (int i = 0; i < (*pal); ++i)
        {
            rep[i] = 0;
        }
        contadorDeRepeticiones(f, rep);
        arch->resultado =rep;
        printf("El archivo %s contiene:\n", arch->nombre_archivo);
        arch->cant_palabras_archivo = contarPalabras(f);
        for (int i = 0; i < (*pal); ++i)
        {
            printf("\t%6d\t %s\n", rep[i], Palabras[i]);
        }
    }
    else
    {
        fprintf(stderr, "No se pudo abrir el archivo %s\n", arch->nombre_archivo);
    }

    // int tam = contarPalabras(f);
    // printf("El archivo: %s  tiene %d palabras\n",arch,tam);
    pthread_exit((void *)arch);
}
int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Por favor indica cuantos hilos necesitas\n");
        exit(-1);
    }

    int numeroDeHilos = atoi(argv[1]);
    int numeroDePalabras = atoi(argv[2]);
    hil = &numeroDeHilos;
    pal = &numeroDePalabras;
    char **nombre_Archivos = (char **)malloc(numeroDeHilos * sizeof(char *));
    struct nodo *nodos = (struct nodo*) malloc(numeroDeHilos *sizeof(struct nodo));

    Palabras = (char **)malloc(numeroDePalabras * sizeof(char *));
    // struct nodo * array_datos = (struct nodo *)malloc(numeroDeHilos*sizeof(struct nodo));
    system("clear");

    for (int i = 0; i < numeroDePalabras; i++)
    {
        char palabra[100];
        printf("Por favor dime las palabras que deseas buscar en los archivos\n");
        scanf("%s",palabra);
        /*int tam = (int)strlen(palabra);
        palabra[tam] = '\0';
        */
        Palabras[i] = (char *)(malloc(strlen(palabra) * sizeof(char)));
        strcpy(Palabras[i], palabra);
    }
    system("clear");
    for (int i = 0; i < numeroDeHilos; i++)
    {
        char palabra[100];
        printf("Por favor idica el archivo que deseas revisar\n");
        scanf("%s",palabra);
        /*int tam = (int)strlen(palabra);
        palabra[tam] = '\0';
        */
        nodos[i].nombre_archivo = (char *)(malloc(strlen(palabra) * sizeof(char)));
        strcpy(nodos[i].nombre_archivo, palabra);
    }
    system("clear");
    pthread_t *thread1 = (pthread_t *)malloc(numeroDeHilos * sizeof(pthread_t));
    // struct nodo * valor_Retorno;
    for (int i = 0; i < numeroDeHilos; i++)
    {
        nodos[i].pos=i;
        // strcpy(arrayNode[i].nombre,"Hola mundo yo soy el hilo: ");

        pthread_create(thread1 + i, NULL, LeerArchivo, &nodos[i]);
    }

    for (int j = 0; j < numeroDeHilos; j++)
    {
        pthread_join(thread1[j], NULL /*(void **)(&valor_Retorno)*/); // TAREA 1. SABER COMO RECIBIR PARAMETROS DEL JOIN
        // printf("%i\n",(*valor_Retorno).i);
    }
    // printf("%i\n",(*valor_Retorno).i);

    free(thread1);
    // free(arrayNode);

    // TAREA 2. HACERLO CON MEMORIA DINAMICA
    return 0;
}
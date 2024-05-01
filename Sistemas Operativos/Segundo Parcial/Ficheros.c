/*
    Grupo 4VC2
    Integrantes:    TEJEDA MOYAO LEON FRANCISCO
                    TELLEZ PARTIDA MARIO IAHVEH
    Ejercicio 3 de los ficheros
*/
#include <stdio.h>      // Inclusión de la biblioteca estándar de entrada/salida.
#include <stdlib.h>     // Inclusión de la biblioteca estándar para funciones como exit.
#include <sys/types.h>  // Necesario para tipos de datos como uid_t.
#include <sys/stat.h>   // Inclusión de la biblioteca para obtener información de los atributos de los archivos.
#include <unistd.h>     // Acceso a la API de POSIX (por ejemplo, geteuid).
#include <dirent.h>     // Necesaria para las funciones de directorio como opendir.
#include <errno.h>      // Acceso a la variable errno para determinar el tipo de error.
#include <string.h>     // Para usar funciones de manejo de cadenas como strcmp.
#include <time.h>       // Para manipular y formatear tiempos.
#include <limits.h>     // Para constantes como PATH_MAX.

// Función que busca los archivos que cumplen con las condiciones en el directorio dado.
void search_dir(const char *dir_name, uid_t user_uid, time_t time_threshold) {
    DIR *d;                // Puntero a la estructura DIR para recorrer directorios.
    struct dirent *entry;  // Estructura para información de la entrada del directorio.
    struct stat statbuf;   // Estructura para almacenar información del archivo/directorio.
    char filepath[PATH_MAX + 1];  // Array para guardar la ruta completa de cada archivo.

    d = opendir(dir_name); // Intenta abrir el directorio.
    if (!d) {
        fprintf(stderr, "No se puede abrir el directorio '%s': %s\n", dir_name, strerror(errno));
        return;
    }

    // Lee las entradas del directorio.
    while ((entry = readdir(d)) != NULL) {
        snprintf(filepath, PATH_MAX, "%s/%s", dir_name, entry->d_name); // Construye la ruta completa.

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue; // Ignora los directorios '.' (actual) y '..' (padre).

        if (lstat(filepath, &statbuf) == -1) {
            fprintf(stderr, "No se puede acceder a '%s': %s\n", filepath, strerror(errno));
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            search_dir(filepath, user_uid, time_threshold); // Si es un directorio, llamada recursiva.
        } else if (S_ISREG(statbuf.st_mode)) {
            // Si es un archivo regular, verifica el UID y la hora de acceso.
            if (statbuf.st_uid == user_uid && statbuf.st_atime >= time_threshold) {
                printf("Cumple: %s\n", filepath);
            } else {
                printf("No cumple: %s\n", filepath);
            }
        }
    }
    closedir(d); // Cierra el directorio.
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <directorio>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Se abrio el directorio: %s\n", argv[1]);
    printf("\nCriterios:\n-Archivos tales que pertenezcan al usuario que ejecuta el programa\n-Se haya abierto una hora antes de la ejecucion del programa\n\n");

    const char *dir_name = argv[1];                  // El directorio proporcionado como argumento.
    uid_t user_uid = geteuid();                      // Obtiene el UID del usuario que ejecuta el programa.
    time_t time_threshold = time(NULL) - 3600;       // Calcula el tiempo actual menos una hora.

    search_dir(dir_name, user_uid, time_threshold);  // Inicia la búsqueda recursiva.

    return 0; // Finaliza el programa.
}
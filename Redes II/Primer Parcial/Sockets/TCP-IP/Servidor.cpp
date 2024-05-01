#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Index
    char buffer[100];
    if(argc < 3){
        printf("Falto introducir direccion ip y puerto\n");
        exit(-1);
    }

    int puerto = atoi(argv[2]);

    // Paso 1. Creacion del socket
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);

    if(mySocket < 0) {
        printf("Error al abrir socket\n");
        exit(-1);
    }

    // Paso 2. Hacer publico el servicio
    struct sockaddr_in servidor, cliente;
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(puerto);
    servidor.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &(servidor.sin_addr));
    //Acepta conexiones desde cualquier direccion
    //servidor.sin_addr.s_addr = INADDR_ANY;
    bzero(&(servidor.sin_zero), 8);

    

    //char str[INET_ADDRSTRLEN];
    //servidor.sin_addr = inet_ntop(AF_INET, &(servidor.sin_addr), str, INET_ADDRSTRLEN);
    int isBind = bind(mySocket, (struct sockaddr*) &servidor, sizeof(servidor));

    if (isBind == -1) {
        printf("No se estableció la conexion con el servidor\n");
        exit(-1);
    }

    // Paso 3. Encolar las peticiones
    listen(mySocket, 4);
    while(true) {

        // Paso 5. Canal de conexion
        socklen_t tamCliente = sizeof(cliente);
        int canal = accept(mySocket, (struct sockaddr*) &cliente, &tamCliente); //ID del canal

        if(canal == -1) {
            printf("No se establecio el canal \n");
            exit(-1);
        }

        //Paso 6. Recibir
        int tam = recv(canal, buffer, sizeof(buffer), 0);
        buffer[tam] = '\0';
        printf("Mensaje del cliente: %s\n", buffer);

        // Paso 7. Enviar la respuesta del servidor
        strcpy(buffer, "Soy servidor");
        tam = send(canal, buffer, strlen(buffer), 0);
        close(canal);
    }

    return 0;
}
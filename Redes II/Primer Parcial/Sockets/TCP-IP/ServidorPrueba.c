#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
int main(int argc, char **argv) {
    // Index
    char buffer[100];
    int e;
    struct sockaddr_in servidor, cliente;
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
    memset(buffer,'0',sizeof(buffer));
    memset(&servidor,'0',sizeof(servidor));
    memset(&cliente,'0',sizeof(cliente));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(puerto);
    e=inet_pton(AF_INET, argv[1], &(servidor.sin_addr));
//    e=inet_pton(AF_INET,"127.12.42.105", &(servidor.sin_addr.s_addr));
    printf("inet devolvio:%d\n",e);
    int isBind = bind(mySocket, (struct sockaddr *)&servidor, sizeof(servidor));

    if (isBind == -1) {
        printf("No se pudo enlazar el servidor, Error\n %s\n",strerror(errno));
        exit(-1);
    }

    // Paso 3. Encolar las peticiones
    listen(mySocket, 4);
    int canal;
    socklen_t tamCliente;
    int tamBuff=sizeof(buffer);
    while(1) {
        // Paso 5. Canal de conexion
        tamCliente = sizeof(cliente);
        canal = accept(mySocket, (struct sockaddr*)&cliente, &tamCliente); //ID del canal
        if(canal!=-1)printf("Aceptado canal %d\n",canal);
        if(canal == -1) {
            printf("No se establecio el canal\n");
            exit(-1);
        }

        do{
            //Paso 6. Recibir
            int tam = recv(canal, buffer,tamBuff, 0);
            buffer[tam] = '\0';
            printf("Cliente: %s\n", buffer);
            if(strncmp(buffer,"exit",4)==0)break;//Cerro coneccion
            // Paso 7. Enviar la respuesta del servidor
            for (int i = 0; i < tamBuff; i++) buffer[i]='\0';
            printf("\nMensaje a cliente: ");
            fgets(buffer,tamBuff,stdin);
            send(canal, buffer, strlen(buffer), 0);
        }while(strncmp(buffer,"exit",4)!=0);
        printf("Cerrando canal %d\n",canal);
        close(canal);
    }

    return 0;
}
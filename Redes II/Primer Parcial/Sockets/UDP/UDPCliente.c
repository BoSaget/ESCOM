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
    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in servidor,cliente;
    if(argc < 5){
        printf("Falto introducir direccion ip y puerto\n");
        exit(-1);
    }

    int puerto = atoi(argv[2]);
    int puerto2 = atoi(argv[4]);

    // Paso 1. Creacion del socket
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);

    if(mySocket < 0) {
        printf("Error al abrir socket\n");
        exit(-1);
    }

    // Paso 2. Establecer la conexion hacia el servidor
    memset(buffer,'0',sizeof(buffer));
    memset(&cliente,'0',sizeof(cliente));
    cliente.sin_family = AF_INET;
    cliente.sin_port = htons(puerto);
    inet_pton(AF_INET, argv[1], &(cliente.sin_addr));

    memset(buffer,'0',sizeof(buffer));
    memset(&servidor,'0',sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(puerto2);
    inet_pton(AF_INET, argv[3], &(servidor.sin_addr));

    int isBind = bind(mySocket, (struct sockaddr*)&cliente, sizeof(cliente));

    if (isBind == -1) {
        printf("No se pudo publicar la direccióon del cliente, Error\n %s\n",strerror(errno));
        exit(-1);
    }

    // Paso 3. Fase de comunicacion
    int tamBuffer=sizeof(buffer);
    do{
        printf("\nMensaje a servidor: ");
        fgets(buffer,tamBuffer,stdin);
        sendto(mySocket, buffer, strlen(buffer), 0, (struct sockaddr*)&servidor, sizeof(servidor)); // Enviando mensaje al servidor
        if(strncmp(buffer,"exit",4)==0) break;
        // Paso 4. Recibir el mensaje
        for (int i = 0; i < tamBuffer; i++) buffer[i]='\0';
        int len = sizeof(servidor);
        int mensaje = recvfrom(mySocket, buffer, tamBuffer, 0, (struct sockaddr*)&servidor, &len);
        buffer[mensaje] = '\0';
        
        inet_ntop(AF_INET, &(servidor.sin_addr), ip, INET_ADDRSTRLEN);
        
        printf("Servidor(%s): %s\n", ip, buffer);
    }while(strncmp(buffer,"exit",4)!=0);
    // Paso 5. Se cierra el socket
    close(mySocket);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    //Index
    char buffer[100];
    
    if(argc < 3)
    {
        printf("Falto indtroducir dirección ip y puerto \n");
        exit(-1);
    }

    int puerto = atoi(argv[2]);

    //Paso 1 Crecion del socket
    int mysocket = socket(AF_INET, SOCK_STREAM, 0);

    if(mysocket < 0)
    {
        printf("Error al abrir socket \n");
        exit(-1);
    } 

    //Paso 2 Establecer la conexión hacia el servidor
    struct sockaddr_in servidor;
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(puerto);

    //Pasa la cadena de formato char a formato de red
    servidor.sin_addr.s_addr = inet_pton(AF_INET, argv[1], &(servidor.sin_addr));

    /*Para pasar la cadena de formato de red a formato de char
    char str(INET_ADDRSSTRLEN);
    servidor.sin_addr = inet_ntop(AF_INET, &(servidor.sin_addr), str INET_ADDRSSTRLEN);
    */

   int isConnect = connect(mysocket, (struct sockaddr*) &servidor, sizeof(servidor));

   if(isConnect == -1)
   {
    printf("No se ha establecido la conexión con el servidor \n");
    exit(-1);
   }

   //Paso 3 Fase de comunicación
   strcpy(buffer, "Hola desde cliente");
   send(mysocket, buffer, strlen(buffer), 0);

   //Paso 4 Recibir el mensaje
   int mensaje = recv(mysocket, buffer, sizeof(buffer), 0);
    buffer[mensaje] = '\0';

    printf("Mensaje recibido por el servidor \n");
    close(mysocket);

return 0;
}
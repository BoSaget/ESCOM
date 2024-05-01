#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fecha[20];
    char hora[20];
    char actividad[100];
} registroAgenda;

registroAgenda* agregarRegistro(registroAgenda* agenda, int* registros)
{
	(*registros)++;
    agenda = (registroAgenda*) realloc(agenda, (*registros) * sizeof(registroAgenda));

    printf("Fecha (dd/mm/aaaa): ");
    scanf("%s", agenda[*registros-1].fecha);
    printf("Hora (hh:mm): ");
    scanf("%s", agenda[*registros-1].hora);
    printf("Tarea: ");
    scanf(" %[^\n]s", agenda[*registros-1].actividad);

    printf("Registro agregado correctamente.\n");
    
return agenda; 
}

void mostrar(registroAgenda* agenda, int registros)
{
	int i;
	for(i = 0; i < registros; i++)
	{
        printf("%d. %s - %s - %s\n", i+1, agenda[i].fecha, agenda[i].hora, agenda[i].actividad);
    }	
}

void guardarEnArchivo(registroAgenda* agenda, int registros)
{
	int i;
	FILE *archivo;
	
	archivo = fopen("agenda.csv", "w");
    if(archivo == NULL) 
	{
        printf("Error al abrir el archivo.\n");
    } 
	
    else
    {
    	fprintf(archivo, "FECHA, HORA, ACTIVIDAD\n");
		for(i = 0; i < registros; i++) 
		{
	        
			fprintf(archivo, "%s,%s,%s\n", agenda[i].fecha, agenda[i].hora, agenda[i].actividad);
	    }
	    
	    printf("Registros guardados correctamente en el archivo.\n");
	    fclose(archivo);
	}
}

int main() {
    int opcion, numRegistros;
    registroAgenda *agenda = NULL;
    
    
    opcion = 0;
    numRegistros = 0;

    while(opcion != 4)
	{
        printf("\n\tAGENDA\n");
        printf("1. Agregar registro\n");
        printf("2. Mostrar registros\n");
        printf("3. Guardar registros en archivo\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
		{
            case 1:
                agenda = agregarRegistro(agenda, &numRegistros);

                break;
                
            case 2:
                if(numRegistros == 0)
				{
                    printf("No hay registros en la agenda.\n");
                }
                else
                {
                	mostrar(agenda, numRegistros);
				}
				
                break;
                
            case 3:
                if(numRegistros == 0)
				{
                    printf("No hay registros en la agenda.\n");
                }
				else
				{
                    guardarEnArchivo(agenda, numRegistros);
                }
                
                break;
                
            case 4:
                printf("Saliendo de la agenda.\n");
                break;
                
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    }

    free(agenda);
    return 0;
}


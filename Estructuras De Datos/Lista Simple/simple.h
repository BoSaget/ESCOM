#include <stdio.h>
#include <stdlib.h>

struct Simple
{
	int dato;
	struct Simple * Siguiente;	
};

struct Simple * Insertar_Nodo(struct Simple * , int );

void Mostrar_Lista(struct Simple * );

struct Simple * Eliminar_Nodo(struct  Simple * , int);

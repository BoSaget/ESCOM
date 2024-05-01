#include <stdio.h>
#include <stdlib.h>

struct Cola
{
	int dato;
	struct Cola * Siguiente;
	struct Cola * First;
	struct Cola * Last;
};

struct Cola * Insertar(struct Cola * , int );

void Mostrar_First(struct Cola * );

struct Cola * Eliminar(struct  Cola * );

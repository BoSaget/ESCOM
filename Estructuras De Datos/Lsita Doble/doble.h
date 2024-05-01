#include <stdio.h>
#include <stdlib.h>

struct Doble
{
	int dato;
	struct Doble * Siguiente;
	struct Doble * Anterior;	
};

struct Doble * Insertar_Nodo(struct Doble * , int);

void Mostrar_ListaDoble(struct Doble *);

struct Doble * Eliminar_Nodo(struct  Doble * , int);

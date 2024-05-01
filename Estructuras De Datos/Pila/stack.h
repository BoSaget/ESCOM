#include <stdio.h>
#include <stdlib.h>

struct Pila
{
	int dato;
	struct Pila * Siguiente;
	struct Pila * Tope;
	struct Pila * Fin;	
};

struct Pila * Insertar(struct Pila * , int );

void Mostrar_Tope(struct Pila * );

struct Pila * Eliminar_Tope(struct  Pila * );

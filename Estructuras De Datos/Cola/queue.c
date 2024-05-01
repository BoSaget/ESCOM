#include "queue.h"

struct Cola * Insertar(struct Cola * Fila, int dato)
{
	struct Cola * Actual;
	Actual = Fila;
	
	struct Cola * Nuevo;
	Nuevo=malloc(sizeof(struct Cola));
	Nuevo->dato=dato;
	Nuevo->Siguiente=NULL;
	
	if(Actual == NULL)
	{
		Fila=Nuevo;
		Fila->First=Nuevo;
	}
	
	else
	{
		while(Actual->Siguiente != NULL)
		{
			Actual = Actual->Siguiente;
		}
		Actual->Siguiente= Nuevo;
		Fila->Last=Nuevo;
	}
return Fila;
}

void Mostrar_First(struct Cola * Fila)
{
	if(Fila == NULL)
	{
		printf ("La Cola esta Vacia");
	}
	
	else
	{
		printf("%d", Fila->First->dato);
	}
}

struct Cola * Eliminar(struct  Cola * Fila)
{
	if(Fila==NULL)
	{
		printf("No se pueden eliminar mas datos");
	}
	
	else
	{
		struct Cola * Aux;
		Aux=Fila;
		
		Fila=Fila->Siguiente;
		Fila->First=Fila;
		Aux->Siguiente=NULL;
	}
	
return Fila;
}

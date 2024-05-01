#include "stack.h"

struct Pila * Insertar(struct Pila * Mi_Pila, int dato)
{	
	struct Pila * Aux;
	Aux=Mi_Pila;
	struct Pila * Nuevo;
	Nuevo=malloc(sizeof(struct Pila));
	Nuevo->dato=dato;
	Nuevo->Siguiente=Mi_Pila;
	Mi_Pila=Nuevo;
	
	if(Aux == NULL)
	{
		Mi_Pila->Fin=Nuevo;
	}
	
	Mi_Pila->Tope=Nuevo;
	
return Mi_Pila;
}

void Mostrar_Tope(struct Pila * Mi_Pila)
{
	if(Mi_Pila == NULL)
	{
		printf("La Pila esta Vacia");
	}
	else
	{
		printf("%d",Mi_Pila->Tope->dato);
	}
}

struct Pila * Eliminar_Tope(struct  Pila * Mi_Pila)
{
	struct Pila * Aux;
	Aux=Mi_Pila;
	
	if(Mi_Pila == NULL)
	{
		printf("La Pila esta Vacia, No se pueden eliminar datos");
	}
	
	else
	{
		Mi_Pila->Tope=Aux->Siguiente;
		Mi_Pila=Mi_Pila->Siguiente;
		Aux->Siguiente=NULL;
	}
	
return Mi_Pila;
}

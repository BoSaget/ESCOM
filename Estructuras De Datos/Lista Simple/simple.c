#include "simple.h"

//Mete Hasta EL Final
struct Simple * Insertar_Nodo(struct Simple * Mi_Lista, int dato)
{
	struct Simple * Actual;
	Actual=NULL;
	Actual = Mi_Lista;

	struct Simple * Nuevo;
	Nuevo=malloc(sizeof(struct Simple));
	Nuevo->dato=dato;
	Nuevo->Siguiente=NULL;

	if(Actual == NULL)
	{
		Mi_Lista=Nuevo;
	}

	else
	{
		while(Actual->Siguiente != NULL)
		{
			Actual = Actual->Siguiente;
		}
		Actual->Siguiente= Nuevo;
	}
return Mi_Lista;
}

void Mostrar_Lista(struct Simple * Mi_Lista)
{
	struct Simple * Actual;
	Actual=NULL;
	Actual=Mi_Lista;

	if(Actual == NULL)
	{
		printf ("La Lista esta Vacia");
	}

	else
	{
		while(Actual != NULL)
		{
			printf("%d \t", Actual->dato);

			Actual = Actual->Siguiente;
		}
	}
}

struct Simple * Eliminar_Nodo(struct  Simple * Mi_Lista, int dato)
{
	struct Simple * Borrar;
	Borrar = NULL;
	Borrar = Mi_Lista;

	struct Simple * Aux;

	if(Borrar->dato == dato)
	{
		Mi_Lista=Mi_Lista->Siguiente;
	}

	else
	{
		while(Borrar->Siguiente->dato != dato)
		{
			Borrar=Borrar->Siguiente;
		}
		Aux=Borrar;
		Borrar=Borrar->Siguiente;
		Aux->Siguiente=Borrar->Siguiente;
	}
return Mi_Lista;
}

#include "doble.h"

//Mete Hasta EL Final
struct Doble * Insertar_Nodo(struct Doble * Mi_Lista, int dato)
{
	struct Doble * Actual;
	Actual = Mi_Lista;
	
	struct Doble * Nuevo;
	Nuevo=malloc(sizeof(struct Doble));
	Nuevo->dato=dato;
	Nuevo->Siguiente=NULL;
	Nuevo->Anterior=NULL;
	
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
		Nuevo->Anterior=Actual;
	}
return Mi_Lista;
}

void Mostrar_ListaDoble(struct Doble * Mi_Lista)
{
	struct Doble * Actual;
	Actual=Mi_Lista;
	
	if(Actual == NULL)
	{
		printf ("La Lista esta Vacia");
	}
	
	else
	{
		while(Actual->Siguiente != NULL)
		{
			printf("%d \t", Actual->dato);
			
			Actual = Actual->Siguiente;
		}
		printf("%d",Actual->dato);
	}
	
	printf("\n");
	
	while(Actual != Mi_Lista)
	{
		printf("%d \t", Actual->dato);
	
		Actual = Actual->Anterior;
	}
	printf("%d",Actual->dato);
}

struct Doble * Eliminar_Nodo(struct  Doble * Mi_Lista, int dato)
{
	struct Doble * Borrar;
	Borrar = Mi_Lista;
	
	struct Doble * Aux;
	
	if(Borrar->dato == dato)
	{
		Mi_Lista=Mi_Lista->Siguiente;
		Mi_Lista->Anterior=NULL;
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
		Aux->Siguiente->Anterior=Borrar->Anterior;
	}
return Mi_Lista;
}

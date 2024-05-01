#include <stdio.h>
#include <stdlib.h>

struct Circular
{
	int dato;
	struct Circular * Siguiente;
	struct Circular * Fin;
};

//Mete Hasta EL Final
struct Circular * Insertar_Nodo(struct Circular * Mi_Lista, int dato)
{
	struct Circular * Actual;
	Actual = Mi_Lista;
	
	struct Circular * Nuevo;
	Nuevo=malloc(sizeof(struct Circular));
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

	Mi_Lista->Fin=Nuevo;
	
return Mi_Lista;
}

void Mostrar_Circular(struct Circular * Mi_Lista)
{
	struct Circular * Actual;
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
}

struct Circular * Eliminar_Nodo(struct Circular * Mi_Lista, int dato)
{
	struct Circular * Borrar;
	Borrar = Mi_Lista;
	
	struct Circular * Aux;
	
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

int main (void)
{	
	struct Circular * Numeros;
	Numeros=NULL;
	
	Numeros=Insertar_Nodo(Numeros, 5);
	Numeros=Insertar_Nodo(Numeros, 4);
	Numeros=Insertar_Nodo(Numeros, 3);
	Numeros=Insertar_Nodo(Numeros, 2);
	Numeros=Insertar_Nodo(Numeros, 1);

	Mostrar_Circular(Numeros);
	
	printf("\n%d", Numeros->Fin->dato);
	
	printf("\n");
	
	Eliminar_Nodo(Numeros, 2);
	
	Mostrar_Circular(Numeros);
	
return 0;
}

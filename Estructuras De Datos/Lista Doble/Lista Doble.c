#include <stdio.h>
#include <stdlib.h>

struct Doble
{
	int dato;
	struct Doble * Siguiente;
	struct Doble * Anterior;	
};

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

int main (void)
{
	struct Doble * Numeros;
	Numeros=NULL;
	
	Numeros=Insertar_Nodo(Numeros, 5);
	Numeros=Insertar_Nodo(Numeros, 4);
	Numeros=Insertar_Nodo(Numeros, 3);
	Numeros=Insertar_Nodo(Numeros, 2);
	Numeros=Insertar_Nodo(Numeros, 1);

	Mostrar_ListaDoble(Numeros);
	
	
	printf("\n");
	
	Numeros=Eliminar_Nodo(Numeros, 2);
	
	Mostrar_ListaDoble(Numeros);
	
return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Cola
{
	int dato;
	struct Cola * Siguiente;
	struct Cola * First;
	struct Cola * Last;
};

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

int main (void)
{
	struct Cola * Numeros;
	Numeros=NULL;
	
	Numeros=Insertar(Numeros, 5);
	Numeros=Insertar(Numeros, 1);
	Numeros=Insertar(Numeros, 4);
	Numeros=Insertar(Numeros, 2);
	Numeros=Insertar(Numeros, 3);

	Mostrar_First(Numeros);
	
	printf("\n");
	
	Numeros=Eliminar(Numeros);
	
	Mostrar_First(Numeros);
	
return 0;
}

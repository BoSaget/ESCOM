#include <stdio.h>

struct Nodo
{
	int dato;
	struct Nodo * Siguiente;	
};

struct Lista
{
	struct Nodo * Inicio;
};

//Mete Hasta EL Final
void Insertar_Nodo(struct Lista * Mi_Lista, int dato)
{
	struct Nodo * Actual;
	Actual = Mi_Lista->Inicio;
	
	if(Mi_Lista->Inicio == NULL)
	{
		Mi_Lista->Inicio->dato=dato;
		Mi_Lista->Inicio->Siguiente=NULL;
	}
	
	else
	{
		while(Actual->Siguiente != NULL)
		{
			Actual = Actual->Siguiente;
		}
		
		Actual= Actual->Siguiente;
		Actual->dato=dato;
	}
}

void Mostrar_Lista(struct Lista * Mi_Lista)
{
	struct Nodo * Actual;
	Actual=Mi_Lista->Inicio;
	
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
	}
}

int main (void)
{
	int i=0;
	struct Lista * Numeros;
	Numeros=NULL;
	
	for(i=0; i<21; i=i+2)
	{
		Insertar_Nodo(Numeros, i);
	}
	
	Mostrar_Lista(Numeros);
	
return 0;
}

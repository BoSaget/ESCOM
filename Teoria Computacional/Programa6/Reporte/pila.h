#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


struct Pila
{
	char dato;
	struct Pila * Siguiente;
	struct Pila * Tope;
	struct Pila * Fin;	
};

struct Pila * Insertar(struct Pila * , char );

void Mostrar_Tope(struct Pila * );

struct Pila * Eliminar_Tope(struct  Pila * );

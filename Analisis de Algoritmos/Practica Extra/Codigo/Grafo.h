#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

typedef struct NODO
{
	int id;
	int* nodos_conectados;
	int conexiones;
	struct NODO * siguiente;
}nodo;


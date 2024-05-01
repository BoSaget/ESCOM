#include<iostream>
#include<stdlib.h>
//#include<conio.h>
#include<curses.h>

using namespace std;

typedef struct NODO
{
	int id;
	int* nodos_conectados;
	int conexiones;
	struct NODO * siguiente;
}nodo;

nodo *grafo;

void insertar_nodo()
{
	int id_nodo,aux;
	
	nodo * grafo_aux;
	nodo * nuevo_nodo;
	nuevo_nodo =(nodo *) malloc(sizeof(nodo));
	
	cout << "--Favor de ingresar el id del nodo -- " << endl;
	cin >> id_nodo;
	
	nuevo_nodo->id=id_nodo;
	nuevo_nodo->conexiones = 1;
	nuevo_nodo->siguiente = NULL; 
	
	if(grafo == NULL)
	{
		grafo = nuevo_nodo;
	}
	
	else
	{	
		grafo_aux = grafo;
		while(grafo_aux->siguiente != NULL)
		{
			grafo_aux = grafo_aux->siguiente;
		}
		grafo_aux->siguiente=nuevo_nodo;
	}
	
	cout << "Nodo ingresado correctamente" << endl;
	system("pause");
}

bool exite_nodo(int id_nodo)
{
	nodo * grafo_aux;
	grafo_aux = grafo;
	
	while(id_nodo != grafo_aux->id)
	{
		if(grafo_aux->siguiente == NULL)
		{
			return false;
		}
		grafo_aux = grafo_aux->siguiente;
	}
	return true;
}

void conectar(int nodoRef, int nodoDestino)
{	
	int conexion;
	
	nodo* grafo_aux;
	grafo_aux=grafo;
	
	while(grafo_aux->id != nodoRef)
	{
		grafo_aux = grafo_aux->siguiente;	
	}
	
	conexion = grafo_aux->conexiones;
	
	if(conexion == 1)
	{
		grafo_aux->nodos_conectados = (int*)malloc(conexion*sizeof(int));
		grafo_aux->nodos_conectados[0] = nodoDestino;
		grafo_aux->conexiones = conexion+1;
	}
	else
	{
		grafo_aux->nodos_conectados = (int *) realloc (grafo_aux->nodos_conectados, (conexion) * sizeof (int));
		grafo_aux->nodos_conectados[conexion-1] = nodoDestino;
		grafo_aux->conexiones = conexion+1;
	}
}

void insertar_arista()
{
	int nodo1, nodo2;
	nodo1 = 0;
	nodo2 = 0;
	
	cout << "--Favor de ingresar el id del primer nodo a conectar-- " << endl;
	cin >> nodo1;
	
	if(exite_nodo(nodo1) == false)
	{
		cout<< "Nodo no existente" << endl;
		system("pause");
		return;
	}
	
	cout << "--Favor de ingresar el id del segundo nodo a conectar-- " << endl;
	cin >> nodo2;
	
	if(exite_nodo(nodo2) == false)
	{
		cout<< "Nodo no existente" << endl;
		system("pause");
		return;
	}
	
	//Conexi�n de ida
	conectar(nodo1, nodo2);

	//Conexi�n de vuelta
	conectar(nodo2, nodo1);
	
	
	system("pause");
	
	
}

void mostrar_tabla()
{
	nodo * grafo_aux;
	grafo_aux = grafo;
	
	cout << "-- Tabla de adyacenc�a--" << endl;
	while (grafo_aux != NULL)
	{
		cout << "Nodo: " << grafo_aux->id << "\t" << grafo_aux->nodos_conectados[0] << endl;
		for(int i = 1; i<grafo_aux->conexiones-1; i++)
		{
			if(grafo_aux->nodos_conectados[i] != 0)
			{
				cout << "\t" << grafo_aux->nodos_conectados[i] << endl;
			}
			
		}
		cout << endl;
		grafo_aux=grafo_aux->siguiente;
	}
	system("pause");
}

bool conectado(int id_buscar, nodo * actual)
{
	int limite;
	limite = actual->conexiones;

	for(int i =0; i< limite; i++)
	{
		if(id_buscar == actual->nodos_conectados[i])
		{
			return true;
		}
	}

return false;
}

int ciclo(int nodos)
{
	int ruta[] = {3,1,2,3};
	
	nodo * grafo_aux;
	nodo * inicio;

	inicio = buscarNodo(ruta[0]);
	grafo_aux = inicio;
	
	for(int i = 0; i< nodos+1; i++)
	{
		if (conectado(ruta[i], ruta[i+1]) == false)
		{
			return 0;	
		}
	}
	
return 1;
}

void menu()
{
	grafo = NULL;
	int opcion, hamiltoniano, max_nodos;
	opcion=0;
	max_nodos=0;
	
	while(opcion < 9)
	{
		
		cout << "Favor de seleccionar una opci�n" << endl;
		cout << "1- Ingresar nodo" << endl;
		cout << "2- Ingresar arista" << endl;
		cout << "3- Ver tabla de adyacencia" << endl;
		cout << "4- Ciclo hamiltoniano" << endl;
		cout << "9- Salir" << endl;
		
		cin >> opcion;
		//system("clear");
		switch(opcion){
			case 1:
				insertar_nodo();
				max_nodos++;
				break;
			case 2:
				insertar_arista();
				break;
			case 3:
				mostrar_tabla();
				break;
			case 4:
				hamiltoniano = ciclo(max_nodos);
				
				if(hamiltoniano == -1)
				{
					cout << "No se encontr� nodo de cabecera"<< endl;
				}
				
				else if(hamiltoniano == 0)
				{
					cout << "No es un ciclo" << endl;
				}
				
				else if(hamiltoniano == 1)
				{
					cout << "Si tiene ciclo hamiltoniano" << endl;
				}
				system("pause");
				break;
				
			case 9:
				cout<<"Programa terminado" <<endl;
				return ;
		}
		//system("clear");
	}
}


int main (void)
{
	system("clear");
	menu();
	
return 0;	
}




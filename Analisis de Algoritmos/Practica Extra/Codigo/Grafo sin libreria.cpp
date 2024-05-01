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
		grafo=nuevo_nodo;
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

void insertar_arista()
{
	int nodo1, nodo2;
	nodo1 = 0;
	nodo2 = 0;
	
	nodo * grafo_aux;
	nodo * grafo_aux2;
	grafo_aux = grafo;
	grafo_aux2 = grafo;
	
	int arreglo, arreglo2;
	arreglo = grafo_aux->conexiones;
	arreglo2 = grafo_aux2->conexiones;
	
	
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
	if(grafo_aux->id != nodo1)
	{
		grafo_aux = grafo_aux->siguiente;
	}
	
	if (grafo_aux->conexiones == 1)
	{
		grafo_aux->nodos_conectados = (int*) malloc(sizeof(int));
		grafo_aux->nodos_conectados[0] = nodo2;
		grafo_aux->conexiones = arreglo+1;  
	}
	
	else
	{
		grafo_aux->nodos_conectados = (int*) malloc(arreglo+1 * sizeof(int));
		grafo_aux->nodos_conectados[arreglo+1] = nodo2;
		grafo_aux->conexiones = arreglo+1;
	}
	
	//Conexi�n de vuelta
	if(grafo_aux2->id != nodo2)
	{
		grafo_aux2 = grafo_aux2->siguiente;
	}
	
	if (grafo_aux2->conexiones == 1)
	{
		grafo_aux2->nodos_conectados = (int*) malloc(sizeof(int));
		grafo_aux2->nodos_conectados[0] = nodo1;
		grafo_aux2->conexiones = arreglo+1;  
	}
	
	else
	{
		grafo_aux2->nodos_conectados = (int*) malloc(arreglo+1 * sizeof(int));
		grafo_aux2->nodos_conectados[arreglo+1] = nodo1;
		grafo_aux2->conexiones = arreglo+1;
	}
	
	system("pause");
	
	
}

void mostrar_tabla()
{
	nodo * grafo_aux;
	grafo_aux = grafo;
	
	cout << "-- Tabla de adyacenc�a--" << endl;
	
}

void ciclo()
{
	
}

void menu()
{
	grafo = NULL;
	int opcion = 0;
	
	while(opcion < 9)
	{
		
		cout << "Favor de seleccionar una opci�n" << endl;
		cout << "1- Ingresar nodo" << endl;
		cout << "2- Ingresar arista" << endl;
		cout << "3- Ver tabla de adyacencia" << endl;
		cout << "4- Ciclo hamiltoniano" << endl;
		cout << "9- Salir" << endl;
		
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertar_nodo();
				break;
			case 2:
				insertar_arista();
				break;
			case 3:
				mostrar_tabla();
				break;
			case 4:
				ciclo();
				break;
				
			case 9:
				cout<<"Programa terminado" <<endl;
				return ;
		}
		system("cls");
	}
}


int main (void)
{
	menu();
	
return 0;	
}




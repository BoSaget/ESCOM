#include "pila.h"

using namespace std;


struct Pila * Insertar(struct Pila * Mi_Pila, char dato)
{	
	struct Pila * Aux;
	Aux=Mi_Pila;
	struct Pila * Nuevo;
	Nuevo=(Pila *)malloc(sizeof(struct Pila));
	Nuevo->dato=dato;
	Nuevo->Siguiente=Mi_Pila;
	Mi_Pila=Nuevo;
	
	if(Aux == NULL)
	{
		Mi_Pila->Fin=Nuevo;
	}
	
	Mi_Pila->Tope=Nuevo;
	
return Mi_Pila;
}

void Mostrar_Tope(struct Pila * Mi_Pila)
{
	if(Mi_Pila == NULL)
	{
		//cout << "La Pila esta Vacia" << endl;
	}
	else
	{
		cout << Mi_Pila->Tope->dato;
	}
}

struct Pila * Eliminar_Tope(struct  Pila * Mi_Pila)
{
	struct Pila * Aux;
	Aux=Mi_Pila;
	
	if(Mi_Pila == NULL)
	{
		//cout << "La Pila esta Vacia, No se pueden eliminar datos" << endl;
	}
	
	else
	{
		Mi_Pila->Tope=Aux->Siguiente;
		Mi_Pila=Mi_Pila->Siguiente;
		Aux->Siguiente=NULL;
	}
	
return Mi_Pila;
}

void descripciones(char estado, char evaluacion, string cadena, int aux)
{
	ofstream documento;
	
	if (aux == 0)
	{
		documento.open("Programa6_Descripciones.txt", ios::out);

		if (evaluacion == 'e')
		{
			documento << "d(q, 0, Z0) = {(q, XZ0)}" << endl;
			
			cout << "d(q, 0, Z0) = {(q, XZ0)}" << endl;
		}
		
		//Cadena Rechazada
		else
		{
			documento << "d(p, 1, X) = {(p, e)}" << endl;
			documento << "--Cadena Invalida--" << endl;
			
			cout << "d(p, 1, X) = {(p, e)}" << endl;
			cout << "--Cadena Invalida--" << endl;			
		} 
	}
	
	else
	{
		documento.open("Programa6_Descripciones.txt", ios::app);
		
		if (evaluacion != 'e')
		{
			//Cadena Aceptada
			if (evaluacion == 'a')
			{
				documento << endl;
				documento << "d(p, e, Z0) = {(F, Z0)}" << endl;
				documento << "--Cadena Aceptada--" << endl;
				
				cout << endl;
				cout << "d(p, e, Z0) = {(F, Z0)}" << endl;
				cout << "--Cadena Aceptada--" << endl;
			}
			
			//Cadena Rechazada
			else
			{
				if (estado == 'q')
				{
					documento << "d(q, 0, X) = {(q, " << cadena << ")}" << endl;
					documento << "--Cadena Invalida--" << endl;
				
					cout << "d(q, 0, X) = {(q, " << cadena << ")}" << endl;
					cout << "--Cadena Invalida--" << endl;
				}
				
				else if (aux != -1)
				{
					documento << "d(p, 1, X) = {(p, " << cadena << ")}" << endl;
					documento << "--Cadena Invalida--" << endl;
				
					cout << "d(p, 1, X) = {(p, " << cadena << ")}" << endl;
					cout << "--Cadena Invalida--" << endl;
				}
				
				else
				{
					documento << "--Cadena Invalida--" << endl;
					
					cout << "--Cadena Invalida--" << endl;
				}		
			}
		}
		
		//Cadena en espera de evaluacion
		else
		{
			if (estado == 'q')
			{
				documento << "d(q, 0, X) = {(q, " << cadena << ")}" << endl;
				
				cout << "d(q, 0, X) = {(q, " << cadena << ")}" << endl;
			}
				
			else
			{
				documento << "d(p, 1, X) = {(p, " << cadena << ")}" << endl;
				
				cout << "d(p, 1, X) = {(p, " << cadena << ")}" << endl;
			}
		}
	}
	
	documento.close();
}

void proceso(string cadena)
{
	struct Pila * automata;
	automata=NULL;
	
	string cadena_aux;
	cadena_aux = "e";
	
	int aux;
	
	for (int i = 0; i < cadena.length(); ++i)
	{
		//Filtro para cadenas del tipo: 01010101, 011111
		if(i > 0 && automata == NULL)
		{
			if (cadena[i] == '1')
			{
				descripciones('p', 'r', cadena_aux, i);
			}
			
			else
			{
				descripciones('q', 'r', cadena_aux, i);
			}
			return;
		}
		
		else if (cadena[i] == '0')
		{
			automata = Insertar(automata, 'X');
			
			if (cadena_aux == "e")
			{
				cadena_aux = 'X';
			}
			
			else
			{
				cadena_aux = cadena_aux + 'X';
			}
			descripciones('q', 'e', cadena_aux, i);
		}
		
		//Filtro para cadenas del tipo: 1010101, 1100000
		else if (cadena[i] == '1' && automata != NULL)
		{
			automata = Eliminar_Tope(automata);
			
			aux = cadena_aux.length()-1;
			cadena_aux = "e";
			for (int j=0; j < aux; j++)
			{
				if (cadena_aux == "e")
				{
					cadena_aux[j] = 'X';
				}
				
				else
				{
					cadena_aux = cadena_aux + "X";
				}
			}
			descripciones('p', 'e', cadena_aux, i);
		}
		
		else
		{
			descripciones('p', 'r', cadena_aux, i);
			return;
		}
	}
	
	//Filtro para cadenas del tipo: 00001
	if (automata != NULL)
	{
		descripciones('p', 'r', cadena_aux, -1);
		return;
	}
	
	//Acepta Cadena
	descripciones('p', 'a', cadena_aux, 2);
		
}

void gotoxy (int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(hcon, Pos);
}

void color(int x)
{
	WORD n;
	n=x;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}


void animacion(string cadena)
{
	int posiciony = 20;
	//auxiliar para guardar posicion de borrar
	int aux;
	
	system("cls");
	
	cout << "Cadena: " << cadena << endl;
	
	for (int i = 0; i< cadena.length(); i++)
	{
		Sleep(2000);
		
		if (i< 10 && cadena[i] == '0')
		{
			color(i+1);
			gotoxy(10, posiciony);
			cout << "0";
			aux = posiciony;
			posiciony = posiciony-2;
			
		}
		
		else
		{
			color(0);
			gotoxy(10, aux);
			cout << "0";
			aux = aux +2;
		}
	}
	
	color(7);
	gotoxy(0, 24);
	
	cout << "Fin de animacion";
	Sleep(2000);
	system("cls");
}

int main (void)
{
	bool ciclo = true;
	srand (time(NULL));
	char repetir;
	int cantidad_de_datos;
	char anim;
	
	while (ciclo == true)
	{
		int opcion;
		string cadena;
		cadena = "e";
		
		cout << "Seleccione una opcion" << endl;
		cout << "1. Ingresar la cadena manualmente" << endl;
		cout << "2. Generar la cadena manualmente" << endl;
		cin >> opcion;
		
		if (opcion == 1)
		{
			cout << "Favor de ingresar la cadena. EJ: 00001111" << endl;
			cin >> cadena;
			proceso(cadena);
			
			cout << "Desea ver la animacion?: (y)si, (cualquier tecla)no" << endl;
			cin >> anim;
			if(anim == 'y' || anim == 'Y')
			{
				animacion(cadena);
			}
		}
		
		else if (opcion == 2)
		{
			cout << "Generando cadena aleatoria" << endl;
			Sleep (2000);
			
			cantidad_de_datos = rand() % 10 + 1;
			
			for(int i=0; i<cantidad_de_datos*2; i++)
			{
				if (i < cantidad_de_datos)
				{
					if (cadena == "e")
					{
						cadena = "0";	
					}
					
					else
					{
						cadena = cadena + "0";
					}
				}
				
				else
				{
					cadena = cadena + "1";
				}
			}
			
			cout << "Usando la siguiente cadena: " << cadena << endl;
			proceso(cadena);
			
			cout << "Desea ver la animacion?: (y)si, (cualquier tecla)no" << endl;
			cin >> anim;
			if(anim == 'y' || anim == 'Y')
			{
				animacion(cadena);
			}
		}
		
		else
		{
			cout << "Favor de ingresar una opcion valida" << endl;
		}
		
		cout << "Desea volver a correr el programa (y)si, (cualquier tecla)no?" << endl;
		cin >> repetir;
		
		if (repetir != 'y' && repetir != 'Y')
		{
			ciclo = false;
		}
		system("cls");
		
	}
	
return 0;
}

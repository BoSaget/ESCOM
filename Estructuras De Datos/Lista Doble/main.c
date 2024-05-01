#include "doble.h"

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

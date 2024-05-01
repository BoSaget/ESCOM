#include "stack.h"

int main (void)
{
	struct Pila * Numeros;
	Numeros=NULL;
	
	Numeros=Insertar(Numeros, 5);
	Numeros=Insertar(Numeros, 4);
	Numeros=Insertar(Numeros, 3);
	Numeros=Insertar(Numeros, 2);
	Numeros=Insertar(Numeros, 1);
	
	Mostrar_Tope(Numeros);
	
	printf("\n");
	
	Numeros=Eliminar_Tope(Numeros);
	
	Mostrar_Tope(Numeros);
	
return 0;
}

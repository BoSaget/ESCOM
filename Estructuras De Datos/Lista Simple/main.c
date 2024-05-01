#include "simple.h"

int main (void)
{
	struct Simple * Numeros;
	Numeros=NULL;

	Numeros=Insertar_Nodo(Numeros, 5);
	Numeros=Insertar_Nodo(Numeros, 1);
	Numeros=Insertar_Nodo(Numeros, 4);
	Numeros=Insertar_Nodo(Numeros, 2);
	Numeros=Insertar_Nodo(Numeros, 3);

	Mostrar_Lista(Numeros);

	printf("\n");

	Numeros=Eliminar_Nodo(Numeros, 1);

	Mostrar_Lista(Numeros);

return 0;
}

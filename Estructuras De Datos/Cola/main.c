#include "queue.h"

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

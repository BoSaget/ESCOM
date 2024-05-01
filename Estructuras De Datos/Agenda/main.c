#include "agenda.h"

int main (void)
{
	struct tabla* dato;
	dato=NULL;
	
	int key, i, cons, datos, cont, intento;
	bool check=false;

	intento=0;

	printf("Cuantos Datos quiere meter? \n");
	scanf("%d", &datos);
	
	struct tabla* agenda[datos]
	
	for(i=0; i<datos; ++i)
	{
		agenda[i]=NULL;
	}

	cont=0;

	
	system("clear");

	while(cont < datos)
	{
		dato=Lectura();
		key=Hash(dato);

		while(check == false)
		{
			check=Empty(agenda[key]);
			if(check == false)
			{
				key=ReHash(dato, intento);
				intento++;
			}
		}
		printf("ID \t%d \n", key);

		agenda[key]=IngresarDato(agenda, dato, key);
		cont++;
	}

	printf("Inserte el id que quiera consultar \n");
	scanf("%d", &cons);

	system("clear");

	Consulta(agenda, cons);

return 0;
}

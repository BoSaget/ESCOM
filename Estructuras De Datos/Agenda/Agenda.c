#include "agenda.h"

int Hash(struct tabla* dato)
{
	int id, i;
	id=0;

	for(i=0; i<20; i++)
	{
		id=((dato->Nombre[i]-'0')+id)%100-1;
		id=((dato->Apellido[i]-'0')+id)%100-1;
	}

	id=((dato->Celular)+id)%100-1;

	if(id < 0)
	{
		id=id+-1;
	}

return id;
}

int ReHash(struct tabla* dato, int t)
{
	int id, i;
	id=0;

	if(t==0)
	{
		for(i=0; i<20; i++)
		{
			id=((dato->Nombre[i]-'0')+id);
			id=((dato->Apellido[i]-'0')+id);
		}

		id=dato->Celular+id;
		id=id*id;
		id=id%100-1;
	}

	else if(t == 1)
	{
		for(i=0; i<20; i++)
		{
			id=((dato->Nombre[i]-'0')+id)*100;
			id=((dato->Apellido[i]-'0')+id)*100;
		}

		id=(dato->Celular+id)*100;
		id=id%100-1;
	}

	if(id < 0)
	{
		id=id+-1;
	}

return id;
}

bool Empty (struct tabla* dato)
{
	if(dato != NULL)
	{
		return false;
	}
return true;
}

struct tabla* IngresarDato(struct tabla* agenda[], struct tabla * dato, int id)
{
	agenda[id]=dato;

return agenda[id];
}

struct tabla* Lectura()
{
	char name[20], lastname[20];
	int i;
	long long int num;

	struct tabla* dato;
	dato=malloc (sizeof(struct tabla));

	printf("Ingresa Nombre (20)\n");
	scanf("%s", name);

	printf("Ingresa Apellido (20)\n");
	scanf("%s", lastname);

	printf("Ingresa Celular (10)\n");
	scanf("%lld",&num)



	for(i=0; i<20; i++)
	{
		dato->Apellido[i]=lastname[i];
		dato->Nombre[i]=name[i];
	}

	dato->Celular=num;

return dato;
}

void Consulta(struct tabla* agenda[], int id)
{
	if(agenda[id] == NULL)
	{
		printf("No existe registro");
	}

	else
	{
		printf("Nombre: \n");
		printf("%s", agenda[id]->Nombre);
		printf("\nApellido: \n");
		printf("%s", agenda[id]->Apellido);
		printf("\nCelular: \n");
		printf("%lld", agenda[id]->Celular);
	}
}

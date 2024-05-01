#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tabla
{
	char Nombre[20];
	char Apellido[20];
	long long int Celular;
};

int Hash(struct tabla* );

int ReHash(struct tabla* , int );

bool Empty (struct tabla* );

struct tabla* IngresarDato(struct tabla* [], struct tabla * , int );

struct tabla* Lectura();

void Consulta(struct tabla* [] , int );


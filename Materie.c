#include "Materie.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Materie creeaza(char* nume, char* producator, int cantitate) {
	/*Creeaza o materie prima cu nume un C-string, producator un C-string si cantitate un int
	*/
	Materie m;
	int nrC = (int)strlen(nume) + 1;
	m.nume = malloc(nrC * sizeof(char));
	strcpy_s(m.nume, nrC, nume);

	nrC = (int)strlen(producator) + 1;
	m.producator = malloc(nrC * sizeof(char));
	strcpy_s(m.producator, nrC, producator);

	m.cantitate = cantitate;
	return m;
}

void distruge(Materie* m) {
	free(m->nume);
	free(m->producator);
	m->cantitate = -1;
}

int valideaza(Materie m) {
	if (strlen(m.nume) == 0)
		return 0;
	if (strlen(m.producator) == 0)
		return 0;
	if (m.cantitate <= 0) return 0;
	return 1;
}
Materie copiazaMaterie(Materie m) {
	return creeaza(m.nume, m.producator, m.cantitate);
}

void testCreeazaDistruge() {
	Materie m = creeaza("Cafea", "Jacobs", 20);

	assert(strcmp(m.nume, "Cafea") == 0);
	assert(strcmp(m.producator, "Jacobs") == 0);
	assert(m.cantitate == 20);

	distruge(&m);
}

void testValidare() {
	Materie m1 = creeaza("", "Jacobs", 23);
	assert(valideaza(m1) == 0);

	Materie m2 = creeaza("Cafea", "", 20);
	assert(valideaza(m2) == 0);

	Materie m3 = creeaza("Cafea", "Jacobs", -8);
	assert(valideaza(m3) == 0);

	Materie m4 = creeaza("Cafea", "Jacobs", 188);
	assert(valideaza(m4) == 1);

	distruge(&m1);
	distruge(&m2);
	distruge(&m3);
	distruge(&m4);
}
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "service.h"

int adaugaMaterie(char* nume, char* producator, int cantitate, MyList* v) {
	Materie m;
	/*m.cantitate = cantitate;
	m.nume = malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(m.nume, nume);
	m.producator = malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy(m.producator, producator);*/
	m = creeaza(nume, producator, cantitate);
	int validat = valideaza(m);
	if (validat) {
		int unic = 1;
		Materie verifica_unic;
		for (int i = 0; i < size(v); i++)
		{
			verifica_unic = get(v, i);
			if (strcmp(m.nume, verifica_unic.nume) == 0 && strcmp(m.producator, verifica_unic.producator) == 0) {
				m = setElem(v, i, m);
				distruge(&m);
				return 1;
			}
		}
		add(v, m);
		return 1;}
	else {
		distruge(&m);
		return 0;
	}
}


int modifyMaterie(MyList* v, char* nume, char* producator, int cantitate) {
	Materie m = creeaza(nume, producator, cantitate);
	/*m.cantitate = cantitate;
	m.nume = malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(m.nume, nume);
	m.producator = malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy(m.producator, producator);*/
	int validat = valideaza(m);
	if (validat) {
		int index = findMaterie(v, nume, producator);
		if (index != -1) {
			m = setElem(v, index, m);
			distruge(&m);
			return 1;
		}
	}
	distruge(&m);
	return 0;
}

int deleteMaterie(MyList* v, char* nume, char* producator) {
	int index = findMaterie(v, nume, producator);
	Materie m;
	if (index != -1) {
		m = delete(v, index);
		distruge(&m);
		return 1;
	}
	return 0;
}

int findMaterie(MyList* v, char* nume, char* producator) {
	int i = 0;
	Materie m;
	while (i < size(v)) {
		m = get(v, i);
		if (strcmp(m.nume, nume) == 0 && strcmp(m.producator, producator) == 0) return i;
		i++;
	}
	return -1;
}

void filtrareMaterie(MyList* listainitiala, MyList* listaFiltrata, char filtru_nume, int filtru_cantitate) {
	bool no_name_filter = false;
	if (filtru_nume == '\0') no_name_filter = true;
	Materie m;
	if (no_name_filter) {
		for (int i = 0; i < size(listainitiala); i++) {
			m = get(listainitiala, i);
			if (m.cantitate <= filtru_cantitate) add(listaFiltrata, copiazaMaterie(m));
		}
	}
	else {
		for (int i = 0; i < size(listainitiala); i++) {
			m = get(listainitiala, i);
			if ((m.cantitate <= filtru_cantitate) && (m.nume[0] == filtru_nume)) add(listaFiltrata, copiazaMaterie(m));
		}
	}
}

void sortByName(MyList* lista_initiala, MyList* lista_sortata, int ordine) {
	Materie m1, m2;
	*lista_sortata = copyList(lista_initiala);
	int i, j;
	if (ordine)
		for (i = 0; i < size(lista_sortata) - 1; i++)  
			for (j = 0; j < size(lista_sortata) - i - 1; j++) {
				m1 = get(lista_sortata, j);
				m2 = get(lista_sortata, j+1);
				if (strcmp(m1.nume,m2.nume) > 0)
					swap(lista_sortata, j, j + 1);
			}
	else
		for (i = 0; i < size(lista_sortata) - 1; i++)
			for (j = 0; j < size(lista_sortata) - i - 1; j++) {
				m1 = get(lista_sortata, j);
				m2 = get(lista_sortata, j + 1);
				if (strcmp(m1.nume, m2.nume) < 0)
					swap(lista_sortata, j, j + 1);
			}
}

void sortByCantitate(MyList* lista_initiala, MyList* lista_sortata, int ordine) {
	Materie m1, m2;
	*lista_sortata = copyList(lista_initiala);
	int i, j;
	if (ordine)
		for (i = 0; i < size(lista_sortata) - 1; i++)
			for (j = 0; j < size(lista_sortata) - i - 1; j++) {
				m1 = get(lista_sortata, j);
				m2 = get(lista_sortata, j + 1);
				if (m1.cantitate > m2.cantitate)
					swap(lista_sortata, j, j + 1);
			}
	else
		for (i = 0; i < size(lista_sortata) - 1; i++)
			for (j = 0; j < size(lista_sortata) - i - 1; j++) {
				m1 = get(lista_sortata, j);
				m2 = get(lista_sortata, j + 1);
				if (m1.cantitate < m2.cantitate)
					swap(lista_sortata, j, j + 1);
			}
}

void sort(MyList* lista_initiala, MyList* lista_sortata, int ordine, int (*comparare)(Materie, Materie, int)) {
	Materie m1, m2;
	*lista_sortata = copyList(lista_initiala);
	int i, j;
	for (i = 0; i < size(lista_sortata) - 1; i++)
		for (j = 0; j < size(lista_sortata) - i - 1; j++) {
			m1 = get(lista_sortata, j);
			m2 = get(lista_sortata, j + 1);
			if (comparare(m1,m2, ordine))
				swap(lista_sortata, j, j + 1);
		}
}

int comparareCantitate(Materie m1, Materie m2, int ordine) {
	if (ordine)
		return m1.cantitate > m2.cantitate;
	else
		return m1.cantitate < m2.cantitate;
}

int comparareNume(Materie m1, Materie m2, int ordine) {
	if (ordine)
		return strcmp(m1.nume, m2.nume) > 0;
	else
		return strcmp(m1.nume, m2.nume) < 0;
}

void testAddService() {
	MyList v = createEmpty();

	int successful1 = adaugaMaterie("Child in Time", "Deep Purple", 56, &v);
	assert(successful1 == 1);

	assert(size(&v) == 1);
	Materie m = get(&v, 0);

	assert(strcmp(m.producator, "Deep Purple") == 0);
	assert(strcmp(m.nume, "Child in Time") == 0);
	assert(m.cantitate == 56);

	int successful2 = adaugaMaterie("", "", 56, &v);
	assert(successful2 == 0);

	int successful3 = adaugaMaterie("Mercedes Benz", "Janis Joplin", -6, &v);
	assert(successful3 == 0);

	int successful4 = adaugaMaterie("Child in Time", "Deep Purple", 70, &v);
	assert(successful1 == 1);

	assert(size(&v) == 1);
	m = get(&v, 0);

	assert(strcmp(m.producator, "Deep Purple") == 0);
	assert(strcmp(m.nume, "Child in Time") == 0);
	assert(m.cantitate == 70);
	destroy(&v);


}
void testFindService() {
	MyList v = createEmpty();

	int successful1 = adaugaMaterie("Child in Time", "Deep Purple", 56, &v);
	assert(successful1 == 1);

	int successful2 = adaugaMaterie("Kashmir", "Led Zeppelin", 56, &v);
	assert(successful2 == 1);

	int successful3 = adaugaMaterie("(Don't fear) The Reaper", "Blue Oyster Cult", 76, &v);
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int poz = findMaterie(&v, "Kashmir", "Led Zeppelin");

	assert(poz == 1);

	destroy(&v);
	assert(size(&v) == 0);
}
void testModifyService() {
	MyList v = createEmpty();

	int successful1 = adaugaMaterie("Child in Time", "Deep Purple", 56, &v);
	assert(successful1 == 1);

	int successful2 = adaugaMaterie("Kashmir", "Led Zeppelin", 56, &v);
	assert(successful2 == 1);

	int successful3 = adaugaMaterie("(Don't fear) The Reaper", "Blue Oyster Cult", 76, &v);
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int modify_success = modifyMaterie(&v, "Kashmir", "Led Zeppelin", 120);
	assert(modify_success == 1);
	int modify_success2 = modifyMaterie(&v, "Comfortably Numb", "Pink Floyd", 25);
	assert(modify_success2 == 0);
	destroy(&v);
}
void testDeleteService() {
	MyList v = createEmpty();

	int successful1 = adaugaMaterie("Child in Time", "Deep Purple", 56, &v);
	assert(successful1 == 1);

	int successful2 = adaugaMaterie("Kashmir", "Led Zeppelin", 56, &v);
	assert(successful2 == 1);

	int successful3 = adaugaMaterie("(Don't fear) The Reaper", "Blue Oyster Cult", 76, &v);
	assert(successful3 == 1);

	assert(size(&v) == 3);
	int succesful_del = deleteMaterie(&v, "Kashmir", "Led Zeppelin");
	assert(succesful_del == 1);
	int succesfully_del = deleteMaterie(&v, "Comfortably Numb", "Pink Floyd");
	assert(succesfully_del == 0);
	destroy(&v);
	assert(size(&v) == 0);
}

void testFiltrareService() {
	MyList v = createEmpty();
	MyList f = createEmpty();

	int successful1 = adaugaMaterie("ba", "Deep Purple", 3, &v);
	assert(successful1 == 1);

	int successful2 = adaugaMaterie("bac", "Led Zeppelin", 1, &v);
	assert(successful2 == 1);

	int successful3 = adaugaMaterie("cab", "Blue Oyster Cult", 10, &v);
	assert(successful3 == 1);

	filtrareMaterie(&v, &f, 'b', 5);
	assert(size(&f) == 2);
	destroy(&f);
	f = createEmpty();
	filtrareMaterie(&v, &f, 'b', 10);
	assert(size(&f) == 2);
	destroy(&f);
	f = createEmpty();
	filtrareMaterie(&v, &f, 'b', INT_MAX);
	assert(size(&f) == 2);
	destroy(&f);
	f = createEmpty();
	filtrareMaterie(&v, &f, '\0', 5);
	assert(size(&f) == 2);
	destroy(&f);
	f = createEmpty();
	filtrareMaterie(&v, &f, '\0', 11);
	assert(size(&f) == 3);
	destroy(&f);
	destroy(&v);
}

void testSortareService() {
	MyList v = createEmpty();
	MyList v1 = createEmpty();
	MyList f;
	Materie m;

	int successful1 = adaugaMaterie("ba", "Deep Purple", 3, &v);
	assert(successful1 == 1);

	int successful2 = adaugaMaterie("bac", "Led Zeppelin", 1, &v);
	assert(successful2 == 1);

	int successful3 = adaugaMaterie("cab", "Blue Oyster Cult", 10, &v);
	assert(successful3 == 1);

	successful1 = adaugaMaterie("bac", "Deep Purple", 3, &v1);
	assert(successful1 == 1);

	successful2 = adaugaMaterie("ba", "Led Zeppelin", 1, &v1);
	assert(successful2 == 1);

	successful3 = adaugaMaterie("cab", "Blue Oyster Cult", 10, &v1);
	assert(successful3 == 1);


	sortByName(&v, &f, 1);
	m = get(&f, 0);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "cab") == 0);
	destroy(&f);

	sortByName(&v1, &f, 1);
	m = get(&f, 0);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "cab") == 0);
	destroy(&f);

	sortByName(&v, &f, 0);
	m = get(&f, 0);
	assert(strcmp(m.nume, "cab") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "ba") == 0);
	destroy(&f);

	sortByCantitate(&v, &f, 1);
	m = get(&f, 0);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "cab") == 0);
	destroy(&f);

	sortByCantitate(&v, &f, 0);
	m = get(&f, 0);
	assert(strcmp(m.nume, "cab") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "bac") == 0);
	destroy(&f);

	sort(&v, &f, 1, comparareNume);
	m = get(&f, 0);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "cab") == 0);
	destroy(&f);

	sort(&v, &f, 0, comparareNume);
	m = get(&f, 0);
	assert(strcmp(m.nume, "cab") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "ba") == 0);
	destroy(&f);

	sort(&v, &f, 1, comparareCantitate);
	m = get(&f, 0);
	assert(strcmp(m.nume, "bac") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "cab") == 0);
	destroy(&f);

	sort(&v, &f, 0, comparareCantitate);
	m = get(&f, 0);
	assert(strcmp(m.nume, "cab") == 0);
	m = get(&f, 1);
	assert(strcmp(m.nume, "ba") == 0);
	m = get(&f, 2);
	assert(strcmp(m.nume, "bac") == 0);

	destroy(&f);
	destroy(&v);
	destroy(&v1);
}
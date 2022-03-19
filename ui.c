#include "MyList.h"
#include "service.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void uiAdd(MyList* list) {
	char* nume = malloc(21), * producator = malloc(21);
	int cantitate;
	getchar();
	printf("Numele materiei prime: ");
	gets_s(nume, 20);
	printf("Producatorul materiei prime: ");
	gets_s(producator, 20);
	printf("Cantitatea materiei prime: ");
	scanf("%d", &cantitate);
	char reziduu[21];
	gets_s(reziduu, 20);
	int succes = adaugaMaterie(nume, producator, cantitate, list);
	if (succes) printf("Adaugarea s-a realizat cu succes!\n\n");
	else printf("Materia prima este invalida!\n\n");
	free(nume);
	free(producator);
}

void uiModify(MyList* list) {
	char* nume = malloc(21), * producator = malloc(21);
	int cantitate;
	getchar();
	printf("Numele materiei prime: ");
	gets_s(nume, 20);
	printf("Producatorul materiei prime: ");
	gets_s(producator, 20);
	printf("Cantitatea materiei prime: ");
	scanf("%d", &cantitate);
	char reziduu[21];
	gets_s(reziduu, 20);
	int succes = modifyMaterie(list, nume, producator, cantitate);
	if (succes) printf("Modificarea s-a realizat cu succes!\n\n");
	else printf("Modificarea nu s-a putut realiza!\n\n");
	free(nume);
	free(producator);
}

void uiDelete(MyList* list) {
	char* nume = malloc(21), * producator = malloc(21);
	getchar();
	printf("Numele materiei prime: ");
	gets_s(nume, 20);
	printf("Producatorul materiei prime: ");
	gets_s(producator, 20);
	int succes = deleteMaterie(list, nume, producator);
	if (succes) printf("Stergerea s-a realizat cu succes!\n\n");
	else printf("Stergerea nu s-a putut realiza!\n\n");
	free(nume);
	free(producator);
}

void uiPrint(MyList* list) {
	int i;
	Materie m;
	for (i = 0; i < size(list); i++)
	{
		m = get(list, i);
		printf("%s %s %d\n", m.nume, m.producator, m.cantitate);
	}
	printf("\n\n");
}

void uiFiltrare(MyList* list) {
	MyList listafiltrata = createEmpty();
	char inceput[2];
	int cant;
	printf("Aplicati filtru asupra materiilor prime ce se vor afisa!\n\n");
	printf("Daca nu doriti filtru pe nume, apasati direct ENTER, iar daca nu doriti pentru cantitate, introduceti -1\n\n");
	getchar();
	gets_s(&inceput, 2);
	scanf("%d", &cant);
	if (cant == -1) cant = INT_MAX;
	else if (cant < -1) {
		printf("Cantitatea trebuie sa fie un intreg pozitiv sau -1 pentru a elimina filtrul!\n\n");
		destroy(&listafiltrata);
		return;
	}
	filtrareMaterie(list, &listafiltrata, inceput[0], cant);
	int i;
	Materie m;
	uiPrint(&listafiltrata);
	destroy(&listafiltrata);
}

void uiSort(MyList* list) {
	MyList lista_sortata;
	printf("Daca doriti sa sortati dupa nume, apasati 1, daca doriti sa sortati dupa cantitate, apasati 2\n");
	int cmd, reusit,ordine;
	char reziduu[21];
	reusit = scanf("%d", &cmd);
	if (reusit != 1 || (cmd != 1 && cmd != 2)) {
		gets_s(reziduu, 20);
		printf("Nu ati introdus o optiune valida!\n\n");
		destroy(&lista_sortata);
		return;
	}
	if (cmd == 1) {
		printf("Pentru sortare ascendenta apasati 1, iar pentru o sortare descendenta apasati 2!\n");
		reusit = scanf("%d", &ordine);
		if (reusit != 1) {
			gets_s(reziduu, 20);
			printf("Nu ati introdus o optiune valida!\n\n");
			destroy(&lista_sortata);
			return;
		}
		if (ordine != 1 && ordine != 2) {
			printf("Nu ati introdus o optiune valida!\n\n");
			destroy(&lista_sortata);
			return;
		}
		if (ordine == 2) ordine = 0;
		sort(list, &lista_sortata, ordine, comparareNume);
		uiPrint(&lista_sortata);
	}
	else if (cmd == 2) {
		printf("Pentru sortare ascendenta apasati 1, iar pentru o sortare descendenta apasati 2!\n");
		reusit = scanf("%d", &ordine);
		if (reusit != 1) {
			gets_s(reziduu, 20);
			printf("Nu ati introdus o optiune valida!\n\n");
			destroy(&lista_sortata);
			return;
		}
		if (ordine != 1 && ordine != 2) {
			printf("Nu ati introdus o optiune valida!\n\n");
			destroy(&lista_sortata);
			return;
		}
		if (ordine == 2) ordine = 0;
		sort(list, &lista_sortata, ordine, comparareCantitate);
		uiPrint(&lista_sortata);
	}
	destroy(&lista_sortata);
}


void consola() {
	int cmd, reusit;
	char reziduu[21];
	MyList v = createEmpty();
	while (1)
	{
		printf("1.Adaugare materie prima\n2.Modificare materie prima\n3.Stergere materie prima\n4.Vizualizare materii prime dupa criteriu\n5.Vizualizare materii prime ordonat\n6.Print\n0.Exit\n\n\n");
		reusit = scanf("%d", &cmd);
		if (reusit != 1) {
			gets_s(reziduu, 20);
			printf("Comanda introdusa nu exista!\n\n");
			continue;
		}
		if (cmd == 1) {
			uiAdd(&v);
		}
		else if (cmd == 2) {
			uiModify(&v);
		}
		else if (cmd == 3) {
			uiDelete(&v);
		}
		else if (cmd == 4) {
			uiFiltrare(&v);
		}
		else if (cmd == 5) {
			uiSort(&v);
		}
		else if (cmd == 6) {
			uiPrint(&v);
		}
		else if (cmd == 0) {
			destroy(&v);
			return;
		}
	}
}
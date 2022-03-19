#pragma once
#include "MyList.h"

/*
* Adauga o materie
*
* @param nume: numele materiei care se adauga (char*)
* @param producator: producatorul materiei care se adauga (char*)
* @param cantitate: cantitatea materiei care se adauga (int)
* @param v: (adresa pentru) lista in care se adauga (MyList* v)
*
* @return: 1 daca materia a fost adaugata cu succes, 0 altfel (int)
* post: materia cu datele date este adaugata in lista (daca este o materie valida)
*/
int adaugaMaterie(char* nume, char* producator, int cantitate, MyList* v);

/*
* Sterge o materie
*
* @param v: (adresa pentru) lista din care se sterge (MyList* v)
* @param nume: numele materiei care se sterge (char*)
* @param producator: producatorul materiei care se sterge (char*)
*
* @return: 1 daca materia a fost stearsa cu succes, 0 altfel (int)
* post: materia cu numele si producatorul este stearsa din lista daca exista
*/
int deleteMaterie(MyList* v, char* nume, char* producator);

/*
* Modifica o materie
*
* @param v: (adresa pentru) lista in care se modifica (MyList* v)
* @param nume: numele materiei care se modifica (char*)
* @param producator: producatorul materiei care se modifica (char*)
* @param cantitate: noua cantitate a materiei (int)
*
* @return: 1 daca melodia a fost modificata cu succes, 0 altfel (int)
* post: materia cu numele nume si producatorul producator are cantitatea noua cantitate (daca o astfel
*		de materie exista)
*/
int modifyMaterie(MyList* v, char* nume, char* producator, int cantitate);


/*
* Gaseste o materie cu numele si producatorul dat
*
* @param v: (adresa pentru) lista in care se cauta (MyList* v)
* @param nume: numele materiei care se cauta (char*)
* @param producator: producatorul materiei care se cauta (char*)
*
* @return: pozitia din lista a materie cautate, -1 daca
			materia nu exista in lista (int)
*/
int findMaterie(MyList* v, char* nume, char* producator);

/*
* @param listainitiala: (adresa pentru) lista din care se va face filtrarea (MyList* listainitiala)
* @param listaFiltrata: (adresa pentru) lista in care se vor stoca materiile prime filtrate (MyList* listaFiltrata)
* @param filtru_nume: litera cu care trebuie sa inceapa materiile prime (char)
* @param filtru_cantitate: valoarea maxima pe care o poate avea cantitatea materilor prime (int)
*
* @return: -
*/
void filtrareMaterie(MyList* listainitiala, MyList* listaFiltrata, char filtru_nume, int filtru_cantitate);

/*
* Sorteaza lista de materii prime dupa nume ascendent sau descendent in functie de parametru ordine
*
* @param lista_initiala: (adresa pentru) lista initiala (MyList* lista_initiala)
* @param lista_sortata: (adresa pentru) lista sortata (MyList* lista_sortata)
* @param ordine: modul in care se face sortarea(1 pentru crescator sau 0 pentru descrescator) (int)
* 
* @return: -
*/
void sortByName(MyList* lista_initiala, MyList* lista_sortata, int ordine);

/*
* Sorteaza lista de materii prime dupa cantitate ascendent sau descendent in functie de parametru ordine
*
* @param lista_initiala: (adresa pentru) lista initiala (MyList* lista_initiala)
* @param lista_sortata: (adresa pentru) lista sortata (MyList* lista_sortata)
* @param ordine: modul in care se face sortarea(1 pentru crescator sau 0 pentru descrescator) (int)
*
* @return: -
*/
void sortByCantitate(MyList* lista_initiala, MyList* lista_sortata, int ordine);

/*
* compara doua materii in fct de cantitate
* @param m1: materia prima 1 (Materie m1)
* @param m2: materia prima 2 (Materie m2)
* @param ordine: daca e 1, se compara pentru ascendent, daca e 0 se compara pentru descendent (int)
* 
* @return: 1 daca comparatia echivalenta e adevarata, 0 alftel
* 
*/
int comparareCantitate(Materie m1, Materie m2, int ordine);

/*
* compara doua materii in fct de nume
* @param m1: materia prima 1 (Materie m1)
* @param m2: materia prima 2 (Materie m2)
* @param ordine: daca e 1, se compara pentru ascendent, daca e 0 se compara pentru descendent (int)
*
* @return: 1 daca comparatia echivalenta e adevarata, 0 alftel
*
*/
int comparareNume(Materie m1, Materie m2, int ordine);

void sort(MyList* lista_initiala, MyList* lista_sortata, int ordine, int (*comparare)(Materie, Materie, int));

void testAddService();
void testModifyService();
void testDeleteService();
void testFindService();
void testFiltrareService();
void testSortareService();

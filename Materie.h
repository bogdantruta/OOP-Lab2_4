#pragma once
typedef struct {
	char* nume;
	char* producator;
	int cantitate;
} Materie;


/*
* Creeaza o materie cu datele din parametrii
*
* @param nume: numele materiei (C-string)
* @param producator: numele producatorului (C-string)
* @param cantitate: cantitatea de materie prima (int)
* 
* @return: materia prima creata (Materie)
*/
Materie creeaza(char* nume, char* producator, int cantitate);

/*
* Distruge Materia(elibereaza memoria pentru stringuri si seteaza cantitatea la -1
* @return: materia prima creata (Materie)
*/
void distruge(Materie* m);

/*Valideaza o materie
* 
* O materie prima este valida daca numele materiei si al producatorului sunt diferite de ""
* Valoarea cantitatii trebuie sa fie pozitiva
* @param m: materia de validat (Materie)
* 
* @return: 1 daca materia este valida, 0 daca nu
*/
int valideaza(Materie m);


/*
* Creeaza o copie a materiei date
*/
Materie copiazaMaterie(Materie m);

void testCreeazaDistruge();
void testValidare();

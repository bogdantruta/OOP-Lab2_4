#define _CRTDBG_MAP_ALLOC
#include "MyList.h"
#include "service.h"
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
/*6. Cofetarie
Creati o aplicatie care permite gestiunea stocului de materii prime folosite intr-o cofetarie.
Fiecare materie prima din stoc are un nume unic, un producator si cantitate.
Aplicatia permite:
a) adaugare de materie prima (daca exista deza in stoc se actualizeaza cantitatea)
b) modificare materie prima 
c) stergere  materie prima
d) Vizualizare materii prime care satisfac un criteriu (nume incepe cu o litera data, cantitatea disponibila e mai mica decat un numar dat)
e) Vizualizare materii prime din stoc ordonat dupa nume sau cantitate disponibila (crescator/descrescator)*/

void testAll() {
	testCreeazaDistruge();
	testValidare();
	testCreateVector();
	testIterate();
	testCopy();
	testAddService();
	testModifyService();
	testDeleteService();
	testFindService();
	testSwap();
	testFiltrareService();
	testSortareService();
}

int main()
{
	testAll();
	consola();
	_CrtDumpMemoryLeaks();
	return 0;
}
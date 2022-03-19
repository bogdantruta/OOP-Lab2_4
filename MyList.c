#pragma once
#include "MyList.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

MyList createEmpty() {
	MyList v;
	v.capacitate = 2;
	v.length = 0;
	v.elems = malloc(sizeof(ElemType) * v.capacitate);
	return v;
}

void destroy(MyList* v) {
	for (int i = 0; i < v->length; i++) {
		ElemType el = get(v, i);
		distruge(&el);
	}
	v->length = 0;
	free(v->elems);
}

ElemType get(MyList* v, int poz) {
	return v->elems[poz];
}
ElemType setElem(MyList* v, int poz, ElemType el) {
	ElemType replacedElement = v->elems[poz];
	v->elems[poz] = el;
	return replacedElement;
}


int size(MyList* v) {
	return v->length;
}

void add(MyList* v, ElemType el) {
	if (v->length == v->capacitate) {
		int newCapacitate = v->capacitate * 2;
		ElemType* aux_elems = malloc(sizeof(ElemType) * newCapacitate);
		for (int i = 0; i < v->length; i++) {
			aux_elems[i] = v->elems[i];
		}
		free(v->elems);
		v->elems = aux_elems;
		v->capacitate = newCapacitate;
	}

	v->elems[v->length] = el;
	v->length++;
}
ElemType delete(MyList* v, int poz) {
	ElemType el = v->elems[poz];
	for (int i = poz; i < v->length-1; i++) {
		v->elems[i] = v->elems[i + 1];
	}
	v->length--;
	return el;
}

MyList copyList(MyList* v) {
	MyList v_copy = createEmpty();
	for (int i = 0; i < v->length; i++) {
		ElemType el = get(v, i);
		add(&v_copy, copiazaMaterie(el));
	}
	return v_copy;
}

void swap(MyList* v, int i, int j) {
	Materie m1,m2;
	m1 = get(v, i);
	m2 = setElem(v, j, m1);
	setElem(v, i, m2);
}

void testCreateVector() {
	MyList v = createEmpty();
	assert(size(&v) == 0);
	destroy(&v);

}
void testIterate() {
	MyList v = createEmpty();
	Materie m1 = creeaza("Child in Time", "Deep Purple", 56);
	Materie m2 = creeaza("When the Levee Breaks", "Led Zeppelin", 78);
	Materie m3 = creeaza("Whole Lotta Love", "Led Zeppelin", 100);

	add(&v, m1);
	add(&v, m2);
	add(&v, m3);

	assert(size(&v) == 3);
	Materie m = get(&v, 0);

	assert(strcmp(m.producator, "Deep Purple")==0);
	assert(strcmp(m.nume, "Child in Time")==0);
	assert(m.cantitate == 56);

	destroy(&v);
	assert(size(&v) == 0);

}

void testCopy() {
	MyList v1 = createEmpty();
	add(&v1, creeaza("Animal de Prada", "Carla's Dreams", 65));
	add(&v1, creeaza("Anti CSD", "Carla's Dreams", 70));

	assert(size(&v1) == 2);
	MyList v2 = copyList(&v1);
	assert(size(&v2) == 2);
	Materie m = get(&v2, 0);
	assert(strcmp(m.producator, "Carla's Dreams") == 0);

	destroy(&v1);
	destroy(&v2);

}

void testSwap() {
	MyList v1 = createEmpty();
	add(&v1, creeaza("Animal de Prada", "Carla's Dreams", 65));
	add(&v1, creeaza("Anti CSD", "Carla's Dreams", 70));
	swap(&v1, 0, 1);
	Materie m;
	m = get(&v1, 0);
	assert(strcmp(m.nume, "Anti CSD") == 0);
	m = get(&v1, 1);
	assert(strcmp(m.nume, "Animal de Prada") == 0);
	destroy(&v1);
}
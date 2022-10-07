// listas1_objetos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

class lista1 {
private:
	nodo *inicial;
public:
	void crear_lista(nodo *anterior, nodo *nuevo);
	lista1() {
		inicial = NULL;
	}
	~lista1();

};

nodo *inicial = NULL;

void lista1::crear_lista(nodo *anterior, nodo *nuevo) {
	if (anterior == NULL) {
		cout << "Creo" << endl;
		nuevo->sig = inicial;
		inicial = nuevo;
	}
	else {
		cout << "Creo" << endl;
		nuevo->sig = anterior->sig;
		anterior->sig = nuevo;
	}
}
lista1::~lista1() {
	nodo *apun = inicial;
	while (apun != NULL) {
		cout << "Borro" << endl;
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

void main()
{
	nodo *anterior, *nuevo;
	lista1 lista;
	int i;
	anterior = NULL;
	for (i = 1; i <= 3; i++) {
		nuevo = new nodo;
		lista.crear_lista(anterior, nuevo);
		anterior = nuevo;
	}
	
	
}


// listas1_objetos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

class lista2 {
private:
	nodo *inicial;
public:
	void crear_lista(nodo *anterior, nodo *nuevo);
	lista2() {
		inicial = NULL;
	}
	~lista2();

};

nodo *inicial = NULL;

void lista2::crear_lista(nodo *anterior, nodo *nuevo) {
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
lista2::~lista2() {
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
	lista2 lista;
	char resp;
	anterior = NULL;
	do {
		nuevo = new nodo;
		lista.crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout << "¿Desea crear otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');
	
	
}


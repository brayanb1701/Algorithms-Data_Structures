// listas1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

nodo *inicial = NULL;

void crear_lista(nodo *anterior, nodo *nuevo) {
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
void borrar_lista() {
	nodo *apun=inicial;
	while (apun != NULL) {
		cout << "Borro" << endl;
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
}

void main()
{
	nodo *anterior, *nuevo;
	int i;
	anterior = NULL;
	for (i = 1; i <= 3; i++) {
		nuevo = new nodo;
		crear_lista(anterior, nuevo);
		anterior = nuevo;
	}
	borrar_lista();
	system("pause");
}

// listas4_objetos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

class lista4 {
public:
	nodo *inicial;
public:
	void leer_nodo(nodo *nuevo);
	void crear_lista(nodo *anterior, nodo *nuevo);
	void imprime_nodo(nodo *apun);
	void reco_recur(nodo *apun);
	lista4() {
		inicial = NULL;
	}
	~lista4();

};


void lista4::leer_nodo(nodo *nuevo) {
	cout << "Entre el valor del nodo " << endl;
	cin >> nuevo->datos;
}


void lista4::crear_lista(nodo *anterior, nodo *nuevo) {
	if (anterior == NULL) {
		nuevo->sig = inicial;
		leer_nodo(nuevo);
		inicial = nuevo;
	}
	else {
		nuevo->sig = anterior->sig;
		anterior->sig = nuevo;
		leer_nodo(nuevo);
	}
}

void lista4::imprime_nodo(nodo *apun) {
	cout << "El valor es " << apun->datos << endl;
}

void lista4::reco_recur(nodo *apun) {
	if(apun != NULL) {
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

lista4::~lista4() {
	nodo *apun = inicial;
	while (apun != NULL) {

		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

void main()
{
	nodo *anterior, *nuevo, *apun;
	lista4 lista;
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
	apun = lista.inicial;
	lista.reco_recur(apun);
}

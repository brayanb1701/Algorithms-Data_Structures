// listas3_objetos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

class lista3 {
public:
	nodo *inicial;
public:
	void leer_nodo(nodo *nuevo);
	void crear_lista(nodo *anterior, nodo *nuevo);
	void imprime_nodo(nodo *apun);
	void reco_iter(nodo *apun);
	lista3() {
		inicial = NULL;
	}
	~lista3();

};


void lista3::leer_nodo(nodo *nuevo) {
	cout << "Entre el valor del nodo " << endl;
	cin >> nuevo->datos;
}


void lista3::crear_lista(nodo *anterior, nodo *nuevo) {
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

void lista3::imprime_nodo(nodo *apun) {
	cout << "El valor es " << apun->datos << endl;
}

void lista3::reco_iter(nodo *apun) {
	while (apun != NULL) {
		imprime_nodo(apun);
		apun = apun->sig;
	}
}

lista3::~lista3() {
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
	lista3 lista;
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
	lista.reco_iter(apun);
}

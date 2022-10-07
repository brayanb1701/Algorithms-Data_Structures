// listas6_objetos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int codigo;
	char *nombre;
	int nivel;
	nodo* sig;
};

class lista6 {
public:
	nodo *inicial;
public:
	void leer_nodo(nodo *nuevo);
	void crear_lista(nodo *anterior, nodo *nuevo);
	void imprime_nodo(nodo *apun);
	void reco_recur(nodo *apun);
	nodo * buscar_nodo(nodo *apun, int &codigo);
	nodo * agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo);
	lista6() {
		inicial = NULL;
	}
	~lista6();

};


void lista6::leer_nodo(nodo *nuevo) {
	cout << "Entre el codigo del estudiante " << endl;
	cin >> nuevo->codigo;
	cout << "Entre el nombre del estudiante " << endl;
	cin.ignore();
	nuevo->nombre = new char[30];
	cin.getline(nuevo->nombre, 30);
	cout << "Entre el nivel del estudiante " << endl;
	cin >> nuevo->nivel;
}


void lista6::crear_lista(nodo *anterior, nodo *nuevo) {
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

void lista6::imprime_nodo(nodo *apun) {
	cout << "El codigo es " << apun->codigo << endl;
	cout << "El nombre es " << apun->nombre << endl;
	cout << "El nivel es " << apun->nivel << endl;
}

void lista6::reco_recur(nodo *apun) {
	if (apun != NULL) {
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

lista6::~lista6() {
	nodo *apun = inicial;
	while (apun != NULL) {

		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

nodo * lista6::buscar_nodo(nodo *apun, int &codigo) {
	while (apun != NULL) {
		if (apun->codigo == codigo) return apun;
		else apun = apun->sig;
	}
	return NULL;
}

nodo * lista6::agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo) {
	if (codigo == 0) {
		nuevo->sig = anterior;
		anterior = nuevo;
		leer_nodo(nuevo);
		return anterior;
	}
	else {
		nuevo->sig = anterior->sig;
		anterior->sig = nuevo;
		leer_nodo(nuevo);
		return anterior;
	}
}
void main()
{
	nodo *anterior, *nuevo, *apun;
	lista6 lista;
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

	//inicio del recorrido de la lista
	cout << "LA LISTA ORIGINALMENTE CREADA ES: " << endl;
	apun = lista.inicial;
	lista.reco_recur(apun);

	//inicio agregacion nuevos nodos
	cout << endl;
	cout << "INICIO DE AGREGACION DE NUEVOS NODOS A LA LISTA ORIGINAL" << endl;
	int codigo;
	apun = lista.inicial;
	do {
		cout << endl;
		cout << "Entre codigo clave (Digite 0  si va a agregar a la cabeza de la lista, en" << endl;
		cout << "caso contrario digite el nodo del codigo anterior al que va a crear)" << endl << endl;

		cin >> codigo;
		if (codigo == 0) {
			nuevo = new nodo;
			lista.inicial = lista.agregar_nodo(lista.inicial, nuevo, codigo);
		}
		else {
			anterior = lista.inicial;
			anterior = lista.buscar_nodo(anterior, codigo);
			if (anterior != NULL) {
				nuevo = new nodo;
				anterior = lista.agregar_nodo(anterior, nuevo, codigo);
			}
			else cout << "El nodo no ha sido encontrado" << endl;
		}
		cout << "¿DESEA AGREGAR OTRO NODO (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');

	cout << "LA LISTA COMPLETA ES:" << endl;
	apun = lista.inicial;
	lista.reco_recur(apun);
}

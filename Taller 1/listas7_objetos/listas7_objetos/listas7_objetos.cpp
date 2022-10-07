// listas7_objetos.cpp: archivo de proyecto principal.


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

class lista7 {
public:
	nodo *inicial;
public:
	void leer_nodo(nodo *nuevo);
	void crear_lista(nodo *anterior, nodo *nuevo);
	void imprime_nodo(nodo *apun);
	void reco_recur(nodo *apun);
	nodo * buscar_nodo(nodo *apun, int &codigo);
	nodo * agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo);
	void eliminar_nodo(nodo *objetivo);
	lista7() {
		inicial = NULL;
	}
	~lista7();

};


void lista7::leer_nodo(nodo *nuevo) {
	cout << "Entre el codigo del estudiante " << endl;
	cin >> nuevo->codigo;
	cout << "Entre el nombre del estudiante " << endl;
	cin.ignore();
	nuevo->nombre = new char[30];
	cin.getline(nuevo->nombre, 30);
	cout << "Entre el nivel del estudiante " << endl;
	cin >> nuevo->nivel;
}


void lista7::crear_lista(nodo *anterior, nodo *nuevo) {
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

void lista7::imprime_nodo(nodo *apun) {
	cout << "El codigo es " << apun->codigo << endl;
	cout << "El nombre es " << apun->nombre << endl;
	cout << "El nivel es " << apun->nivel << endl;
}

void lista7::reco_recur(nodo *apun) {
	if (apun != NULL) {
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}

lista7::~lista7() {
	nodo *apun = inicial;
	while (apun != NULL) {

		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");
}

nodo * lista7::buscar_nodo(nodo *apun, int &codigo) {
	while (apun != NULL) {
		if (apun->codigo == codigo) return apun;
		else apun = apun->sig;
	}
	return NULL;
}

nodo * lista7::agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo) {
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

void lista7::eliminar_nodo(nodo *objetivo) {
	nodo *aux;
	aux = inicial;
	if (aux == objetivo) {
		inicial = aux->sig;
		delete objetivo;
	}
	else {
		while (aux->sig != objetivo) {
			aux = aux->sig;
		}
		aux->sig = objetivo->sig;
		delete objetivo;
	}
}

void main()
{
	nodo *anterior, *nuevo, *apun;
	lista7 lista;
	char resp;
	anterior = NULL;
	int opc;

	do {
		system("cls");
		cout << endl << endl;
		cout << "1. Crear lista " << endl;
		cout << "2. Mostrar lista actual" << endl;
		cout << "3. Agregar elemento a la lista " << endl;
		cout << "4. Eliminar elemento de la lista" << endl;
		cout << "5. Salir " << endl;
		cout << "Escoja la opcion deseada del anterior menu: " << endl;
		cin >> opc;
		cout << endl << endl;
		system("cls");
		switch (opc)
		{
		case 1:
			do {
				system("cls");
				nuevo = new nodo;
				lista.crear_lista(anterior, nuevo);
				anterior = nuevo;
				cout << "¿Desea crear otro nodo? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp != 'n');
			system("pause");
			break;
		case 2:
			cout << "LA LISTA ACTUAL ES: " << endl;
			apun = lista.inicial;
			lista.reco_recur(apun);
			system("pause");
			break;
		case 3:
			cout << endl;
			cout << "AGREGACION DE NUEVO NODO A LA LISTA ORIGINAL" << endl;
			int codigo;
			apun = lista.inicial;
			cout << endl;
			cout << "Entre codigo clave (Digite 0  si va a agregar a la cabeza de la lista, en" << endl;
			cout << "caso contrario digite el codigo del nodo anterior al que va a crear)" << endl << endl;

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
			system("pause");
			break;

		case 4:
			cout << endl;
			cout << "ELIMINACION DE NODOS A LA LISTA" << endl;
			int codigo_eliminar;
			apun = lista.inicial;
			cout << "Digite el codigo del nodo que desea eliminar:" << endl << endl;
			cin >> codigo_eliminar;
			nodo *eliminar;
			eliminar = lista.buscar_nodo(lista.inicial, codigo_eliminar);
			if (eliminar != NULL) lista.eliminar_nodo(eliminar);
			else cout << "El nodo no ha sido encontrado" << endl;
			system("pause");
			break;

		case  5:
			
			break;
		}

	} while (opc != 5);
}
/*
void main()
{
	nodo *anterior, *nuevo, *apun;
	lista7 lista;
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
*/

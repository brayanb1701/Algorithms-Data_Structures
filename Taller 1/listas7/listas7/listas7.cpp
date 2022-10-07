// listas7.cpp: archivo de proyecto principal.


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

nodo *inicial = NULL;

void leer_nodo(nodo *nuevo) {
	cout << "Entre el codigo del estudiante " << endl;
	cin >> nuevo->codigo;
	cout << "Entre el nombre del estudiante " << endl;
	cin.ignore();
	nuevo->nombre = new char[30];
	cin.getline(nuevo->nombre, 30);
	cout << "Entre el nivel del estudiante " << endl;
	cin >> nuevo->nivel;
}

void crear_lista(nodo *anterior, nodo *nuevo) {
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

void imprime_nodo(nodo *apun) {
	cout << "El codigo es " << apun->codigo << endl;
	cout << "El nombre es " << apun->nombre << endl;
	cout << "El nivel es " << apun->nivel << endl;
}

void reco_recur(nodo *apun) {
	if (apun != NULL) {
		imprime_nodo(apun);
		reco_recur(apun->sig);
	}
}
void borrar_lista() {
	nodo *apun = inicial;
	while (apun != NULL) {
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
}

nodo * buscar_nodo(nodo *apun, int &codigo) {
	while (apun != NULL) {
		if (apun->codigo == codigo) return apun;
		else apun = apun->sig;
	}
	return NULL;
}

nodo * agregar_nodo(nodo *anterior, nodo *nuevo, int &codigo) {
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

void eliminar_nodo(nodo *objetivo) {
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
					crear_lista(anterior, nuevo);
					anterior = nuevo;
					cout << "¿Desea crear otro nodo? (s/n)" << endl;
					cin >> resp;
					resp = tolower(resp);
				} while (resp != 'n');
				system("pause");
				break;
			case 2:
				cout << "LA LISTA ACTUAL ES: " << endl;
				apun = inicial;
				reco_recur(apun);
				system("pause");
				break;
			case 3:
				cout << endl;
				cout << "AGREGACION DE NUEVO NODO A LA LISTA ORIGINAL" << endl;
				int codigo;
				apun = inicial;
				cout << endl;
				cout << "Entre codigo clave (Digite 0  si va a agregar a la cabeza de la lista, en" << endl;
				cout << "caso contrario digite el codigo del nodo anterior al que va a crear)" << endl << endl;

				cin >> codigo;
				if (codigo == 0) {
					nuevo = new nodo;
					inicial = agregar_nodo(inicial, nuevo, codigo);
				}
				else {
					anterior = inicial;
					anterior = buscar_nodo(anterior, codigo);
					if (anterior != NULL) {
						nuevo = new nodo;
						anterior = agregar_nodo(anterior, nuevo, codigo);
					}
					else cout << "El nodo no ha sido encontrado" << endl;
				}
				system("pause");
				break;

			case 4:
				cout << endl;
				cout << "ELIMINACION DE NODOS A LA LISTA" << endl;
				int codigo_eliminar;
				apun = inicial;
				cout << "Digite el codigo del nodo que desea eliminar:" << endl << endl;
				cin >> codigo_eliminar;
				nodo *eliminar;
				eliminar = buscar_nodo(inicial, codigo_eliminar);
				eliminar_nodo(eliminar);
				system("pause");
				break;

			case  5:
				borrar_lista();
				system("pause");
				break;
			}

	} while (opc != 5);

	/*
	do {
		nuevo = new nodo;
		crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout << "¿Desea crear otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');

	//inicio del recorrido de la lista
	cout << "LA LISTA ORIGINALMENTE CREADA ES: " << endl;
	apun = inicial;
	reco_recur(apun);

	//inicio agregacion nuevos nodos
	cout << endl;
	cout << "INICIO DE AGREGACION DE NUEVOS NODOS A LA LISTA" << endl;
	int codigo;
	apun = inicial;
	do {
		cout << endl;
		cout << "Entre codigo clave (Digite 0  si va a agregar a la cabeza de la lista, en" << endl;
		cout << "caso contrario digite el codigo del nodo anterior al que va a crear)" << endl << endl;

		cin >> codigo;
		if (codigo == 0) {
			nuevo = new nodo;
			inicial = agregar_nodo(inicial, nuevo, codigo);
		}
		else {
			anterior = inicial;
			anterior = buscar_nodo(anterior, codigo);
			if (anterior != NULL) {
				nuevo = new nodo;
				anterior = agregar_nodo(anterior, nuevo, codigo);
			}
			else cout << "El nodo no ha sido encontrado" << endl;
		}
		cout << "¿DESEA AGREGAR OTRO NODO (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');

	cout << "LA LISTA COMPLETA ES:" << endl;
	apun = inicial;
	reco_recur(apun);

	//inicio eliminacion de nuevos nodos
	cout << endl;
	cout << "ELIMINACION DE NODOS A LA LISTA" << endl;
	int codigo_eliminar;
	apun = inicial;
	do {
		cout << "Digite el codigo del nodo que desea eliminar:" << endl << endl;

		cin >> codigo_eliminar;

		nodo *eliminar = buscar_nodo(inicial, codigo_eliminar);
		eliminar_nodo(eliminar);

		cout << "¿DESEA ELIMINAR OTRO NODO (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp != 'n');
	
	cout << "LA LISTA COMPLETA ES:" << endl;
	apun = inicial;
	reco_recur(apun);

	borrar_lista();
	system("pause");*/
}

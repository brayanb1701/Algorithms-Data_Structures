// Pila_menu.cpp: archivo de proyecto principal.


#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
};
class Pila {
private:
	nodo *tope;
public:
	Pila();
	char meter(int valor);
	char sacar(int &valor);
	~Pila();
	void limpiarPila();
	int cimaPila();
	int longitudPila();
	void desplegarPila();
};
Pila::Pila() {
	tope = NULL;
}
Pila::~Pila() {
	nodo *apunt;
	apunt = tope;
	while (tope != NULL) {
		tope = apunt->sig;
		delete apunt;
		apunt = tope;
	}
}
char Pila::meter(int valor) {
	nodo *nuevo;
	nuevo = new nodo;
	if (nuevo == NULL) return 0;
	else {
		nuevo->dato = valor;
		nuevo->sig = tope;
		tope = nuevo;
		return 1;
	}
}
char Pila::sacar(int &valor) {
	nodo *apunt;
	apunt = tope;
	if (apunt == NULL) return 0;
	else {
		valor = apunt->dato;
		tope = tope->sig;
		delete apunt;
		return 1;
	}
}
void Pila::limpiarPila() {
	nodo *apunt;
	apunt = tope;
	while (tope != NULL) {
		tope = apunt->sig;
		delete apunt;
		apunt = tope;
	}
}
int Pila::cimaPila() {
	return tope->dato;
}
int Pila::longitudPila() {
	nodo *apunt;
	int longitud;
	longitud = 0;
	if (tope != NULL) {
		apunt = tope;
		while (apunt != NULL) {
			longitud++;
			apunt = apunt->sig;
		}
	}
	return longitud;
}
void Pila::desplegarPila() {
	nodo *apunt;
	apunt = tope;
	if (apunt == NULL) {
		cout << "La pila esta vacia" << endl;
	}
	else {
		while (apunt != NULL) {
			cout << apunt->dato << endl;
			apunt = apunt->sig;
		}
	}
}
void main() {


	Pila p;
	int valor;
	char resp;
	int opc;

	do {
		system("cls");
		cout << "1. Meter elemento a la pila" << endl;
		cout << "2. Sacar un elemento de la pila" << endl;
		cout << "3. Mostrar longitud de la pila" << endl;
		cout << "4. Mostrar la cima de la pila" << endl;
		cout << "5. Limpiar pila" << endl;
		cout << "6. Desplegar pila" << endl;
		cout << "7. Salir " << endl;
		cout << "Escoja la opcion deseada del anterior menu: " << endl;
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			do {
				system("cls");
				cout << "Entre elemento a la Pila" << endl;
				cin >> valor;
				p.meter(valor);
				cout << "Desea entrar otro elemento a la Pila? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp == 's');
			system("pause");
			break;
		case 2:
			do {
				system("cls");
				if (p.sacar(valor)) {
					cout << "El elemento extraido es:" << valor << endl;
					cout << "Desea sacar otro elemento de la Pila? (s/n)" << endl;
					cin >> resp;
					resp = tolower(resp);
				}
				else {
					cout << "La Pila esta vacia" << endl;
					break;
				}
			} while (resp == 's');
			system("pause");
			break;
		case 3:
			cout << "Longitud de la Pila: " << p.longitudPila() << endl;
			system("pause");
			break;

		case 4:
			cout << "Cima de la Pila: " << p.cimaPila() << endl;
			system("pause");
			break;

		case  5:
			p.limpiarPila();
			cout << "Fila limpiada" << endl;
			system("pause");
			break;
		case  6:
			cout << "Desplegar Pila: " << endl;
			p.desplegarPila();
			system("pause");
			break;
		case 7:
			system("pause");
			break;
		}
	} while (opc != 7);
}
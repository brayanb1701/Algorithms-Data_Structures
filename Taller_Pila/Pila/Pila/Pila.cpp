// Pila.cpp: archivo de proyecto principal.

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
		cout << "La lista esta vacia" << endl;
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
	do {
		cout << "Entre elemento a la Pila" << endl;
		cin >> valor;
		p.meter(valor);
		cout << "Desea entrar otro elemento a la Pila? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
		system("cls");
	} while (resp == 's');
	cout << "Longitud de la Pila: " << p.longitudPila() << endl;
	cout << "Cima de la Pila: " << p.cimaPila() << endl;
	cout << "Desplegar Pila: " << endl;
	p.desplegarPila();
	cout << "Desea sacar un elemento de la Pila? (s/n)" << endl;
	cin >> resp;
	resp = tolower(resp);
	if (resp == 's') {
		do {
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
			system("cls");
		} while (resp == 's');

	}
	p.limpiarPila();
	p.desplegarPila();
	system("pause");
}
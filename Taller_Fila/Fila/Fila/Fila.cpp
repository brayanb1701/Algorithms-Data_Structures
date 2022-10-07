// Fila.cpp: archivo de proyecto principal.


#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
};
class Fila {
private: 
	nodo *frente;
	nodo *final;
public:
	Fila();
	char meter(int valor);
	char sacar(int &valor);
	~Fila();
	void limpiarFila();
	int frenteFila();
	int longitudFila();
	void desplegarFila();
};
Fila::Fila() {
	frente = NULL;
	final = NULL;
}
Fila::~Fila() {
	nodo *apunt;
	apunt = frente;
	while (frente != NULL) {
		frente = apunt->sig;
		delete apunt;
		apunt = frente;
	}
}
char Fila::meter(int valor) {
	nodo *nuevo;
	nuevo = new nodo;
	if (nuevo == NULL) return 0;
	else {
		nuevo->dato = valor;
		if (final == NULL) frente = nuevo;
		else final->sig = nuevo;
		nuevo->sig = NULL;
		final = nuevo;
		return 1;
	}
}
char Fila::sacar(int &valor) {
	nodo *apunt;
	apunt = frente;
	if (apunt == NULL) return 0;
	else {
		valor = apunt->dato;
		if (frente->sig == NULL) {
			frente = NULL;
			final = NULL;
		}
		else frente = apunt->sig;
		delete apunt;
		return 1;
	}
}
void Fila::limpiarFila() {
	nodo *apunt;
	apunt = frente;
	while (frente != NULL) {
		frente = apunt->sig;
		delete apunt;
		apunt = frente;
	}
}
int Fila::frenteFila() {
	return frente->dato;
}
int Fila::longitudFila(){
	nodo *apunt;
	int longitud;
	longitud = 0;
	if (frente != NULL) {
		apunt = frente;
		while (apunt != NULL) {
			longitud++;
			apunt = apunt->sig;
		}
	}
	return longitud;
}
void Fila::desplegarFila() {
	nodo *apunt;
	apunt = frente;
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
	Fila f;
	int valor; 
	char resp;
	do {
		cout << "Entre elemento a la fila" << endl;
		cin >> valor;
		f.meter(valor);
		cout << "Desea entrar otro elemento a la fila? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
		system("cls");
	} while (resp == 's');
	cout << "Longitud de la fila: " <<f.longitudFila()<< endl;
	cout << "Frente de la fila: " << f.frenteFila()<<endl;
	cout << "Desplegar fila: "<<endl;
	f.desplegarFila();
	cout << "Desea atender un elemento de la fila? (s/n)" << endl;
	cin >> resp;
	resp = tolower(resp);
	if (resp == 's') {
		do {
			if (f.sacar(valor)) {
				cout << "El elemento atendido es:" << valor << endl;
				cout << "Desea atender otro elemento de la fila? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			}
			else {
				cout << "La fila esta vacia" << endl;
				break;
			}
			system("cls");
		} while (resp == 's');
		
	}
	f.limpiarFila();
	f.desplegarFila();
	system("pause");
}
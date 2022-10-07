// Fila_menu.cpp: archivo de proyecto principal.


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
int Fila::longitudFila() {
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
		cout << "La fila esta vacia" << endl;
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
	int opc;

	do {
		system("cls");
		cout << "1. Meter elemento a la fila" << endl;
		cout << "2. Sacar un elemento de la fila" << endl;
		cout << "3. Mostrar longitud de la fila" << endl;
		cout << "4. Mostrar el frente de la fila" << endl;
		cout << "5. Limpiar fila" << endl;
		cout << "6. Desplegar fila" << endl;
		cout << "7. Salir " << endl;
		cout << "Escoja la opcion deseada del anterior menu: " << endl;
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			do {
				system("cls");
				cout << "Entre elemento a la fila" << endl;
				cin >> valor;
				f.meter(valor);
				cout << "Desea entrar otro elemento a la fila? (s/n)" << endl;
				cin >> resp;
				resp = tolower(resp);
			} while (resp == 's');
			system("pause");
			break;
		case 2:
			do {
				system("cls");
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
			} while (resp == 's');
			system("pause");
			break;
		case 3:
			cout << "Longitud de la fila: " << f.longitudFila() << endl;
			system("pause");
			break;

		case 4:
			cout << "Frente de la fila: " << f.frenteFila() << endl;
			system("pause");
			break;

		case  5:
			f.limpiarFila();
			cout << "Fila limpiada"<<endl;
			system("pause");
			break;
		case  6:
			cout << "Desplegar fila: " << endl;
			f.desplegarFila();
			system("pause");
			break;
		case 7:
			system("pause");
			break;
		}
	} while (opc != 7);
}
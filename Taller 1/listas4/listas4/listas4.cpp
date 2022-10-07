// listas3.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

struct nodo {
	int datos;
	nodo* sig;
};

nodo *inicial = NULL;

void leer_nodo(nodo *nuevo) {
	cout << "Entre el valor del nodo " << endl;
	cin >> nuevo->datos;
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

void imprime_nodo(nodo *apun){
	cout<<"El valor es "<<apun->datos<<endl;
}

void reco_recur(nodo *apun){
	if(apun!=NULL){
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

void main()
{
	nodo *anterior, *nuevo, *apun;
	char resp;
	anterior = NULL;
	do {
		nuevo = new nodo;
		crear_lista(anterior, nuevo);
		anterior = nuevo;
		cout<<"¿Desea crear otro nodo? (s/n)"<<endl;
		cin>>resp;
		resp=tolower(resp);
	}while(resp!='n');
	
	apun=inicial;
	reco_recur(apun);
	borrar_lista();
	system("pause");
}

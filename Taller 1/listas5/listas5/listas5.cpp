// listas3.cpp: archivo de proyecto principal.

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
	nuevo->nombre=new char[30];
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

void imprime_nodo(nodo *apun){
	cout<<"El codigo es "<<apun->codigo<<endl;
	cout<<"El nombre es "<<apun->nombre<<endl;
	cout<<"El nivel es "<<apun->nivel<<endl;
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

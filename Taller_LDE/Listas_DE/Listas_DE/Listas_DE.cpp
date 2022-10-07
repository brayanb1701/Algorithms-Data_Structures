// Listas_DE.cpp: archivo de proyecto principal.


#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
	nodo *ant;
};
class Lde
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
public:
	Lde();
	~Lde();
	void agregar();
	void eliminar();
	void desplegarLista();
};
Lde::Lde()
{
	inicial = NULL;
}
Lde::~Lde()
{
	nodo *apun = inicial;
	while (apun != NULL) {

		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");

}
void Lde::desplegarLista()
{
	if (inicial == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		nodo *apunt;
		apunt = inicial;
		while (apunt != NULL)
		{
			cout << apunt->dato << endl;
			apunt = apunt->sig;
		}
	}
	system("pause");
}
nodo *Lde::buscarLista(int clave)
{
	nodo*anterior;
	anterior = NULL;
	if (inicial == NULL) {
		return anterior;
	}
	else {
		if (clave < inicial->dato)return anterior;
		else
		{
			anterior = inicial;
			while ((anterior->sig != NULL) && (clave >= anterior->sig->dato))
				anterior = anterior->sig;
			return anterior;
		}
	}
}
void Lde::agregar()
{
	nodo *nuevo, *anterior;
	char resp;
	do
	{
		nuevo = new nodo();
		cout << "Entre clave del nodo a agregar" << endl;
		cin >> nuevo->dato;

		if (inicial == NULL)
		{
			inicial = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);
			if (anterior == NULL)
			{
				nuevo->sig = inicial;
				nuevo->ant = inicial->ant;
				inicial->ant = nuevo;
				inicial = nuevo;
			}
			else
			{
				if (anterior->dato == nuevo->dato) {
					cout << "El nodo a agregar ya existe" << endl;
				}
				else {
					if (anterior->sig != NULL)
					{
						nuevo->sig = anterior->sig;
						nuevo->ant = anterior;
						anterior->sig->ant = nuevo;
						anterior->sig = nuevo;
					}
					else
					{
						nuevo->sig = NULL;
						nuevo->ant = anterior;
						anterior->sig = nuevo;
					}

				}
			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
}

void Lde::eliminar() {
	char resp;
	do
	{
		int clave;
		cout << "Entre clave del nodo a eliminar" << endl;
		cin >> clave;

		nodo *eliminar;
		eliminar = buscarLista(clave);
		if (eliminar == NULL) {
			cout << "El nodo no ha sido encontrado" << endl;
		}
		else if (eliminar->dato != clave) {
			cout << "El nodo no ha sido encontrado" << endl;
		}
		else if (eliminar->sig == NULL && eliminar->ant == NULL) {
			delete eliminar;
			inicial = NULL;
		}
		else {
			if (eliminar == inicial) {
				inicial = eliminar->sig;
				eliminar->sig->ant = eliminar->ant;
				delete eliminar;
			}
			else {
				nodo *aux;
				aux = inicial;
				while (aux->sig != eliminar) {
					aux = aux->sig;
				}
				aux->sig = eliminar->sig;
				if (eliminar->sig != NULL) {
					eliminar->sig->ant = aux;
				}
				delete eliminar;

			}
		}

		cout << "Desea eliminar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');

}

void main()
{
	Lde l;
	l.agregar();
	l.desplegarLista();
	l.eliminar();
	l.desplegarLista();
}



// Lista_SEC.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
};
class Lsec
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
	nodo *buscarUltimo();
public:
	Lsec();
	~Lsec();
	void agregar();
	void eliminarNodo();
	void desplegarLista();
};
Lsec::Lsec()
{
	inicial = NULL;
}
Lsec::~Lsec()
{
	if (inicial != NULL) {
		nodo *apun = inicial;
		while (apun != inicial->sig) {

			inicial = apun->sig;
			delete apun;
			apun = inicial;
		}
		system("pause");
	}
}
void Lsec::desplegarLista()
{
	nodo *apunt;
	if (inicial == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		
		apunt = inicial;
		do
		{
			cout << apunt->dato << " ";
			apunt = apunt->sig;
		} while (apunt != inicial);
	}
	system("pause");
}
nodo *Lsec::buscarUltimo() {
	nodo *ultimo;
	ultimo = inicial;
	while (ultimo->sig != inicial) {
		ultimo = ultimo->sig;
	}
	return ultimo;
}
nodo *Lsec::buscarLista(int clave)
{
	nodo*anterior;
	anterior = NULL;
		if (clave < inicial->dato)return anterior;
		else
		{
			anterior = inicial;
			while ((anterior->sig != inicial) && (clave >= anterior->sig->dato))
				anterior = anterior->sig;
			return anterior;
		}
	
}
void Lsec::agregar()
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
			nuevo->sig = nuevo;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);
			if (anterior == NULL)
			{
				nodo *ultimo;
				ultimo = buscarUltimo();
				ultimo->sig = nuevo;
				nuevo->sig = inicial;
				inicial = nuevo;
			}
			else
			{
				if (anterior->dato == nuevo->dato) {
					cout << "El nodo a agregar ya existe" << endl;
				}
				else {
						nuevo->sig = anterior->sig;
						anterior->sig = nuevo;
				}
			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
}

void Lsec::eliminarNodo() {
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
		else if (eliminar == eliminar->sig) {
			delete eliminar;
			inicial = NULL;
		}
		else {
			if (eliminar == inicial) {
				
				nodo *ultimo;
				ultimo = buscarUltimo();
				ultimo->sig = eliminar->sig;
				inicial = eliminar->sig;
				
				delete eliminar;
			}
			else {
				nodo *aux;
				aux = inicial;
				while (aux->sig != eliminar) {
					aux = aux->sig;
				}
				aux->sig = eliminar->sig;
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
	Lsec l;
	l.agregar();
	l.desplegarLista();
	l.eliminarNodo();
	l.desplegarLista();
}



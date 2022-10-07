// Listas_menu.cpp: archivo de proyecto principal.


#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;
struct nodo
{
	int dato;
	nodo *sig;
};
class Lse
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
public:
	Lse();
	~Lse();
	void agregar();
	void eliminar();
	void desplegarLista();
};
Lse::Lse()
{
	inicial = NULL;
}
Lse::~Lse()
{
	nodo *apun = inicial;
	while (apun != NULL) {

		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
	system("pause");

}
void Lse::desplegarLista()
{
	system("cls");
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
nodo *Lse::buscarLista(int clave)
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
void Lse::agregar()
{
	nodo *nuevo, *anterior;
	char resp;
	
	do
	{
		system("cls");
		nuevo = new nodo();
		cout << "Entre clave del nodo a agregar" << endl;
		cin >> nuevo->dato;

		if (inicial == NULL)
		{
			inicial = nuevo;
			nuevo->sig = NULL;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);
				if (anterior == NULL)
				{
					nuevo->sig = inicial;
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
							anterior->sig = nuevo;
						}
						else
						{
							nuevo->sig = NULL;
							anterior->sig = nuevo;
						}
					}
				}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
	system("pause");
}

void Lse::eliminar() {
	char resp;
	system("cls");
	do
	{
		system("cls");
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
		else {
			if (eliminar == inicial) {
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
	system("pause");
}

void main()
{
	Lse lista;
	nodo *anterior, *nuevo, *apun;
	char resp;
	anterior = NULL;
	int opc;

	do {
		system("cls");
		cout << "1. Agregar elementos a la lista  " << endl;
		cout << "2. Mostrar lista actual" << endl;
		cout << "3. Eliminar elementos de la lista" << endl;
		cout << "4. Salir " << endl;
		cout << "Escoja la opcion deseada del anterior menu: " << endl;
		cin >> opc;
		cout << endl << endl;
		system("cls");
		switch (opc)
		{
			case 1:
				lista.agregar();
			break;
			case 2:
				lista.desplegarLista();
			break;
			case 3:
				lista.eliminar();
			break;

		case 4:
			
			break;

		case  5:

			break;
		}

	}while(opc != 4);
}



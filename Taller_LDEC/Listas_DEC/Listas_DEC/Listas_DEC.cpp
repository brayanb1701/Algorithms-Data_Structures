// Listas_DEC.cpp: archivo de proyecto principal.


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
class Ldec
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
public:
	Ldec();
	~Ldec();
	void agregar();
	void eliminar();
	void desplegarLista();
};
Ldec::Ldec()
{
	inicial = NULL;
}
Ldec::~Ldec()
{
	if (inicial != NULL) {
		nodo *apun = inicial;

		do {

			inicial = apun->sig;
			delete apun;
			apun = inicial;
		} while (apun != inicial);
	}
	system("pause");

}
void Ldec::desplegarLista()
{
	int respuesta;
	nodo *apunt;

	if (inicial == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		cout << "Digite 1: para desplegar en sentido horario" << endl;
		cout << " 2: para desplegar en sentido horario" << endl;
		cin >> respuesta;
		if (respuesta == 1) {
			apunt = inicial;
			do
			{
				cout << apunt->dato <<" "<< endl;
				apunt = apunt->sig;
			} while (apunt != inicial);
		}
		else if(respuesta==2){
			apunt = inicial->ant;
			do
			{
				cout << apunt->dato << " " << endl;
				apunt = apunt->ant;
			} while (apunt != inicial->ant);
		}
	}
	system("pause");
}
nodo *Ldec::buscarLista(int clave)
{
	nodo*anterior;
	anterior = NULL;
	if (inicial == NULL) {
		return anterior;
	}
	else {
		if (clave <= inicial->dato)return anterior;
		else
		{
			anterior = inicial;
			while ((anterior->sig != inicial) && (clave > anterior->sig->dato))
				anterior = anterior->sig;
			return anterior;
		}
	}
}
void Ldec::agregar()
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
			nuevo->ant = nuevo;
		}
		else
		{
			anterior = buscarLista(nuevo->dato);
			if (anterior == NULL)
			{
				if (inicial->dato == nuevo->dato) {
					cout << "El nodo a agregar ya existe" << endl;
				}
				else if(inicial->dato != nuevo->dato){
					inicial->ant->sig = nuevo;
					nuevo->sig = inicial;
					nuevo->ant = inicial->ant;
					inicial->ant = nuevo;
					inicial = nuevo;
				}
			}
			else
			{
				if (anterior->sig->dato == nuevo->dato) {
					cout << "El nodo a agregar ya existe" << endl;
				}
				else {
					
						nuevo->sig = anterior->sig;
						nuevo->ant = anterior;
						anterior->sig->ant = nuevo;
						anterior->sig = nuevo;
					

				}
			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');
}

void Ldec::eliminar() {
	char resp;
	do
	{
		int clave;
		cout << "Entre clave del nodo a eliminar" << endl;
		cin >> clave;

		nodo *anterior;
		anterior = buscarLista(clave);
		if (anterior == NULL) {
			if (inicial == NULL) cout << "No quedan nodos por eliminar" << endl;
			else if (inicial->dato == clave) {
				if (inicial->sig==inicial->ant) {
					anterior = inicial;
					delete anterior;
					inicial = NULL;
				}
				else {
					anterior = inicial;
					inicial = anterior->sig;
					inicial->ant = anterior->ant;
					inicial->sig->ant = inicial;
					anterior->ant->sig = inicial;
					inicial->sig = anterior->sig->sig;
					delete anterior;
				}
			}
			else {
				cout << "El nodo no ha sido encontrado" << endl;
			}
		}
		else if (anterior->sig->dato != clave) {
			cout << "El nodo no ha sido encontrado" << endl;
		}
		/*else if (anterior->sig->sig == anterior->sig && anterior == anterior->sig) {
			delete anterior;
			inicial = NULL;
		}*/
		else {
			
			
				nodo *aux, *eliminar;
				eliminar = anterior->sig;
				aux = anterior;
				
					eliminar->ant->sig = eliminar->sig;
					eliminar->sig->ant = aux;
				
				delete eliminar;

			
		}

		cout << "Desea eliminar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
	} while (resp == 's');

}

void main()
{
	Ldec l;
	l.agregar();
	l.desplegarLista();
	l.eliminar();
	l.desplegarLista();
}



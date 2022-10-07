// arboles_binarios.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"
using namespace System;
using namespace std;

class nodoarbol
{
public:
	int info;
	nodoarbol *der, *izq;
	nodoarbol()
	{
		izq = NULL;
		der = NULL;
	}
	nodoarbol(int dato)
	{
		info = dato;
		izq = NULL;
		der = NULL;
	}
};

struct nodo
{
	nodoarbol *dato;
	nodo *sig;
};
class Fila {
private:
	nodo *frente;
	nodo *final;

public:

	Fila() {
		frente = NULL;
		final = NULL;
	}
	~Fila() {
		nodo *apunt;
		apunt = frente;
		while (frente != NULL) {
			frente = apunt->sig;
			delete apunt;
			apunt = frente;
		}
	}
	char meter(nodoarbol *valor) {
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
	nodoarbol* sacar() {
		nodo *apunt;
		apunt = frente;
		if (apunt == NULL) return NULL;
		else {
			if (frente->sig == NULL) {
				frente = NULL;
				final = NULL;
			}
			else frente = apunt->sig;
			return apunt->dato;
			delete apunt;

		}
	}
	void limpiarFila() {
		nodo *apunt;
		apunt = frente;
		while (frente != NULL) {
			frente = apunt->sig;
			delete apunt;
			apunt = frente;
		}
	}
	nodo* frenteFila() {
		return frente;
	}

};




class ABB
{

private:
	nodoarbol *raiz;
public:
	ABB()
	{
		raiz = NULL;
	}
	~ABB()
	{
		cout << "Entro al destructor " << endl;
		borrar_nodos_postorden_converso(raiz);
		cout << " Salgo del destrcutor" << endl;
		system("pause");
	}
	void borrar_nodos(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			borrar_nodos(raiz->izq);
			borrar_nodos(raiz->der);
			cout << "Destructor de " << raiz->info << endl;
			delete raiz;
		}
	}

	void borrar_nodos_postorden_converso(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			borrar_nodos_postorden_converso(raiz->der);
			borrar_nodos_postorden_converso(raiz->izq);
			cout << "Destructor de " << raiz->info << endl;
			delete raiz;

			
			
		}
	}
	void insertar()
	{
		nodoarbol *aux1, *aux2, *aux3;
		bool igual = false;
		aux1 = new nodoarbol;
		aux2 = raiz;
		aux3 = NULL;
		cout << "Entre el valor del nodo a insertar: ";
		cin >> aux1->info;
		while (aux2 != NULL)
		{
			aux3 = aux2;
			if (aux1->info == aux2->info) {
				cout << "El nodo a insertar ya existe" << endl;
				igual = true;
				break;
			}
			if (aux1->info > aux2->info) aux2 = aux2->der;
			else aux2 = aux2->izq;
		}
		if (!igual) {
			if (aux3 == NULL) raiz = aux1;
			else
				if (aux1->info < aux3->info) aux3->izq = aux1;
				else aux3->der = aux1;
		}
	}
	nodoarbol *devolver_raiz()
	{
		return raiz;
	}
	void despliega_inorden(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			despliega_inorden(raiz->izq);
			cout << raiz->info << endl;
			despliega_inorden(raiz->der);
		}
	}
	void despliega_inorden_converso(nodoarbol *raiz)
	{
		if (raiz != NULL)
		{
			despliega_inorden_converso(raiz->der);
			cout << raiz->info << endl;
			despliega_inorden_converso(raiz->izq);
		}
	}
	void despliega_por_nivel(nodoarbol *raiz) {
		Fila f;
		if (raiz != NULL) {
			f.meter(raiz);
			while (f.frenteFila() != NULL){
				raiz = f.sacar();
				cout << raiz->info<<endl;
				if (raiz->izq != NULL) {
					f.meter(raiz->izq);
				}
				if (raiz->der != NULL) {
					f.meter(raiz->der);
				}
			} 
		}
	}

	void eliminar_nodo(int valor)
	{
		nodoarbol *aux1, *aux2, *temp;
		bool b;
		//Inicio de la busqueda del nodo a eliminar
		if (raiz != NULL)
		{
			aux1 = raiz;
			aux2 = NULL;
			while (aux1->info != valor)
			{
				aux2 = aux1;
				if (valor < aux1->info) aux1 = aux1->izq;
				else aux1 = aux1->der;
				if (aux1 == NULL)
				{
					cout << "EL NODO A ELIMINAR NO EXISTE" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "EL ARBOL NO CONTIENE NODOS" << endl;
			aux1 = NULL;
		}
		//Fin de la busqueda del nodo a eliminar
		//En aux1 queda la direccion del nodo a eliminar
		//En aux2 queda la direccion del nodo padre del nodo a eliminar
		if (aux1 != NULL)
		{
			//Cuando no tiene hijos
			temp = aux1;
			if ((aux1->izq == NULL) && (aux1->der == NULL))
			{
				if (aux2 != NULL)
				{
					if (aux1->info > aux2->info) aux2->der = NULL;
					else aux2->izq = NULL;
				}
				else
				{
					raiz = NULL;
				}

			}
			//else
			//{
			//	if ((aux1->izq != NULL) && (aux1->der != NULL))
			//	{
			//		//Cuando tiene dos hijos
			//		aux2 = aux1; //CON EL PREDECESOR 
			//		temp = aux1->izq;
			//		b = true;
			//		while (temp->der != NULL)
			//		{
			//			aux2 = temp;
			//			temp = temp->der;
			//			b = false;
			//		}
			//		aux1->info = temp->info;
			//		if (b == true)aux1->izq = temp->izq;
			//		else
			//		{
			//			if (temp->izq != NULL)aux2->der = temp->izq;
			//			else aux2->der = NULL;
			//		}
			//	}
			else
			{
				if ((aux1->izq != NULL) && (aux1->der != NULL))
				{
					//Cuando tiene dos hijos
					aux2 = aux1; //CON EL SUCESOR
					temp = aux1->der;
					b = true;
					while (temp->izq != NULL)
					{
						aux2 = temp;
						temp = temp->izq;
						b = false;
					}
					aux1->info = temp->info;
					if (b == true)aux1->der = temp->der;
					else
					{
						if (temp->der != NULL)aux2->izq = temp->der;
						else aux2->izq = NULL;
					}
				}
				else
				{	//Cuando tiene un solo hijo
					if (aux1->izq == NULL)
						if (aux2 != NULL)
						{
							if (aux1->info < aux2->info)
								aux2->izq = aux1->der;
							else aux2->der = aux1->der;
						}
						else raiz = aux1->der;
					else
						if (aux2 != NULL)
						{
							if (aux1->info < aux2->info)
								aux2->izq = aux1->izq;
							else aux2->der = aux1->izq;
						}
						else raiz = aux1->izq;
				}
			}
			delete temp;
		}
	}
};



void main()
{
	nodoarbol *raiz;
	char resp;
	int valor;
	ABB n;
	do
	{
		n.insertar();
		cout << "Desea crear otro nodo? (s/n)" << endl;
		cin >> resp;
		cout << endl;
		resp = tolower(resp);
	} while (resp != 'n');
	cout << "LOS NODOS DEL ARBOL (inorden) SON" << endl;
	raiz = n.devolver_raiz();
	n.despliega_inorden(raiz);
	cout << "LOS NODOS DEL ARBOL (inorden converso) SON" << endl;
	raiz = n.devolver_raiz();
	n.despliega_inorden_converso(raiz);
	cout << "LOS NODOS DEL ARBOL (nivel por nivel) SON" << endl;
	n.despliega_por_nivel(raiz);
	do
	{
		cout << "Entre el valor del nodo a eliminar" << endl;
		cin >> valor;
		n.eliminar_nodo(valor);
		cout << endl;
		cout << "LOS NODOS DEL ARBOL (inorden) SON" << endl;
		raiz = n.devolver_raiz();
		n.despliega_inorden(raiz);
		cout << "LOS NODOS DEL ARBOL (inorden converso) SON" << endl;
		raiz = n.devolver_raiz();
		n.despliega_inorden_converso(raiz);
		cout << "LOS NODOS DEL ARBOL (nivel por nivel) SON" << endl;
		n.despliega_por_nivel(raiz);
		cout << "Desea eliminar otro nodo? (s/n): " << endl;
		cin >> resp;
		cout << endl;
		resp = tolower(resp);
	} while (resp != 'n');
	system("pause");
}
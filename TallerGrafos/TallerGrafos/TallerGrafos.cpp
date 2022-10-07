// TallerGrafos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "stdio.h"

using namespace System;
using namespace std;


class arista;

class vertice {
	vertice *sig;
	arista *ady;
	int numero;
	friend class grafo;
};

class arista {
	arista *sig;
	vertice *ady;
	char letra;
	friend class grafo;
};

class grafo {
	vertice *h;
public:
	void inicializa();
	bool vacio();
	int tamaño();
	vertice *getVertice(int numero);
	void insertarArista(vertice *origen, vertice *destino, char letra);
	void insertarVertice(int numero);
	void listaAdyacencia();
	void recorridoAnchura(vertice *origen);
	void recorridoProfundidad(vertice *origen);

};

void grafo::inicializa() {
	h = NULL;
}

bool grafo::vacio() {
	if (h == NULL) {
		return true;
	}
	else
		return false;
}

int grafo::tamaño() {
	int cont = 0;
	vertice *aux;
	aux = h;
	while (aux != NULL) {
		cont++;
		aux = aux->sig;
	}
	return cont;
}

vertice *grafo::getVertice(int numero) {
	vertice *aux;
	aux = h;
	while (aux != NULL) {
		if (aux->numero == numero)
		{
			return aux;
		}
		aux = aux->sig;
	}
	return NULL;
}

void grafo::insertarVertice(int numero)
{
	vertice *nuevo = new vertice;
	nuevo->numero = numero;
	nuevo->sig = NULL;
	nuevo->ady = NULL;

	if (vacio()) {
		h = nuevo;

	}
	else
	{
		vertice *aux;
		aux = h;
		if (getVertice(numero) != NULL) {
			cout << "El nodo a agregar ya existe" << endl;
		}
		else {
			while (aux->sig != NULL)
			{
				aux = aux->sig;
			}

			aux->sig = nuevo;
		}
	}
}

void grafo::insertarArista(vertice *origen, vertice *destino, char letra) {
	arista *nueva = new arista;
	nueva->letra = letra;
	nueva->sig = NULL;
	nueva->ady = NULL;
	arista *aux;
	aux = origen->ady;

	if (aux == NULL) {
		origen->ady = nueva;
		nueva->ady = destino;
	}
	else {
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nueva;
		nueva->ady = destino;
	}
}

void grafo::listaAdyacencia() {
	vertice *veraux;
	arista *arisaux;

	veraux = h;
	while (veraux != NULL) {
		cout << veraux->numero << "->";
		arisaux = veraux->ady;

		while (arisaux != NULL)
		{
			cout << arisaux->ady->numero << "->";
			arisaux = arisaux->sig;

		}
		veraux = veraux->sig;
		cout << endl;
	}
}

struct nodo
{
	vertice *dato;
	nodo *sig;
};

class Fila {
private:
	nodo *frente;
	nodo *final;
public:
	Fila();
	char meter(vertice *valor);
	char sacar(vertice* &valor);
	~Fila();
	void limpiarFila();
	nodo* frenteFila();
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
char Fila::meter(vertice *valor) {
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
char Fila::sacar( vertice* &valor) {
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
nodo* Fila::frenteFila() {
	return frente;
}

void grafo::recorridoAnchura(vertice *origen) {
	Fila f;
	vertice *valor;
	arista *arisaux;
	int i, cont = 0;
	vertice* visited[10];
	visited[cont] = origen;
	cont++;
	f.meter(origen);
	while (f.frenteFila()!=NULL) {
		f.sacar(valor);
		cout << valor->numero<<" -> ";
		arisaux = valor->ady;
		int limite = (sizeof(visited) / sizeof(visited[0]));
		while (arisaux != NULL)
		{
			int verif=0;
			for (i = 0;i < limite;i++) {
				if (visited[i] == arisaux->ady) {
					verif = 1;
					break;
				}
			}
			if (verif != 1) {
				visited[cont] = arisaux->ady;
				cont++;
				f.meter(arisaux->ady);
			}
			arisaux = arisaux->sig;

		}
	}

}


class Pila {
private:
	nodo *tope;
public:
	Pila();
	char meter(vertice* valor);
	char sacar(vertice* &valor);
	~Pila();
	void limpiarPila();
	nodo* cimaPila();
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
char Pila::meter(vertice* valor) {
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
char Pila::sacar(vertice* &valor) {
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
nodo* Pila::cimaPila() {
	return tope;
}

void grafo::recorridoProfundidad(vertice *origen) {
	Pila p;
	vertice *valor;
	arista *arisaux;
	int i, cont = 0;
	vertice* visited[10];
	visited[cont] = origen;
	cont++;
	p.meter(origen);
	while (p.cimaPila() != NULL) {
		p.sacar(valor);
		cout << valor->numero << " -> ";
		arisaux = valor->ady;
		int limite = (sizeof(visited) / sizeof(visited[0]));
		while (arisaux != NULL)
		{
			int verif = 0;
			for (i = 0;i < limite;i++) {
				if (visited[i] == arisaux->ady) {
					verif = 1;
					break;
				}
			}
			if (verif != 1) {
				visited[cont] = arisaux->ady;
				cont++;
				p.meter(arisaux->ady);
			}
			arisaux = arisaux->sig;

		}
	}

}

void main()
{
	grafo g;
	g.inicializa();
	int opc;
	char resp;
	do
	{
		Console::Clear();
		cout << "\n************MENU PRINCIPAL*****************" << endl;
		cout << "1. Ingresar vertice" << endl;
		cout << "2. Ingresar arista" << endl;
		cout << "3. Desplegar lista de adyacencia" << endl;
		cout << "4. Recorra en amplitud" << endl;
		cout << "5. Recorra en profundidad" << endl;
		cout << "6. Salir" << endl;
		cout << "*******************************************" << endl;
		cin >> opc;
		Console::Clear();
		switch (opc)
		{
		case 1:
			do {
				int numero;
				cout << "Ingrese el vertice" << endl;
				cin >> numero;
				g.insertarVertice(numero);
				cout << "Desea ingresar otro vertice? (s/n)" << endl;
				cin >> resp;
				cout << endl;
				resp = tolower(resp);
			} while (resp != 'n');
			system("pause");
			break;
		case 2:
			do {
				char letra;
				int inicial, final;

				cout << "Ingrese la arista" << endl;
				cin >> letra;
				cout << "Ingrese el vertice inicial" << endl;
				cin >> inicial;
				cout << "Ingrese el vertice final" << endl;
				cin >> final;
				g.insertarArista(g.getVertice(inicial), g.getVertice(final), letra);
				cout << "Desea ingresar otra arista? (s/n)" << endl;
				cin >> resp;
				cout << endl;
				resp = tolower(resp);
			} while (resp != 'n');
			system("pause");
			break;

		case 3:
			g.listaAdyacencia();
			system("pause");
			break;
		case 4:
			int num;
			cout << "Ingrese el nodo a partir del cual se va a recorrer: ";
			cin >> num;
			g.recorridoAnchura(g.getVertice(num));
			system("pause");
			break;
		case 5:
			int num2;
			cout << "Ingrese el nodo a partir del cual se va a recorrer: ";
			cin >> num2;
			g.recorridoProfundidad(g.getVertice(num2));
			system("pause");
			break;
		case 6:
			//exit(0);
			system("pause");
			break;

		default:
			cout << "Lo sentimos, " << opc << " no es una opcion valida, por favor intente de nuevo" << endl;
			system("pause");
			break;
		}

	} while (opc != 6);
	_getch();

}
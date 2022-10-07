// Ford-Fulkerson.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <iostream> 

using namespace System;
using namespace std;


#define V 9 

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
	int ida;
	int regreso;
	friend class grafo;
};

class grafo {
	vertice *h;
public:
	void inicializa();
	void inicializa(vertice* origen);
	bool vacio();
	int tamaño();
	vertice *getVertice(int numero);
	void insertarArista(vertice *origen, vertice *destino, char letra, int ida, int regreso);
	void insertarVertice(int numero);
	void listaAdyacencia();
	void bfs(vertice *origen);
	bool bfs(vertice *origen, int s, int t, int parent[]);
	int grafo::fordFulkerson(vertice* origen, int s, int t);

};

void grafo::inicializa() {
	h = NULL;
}

void grafo::inicializa(vertice* origen) {
	h = origen;
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

void grafo::insertarArista(vertice *origen, vertice *destino, char letra, int ida, int regreso) {
	arista *nueva = new arista;
	nueva->ida = ida;
	nueva->regreso = regreso;
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
char Fila::sacar(vertice* &valor) {
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

void grafo::bfs(vertice *origen) {
	Fila f;
	vertice *valor;
	arista *arisaux;
	int i, cont = 0;
	vertice* visited[10];
	visited[cont] = origen;
	cont++;
	f.meter(origen);
	while (f.frenteFila() != NULL) {
		f.sacar(valor);
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
				f.meter(arisaux->ady);
			}
			arisaux = arisaux->sig;

		}
	}

}

bool grafo::bfs(vertice *origen, int s, int t, int parent[]) {
	Fila f;
	vertice *valor;
	arista *arisaux;
	int i, cont = 0;
	bool visited[V+1];
	memset(visited, 0, sizeof(visited));
	visited[origen->numero] = true;
	cont++;
	f.meter(origen);
	parent[s] = -1;
	while (f.frenteFila() != NULL) {
		f.sacar(valor);
		arisaux = valor->ady;
		int limite = (sizeof(visited) / sizeof(visited[0]));
		while (arisaux != NULL)
		{
			if (visited[arisaux->ady->numero]!=true && arisaux->ida>0) {
				visited[arisaux->ady->numero] = true;
				parent[arisaux->ady->numero] = valor->numero;
				f.meter(arisaux->ady);
			}
			arisaux = arisaux->sig;

		}
	}

	cout << "Vector Parent: " << endl;
	for (int ip = 0; ip < V;ip++) {
		cout << "Parent[" << ip + 1 << "]= " << parent[ip] + 1 << "; " << endl;
	}
	cout << endl;
	// If we reached sink in BFS starting from source, then return 
	// true, else false 
	return (visited[t] != NULL);

}

int grafo::fordFulkerson(vertice* origen, int s, int t)
{
	int u, v;

	// Create a residual graph and fill the residual graph with 
	// given capacities in the original graph as residual capacities 
	// in residual graph 
	grafo rGraph; // Residual graph where rGraph[i][j] indicates  
					  // residual capacity of edge from i to j (if there 
					  // is an edge. If rGraph[i][j] is 0, then there is not)   

	rGraph.inicializa(origen);

	
	int parent[V];  // This array is filled by BFS and to store path 

	int max_flow = 0;  // There is no flow initially 

					   // Augment the flow while tere is path from source to sink 
	while (rGraph.bfs(rGraph.getVertice(s), s, t, parent))
	{
		// Find minimum residual capacity of the edges along the 
		// path filled by BFS. Or we can say find the maximum flow 
		// through the path found. 
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			vertice* aux=rGraph.getVertice(u);
			arista* arisaux = aux->ady;
			while (arisaux->ady->numero != v) {
				arisaux = arisaux->sig;
			}
			if (path_flow > arisaux->ida) {
				path_flow = arisaux->ida;
			}
		}
		cout << "Flujo del patron = " << path_flow << endl << endl;
		// update residual capacities of the edges and reverse edges 
		// along the path 
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			vertice* aux = rGraph.getVertice(u);
			arista* arisaux = aux->ady;
			while (arisaux->ady->numero != v) {
				arisaux = arisaux->sig;
			}
			arisaux->ida -= path_flow;
			arisaux->regreso += path_flow;
		}
		
		// Add path flow to overall flow 
		max_flow += path_flow;
		cout << "Flujo maximo = " << max_flow << endl << endl;
	}
	cout << "El flujo maximo posible es: ";
	// Return the overall flow 
	return max_flow;
}


// Driver program to test above functions 
int main()
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
		cout << "5. Flujo Maximo (Ford-Fulkerson)" << endl;
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
				int inicial, final, ida, regreso;

				cout << "Ingrese la arista" << endl;
				cin >> letra;
				cout << "Ingrese el vertice inicial" << endl;
				cin >> inicial;
				cout << "Ingrese el vertice final" << endl;
				cin >> final;
				cout << "Ingrese el peso de ida" << endl;
				cin >> ida;
				cout << "Ingrese el peso de regreso" << endl;
				cin >> regreso;
				g.insertarArista(g.getVertice(inicial), g.getVertice(final), letra, ida, regreso);
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
			g.bfs(g.getVertice(num));
			system("pause");
			break;
		case 5:
			int partida, llegada;
			cout << "Ingrese el nodo de partida: ";
			cin >> partida;
			cout << "Ingrese el nodo de llegada: ";
			cin >> llegada;
			cout << g.fordFulkerson(g.getVertice(partida), partida, llegada) << endl;
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
	// Let us create a graph shown in the above example 
	
	system("pause");
}
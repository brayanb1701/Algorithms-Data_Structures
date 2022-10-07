// Ford-Fulkerson-noLib.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <iostream> 

using namespace System;
using namespace std;

// Number of vertices in given graph 
#define V 9 

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
nodo* Fila::frenteFila() {
	return frente;
}


/* Returns true if there is a path from source 's' to sink 't' in
residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	// Create a visited array and mark all vertices as not visited 
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// Create a queue, enqueue source vertex and mark source vertex 
	// as visited 
	Fila f;
	int valor, u;
	f.meter(s);
	visited[s] = true;
	parent[s] = -1;

	// Standard BFS Loop 
	while (f.frenteFila() != NULL) 
	{
		f.sacar(valor);
		u = valor;
		for (int v = 0; v < V; v++)
		{
			if (visited[v] !=true && rGraph[u][v] > 0)
			{
				f.meter(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	cout << "Vector Parent: " << endl;
	for (int ip = 0; ip < V;ip++) {
		cout << "Parent[" << ip + 1 << "]= " << parent[ip] + 1 << "; " << endl;
	}
	cout << endl;
	// If we reached sink in BFS starting from source, then return 
	// true, else false 
	return (visited[t] == true);
}

// Returns the maximum flow from s to t in the given graph 
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	// Create a residual graph and fill the residual graph with 
	// given capacities in the original graph as residual capacities 
	// in residual graph 
	int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates  
					  // residual capacity of edge from i to j (if there 
					  // is an edge. If rGraph[i][j] is 0, then there is not)   

	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	cout << "Grafo Residual:" << endl;
	for (u = 0; u < V; u++) {
		for (v = 0; v < V; v++) {
			cout << rGraph[u][v] << "	";
		}
		cout << endl;
	}
	cout << endl;
	int parent[V];  // This array is filled by BFS and to store path 

	int max_flow = 0;  // There is no flow initially 

					   // Augment the flow while tere is path from source to sink 
	while (bfs(rGraph, s, t, parent))
	{
		// Find minimum residual capacity of the edges along the 
		// path filled by BFS. Or we can say find the maximum flow 
		// through the path found. 
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			if (path_flow > rGraph[u][v]) {
				path_flow = rGraph[u][v];
			}
		}
		cout << "Flujo del patron = " << path_flow << endl << endl;
		// update residual capacities of the edges and reverse edges 
		// along the path 
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		cout << "Grafo Residual modificado:" << endl;
		for (u = 0; u < V; u++) {
			for (v = 0; v < V; v++) {
				cout << rGraph[u][v] << "	";
			}
			cout << endl;
		}
		cout << endl;
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
	// Let us create a graph shown in the above example 
	int graph[V][V] = {
		{ 0, 20, 0, 0, 30, 0, 30, 0, 0 },
		{ 10, 0, 30, 0, 0, 0, 0, 20, 0 },
		{ 0, 20, 0, 10, 0, 0, 0, 0, 0 },
		{ 0, 0, 10, 0, 0, 20, 0, 0, 30 },
		{ 20, 0, 0, 0, 0, 30, 0, 0, 0 },
		{ 0, 0, 0, 30, 20, 0, 0, 0, 10 },
		{ 10, 0, 0, 0, 0, 0, 0, 0, 50 },
		{ 0, 10, 0, 0, 0, 0, 0, 0, 10 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	cout << fordFulkerson(graph, 0, 8) << endl;
	system("pause");

	return 0;
}
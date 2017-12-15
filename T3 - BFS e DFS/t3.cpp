#include <iostream>
#include <list>
#include <queue> // fila para usar na BFS
#include <algorithm> // função find
#include <stack> // pilha para usar na DFS

using namespace std;

class Grafo{
	int V;
	list<int> *adj;

public:
	Grafo(int V);

	void adicionarAresta(int v1, int v2);
	void bfs(int v, int n);
	void dfs(int v, int n);
};

Grafo::Grafo(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v, int n){
	queue<int> fila;
	bool visitados[V];
	bool encontrado = false;

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	visitados[v] = true;
	cout << "Vertice " << v << " visitado." << endl;

	while(!encontrado){
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				visitados[*it] = true;
				cout << "Vertice " << *it << " visitado." << endl;
				if(*it == n){
                    cout << "VERTICE " << *it << " ENCONTRADO!!!\n";
                    encontrado = true;

				}
				if(!encontrado){
                    fila.push(*it);
                    //Vertice inserido Na fila
				}
			}
		}

		if(!fila.empty() && !encontrado){
			v = fila.front();
			fila.pop();
			//Vertice removido da fila
		}
		else
			break;
	}
}

void Grafo::dfs(int v, int n){
    int x;
	stack<int> pilha;
	bool visitados[V];

	for(int i = 0; i < V; i++)
		visitados[i] = false;

    bool encontrado = false;

	while(!encontrado){
		if(!visitados[v]){
			visitados[v] = true;
			cout << "Vertice " << v << " visitado\n";
			pilha.push(v);
			//Vertice inserido na pilha
		}

		bool achou = false;
		list<int>::iterator it;

		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				achou = true;
				break;
			}
		}

		if(achou){
			v = *it;
			if(v == n){
                cout << "VERTICE " << v << " ENCONTRADO!!!\n";
                encontrado = true;
			}
		}
		else{
			// caso os vizinhos já tenham sido visitados ou nao possui vizinhos
			pilha.pop();
			// Busca finalizada
			if(pilha.empty())
				break;
			v = pilha.top();
			//Vertice retirado do topo da pilha
		}
	}
}
int main(){
	int V_Karate = 34;
    int V_Dolphins = 62;

	int verticeKarate = 34;  //Vértice a ser buscado
    int verticeDolphins = 62;

	int raiz = 1;

	Grafo grafoKarate(V_Karate);
    Grafo grafoDolphins(V_Dolphins);

	//Adicionando arestas no grafo Karate

    grafoKarate.adicionarAresta(1, 2);
    grafoKarate.adicionarAresta(1, 3);
    grafoKarate.adicionarAresta(2, 3);
    grafoKarate.adicionarAresta(1, 4);
    grafoKarate.adicionarAresta(2, 4);
    grafoKarate.adicionarAresta(3, 4);
    grafoKarate.adicionarAresta(1, 5);
    grafoKarate.adicionarAresta(1, 6);
    grafoKarate.adicionarAresta(1, 7);
    grafoKarate.adicionarAresta(5, 7);
    grafoKarate.adicionarAresta(6, 7);
    grafoKarate.adicionarAresta(1, 8);
    grafoKarate.adicionarAresta(2, 8);
    grafoKarate.adicionarAresta(3, 8);
    grafoKarate.adicionarAresta(4, 8);
    grafoKarate.adicionarAresta(1, 9);
    grafoKarate.adicionarAresta(3, 9);
    grafoKarate.adicionarAresta(3, 10);
    grafoKarate.adicionarAresta(1, 11);
    grafoKarate.adicionarAresta(5, 11);
    grafoKarate.adicionarAresta(6, 11);
    grafoKarate.adicionarAresta(1, 12);
    grafoKarate.adicionarAresta(1, 13);
    grafoKarate.adicionarAresta(4, 13);
    grafoKarate.adicionarAresta(1, 14);
    grafoKarate.adicionarAresta(2, 14);
    grafoKarate.adicionarAresta(3, 14);
    grafoKarate.adicionarAresta(4, 14);
    grafoKarate.adicionarAresta(6, 17);
    grafoKarate.adicionarAresta(7, 17);
    grafoKarate.adicionarAresta(1, 18);
    grafoKarate.adicionarAresta(2, 18);
    grafoKarate.adicionarAresta(1, 20);
    grafoKarate.adicionarAresta(2, 20);
    grafoKarate.adicionarAresta(1, 22);
    grafoKarate.adicionarAresta(2, 22);
    grafoKarate.adicionarAresta(24, 26);
    grafoKarate.adicionarAresta(25, 26);
    grafoKarate.adicionarAresta(3, 28);
    grafoKarate.adicionarAresta(24, 28);
    grafoKarate.adicionarAresta(25, 28);
    grafoKarate.adicionarAresta(3, 29);
    grafoKarate.adicionarAresta(24, 30);
    grafoKarate.adicionarAresta(27, 30);
    grafoKarate.adicionarAresta(2, 31);
    grafoKarate.adicionarAresta(9, 31);
    grafoKarate.adicionarAresta(1, 32);
    grafoKarate.adicionarAresta(25, 32);
    grafoKarate.adicionarAresta(26, 32);
    grafoKarate.adicionarAresta(29, 32);
    grafoKarate.adicionarAresta(3, 33);
    grafoKarate.adicionarAresta(9, 33);
    grafoKarate.adicionarAresta(15, 33);
    grafoKarate.adicionarAresta(16, 33);
    grafoKarate.adicionarAresta(19, 33);
    grafoKarate.adicionarAresta(21, 33);
    grafoKarate.adicionarAresta(23, 33);
    grafoKarate.adicionarAresta(24, 33);
    grafoKarate.adicionarAresta(30, 33);
    grafoKarate.adicionarAresta(31, 33);
    grafoKarate.adicionarAresta(32, 33);
    grafoKarate.adicionarAresta(9, 34);
    grafoKarate.adicionarAresta(10, 34);
    grafoKarate.adicionarAresta(14, 34);
    grafoKarate.adicionarAresta(15, 34);
    grafoKarate.adicionarAresta(16, 34);
    grafoKarate.adicionarAresta(19, 34);
    grafoKarate.adicionarAresta(20, 34);
    grafoKarate.adicionarAresta(21, 34);
    grafoKarate.adicionarAresta(23, 34);
    grafoKarate.adicionarAresta(24, 34);
    grafoKarate.adicionarAresta(27, 34);
    grafoKarate.adicionarAresta(28, 34);
    grafoKarate.adicionarAresta(29, 34);
    grafoKarate.adicionarAresta(30, 34);
    grafoKarate.adicionarAresta(31, 34);
    grafoKarate.adicionarAresta(32, 34);
    grafoKarate.adicionarAresta(33, 34);

    //Adicionando arestas no grafo Dolphins

    grafoDolphins.adicionarAresta(4, 9);
    grafoDolphins.adicionarAresta(6, 10);
    grafoDolphins.adicionarAresta(7, 10);
    grafoDolphins.adicionarAresta(1, 11);
    grafoDolphins.adicionarAresta(3, 11);
    grafoDolphins.adicionarAresta(6, 14);
    grafoDolphins.adicionarAresta(7, 14);
    grafoDolphins.adicionarAresta(10, 14);
    grafoDolphins.adicionarAresta(1, 15);
    grafoDolphins.adicionarAresta(4, 15);
    grafoDolphins.adicionarAresta(1, 16);
    grafoDolphins.adicionarAresta(15, 17);
    grafoDolphins.adicionarAresta(2, 18);
    grafoDolphins.adicionarAresta(7, 18);
    grafoDolphins.adicionarAresta(10, 18);
    grafoDolphins.adicionarAresta(14, 18);
    grafoDolphins.adicionarAresta(16, 19);
    grafoDolphins.adicionarAresta(2, 20);
    grafoDolphins.adicionarAresta(8, 20);
    grafoDolphins.adicionarAresta(9, 21);
    grafoDolphins.adicionarAresta(17, 21);
    grafoDolphins.adicionarAresta(19, 21);
    grafoDolphins.adicionarAresta(19, 22);
    grafoDolphins.adicionarAresta(18, 23);
    grafoDolphins.adicionarAresta(15, 25);
    grafoDolphins.adicionarAresta(16, 25);
    grafoDolphins.adicionarAresta(19, 25);
    grafoDolphins.adicionarAresta(18, 26);
    grafoDolphins.adicionarAresta(2, 27);
    grafoDolphins.adicionarAresta(26, 27);
    grafoDolphins.adicionarAresta(2, 28);
    grafoDolphins.adicionarAresta(8, 28);
    grafoDolphins.adicionarAresta(18, 28);
    grafoDolphins.adicionarAresta(26, 28);
    grafoDolphins.adicionarAresta(27, 28);
    grafoDolphins.adicionarAresta(2, 29);
    grafoDolphins.adicionarAresta(9, 29);
    grafoDolphins.adicionarAresta(21, 29);
    grafoDolphins.adicionarAresta(11, 30);
    grafoDolphins.adicionarAresta(19, 30);
    grafoDolphins.adicionarAresta(22, 30);
    grafoDolphins.adicionarAresta(25, 30);
    grafoDolphins.adicionarAresta(8, 31);
    grafoDolphins.adicionarAresta(20, 31);
    grafoDolphins.adicionarAresta(29, 31);
    grafoDolphins.adicionarAresta(18, 32);
    grafoDolphins.adicionarAresta(10, 33);
    grafoDolphins.adicionarAresta(14, 33);
    grafoDolphins.adicionarAresta(13, 34);
    grafoDolphins.adicionarAresta(15, 34);
    grafoDolphins.adicionarAresta(17, 34);
    grafoDolphins.adicionarAresta(22, 34);
    grafoDolphins.adicionarAresta(15, 35);
    grafoDolphins.adicionarAresta(34, 35);
    grafoDolphins.adicionarAresta(30, 36);
    grafoDolphins.adicionarAresta(2, 37);
    grafoDolphins.adicionarAresta(21, 37);
    grafoDolphins.adicionarAresta(24, 37);
    grafoDolphins.adicionarAresta(9, 38);
    grafoDolphins.adicionarAresta(15, 38);
    grafoDolphins.adicionarAresta(17, 38);
    grafoDolphins.adicionarAresta(22, 38);
    grafoDolphins.adicionarAresta(34, 38);
    grafoDolphins.adicionarAresta(35, 38);
    grafoDolphins.adicionarAresta(37, 38);
    grafoDolphins.adicionarAresta(15, 39);
    grafoDolphins.adicionarAresta(17, 39);
    grafoDolphins.adicionarAresta(21, 39);
    grafoDolphins.adicionarAresta(34, 39);
    grafoDolphins.adicionarAresta(37, 40);
    grafoDolphins.adicionarAresta(1, 41);
    grafoDolphins.adicionarAresta(8, 41);
    grafoDolphins.adicionarAresta(15, 41);
    grafoDolphins.adicionarAresta(16, 41);
    grafoDolphins.adicionarAresta(34, 41);
    grafoDolphins.adicionarAresta(37, 41);
    grafoDolphins.adicionarAresta(38, 41);
    grafoDolphins.adicionarAresta(2, 42);
    grafoDolphins.adicionarAresta(10, 42);
    grafoDolphins.adicionarAresta(14, 42);
    grafoDolphins.adicionarAresta(1, 43);
    grafoDolphins.adicionarAresta(3, 43);
    grafoDolphins.adicionarAresta(11, 43);
    grafoDolphins.adicionarAresta(31, 43);
    grafoDolphins.adicionarAresta(15, 44);
    grafoDolphins.adicionarAresta(30, 44);
    grafoDolphins.adicionarAresta(34, 44);
    grafoDolphins.adicionarAresta(38, 44);
    grafoDolphins.adicionarAresta(39, 44);
    grafoDolphins.adicionarAresta(3, 45);
    grafoDolphins.adicionarAresta(21, 45);
    grafoDolphins.adicionarAresta(35, 45);
    grafoDolphins.adicionarAresta(39, 45);
    grafoDolphins.adicionarAresta(9, 46);
    grafoDolphins.adicionarAresta(16, 46);
    grafoDolphins.adicionarAresta(19, 46);
    grafoDolphins.adicionarAresta(22, 46);
    grafoDolphins.adicionarAresta(24, 46);
    grafoDolphins.adicionarAresta(25, 46);
    grafoDolphins.adicionarAresta(30, 46);
    grafoDolphins.adicionarAresta(38, 46);
    grafoDolphins.adicionarAresta(44, 47);
    grafoDolphins.adicionarAresta(1, 48);
    grafoDolphins.adicionarAresta(11, 48);
    grafoDolphins.adicionarAresta(21, 48);
    grafoDolphins.adicionarAresta(29, 48);
    grafoDolphins.adicionarAresta(31, 48);
    grafoDolphins.adicionarAresta(43, 48);
    grafoDolphins.adicionarAresta(35, 50);
    grafoDolphins.adicionarAresta(47, 50);
    grafoDolphins.adicionarAresta(15, 51);
    grafoDolphins.adicionarAresta(17, 51);
    grafoDolphins.adicionarAresta(21, 51);
    grafoDolphins.adicionarAresta(34, 51);
    grafoDolphins.adicionarAresta(43, 51);
    grafoDolphins.adicionarAresta(46, 51);
    grafoDolphins.adicionarAresta(5, 52);
    grafoDolphins.adicionarAresta(12, 52);
    grafoDolphins.adicionarAresta(19, 52);
    grafoDolphins.adicionarAresta(22, 52);
    grafoDolphins.adicionarAresta(24, 52);
    grafoDolphins.adicionarAresta(25, 52);
    grafoDolphins.adicionarAresta(30, 52);
    grafoDolphins.adicionarAresta(46, 52);
    grafoDolphins.adicionarAresta(51, 52);
    grafoDolphins.adicionarAresta(15, 53);
    grafoDolphins.adicionarAresta(30, 53);
    grafoDolphins.adicionarAresta(39, 53);
    grafoDolphins.adicionarAresta(41, 53);
    grafoDolphins.adicionarAresta(44, 54);
    grafoDolphins.adicionarAresta(2, 55);
    grafoDolphins.adicionarAresta(7, 55);
    grafoDolphins.adicionarAresta(8, 55);
    grafoDolphins.adicionarAresta(14, 55);
    grafoDolphins.adicionarAresta(20, 55);
    grafoDolphins.adicionarAresta(42, 55);
    grafoDolphins.adicionarAresta(16, 56);
    grafoDolphins.adicionarAresta(52, 56);
    grafoDolphins.adicionarAresta(6, 57);
    grafoDolphins.adicionarAresta(7, 57);
    grafoDolphins.adicionarAresta(6, 58);
    grafoDolphins.adicionarAresta(7, 58);
    grafoDolphins.adicionarAresta(10, 58);
    grafoDolphins.adicionarAresta(14, 58);
    grafoDolphins.adicionarAresta(18, 58);
    grafoDolphins.adicionarAresta(40, 58);
    grafoDolphins.adicionarAresta(42, 58);
    grafoDolphins.adicionarAresta(49, 58);
    grafoDolphins.adicionarAresta(55, 58);
    grafoDolphins.adicionarAresta(39, 59);
    grafoDolphins.adicionarAresta(4, 60);
    grafoDolphins.adicionarAresta(9, 60);
    grafoDolphins.adicionarAresta(16, 60);
    grafoDolphins.adicionarAresta(37, 60);
    grafoDolphins.adicionarAresta(46, 60);
    grafoDolphins.adicionarAresta(33, 61);
    grafoDolphins.adicionarAresta(3, 62);
    grafoDolphins.adicionarAresta(38, 62);
    grafoDolphins.adicionarAresta(54, 62);

	cout << "Buscando vertice " << verticeKarate << " partindo de " << raiz << endl << endl;

	cout << "BFS Karate:" << endl << endl;

	grafoKarate.bfs(raiz, verticeKarate);

	cout << endl << "DFS Karate:" << endl << endl;

	grafoKarate.dfs(raiz, verticeKarate);

	cout << endl << "Buscando vertice " << verticeDolphins << " partindo de " << raiz << endl << endl;

	cout << "BFS Dolphins:" << endl << endl;

	grafoDolphins.bfs(raiz, verticeDolphins);

	cout << endl << "DFS Dolphins:" << endl << endl;

	grafoDolphins.dfs(raiz, verticeDolphins);

	return 0;
}

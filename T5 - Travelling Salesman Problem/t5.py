import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
from heapq import heappush
from heapq import heappop
Tam = 30

def twiceAround(G, ini = 0):
    F = nx.minimum_spanning_tree(G) #Gera uma MST do grafo G
    F = nx.MultiGraph(F) #Define um MultiGrafo
    
    for u,v in list(F.edges()): #Dublica aresta da mst
        F.add_edge(u,v)

    #Gera o caminho de euler
    euler= list(nx.eulerian_circuit(F, ini))
    #Inicializa o grafo e cria um auxiliar
    caminho = nx.Graph()
    Aux = []
    #Salva o ciclo Euleriano no Aux
    for u,v in euler:
        Aux.append(u)
        Aux.append(v)

    fila = []
    
    
    for i in Aux:
        #Elimina as repetições
        if(i not in fila):
            fila.append(i)
    fila.append(ini)
    for i in range(Tam):
        #Grafo resultante
        caminho.add_edge(fila[i], fila[i+1])
        #Copia os pesos
        caminho[fila[i]][fila[i+1]]['weight'] = G[fila[i]][fila[i+1]]['weight']
    return caminho

#Função para registrar o custo de cada caminho
def calc_custo(G):
    custo = 0
    custos = nx.get_edge_attributes(G, 'weight')
    for v in G.edges():
        custo = custo + custos[v]
    return custo

A = np.loadtxt("ha30_dist.txt")
G = nx.from_numpy_matrix(A)

caminhos = [] #Lista com os custos de cada caminho

for i in range(30):
    Caminho = twiceAround(G, i)
    custo = calc_custo(Caminho)
    heappush(caminhos, (custo, i))

for i in range(30):
    custo, inicial = heappop(caminhos)
    print("Caminho inicia em ", inicial, " com custo: ", custo)


nx.draw(Caminho, with_labels=True)
plt.show()
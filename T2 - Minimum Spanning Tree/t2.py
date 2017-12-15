# -*- coding: utf-8 -*-

import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

#função que retorna a MST dado determinado grafo
def mst_prim(graph):
    #Seta todas as cores dos nós como branco
    nx.set_node_attributes(graph, 'B', 'color')

    # Inicializa o pi(vértice antecessor) dos vértices como vazio
    nx.set_node_attributes(graph, None, 'pi')

    #Inicializa o lambda de todo v e V != Raíz como infinito
    nx.set_node_attributes(graph, float('inf'), 'λ')
    node = 1
    nx.set_node_attributes(graph, {node: 0}, 'λ')#Seta o lambda do primeiro nó com 0
        

    # Verifica se um vértice foi visitado
    nodes_info = graph.nodes(data=True) 
    while any(node[1]['color'] == 'B' for node in nodes_info):
        # Seleciona todos vértices que ainda não foram visitados, i.e color = B
        white_nodes = [node for node in nodes_info if node[1]['color'] == 'B']
        # Seleciona o node com menor lambda
        mNode = min(white_nodes, key=lambda x: x[1]['λ'])

       
        for node in graph.neighbors(mNode[0]):
            node_info = (node, dict(nodes_info)[node])
            if node_info[1]['color'] == 'B':
                novaDistancia = graph.get_edge_data(mNode[0], node_info[0])['weight']
                # Verifica se o lambda atual é menor que w(u,v), se for nao atualiza. 
                if novaDistancia< node_info[1]['λ']:
                    nx.set_node_attributes(graph, {node_info[0]: novaDistancia}, 'λ')
                    nx.set_node_attributes(graph, {node_info[0]: mNode[0]}, 'pi')
                    
        #Marca o Node como visitado
        nx.set_node_attributes(graph, {mNode[0]: 'P'}, 'color')
        nodes_info = graph.nodes(data=True)

    #mst resultante
    mst = nx.DiGraph()

    for node in graph.nodes(data=True):
        if node[1]['pi'] is not None:
            edge_weight = node[1]['λ']
            parent = node[1]['pi']
            mst.add_weighted_edges_from([[parent, node[0], edge_weight]])

    return mst



#Carregando arquivo com matriz de adj
A = np.loadtxt('ha30_dist.txt')
G = nx.from_numpy_matrix(A)



#chamando a função Prim, passando G como parametro
mst = mst_prim(G)
#Desenhando a MST tree
nx.draw(mst)




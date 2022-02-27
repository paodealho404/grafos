#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
typedef struct dist_vert dist_vert;
#define PAIR_INT pair<int, int>
using namespace std;

/**
 * @brief Classe Graph , que é um grafo com lista de adjacências onde cada posição
 * representa um vértice e o elemento da posição é um pair de inteiros que indica
 * o vértice vizinho e o peso da aresta da posição para o vizinho, respectivamente.
 * A classe inclui o algoritmo de Dijkstra para caminhos de menor custo, bem como
 * funções utilitárias de tamanho e construção do grafo.
 * 
 */
class Graph
{
    list<PAIR_INT> *adj_list;
    int size;
public:
    Graph(){
        return;
    }
    Graph(int size)
    {
        this->size = size;
        adj_list = new list<PAIR_INT>[size];
    }
    int get_size();
    void add_edge(int u, int v, int w);
    dist_vert dijkstra(int s, int target, int sorted, FILE* output_file);
    int construct_graph(FILE* input_file, FILE* output_file, int a);
};

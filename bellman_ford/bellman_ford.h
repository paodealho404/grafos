#include <stdio.h>
#include <stdlib.h>

typedef struct Graph Graph;
/**
 * @brief Imprime o array de distancias [distance] de tamanho
 * [n_vertex] de um vértice [source], no arquivo [output]
 * 
 * @param distance 
 * @param source 
 * @param n_vertex 
 * @param output 
 */
void printar(int distance[], int source, int n_vertex, FILE* output);
/**
 * @brief Executa o algoritmo de Bellman-Ford no grafo [gf], de tamanho[n_vertex],
 * para as [n_edges] a partir de um vértice [begin] e salva os valores
 * no array [distance]
 * 
 * @param n_vertex 
 * @param n_edges 
 * @param gf 
 * @param begin 
 * @param distance 
 */
void BellmanFord(int n_vertex, int n_edges, Graph *gf, int begin, int *distance);

//

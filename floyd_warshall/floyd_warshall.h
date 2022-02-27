#include <stdio.h>
/**
 * @brief Imprime as distâncias de uma ou várias origens[s] para um 
 * ou mais destinos [t] do grafo [graph] de tamanho [v], ordenando-as pelo custo
 * do caminho caso [is_sorted] seja 1
 * 
 * @param output 
 * @param v 
 * @param graph 
 * @param s 
 * @param t 
 * @param is_sorted 
 */
void print_dist_matrix(FILE *output, int v, int graph[v][v], int s, int t, int is_sorted);
/**
 * @brief Preenche o grafo [graph] de tamanho [v] com as [a] arestas
 * 
 * @param input_file 
 * @param output_file 
 * @param v 
 * @param a 
 * @param graph 
 */
void fill(FILE *input_file, FILE *output_file, int v, int a, int graph[v][v]);
/**
 * @brief Executa o algoritmo de Floyd-Warshall na matriz de distâncias [dist]
 * de tamanho [v]
 * 
 * @param v 
 * @param dist 
 */
void floyd_warshall(int v, int dist[v][v]);
/**
 * @brief Executa as principais funções solicitadas na documentação da atividade
 * 
 * @param s 
 * @param t 
 * @param input_file 
 * @param output_file 
 * @param is_sorted 
 */
void execute(int s, int t, FILE *input_file, FILE *output_file, int is_sorted);
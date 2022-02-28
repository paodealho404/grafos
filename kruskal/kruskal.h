#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
struct Grafo {
    int num_Vertices, num_Arestas;
    int aresta[MAX][3];
};
struct subset {
    int parent;
    int rank;
};
/**
 * @brief Executa o algoritmo de Kruskal no grafo [grafo] e caso
 * solicite [solution], as arestas que compõe a solução são exibidas
 * no arquivo [output_file].
 * 
 * @param grafo 
 * @param solution 
 * @param output_file 
 */
void kruskal(struct Grafo* grafo, int solution, FILE* output_file);
/**
 * @brief Método Find dos conjuntos disjuntos
 * 
 * @param subsets 
 * @param i 
 * @return int 
 */
int encontrar(struct subset subsets[], int i);
/**
 * @brief Método MakeSET dos conjuntos disjuntos
 * 
 * @param vert 
 * @return struct subset* 
 */
struct subset* iniciar_subsets(int vert);
/**
 * @brief Comparador simples
 * 
 * @param q 
 * @param w 
 * @return int 
 */
int compara(const void *q, const void *w);

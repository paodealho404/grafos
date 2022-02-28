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
void kruskal(struct Grafo* grafo, int solution, FILE* output_file);
int encontrar(struct subset subsets[], int i);
struct subset* iniciar_subsets(int vert);
int compara(const void *q, const void *w);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontrar(struct subset subsets[], int i);
void fazer_uniao(struct subset subsets[], int v1, int v2);
struct subset* criar_subsets(int vert);
struct subset* iniciar_subsets(int vert);
int compara(const void *q, const void *w);
void kruskal(struct Grafo* grafo);
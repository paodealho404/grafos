#include <stdio.h>
#include <stdlib.h>

typedef struct Graph Graph;
void printar(int distance[], int source, int n_vertex, FILE* output);
void BellmanFord(int n_vertex, int n_edges, Graph *gf, int begin, int *distance);

//

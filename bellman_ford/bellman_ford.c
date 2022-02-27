#include <stdio.h>
#include <stdlib.h>
#include "bellman_ford.h"
#define INF 50000

typedef struct Data {
    int origin, destiny, peso;
}Data;
 
typedef struct Graph {
    Data vertexs[INF];
}Graph;
 
 //
void BellmanFord(int n_vertex, int n_edges, Graph *gf, int begin) {
    int distance[n_vertex];
 
    for(int i = 0; i < n_vertex; i++) { 
        distance[i] = INF;
    }
    distance[begin] = 0; 
 
    for(int i = 0; i < n_vertex; i++) {
        for(int j = 0; j < n_vertex; j++) {
            int origin = gf->vertexs[j].origin;
            int destiny = gf->vertexs[j].destiny;
            int peso = gf->vertexs[j].peso;
            if (distance[origin] != INF && distance[origin] + peso < distance[destiny]) {
                distance[destiny] = distance[origin] + peso;
            }
        }
    }
    printar(distance, n_vertex);
    return;
}

 
int main() {
    int n_vertex, n_edges, i = 0;
    scanf("%d %d", &n_vertex, &n_edges);
 
    Graph * graph = (Graph*) malloc(sizeof(Graph));
 
    int v1, v2, peso;

    while(scanf("%d %d %d", &v1, &v2, &peso) != EOF) {
        graph->vertexs[i].origin = v1;
        graph->vertexs[i].destiny = v2;
        graph->vertexs[i].peso = peso;
        i = i+ 1;
    }

    BellmanFord(n_vertex, n_edges, graph, 0);
}

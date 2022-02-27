#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kruskal.h"
#define MAX 30


struct Grafo {
    int num_Vertices, num_Arestas;
    int aresta[MAX][3];
};

void kruskal(struct Grafo* grafo){    
    int vert = grafo->num_Vertices;
    int j = 0;
    int i = 0;
    float mst[vert-1][3];

    struct subset* subsets = iniciar_subsets(vert);

    qsort(grafo->aresta, grafo->num_Arestas, sizeof(grafo->aresta[0]), compara);
    
    while (j < vert - 1) {

        int* aresta = grafo->aresta[i++];
 
        int x = encontrar(subsets, aresta[0]);
        int y = encontrar(subsets, aresta[1]);
 
        if (x != y) {
            mst[j][0] = aresta[0];
            mst[j][1] = aresta[1];
            mst[j][2] = aresta[2];
            j++;
            fazer_uniao(subsets, x, y);
        }
    }
 
    int custo = 0;
    
    for (i = 0; i < j; ++i)
    {
        printf("%d -- %d == %d\n", (int) mst[i][0],(int) mst[i][1], (int) mst[i][2]);
        custo = custo + mst[i][2];
    }
    printf("Custo: %d\n",custo);
    return;
}

int main(){
    struct Grafo* grafo = (struct Grafo*)(malloc(sizeof(struct Grafo)));
    int num_Vertices,num_Arestas,v1,v2,peso;

//pegando o numero de vertices e numero de arestas
    scanf("%d %d", &num_Vertices, &num_Arestas);
    grafo->num_Vertices = num_Vertices;
    grafo->num_Arestas= num_Arestas;
//pegando as ligacoes e os pesos
    for(int i = 0; i < num_Arestas; i++){
        scanf("%d %d %d", &v1, &v2, &peso);
        grafo->aresta[i][0]= v1;
        grafo->aresta[i][1] = v2;
        grafo->aresta[i][2] = peso;
    }
 


    kruskal(grafo);

    return 0;
}
//

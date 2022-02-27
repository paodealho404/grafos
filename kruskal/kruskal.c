#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kruskal.h"
#define MAX 30


struct Grafo {
    int num_Vertices, num_Arestas;
    int aresta[MAX][3];
};
struct subset {
    int parent;
    int rank;
};
int encontrar(struct subset subsets[], int i){   
    if (subsets[i].parent == i)
        return i;
 
    return encontrar(subsets, subsets[i].parent);
}

void fazer_uniao(struct subset subsets[], int v1, int v2){

    int raiz1 = encontrar(subsets, v1);
    int raiz2 = encontrar(subsets, v2);

    if (subsets[raiz1].rank < subsets[raiz2].rank){
        subsets[raiz1].parent = raiz2;
    }else if(subsets[raiz1].rank > subsets[raiz2].rank){        
        subsets[raiz2].parent = raiz1;}
    else{
        subsets[raiz2].parent = raiz1;
        subsets[raiz2].rank++;
    }

}

struct subset* criar_subsets(int vert){
    return (struct subset*)malloc(vert * sizeof(struct subset));
}

struct subset* iniciar_subsets(int vert){

    struct subset* subsets = criar_subsets(vert);

    for (int v = 0; v < vert; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    return subsets;
}

int compara(const void *q, const void *w){
    int *y = (int *)w;
    int *x = (int *)q;

  
  return y[2] < x[2];
}
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

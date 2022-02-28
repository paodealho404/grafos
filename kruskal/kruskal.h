#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

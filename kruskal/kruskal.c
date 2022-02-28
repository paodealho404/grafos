#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kruskal.h"
#include "../utils/utils.h"

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
int encontrar(struct subset subsets[], int i){   
    if (subsets[i].parent == i)
        return i;
 
    return encontrar(subsets, subsets[i].parent);
}
void kruskal(struct Grafo* grafo, int solution, FILE* output_file){    
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
        if(solution){
            if(output_file) fprintf(output_file, "(%d, %d)\n", (int) mst[i][0],(int) mst[i][1]);
            else printf("(%d, %d)\n", (int) mst[i][0],(int) mst[i][1]);
        }
        custo = custo + mst[i][2];
    }
    if(!solution){
        if(output_file){
            fprintf(output_file,"Custo: %d\n",custo);
        }
        else printf("Custo: %d\n",custo);
    }
}

void main(int argc, char *argv[]){
    struct Grafo* grafo = (struct Grafo*)(malloc(sizeof(struct Grafo)));
    int num_Vertices,num_Arestas;
    int source = 0, target = 0, is_sorted = 0;
    FILE *input_file = NULL, *output_file = NULL;
    char *mensagem = "\nAlgoritmo de Kruskal para Arvores Geradoras Minimas.\nParametros suportados:\n\t-h [Ajuda]\n\t-f [Arquivo de Entrada]\n\t-o [Arquivo de Saida]\n\t-s [Solucao Ordenada]\nInsira no mesmo formato especificado na lista.\ne.g.:\n6 8\n1 2 5\n1 3 4\n1 4 2\n1 6 6\n2 4 1\n2 5 7\n3 5 6\n4 6 1\n";
    if(!require_params(&source, &target, &is_sorted, &input_file, &output_file, argc, argv, mensagem)) 
        return;
    
    int args[2], c = 0;
    char buffer[500];
    if (!input_file)
    {
        printf("Lendo do terminal...\n");
        fgets(buffer, 500, stdin);
    }
    else
    {
        fgets(buffer, 500, input_file);
    }
    if (extract_int_inputs(buffer, args) != 2)
    {
        if (!output_file)
        {
            printf("Entrada inicial invalida");
        }
        else
            fprintf(output_file, "Entrada inicial invalida");
    }

    num_Vertices = args[0];
    num_Arestas = args[1];
    grafo->num_Arestas = num_Arestas;
    grafo->num_Vertices = num_Vertices;
    char input[500];
    for (int i = 0; i < num_Arestas; i++)
    {
        int args[3] = {0}, c = 0;
        int v1, v2, p = 1;
        if (!input_file)
        {
            fgets(input, 500, stdin);
        }
        else
        {
            fgets(input, 500, input_file);
        }
        c = extract_int_inputs(input, args);
        v1 = args[0];
        v2 = args[1];
        if (c == 3 && args[2])
            p = args[2];
       grafo->aresta[i][0] = v1;
       grafo->aresta[i][1] = v2;
       grafo->aresta[i][2] = p;
    }

    kruskal(grafo, is_sorted, output_file);

}
//

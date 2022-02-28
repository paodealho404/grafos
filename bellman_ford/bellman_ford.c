#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "bellman_ford.h"
#define INF 50000

typedef struct Data {
    int origin, destiny, peso;
}Data;

typedef struct Graph {
    Data vertexs[INF];
}Graph;
 
void printar(int distance[], int source, int n_vertex, FILE* output) {
    for(int i = 1; i < n_vertex; i++) {
        if(output){
            if(distance[i]==INF){
                 fprintf(output, "(%d, %d): Non Reachable\n", source, i);   
            }
            else fprintf(output, "(%d, %d): %d\n", source, i, distance[i]);
        } 
        else {
            if(distance[i]==INF){
                 fprintf(stdout, "(%d, %d): Non Reachable\n", source, i);   
            }
            else fprintf(stdout, "(%d, %d): %d\n", source, i, distance[i]);

        }
    }
}
void BellmanFord(int n_vertex, int n_edges, Graph *gf, int begin, int *distance) {
 
    for(int i = 1; i < n_vertex; i++) { 
        distance[i] = INF;
    }
    distance[begin] = 0; 
 
    for(int i = 1; i < n_vertex; i++) {
        for(int j = 1; j < n_vertex; j++) {
            int origin = gf->vertexs[j].origin;
            int destiny = gf->vertexs[j].destiny;
            int peso = gf->vertexs[j].peso;

            if (distance[origin] != INF && distance[origin] + peso < distance[destiny]) {
                distance[destiny] = distance[origin] + peso;
            }
        }
    }
}

 
void main(int argc, char *argv[]) {
    int source = 0, target = 0, is_sorted = 0;
    FILE *input_file = NULL, *output_file = NULL;
    char *mensagem = "\nAlgoritmo de Bellman-Ford para caminhos de menor custo.\nParametros suportados:\n\t-h [Ajuda]\n\t-i [Vertice de Origem]\n\t-l [Vertice de Destino]\n\t-f [Arquivo de Entrada]\n\t-o [Arquivo de Saida]\nInsira no mesmo formato especificado na lista.\ne.g.:\n4 6\n1 2 3\n2 1\n3 1\n1 3\n3 2\n2 4 5\n";
    if(!require_params(&source, &target, &is_sorted, &input_file, &output_file, argc, argv, mensagem)) 
        return;
    
    int n_vertex, n_edges;
    int args[2], c = 0;
    char buffer[500];
    if (!input_file)
    {
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

    n_vertex = ++(args[0]);
    n_edges = args[1];

    Graph * graph = (Graph*) malloc(sizeof(Graph));
    char input[500];
    int v1, v2, peso;
    for (int i = 0; i < n_edges; i++)
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
        graph->vertexs[i].origin = v1;
        graph->vertexs[i].destiny = v2;
        graph->vertexs[i].peso = p;
    }

    int distance[n_vertex];
    if(source){
        if(target){
            BellmanFord(n_vertex, n_edges, graph, source, distance);
           if(!output_file){
               if(distance[target]==INF){
                fprintf(stdout, "(%d, %d): Non Reachable\n", source, target);   
               }else
                fprintf(stdout, "(%d, %d): %d\n", source, target, distance[target]);
           }
               
           else {
               if(distance[target]==INF){
                fprintf(output_file, "(%d, %d): Non Reachable\n", source, target);   
               }
               else fprintf(output_file, "(%d, %d): %d\n", source, target, distance[target]);
           }
        }
        else{
            BellmanFord(n_vertex, n_edges, graph, source, distance);
            printar(distance, source, n_vertex, output_file);
        }
    }
    else {
        if(target){
            for (int i = 1; i < n_vertex; i++)
            {
                BellmanFord(n_vertex, n_edges, graph, i, distance);
                if(!output_file) {
                    if(distance[target]==INF){
                        fprintf(stdout, "(%d, %d): Non Reachable\n", i, target);   
                    }
                    else fprintf(stdout, "(%d, %d): %d\n", i, target, distance[target]);
                }
                else {
                    if(distance[target]==INF){
                        fprintf(output_file, "(%d, %d): Non Reachable\n", i, target);   
                    }
                    else fprintf(output_file, "(%d, %d): %d\n", i, target, distance[target]);
                }
            }
        }
        else {
            for (int i = 0; i < n_vertex; i++)
            {
                BellmanFord(n_vertex, n_edges, graph, i, distance);
                printar(distance, source, n_vertex, output_file);
            }
        }
    }

    if(input_file) fclose(input_file);
    if(output_file) fclose(output_file);
}

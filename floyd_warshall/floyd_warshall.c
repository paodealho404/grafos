#include "floyd_warshall.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../utils/utils.h"

#define INPUT_LINE_SIZE 500
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INF INT_MAX
#define DBG if(1)
int swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
void print_dist_matrix(FILE *output, int v, int graph[v][v], int s, int t, int is_sorted){
    if(s>=v || s<0){
        fprintf(output, "Vértice de origem fora do escopo");
        return;
    }
    if(t>=v || t<0){
        fprintf(output, "Vértice de destino fora do escopo");
        return;
    }

    if(s && !t){
        int dists[v];
        for (int i = 1; i < v; i++)
            dists[i] = graph[s][i];

        if(is_sorted){
            for (int i = 1; i < v; i++)
                for (int j = 1; j < v; j++)
                    if(dists[i]<dists[j]) swap(&dists[i], &dists[j]);
        }
        for (int i = 1; i < v; i++)
            fprintf(output, "(%d,%d) %d\n", s, i, dists[i]);
    }

    else if(s && t){
        if(graph[s][t]==INF) fprintf(output, "(%d, %d) INF\n", s, t);
        else fprintf(output, "(%d, %d) %d\n", s, t, graph[s][t]);
    }
    else if(!s && t){
        int dists[v];
        for (int i = 1; i < v; i++)
            dists[i] = graph[i][t];

        if(is_sorted){
            for (int i = 1; i < v; i++)
                for (int j = 1; j < v; j++)
                    if(dists[i]<dists[j]) swap(&dists[i], &dists[j]);
        }

        for (int i = 1; i < v; i++)
            fprintf(output, "(%d,%d) %d\n", i, t, dists[i]);
    }
    else{
        for (int i = 1; i < v; i++){
            for (int j = 1; j < v; j++){
                if(graph[i][j]==INF) fprintf(output, "(%d, %d) INF\n", i, j);
                else fprintf(output, "(%d, %d) %d\n", i, j, graph[i][j]);
            }
        }    
    }
}
void fill(FILE *input_file, FILE *output_file, int v, int a, int graph[v][v]){
    char input[INPUT_LINE_SIZE];
    for (int i = 0; i < a; i++){
        int args[3]={0},c=0;
        int v1, v2, p=1;
        fgets(input, INPUT_LINE_SIZE, input_file);
        c = extract_int_inputs(input, args);
        v1 = args[0];
        v2 = args[1];
        if(c==3 && args[2])
            p = args[2];
        graph[v1][v2] = p;
    }
}
void floyd_warshall(int v, int dist[v][v]){
    for (int k = 1; k < v; k++){
        for (int i = 1; i < v; i++){
            for (int j = 1; j < v; j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j] = MIN( dist[i][k]+dist[k][j], dist[i][j]);
                }
            }
        }
    }
}
void execute(int s, int t, FILE *input_file, FILE *output_file, int is_sorted){
    int args[2],c=0;
    char buffer[INPUT_LINE_SIZE];
    char * token = "";
    fgets(buffer, INPUT_LINE_SIZE, input_file);
    if(extract_int_inputs(buffer, args)!=2){
        fprintf(output_file, "Entrada inicial inválida");
    }

    int v = ++(args[0]);
    int a = args[1];

    int grafos[v][v];    

    if(!output_file) 
        output_file = fopen("saida.txt", "w");;

    initialize(v, grafos, INF);
    fill(input_file, output_file,  v, a, grafos);
    floyd_warshall(v, grafos);
    print_dist_matrix(output_file, v, grafos, s,t, is_sorted);
    fclose(input_file);
    fclose(output_file);
}
void main(int argc, char *argv[]){
    int source=0, target=0, is_sorted=0;
    FILE *input_file=NULL, *output_file=NULL;
    require_params(&source, &target, &is_sorted, &input_file, &output_file, argc, argv, "Mensagem HELP");
    execute(source, target, input_file, output_file, is_sorted);   
}
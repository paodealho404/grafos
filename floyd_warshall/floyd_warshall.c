#include "floyd_warshall.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h> 
void print_dist_matrix(int v, int graph[v][v]){
    for (int i = 1; i < v; i++){
        for (int j = 1; j < v; j++)
            printf("| %d |", graph[i][j]);
        printf("\n");
    }
        
}
void initialize(int v, int graph[v][v]){
    for (int i = 1; i < v; i++)
        for (int j = 1; j < v; j++)
            graph[i][j]= INT_MAX;
}
void fill(int v, int a, int graph[v][v]){

    for (int i = 0; i < a; i++)
        {
            int v1, v2, p;
            scanf("%d %d %d", &v1, &v2, &p);
            graph[v1][v2] = p;
        }   
    }
void main(int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc, argv, "ho:f:l:si:l:")) != -1){ 
        switch(opt) 
        { 
            case 'h':
                printf("Help");
                break;
            case 's': 
                printf("Sorted solution");
                break;
            case 'l': 
                printf("Target %d", opt);
                break;
            case 'i': 
                printf("Source %d", opt);
                break;
            case 'o': 
                printf("Output %s", optarg); 
                break; 
            case 'f': 
                printf("Input %s", optarg); 
                break; 
            case ':': 
                printf("Os parâmetros precisam de um valor\n"); 
                break; 
            case '?': 
                printf("Parametro desconhecido: %c\n", opt);
                break; 
        } 
    } 
    // int v, a;
    // fscanf("%d %d", &v, &a);
    // int grafos[v+1][v+1];
    // FILE *input_file, *output_file;

    // initialize(v+1,grafos);

    // print_dist_matrix(v+1, grafos);
    
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
/**
 * @brief Extrai de [str] até 3 inteiros separados por espaço e os insere no array [args]
 * e retorna quantos inteiros foram extraídos
 * 
 * @param str 
 * @param args 
 * @return int 
 */
int extract_int_inputs(char *str, int *args){
    int c=0;
    char * token = strtok(str, " ");
    while( token != NULL && c<3 ) { 
        args[c++]= atoi(token);
        token = strtok(NULL, " ");
    }
    return c;
}
/**
 * @brief Inicializa com o valor [value] a matriz
 * de adjacência [graph], com tamanho de [v] vértices
 * 
 * @param v 
 * @param graph 
 * @param value 
 */
void initialize(int v, int graph[v][v], int value){
    for (int i = 1; i < v; i++){
        for (int j = 1; j < v; j++){
            if (i==j) graph[i][j] = 0;
            else graph [i][j]= value;
        }   
    }
}
void require_params(int *source, int *target, int *is_sorted, FILE **input, FILE **output, int argc, char *argv[]){
    int opt;
    while((opt = getopt(argc, argv, ":ho:f:si:l:")) != -1){ 
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
                *output = fopen(optarg, "w+");
                break; 
            case 'f': 
                *input = fopen(optarg, "r+");
                if(!input){
                    printf("Arquivo de Entrada Invalido");
                    return;     
                }
                break; 
            case ':': 
                printf("Os parâmetros precisam de um valor\n"); 
                break; 
            case '?': 
                printf("Parametro desconhecido: %c\n", optopt);
                break; 
        } 
    
    }
}

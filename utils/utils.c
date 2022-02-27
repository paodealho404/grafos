#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
int extract_int_inputs(char *str, int *args){
    int c=0;
    char * token = strtok(str, " ");
    while( token != NULL && c<3 ) { 
        args[c++]= atoi(token);
        token = strtok(NULL, " ");
    }
    return c;
}
#ifndef __cplusplus
void initialize(int v, int graph[v][v], int value){
    for (int i = 1; i < v; i++){
        for (int j = 1; j < v; j++){
            if (i==j) graph[i][j] = 0;
            else graph [i][j]= value;
        }   
    }
}
#endif
int require_params(int *source, int *target, int *is_sorted, FILE **input, FILE **output, int argc, char *argv[], char *str_help){
    int opt;
    while((opt = getopt(argc, argv, ":ho:f:si:l:")) != -1){ 
        switch(opt) 
        { 
            case 'h':
                printf(str_help);
                return 0;
            case 's': 
                *is_sorted = 1;
                break;
            case 'l': 
                *target = atoi(optarg);
                break;
            case 'i': 
                *source = atoi(optarg);
                break;
            case 'o': 
                *output = fopen(optarg, "w+");
                break; 
            case 'f': 
                *input = fopen(optarg, "r");
                if(*input == NULL){
                    printf("Arquivo de Entrada Invalido");
                    return 0;     
                }
                break; 
            case ':': 
                printf("Os parametros precisam de um valor\n"); 
                return 0;
                break; 
            case '?': 
                printf("Parametro desconhecido: %c\n", optopt);
                return 0;
                break; 
        } 
    
    }
    return 1;
}
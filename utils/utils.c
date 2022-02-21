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
/**
 * @brief Este método recebe ponteiros para que irão indicar o valor informado
 * pelas flags informadas pelo usuário e que foram solicitadas na atividade (-h, -f, -o, -s, -i, -l)
 * 
 * @param source  Vértice de origem, caso haja, caso não, é 0 por padrão.
 * @param target Vértice de origem, caso haja, caso não, é 0 por padrão.
 * @param is_sorted Informa se a solução está ordenada (1) ou não (0 por padrão).
 * @param input Ponteiro para arquivo de entrada, NULL caso não consiga abrir
 * @param output Ponteiro para arquivo de saída, se não existir um arquivo com nome passado, 
 * ele cria um "saida.txt"
 * @param argc Contador de argumentos informados, disponível na função main
 * @param argv Vetor de argumentos informados, disponível na função main
 * @param str_help Mensagem a ser informada para o usuário ao se utilizar a flag "-h".
 */
void require_params(int *source, int *target, int *is_sorted, FILE **input, FILE **output, int argc, char *argv[], char *str_help){
    int opt;
    while((opt = getopt(argc, argv, ":ho:f:si:l:")) != -1){ 
        switch(opt) 
        { 
            case 'h':
                printf(str_help);
                break;
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

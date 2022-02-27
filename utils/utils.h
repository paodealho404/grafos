#include <stdio.h>
/**
 * @brief Extrai de [str] até 3 inteiros separados por espaço e os insere no array [args]
 * e retorna quantos inteiros foram extraídos
 * 
 * @param str 
 * @param args 
 * @return int 
 */
int extract_int_inputs(char *str, int *args);
#ifndef __cplusplus
/**
 * @brief Inicializa com o valor [value] a matriz
 * de adjacência [graph], com tamanho de [v] vértices
 * 
 * @param v 
 * @param graph 
 * @param value 
 */
void initialize(int v, int graph[v][v], int value);
#endif
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
int require_params(int *source, int *target, int *is_sorted, FILE **input, FILE **output, int argc, char *argv[], char *str_help);


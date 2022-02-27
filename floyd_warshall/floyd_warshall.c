#include "floyd_warshall.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../utils/utils.h"
#define INPUT_LINE_SIZE 500
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF INT_MAX
#define DBG if (1)
typedef struct dis_vert
{
    int dist;
    int v;
} vert;
int swap(vert *a, vert *b)
{
    vert aux = *a;
    *a = *b;
    *b = aux;
}
void print_dist_matrix(FILE *output, int v, int graph[v][v], int s, int t, int is_sorted)
{
    if (s >= v || s < 0)
    {
        if (!output)
        {
            printf("Vertice de origem %d fora do escopo", s);
        }
        else
            fprintf(output, "Vertice de origem %d fora do escopo", s);
        return;
    }
    if (t >= v || t < 0)
    {
        if (!output)
        {
            printf("Vertice de destino %d fora do escopo", t);
        }
        else
            fprintf(output, "Vertice de destino %d fora do escopo", t);
        return;
    }

    if (s && !t)
    {
        vert dists[v];
        for (int i = 1; i < v; i++)
        {
            dists[i].dist = graph[s][i];
            dists[i].v = i;
        }

        if (is_sorted)
        {
            for (int i = 1; i < v; i++)
                for (int j = 1; j < v; j++)
                    if (dists[i].dist < dists[j].dist)
                        swap(&dists[i], &dists[j]);
        }
        for (int i = 1; i < v; i++)
        {
            if (!output)
            {
                if (dists[i].dist == INF)
                {
                    printf("(%d,%d): Non Reachable\n", s, dists[i].v);
                }
                else
                    printf("(%d,%d): %d\n", s, dists[i].v, dists[i].dist);
            }
            else
            {
                if (dists[i].dist == INF)
                {
                    fprintf(output, "(%d,%d): Non Reachable\n", s, dists[i].v);
                }
                else
                    fprintf(output, "(%d,%d): %d\n", s, dists[i].v, dists[i].dist);
            }
        }
    }

    else if (s && t)
    {
        if (graph[s][t] == INF)
        {
            if (!output)
            {
                printf("(%d, %d): Non Reachable\n", s, t);
            }
            else
                fprintf(output, "(%d, %d): Non Reachable\n", s, t);
        }
        else
        {
            if (!output)
            {
                printf("(%d, %d): %d\n", s, t, graph[s][t]);
            }
            else
                fprintf(output, "(%d, %d): %d\n", s, t, graph[s][t]);
        }
    }
    else if (!s && t)
    {
        vert dists[v];
        for (int i = 1; i < v; i++)
        {
            dists[i].dist = graph[i][t];
            dists[i].v = i;
        }
        if (is_sorted)
        {
            for (int i = 1; i < v; i++)
                for (int j = 1; j < v; j++)
                    if (dists[i].dist < dists[j].dist)
                        swap(&dists[i], &dists[j]);
        }

        for (int i = 1; i < v; i++)
        {
            if (!output)
            {
                if (dists[i].dist == INF)
                {
                    printf("(%d,%d): Non Reachable\n", dists[i].v, t);
                }
                else
                    printf("(%d,%d): %d\n", dists[i].v, t, dists[i].dist);
            }
            else
            {
                if (dists[i].dist == INF)
                {
                    fprintf(output, "(%d,%d): Non Reachable\n", dists[i].v, t);
                }
                else
                    fprintf(output, "(%d,%d): %d\n", dists[i].v, t, dists[i].dist);
            }
        }
    }
    else
    {
        for (int i = 1; i < v; i++)
        {
            for (int j = 1; j < v; j++)
            {
                if (graph[i][j] == INF)
                {
                    if (!output)
                    {
                        printf("(%d, %d): Non Reachable\n", i, j);
                    }
                    else
                        fprintf(output, "(%d, %d): Non Reachable\n", i, j);
                }

                else
                {
                    if (!output)
                    {
                        printf("(%d, %d): %d\n", i, j, graph[i][j]);
                    }
                    else
                        fprintf(output, "(%d, %d): %d\n", i, j, graph[i][j]);
                }
            }
        }
    }
}
void fill(FILE *input_file, FILE *output_file, int v, int a, int graph[v][v])
{
    char input[INPUT_LINE_SIZE];
    for (int i = 0; i < a; i++)
    {
        int args[3] = {0}, c = 0;
        int v1, v2, p = 1;
        if (!input_file)
        {
            fgets(input, INPUT_LINE_SIZE, stdin);
        }
        else
        {
            fgets(input, INPUT_LINE_SIZE, input_file);
        }
        c = extract_int_inputs(input, args);
        v1 = args[0];
        v2 = args[1];
        if (c == 3 && args[2])
            p = args[2];
        graph[v1][v2] = p;
    }
}
void floyd_warshall(int v, int dist[v][v])
{
    for (int k = 1; k < v; k++)
    {
        for (int i = 1; i < v; i++)
        {
            for (int j = 1; j < v; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = MIN(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }
}
void execute(int s, int t, FILE *input_file, FILE *output_file, int is_sorted)
{
    int args[2], c = 0;
    char buffer[INPUT_LINE_SIZE];
    char *token = "";
    if (!input_file)
    {
        fgets(buffer, INPUT_LINE_SIZE, stdin);
    }
    else
    {
        fgets(buffer, INPUT_LINE_SIZE, input_file);
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

    int v = ++(args[0]);
    int a = args[1];
    int grafos[v][v];
    initialize(v, grafos, INF);
    fill(input_file, output_file, v, a, grafos);
    floyd_warshall(v, grafos);
    print_dist_matrix(output_file, v, grafos, s, t, is_sorted);
    if( input_file) fclose(input_file);
    if( output_file) fclose(output_file);
}
void main(int argc, char *argv[])
{
    int source = 0, target = 0, is_sorted = 0;
    FILE *input_file = NULL, *output_file = NULL;
    char *mensagem = "\nAlgoritmo de Floy-Warshall para caminhos de menor custo.\nParametros suportados:\n\t-h [Ajuda]\n\t-i [Vertice de Origem]\n\t-l [Vertice de Destino]\n\t-f [Arquivo de Entrada]\n\t-o [Arquivo de Saida]\n\t-s [Ordenacao pelo custo do caminho]:\n\t\t- Caso um destino nao seja especificado,\n\t\to criterio eh o menor custo dos caminhos que compartilham a mesma origem\n\t\t- Caso uma origem nao seja especificada,\n\t\to criterio eh o menor custo dos caminhos que compartilham do mesmo destino\n\t\t- Caso ambos nao sejam especificados,\n\t\tnao ha criterio, uma vez que todos os caminhos estão sendo mostrados\n] \nInsira no mesmo formato especificado na lista.\ne.g.:\n4 6\n1 2 3\n2 1\n3 1\n1 3\n3 2\n2 4 5\n";
    if(!require_params(&source, &target, &is_sorted, &input_file, &output_file, argc, argv, mensagem)) 
        return;
    execute(source, target, input_file, output_file, is_sorted);
}
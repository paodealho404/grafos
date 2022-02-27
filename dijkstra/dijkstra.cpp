#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include "../utils/utils.h"
#include "dijkstra.h"
using namespace std;
const int INF = 1000000000;
#define PAIR_INT pair<int, int>
#define INPUT_LINE_SIZE 500

typedef struct dist_vert
{
    int vertex_a;
    int vertex_b;

    int dist;
    bool operator<(const dist_vert& a) const
    {
        return dist < a.dist;
    }
} dist_vert;
int Graph::get_size(){
    return size;
}
void Graph::add_edge(int u, int v, int w){
    adj_list[u].push_back(make_pair(v, w)); 
}
dist_vert Graph::dijkstra(int s, int target, int sorted, FILE* output_file)
{
    dist_vert short_path;
    if(s<=0 || s>=size){
        if(!output_file) cout << "Vertice de origem fora do escopo";
        else fprintf(output_file, "Vertice de origem fora do escopo\n");
        return short_path;
    } 
    // Constrói HEAP MÍNIMA
    priority_queue<PAIR_INT, vector<PAIR_INT>, greater<PAIR_INT>> heap_dist;

    // Constrói vetor de distancias com relaçao a origem e inicializa todas com infinito
    vector<int> distance_to(size, INF);

    // Inicializa o par de origem com custo 0 na heap
    heap_dist.push(make_pair(0, s));
    distance_to[s] = 0;
    // Inicializa o vertice origem com custo 0 no vetor de distancias
    while (!heap_dist.empty())
    {

        int u = heap_dist.top().second; // O vertice é o segundo elemento do PAIR_INT na heap
        heap_dist.pop();                // Remove a origem da heap

        for (auto edge : adj_list[u])
        { // Para cada vizinho do vertice U
            int target = edge.first;
            int cost = edge.second;
        
            if (distance_to[u] + cost < distance_to[target])
            {
                distance_to[target] = distance_to[u] + cost;
                heap_dist.push(make_pair(distance_to[target], target));
            }
        }
    }
    vector<dist_vert> distances(size);
    for (int i = 1; i < size; i++)
    {
        distances[i].dist = distance_to[i];
        distances[i].vertex_b = i;
    }
    if(sorted) sort(distances.begin(), distances.end());
    if (!target)
    {
        for (int i = 1; i < size; i++)
        {
            int dist = distances[i].dist;
            if (dist == INF)
                if(!output_file) cout << "(" << s << ", " << distances[i].vertex_b << "): Non Reachable" << endl;
                else fprintf(output_file, "(%d, %d): Non Reachable\n", s, distances[i].vertex_b);
                
            else
                if(!output_file) cout << "(" << s << ", " << distances[i].vertex_b << "): " << dist << endl;
                else fprintf(output_file, "(%d, %d): %d\n", s, distances[i].vertex_b, dist);
        }
    }
    else
    {
        short_path.vertex_a = s;
        short_path.vertex_b = target;
        short_path.dist = distance_to[target];
    }
    return short_path;
}
int Graph::construct_graph(FILE* input_file, FILE* output_file, int a){
    char input[INPUT_LINE_SIZE];
    for (int i = 0; i < a; i++){
        int args[3]={0},c=0;
        int v1, v2, p=1;
        if(!input_file){
            string input_t;
            getline(cin, input_t);
            strcpy(input, input_t.c_str());
        }
        else {
            fgets(input, INPUT_LINE_SIZE, input_file);
        }
        c = extract_int_inputs(input, args);
        v1 = args[0];
        v2 = args[1];
        if(c==3 && args[2])
            p = args[2];

        if(v1<=0 || v1>=size){
            if(!output_file) cout << "O vertice " << v1 <<" de origem esta fora do escopo";
            else fprintf(output_file, "O vertice %d de origem esta fora do escopo\n", v1);
            return 0;
        }
        if(v2<=0 || v2>=size){
            if(!output_file) cout << "O vertice " << v2 <<" de destino esta fora do escopo";
            else fprintf(output_file, "O vertice %d de destino esta fora do escopo\n", v2);
            return 0;
        }
        add_edge(v1,v2,p);
    }
    return 1;
}
int main(int argc, char *argv[])
{
    int source=0, target=0, is_sorted=0;
    FILE *input_file=NULL, *output_file=NULL;
    string msg = "\nAlgoritmo de Dijkstra para caminho de menor custo.\nParametros suportados:\n\t-h [Ajuda]\n\t-i [Vertice de Origem]\n\t-l [Vertice de Destino]\n\t-f [Arquivo de Entrada]\n\t-o [Arquivo de Saida]\n\t-s [Ordenacao pelo custo do caminho]:\n\t\t- Caso um destino nao seja especificado,\n\t\to criterio eh o menor custo dos caminhos que compartilham a mesma origem\n\t\t- Caso uma origem nao seja especificada,\n\t\to criterio eh o menor custo dos caminhos que compartilham do mesmo destino\n\t\t- Caso ambos nao sejam especificados,\n\t\to criterio eh o menor custo dos caminhos que compartilham a mesma origem\n\t\tpara cada uma das possiveis origens\n\nInsira no mesmo formato especificado na lista.\ne.g.:\n4 6\n1 2 3\n2 1\n3 1\n1 3\n3 2\n2 4 5\n";
    char *msg_help = &msg[0];
    if(!require_params(&source, &target, &is_sorted, &input_file, &output_file, argc, argv, msg_help)) return 0;
    int args[2],c=0;
    char buffer[INPUT_LINE_SIZE];
    
    if(!input_file){
        cout << "\nArquivo de entrada nao informado (ou invalido)\nLendo do terminal" << endl;
        string input_t;
        getline(cin, input_t);
        strcpy(buffer, input_t.c_str());
    }
    else {
        fgets(buffer, INPUT_LINE_SIZE, input_file);
    }
    extract_int_inputs(buffer, args);
    if(args[1]==0){
        printf("Entrada inicial invalida\n");
        return 0;
    }
    
    int v = ++(args[0]);
    int a = args[1];
    Graph G(v);
    if(!G.construct_graph(input_file, output_file, a)) return 0;
    if(source){
        if(target){
           dist_vert aux = G.dijkstra(source, target, is_sorted, output_file);
           if (aux.dist == INF){
                if(!output_file) cout << "(" << aux.vertex_a << ", " << aux.vertex_b << "): Non Reachable" << endl;
                else fprintf(output_file,"(%d, %d): Non Reachable\n", aux.vertex_a, aux.vertex_b);         
            }
            else{
                if(!output_file) cout << "(" << aux.vertex_a << ", " << aux.vertex_b << "): " << aux.dist << endl;
                else fprintf(output_file,"(%d, %d): %d\n", aux.vertex_a, aux.vertex_b, aux.dist); 
            }
        } 
        else G.dijkstra(source, 0, is_sorted, output_file);
    }
    else {
        vector<dist_vert> sorted_dist;
        if(target){
            for (int i = 1; i < G.get_size(); i++){
                dist_vert aux = G.dijkstra(i, target, is_sorted, output_file);
                sorted_dist.push_back(aux);
            }
            if(is_sorted) sort(sorted_dist.begin(), sorted_dist.end());

            for (auto edge: sorted_dist)
            { 
                if (edge.dist == INF){
                    if(!output_file) cout << "(" << edge.vertex_a << ", " << edge.vertex_b << "): Non Reachable" << endl;
                    else fprintf(output_file,"(%d, %d): Non Reachable\n", edge.vertex_a, edge.vertex_b);         
                }
                else{
                    if(!output_file) cout << "(" << edge.vertex_a << ", " << edge.vertex_b << "): " << edge.dist << endl;
                    else fprintf(output_file,"(%d, %d): %d\n", edge.vertex_a, edge.vertex_b, edge.dist); 
                }
            }
            
        }
        else {
            for (int i = 1; i < G.get_size(); i++){
                G.dijkstra(i, 0, is_sorted, output_file);
            }
                
        }
    }
    fclose(input_file);
    fclose(output_file);
}
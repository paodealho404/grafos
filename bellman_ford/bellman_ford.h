#include <stdio.h>
#include <stdlib.h>


void printar(int distance[], int n_vertex) {
    for(int i = 0; i < n_vertex; i++) {
        printf("Vertex:  %d |Distance:  %d\n", i+1, distance[i]);
    }
}
//

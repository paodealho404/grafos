#include "floyd_warshall.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
void menu_fw(void){
    int v, a;
    scanf("%d %d", &v, &a);
    int grafos[v+1][v+1];
    memset(grafos, 0, sizeof(grafos));
    for (int i = 0; i < a; i++)
    {
        int v1, v2, p;
        scanf("%d %d %d", v1, v2, p);
        grafos[v1][v2] = p;
    }

}
void main(){
    printf("Hello FW");
}
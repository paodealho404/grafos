#include <stdio.h>
#include <stdlib.h>
#include "floyd_warshall/floyd_warshall.h"
#include "clique/clique.h"

int main(){
    int input;
    printf("Escolha qual implementação de algoritmo deseja utilizar");
    scanf("%d", &input);
    while(1){
        switch (input)
        {
            case 1:
                menu_fw();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }
    
    return 0;
}
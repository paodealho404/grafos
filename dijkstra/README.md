# Algoritmo de Dijkstra
>### " O algoritmo de Dijkstra, concebido pelo cientista da computação holandês Edsger Dijkstra em 1956 e publicado em 1959, soluciona o problema do caminho mais curto num grafo dirigido ou não dirigido com arestas de peso não negativo, em tempo computacional O(E+V.log(V)) onde V é o número de vértices e E é o número de arestas. O algoritmo que serve para resolver o mesmo problema em um grafo com pesos negativos é o algoritmo de Bellman-Ford, que possui maior tempo de execução que o Dijkstra.

>### O algoritmo considera um conjunto S de menores caminhos, iniciado com um vértice inicial I. A cada passo do algoritmo busca-se nas adjacências dos vértices pertencentes a S aquele vértice com menor distância relativa a I e adiciona-o a S e, então, repetindo os passos até que todos os vértices alcançáveis por I estejam em S. Arestas que ligam vértices já pertencentes a S são desconsideradas. "
-[Wikipédia](https://pt.wikipedia.org/wiki/Algoritmo_de_Dijkstra)
## Compilando
```bash
    cd dijkstra
    make build
```

## Executando

```bash
    ./dijkstra -f entrada.in -o saida.txt -i 1 -l 2
```

## Exemplo de entrada

```bash
    4 6
    1 2 3
    2 1 1
    3 1
    1 3
    3 2
    2 4 5
```

## Saída resultante
>### O custo do menor caminho do vértice s=1 para o vértice t=2
```bash
    (1, 2): 2
```
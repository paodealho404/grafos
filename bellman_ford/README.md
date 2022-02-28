# Algoritmo de Bellman-Ford
>### O Algoritmo de Bellman-Ford é um algoritmo de busca de caminho mínimo em um digrafo (grafo orientado dirigido) ponderado, ou seja, cujas arestas têm peso, inclusive negativo. O Algoritmo de Dijkstra r/> ##Resolve o mesmo problema, num tempo menor, porém exige que todas as arestas tenham pesos positivos.> ##Portanto, o algoritmo de Bellman-Ford é normalmente usado apenas quando existem arestas de peso negativo.
-[Wikipédia](https://pt.wikipedia.org/wiki/Algoritmo_de_Bellman-Ford)
## Compilando
```bash
    cd bellman_ford
    make build
```

## Executando

```bash
    ./bellman_ford -f entrada.in -o saida.txt -i 1
```

## Exemplo de entrada

```bash
    4 6
    1 2 3
    2 1
    3 1
    1 3
    3 2
    2 4 5
```

## Saída resultante
>### O custo do menor caminho do vértice s=1 para todos os vértice t
```bash
    (1, 1): 0
    (1, 2): 2
    (1, 2): 2
    (1, 3): 1
    (1, 4): Non Reachable
```
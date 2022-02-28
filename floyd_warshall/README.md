# Algoritmo de Floyd-Warshall
>### Na ciência da computação, o algoritmo de Floyd-Warshall (também conhecido como: Floyd's algorithm, Roy–Warshall algorithm, Roy–Floyd algorithm, ou WFI algorithm) é um algoritmo que resolve o problema de calcular o caminho mais curto entre todos os pares de vértices em um grafo orientado (com direção) e valorado (com peso). O algoritmo Floyd-Warshall foi publicado por Robert Floyd em 1962. Este algoritmo é o mesmo que foi publicado por Bernard Roy em 1959 e também por Stephen Warshall em 1962 para determinar o fechamento transitivo de um grafo. O formato atual do algoritmo de Floyd-Warshall com três loops de repetição foi descrito por Peter Ingerman em 1962.
-[Wikipédia](https://pt.wikipedia.org/wiki/Algoritmo_de_Floyd-Warshall)
O algoritmo é um bom exemplo de programação dinâmica. 
## Compilando
```bash
    cd floyd_warshall
    make build
```

## Executando

```bash
    ./floyd_warshall -f entrada.in -o saida.txt
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
>### O custo do menor caminho de todos os vértice s para todos os vértices t
```bash
    (1, 1): 0
    (1, 2): 2
    (1, 3): 1
    (1, 4): 7
    (2, 1): 1
    (2, 2): 0
    (2, 3): 2
    (2, 4): 5
    (3, 1): 1
    (3, 2): 1
    (3, 3): 0
    (3, 4): 6
    (4, 1): Non Reachable
    (4, 2): Non Reachable
    (4, 3): Non Reachable
    (4, 4): 0
```
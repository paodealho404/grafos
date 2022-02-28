# Algoritmo de Kruskal
>## "O algoritmo de Kruskal é um algoritmo em teoria dos grafos que busca uma árvore geradora mínima para um grafo conexo com pesos. Isto significa que ele encontra um subconjunto das arestas que forma uma árvore que inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado. Se o grafo não for conexo, então ele encontra uma floresta geradora mínima (uma árvore geradora mínima para cada componente conexo do grafo). O algoritmo de Kruskal é um exemplo de um algoritmo guloso (também conhecido como ganancioso ou greedy). "
-[Wikipédia](https://pt.wikipedia.org/wiki/Algoritmo_de_Kruskal)
## Compilando
```bash
    cd kruskal
    make build
```

## Executando

```bash
    ./kruskal -f entrada.in -o saida.txt -s
```

## Exemplo de entrada

```bash
    6 8
    1 2 5
    1 3 4
    1 4 2
    1 6 6
    2 4 1
    2 5 7
    3 5 6
    4 6 1
```

## Saída resultante
>### As arestas que compõem a AGM ordenadas pelo peso
```bash
    (4, 6)
    (2, 4)
    (1, 4)
    (1, 3)
    (3, 5)
```
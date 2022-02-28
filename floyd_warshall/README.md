# Algoritmo de Floyd-Warshall

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
>### O custo do menor caminho do vértice s para o vértice t
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
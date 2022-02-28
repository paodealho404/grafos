# Algoritmo de Bellman-Ford

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
>### O custo do menor caminho do vértice s para o vértice t
```bash
    (1, 1): 0
    (1, 2): 2
    (1, 2): 2
    (1, 3): 1
    (1, 4): Non Reachable
```
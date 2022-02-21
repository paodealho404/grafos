build: floyd_warshall/floyd_warshall.c clique/clique.c utils/utils.c
	gcc floyd_warshall/floyd_warshall.c utils/utils.c -o fd_warshall
	gcc clique/clique.c -o max_clique
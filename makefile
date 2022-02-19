build: floyd_warshall/floyd_warshall.c clique/clique.c 
	gcc floyd_warshall/floyd_warshall.c -o fd_warshall
	gcc clique/clique.c -o max_clique
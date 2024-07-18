#include<stdio.h>
void dij(int, int [20][20], int [20], int [20], int);
void main() {
int i, j, n, visited[20], source, cost[20][20], d[20];
printf("Enter no. of vertices: ");
scanf("%d", &n);
printf("Enter the cost adjacency matrix\n");
for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++){ 
		scanf("%d", &cost[i][j]);
	}
}
printf("\nEnter the source node: ");
scanf("%d", &source);
dij(source, cost, visited, d, n);
for (i = 1; i <= n; i++) {
	if (i != source)
	printf("\nShortest path from %d to %d is %d", source, i, d[i]);
	}
}

void dij(int source, int cost[20][20], int visited[20], int d[20], int n){
int i, j, min, u, w;
for (i = 1; i <= n; i++) {
	visited[i] = 0;
	d[i] = cost[source][i];
}
visited[source] = 1;
d[source] = 0;
for (j = 2; j <= n; j++){
	min = 999;
for (i = 1; i <= n; i++){
	if (!visited[i]) {
		if (d[i] < min){
			min = d[i];
			u = i;
		}
	}
}
visited[u] = 1;
for (w = 1; w <= n; w++) {
	if (cost[u][w] != 999 && visited[w] == 0){
		if (d[w] > cost[u][w] + d[u])
			d[w] = cost[u][w] + d[u];
		}
	}
}}

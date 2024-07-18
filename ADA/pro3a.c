#include<stdio.h>
#include<limits.h>
#define v 4
void Floyd_Warshall (int graph[v][v])
{
	int dist[v][v];
	for(int i=0; i<v; i++)
	for(int j=0; j<v; j++)
		dist[i][j] = graph[i][j];
	for(int k=0; k<v; k++)
	for(int i=0; i<v; i++)
	for(int j=0; j<v; j++)
		if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
			dist[i][j] = dist[i][k]+dist[k][j];
		printf("Shortest distances between every pair of vertices:\n");
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				if (dist[i][j] == INT_MAX)
					printf("INF\t");
				else
					printf("%d\t", dist[i][j]);
			}
		printf("\n");
		}
}

int main()
{
	int graph[v][v] = {{0, INT_MAX, 3, INT_MAX}, {2,0,INT_MAX, INT_MAX},{INT_MAX,7,0,1},{6,INT_MAX,INT_MAX,0}};
	Floyd_Warshall(graph);
	return 0;
}

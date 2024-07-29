#include <stdio.h>
int ne = 1, min_cost = 0;
void main()
{
    int n, i, j, min, a, u, b, v, cost[20][20], parent[20];
    printf("Enter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    for (i = 1; i <= n; i++)
        parent[i] = 0;
    printf("\nThe edges of spanning tree are\n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        if (u != v)
        {
            printf("Edge %d\t(%d->%d)=%d\n", ne++, a, b, min);
            min_cost = min_cost + min;
            parent[v] = u;
        }
        cost[a][b] = 999;
    }
    printf("\nMinimum cost=%d\n", min_cost);
}

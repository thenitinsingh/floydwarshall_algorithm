#include <stdio.h>
#define INF 999
#define n 4

void floydWarshal(int graph[][n])
{
    int dist[n][n], i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("%s	", "INF");
            else
                printf("%d 	", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the distance between each pair of vertices: \n");
    int graph[n][n];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    floydWarshal(graph);
    return 0;
}

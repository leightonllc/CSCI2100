
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_DIS 999999


int cost[MAX_NODES][MAX_NODES];
int distance[MAX_NODES];

void initial(int m, int n);

void Dijkstra(int n);


void initial(int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cost[i][j] = MAX_DIS;
        cost[i][i] = 0;
    }
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        cost[x][y] = cost[y][x] = w;
    }
}

void Dijsktra(int n)
{
    int selected[n], w, w_dist;
    for(int i = 1; i < n; i++)
    {
        if (cost[0][i]) distance[i] = cost[0][i];
            else distance[i] = MAX_DIS;
        selected[i] = 0;
    }
    selected[0] = 1;
    distance[0] = 0;
    w = 1;
    while (w)
    {
        w_dist = MAX_DIS; w = 0;
        for (int i = 1; i < n; i++)
        {
            if (selected[i] == 0 && distance[i] < w_dist)
            {
                w = i;
                w_dist = distance[i];
            }
        }
        selected[w] = 1;
        for (int v = 0; v < n; v++)
        {
            if(cost[w][v] && !(selected[v]))
            {
                if (distance[w] + cost[w][v] < distance[v])
                    distance[v] = distance[w] + cost[w][v];
            }
        }
    }
}

int main()
{
    int m,n;

    printf("Input the number of nodes:\n");
    scanf("%d",&n);
    printf("Input the number of edges:\n");
    scanf("%d",&m);
    printf("Input these edges:\n");
    initial(m,n);
    Dijsktra(n);
    
    for(int i=0;i<n;i++)
			printf("%d ",distance[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_DIS 999999


int cost[MAX_NODES][MAX_NODES];
int distance[MAX_NODES][MAX_NODES];

void initial(int m, int n);

void floyd(int n);


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

void floyd(int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            distance[i][j] = cost[i][j];
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
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
    floyd(n);
    
    for(int i=0;i<n;i++)
    {
			for(int j=0;j<n;j++)
				printf("%d ",distance[i][j]);
			printf("\n");
    }
    return 0;
}
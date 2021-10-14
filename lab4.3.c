#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct _adjlist {
     int node;
     struct _adjlist *link;
} adjlist;

adjlist graph[MAX_NODES]; 

int visited[MAX_NODES];    // 0-unvisited    1-visited

void insert(int v1,int v2)
{
    adjlist *temp;
    temp = (adjlist*)malloc(sizeof(adjlist));
    temp->node = v2;
    temp->link = NULL;
    if (graph[v1].link == NULL){
        graph[v1].link = temp;
        return;
    }
    adjlist *current = graph[v1].link;
    while(1)
    {
        if(current->link == NULL || v2<current->link->node)
        {
            temp->link = current->link;
            current->link = temp;
            return;
        }
        else current = current->link;
    }    
}

void dfs(int v){

   adjlist *w;

   visited[v] = 1;
   for (w = graph[v].link; w != NULL; w = w->link)
        if (visited[w->node] == 0)  dfs(w->node);

}

int conNum()
{
    int count = 0;
    for (int i = 0; i < MAX_NODES; i++){
        if ((graph[i].link != NULL) && (!visited[i]))
        {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main()
{
    int m,a,b;
    
    // initialize
    for(int i=0;i<MAX_NODES;i++)
    {
				graph[i].link=NULL;
				visited[i]=0;  // unvisited 
    }


    printf("Input the number of edges:\n");
    scanf("%d",&m);
    printf("Input these edges:\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        insert(a,b);
				insert(b,a);
    }
    int num=conNum();
    printf("%d",num);
    return 0;
}
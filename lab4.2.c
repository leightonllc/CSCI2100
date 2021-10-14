#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct _adjlist {
     int node;
     struct _adjlist *link;
} adjlist;

typedef struct {
  int size;
  int last; 
  int *elements;
} queue;

queue* createQ(int size)
{
  queue *q;
  q = (queue*)malloc(sizeof(queue));
  q->size = size;
  q->elements = (int*)malloc(size * sizeof(int));
  q->last = -1;
  return q;
}

int IsEmptyQ(queue *q){
  if (q->last == -1) return 1;
  else return 0;
}

int IsFullQ(queue *q){
  if (q->last == q->size - 1) return 1;
  else return 0;
}


void enqueue(queue *q, int e){
  if (!IsFullQ(q)) {  
			q->last++; 
			q->elements[q->last] = e;
  } 
  else  printf("Error\n");
}

int dequeue(queue *q){
  int i, j;
  if (!IsEmptyQ(q)) { 
		  i = q->elements[0];
		  for (j = 1; j <= q->last; j++) 
			q->elements[j-1] = q->elements[j];
		  q->last--;
		  return i;
   } else  printf("Error\n");
}



adjlist graph[MAX_NODES]; 

int visited[MAX_NODES];    // 0:unvisited    1:visited

void insert(int v1, int v2);

void bfs(int v);



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

void bfs(int v)
{
  	queue *q;  adjlist *w;
  	if (graph[v].link != NULL) printf("%d ",v);  visited[v] = 1;
  	q = createQ(MAX_NODES);
  	enqueue(q, v);
  	while (!IsEmptyQ(q)) 
    {
    	v = dequeue(q);
    	for (w = graph[v].link; w != NULL; w = w->link)
      	    if (visited[w->node] == 0) 
            {
        	    printf("%d ", w->node);
        	    enqueue(q, w->node);
        	    visited[w->node] = 1; 
            }
 	}
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
    bfs(0);
    return 0;
}
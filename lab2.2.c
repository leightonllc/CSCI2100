#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linked_list_node{
    int value;
    struct doubly_linked_list_node *prev, *next;
} Node;

typedef struct{
    Node *head; // point to the first node of doubly linked list
    Node *tail; // point to the last node of doubly linked list
} List;

void InitList(List *p)
{
    p->head = NULL;
    p->tail = NULL;
}

List Insert(List l, int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node)); // allocate a piece of memory for the new node
    ptr->value = value;
    ptr->next = NULL;
    if((l.head)==NULL)
    {
        l.head = ptr;
        l.tail = ptr;
        l.head->prev = NULL;
        return l;
    }
    if ((ptr->value) < ((l.head)->value)) 
    { 
        ptr->prev = NULL; 
        (l.head)->prev = ptr; 
        ptr->next = (l.head); 
        (l.head) = ptr; 
        return l; 
    }
    if(value>=l.tail->value)
    {
        ptr->prev = l.tail;
        l.tail->next = ptr;
        l.tail = ptr;
        return l;
    } 
    Node *current = l.head;
    while(1)
    {
        if(current->next==NULL || value<current->next->value)
        {
            ptr->next = current->next;
            ptr->next->prev = ptr;
            ptr->prev = current;
            current->next = ptr;
            break;
        }
        else current = current->next;
    }
    return l;
}


Node* Find(List l, int value)
{
    Node* ptr = l.head;
    while (ptr != NULL) {
        if (ptr->value == value){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

List Delete(List l, int value)
{
    Node* ptr = Find(l, value);
    
    if (l.head == l.tail)
    {
        l.head == NULL;
        l.tail == NULL;
    }
    
    if (l.head == NULL || ptr == NULL) 
        return l; 
    if (l.head == ptr) 
        l.head = ptr->next;

    else if (l.tail == ptr)
        l.tail = ptr->prev;
  
    if (ptr->next != NULL) 
        ptr->next->prev = ptr->prev; 
  
    if (ptr->prev != NULL) 
        ptr->prev->next = ptr->next; 
  
    free(ptr);
    return l;
}

void Print_DESC(List l)
{
    // print all integers in descending order
    Node* temp = l.tail;
    if (l.head == NULL) return;
    while(temp->prev!=NULL)
    {
        printf("%d ", temp->value);
        temp =temp->prev;
    }
    printf("%d", temp->value);
}

int main()
{
    List l;
    int n;
    int value;
    Node* ptr;

    InitList(&l);
    printf("Input the number of integers inserted into the linked list:\n");
    scanf("%d", &n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &value);
        l = Insert(l, value);
    }

    printf("Input the value to find:\n"); // print the integers before and after the given value
    scanf("%d", &value);
    ptr = Find(l, value);
    if(ptr->prev!=NULL) printf("%d", ptr->prev->value);
    else printf("NULL");
    printf(" %d ", ptr->value);
    if(ptr->next!=NULL) printf("%d", ptr->next->value);
    else printf("NULL");
    printf("\n");

    printf("Input the value for deletion:\n");
    scanf("%d", &value);
    l = Delete(l, value);

    Print_DESC(l);
    return 0;
}
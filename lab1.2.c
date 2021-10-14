#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node{
    int value;
    struct linked_list_node* next;
} Node;

typedef Node* List;

int Exist(List p, int value)
{
    // judge whether linked list p contains the value
    // you should visit each node of the linked list one by one, and check whether it is equal to the value
    // if you find it then return 1, otherwise return 0
    while(p!=NULL)
    {
        if(p->value==value) return 1;
        p = p->next;
    }
    return 0;
}

/* function to swap data of two nodes a and b*/
void swap(List a, List b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void Sort(List p)
{
    int swapped, i;
    List ptr1;
    List ptr2 = NULL;
    /* Checking for empty list */
    if (p == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = p;
        while (ptr1->next != ptr2)
        {
            if (ptr1->value > ptr1->next->value)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while (swapped);
}

void Print(List p)
{
    // print all integers from the head of linked list in one line(separated by a space), in other words, you should firstly print the integer p points to
    // to be more specific, print p->value and then move p to the next node p->next recursively, until p points to NULL
    while(p!=NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

List Delete_a(List p){
    List first;
    if (p != NULL)
    {
        first = p;
        p = p->next;
        free(first);
    }
    return p;
}

List Delete_b(List p){
    List last, temp = p;
    if(p->next == NULL){free(p);
        p = NULL;
        return p;
    }
    while(temp->next!=NULL)
    {
        last = temp;
        temp = temp->next;
    }
    free(last->next);
    last->next = NULL;
    return p;
}

List Insert(List p, int value)
{
    if (Exist(p, value) == 1) return p;

    List last, tmp;
    tmp = (List)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    if (p == NULL){
        p = tmp;
        return p;
    }
    last = p;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    Sort(p);
    return p;
}

int main()
{
    List p = NULL;
    int n;
    int value;

    // printf("List initialization: \n");
    // printf("How many integers in list initially: ");
    scanf("%d", &n);
    // printf("What are the integers: ");
    for(int i=0; i<n; i++)
    {
        int value;
        scanf("%d", &value);
        p = Insert(p, value);
    }

    // printf("Delete a value from head\n");
	p = Delete_a(p);

    // printf("Delete a value from end\n");
	p = Delete_b(p);

    // printf("Current array: \n");
    Print(p);
    return 0;
}

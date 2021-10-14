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

List Reverse(List p){
    List prev = NULL;
    List curr = p;
    List next = NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

int main()
{
    List p = NULL;
    int n, m;
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

    // printf("Reverse List: \n");
	p = Reverse(p);

    // printf("Current array: \n");
    Print(p);

    return 0;
}

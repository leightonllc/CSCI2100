#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node{
    int value;
    struct linked_list_node* next;
} Node;

typedef Node* List;

int search(List p, int value) 
{
  List temp = p;
    while (temp != NULL) {
        if (temp->value == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

List Insert(List head, int value)
{
    Node *ptr = (List)malloc(sizeof(Node)); // allocate a piece of memory for the new node
    ptr->value = value;
    if(head==NULL || value<head->value)
    {
        ptr->next = head;
        return ptr;
    }
    Node *current = head;
    while(1)
    {
        if(current->next==NULL || value<current->next->value)
        {
            ptr->next = current->next;
            current->next = ptr;
            break;
        }
        else current = current->next;
    }
    return head;
}

List Intersection(List headA, List headB)
{
    //Generate a linked list head to contain the intersection of A and B in ascending order.
    //You can only visit the input linked list headA and headB but not change them. Finally, return head.
    List head = NULL;
    List temp = headA;
    while(temp != NULL) {
        if (search(headB, temp->value))
        {
          head = Insert(head, temp->value);
        }
        temp = temp->next;
    }
    return head;
}

List Union(List headA, List headB)
{
    //Generate a linked list head to contain the union of A and B in ascending order.
    //You can only visit the input linked list headA and headB but not change them. Finally, return head.
    List head = NULL;
    List temp1 = headA;
    List temp2 = headB;
    while(temp1 != NULL) {
        head = Insert(head, temp1->value);
        temp1 = temp1->next;
    }
    while(temp2 != NULL) {
        if (!search(headA, temp2->value))
        {
          head = Insert(head, temp2->value);
        }
        temp2 = temp2->next;
    }
    return head;
}

void Print(List p)
{
    //do not forget to print a '\n'
    while(p!=NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    List headA = NULL;
    List headB = NULL;
    int n, m;
    int value;

    printf("Input the number of integers in A:\n");
    scanf("%d", &n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &value);
        headA = Insert(headA, value);
    }

    printf("Input the number of integers in B:\n");
    scanf("%d", &m);
    printf("Input these integers:\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d", &value);
        headB = Insert(headB, value);
    }

    List headC = NULL;
    List headD = NULL;
    headC = Intersection(headA, headB);
    headD = Union(headA, headB);

    Print(headA);
    Print(headB);
    printf("The intersection list contains:\n");
    Print(headC);
    printf("The union list contains:\n");
    Print(headD);

    return 0;
}
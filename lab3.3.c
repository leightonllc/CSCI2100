#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
    struct tree_node *left_child;
    struct tree_node *right_child;
    int data;
} Node;

typedef Node* Tree;

Tree searchPoint(Tree root, int key)
{
    if (!root) return NULL;                      /* empty tree */

     if ((key < root->data) && (root->left_child))
            return searchPoint(root->left_child, key);
     if ((key > root->data) && (root->right_child))
            return searchPoint(root->right_child,key);
     return root;  
}

Tree insert(Tree root, int key)
{
    Tree ptr, point;
    point = searchPoint(root, key);

    ptr = (Tree)malloc(sizeof(Node));
	ptr->data = key;
	ptr->left_child = ptr->right_child = NULL;
	if (root==NULL) root = ptr;
	else if (key < point->data) point->left_child = ptr;
	else point->right_child = ptr;
	return root;	// root may be updated   

}

int size(Tree root) 
{ 
    int i = 0;
    if (root == NULL) 
       return 0;
    i = i + size(root->left_child); 
    i = i + size(root->right_child); 
    i++;
    return i; 
} 

int kthsmallest(Tree root, int k)
{
    int leftnum = size(root->left_child);
    if (leftnum < k - 1)
        return kthsmallest(root->right_child, k - leftnum - 1);
    else if (leftnum == k - 1)
        return root->data;
    else return kthsmallest(root->left_child, k);
}

int main()
{
    int n, key, k;
    Tree root = NULL;
    printf("Input the number of integers:\n");
    scanf("%d", &n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    //cal_size(root);
    scanf("%d", &k);
    key = kthsmallest(root, k);
    printf("%d\n", key);
    return 0;
}
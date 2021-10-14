#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
    struct tree_node *left_child;
    struct tree_node *right_child;
    int data;
    int level;
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
	if (root==NULL) {
        root = ptr;
        ptr->level = 1;
    }
	else if (key < point->data) {
        point->left_child = ptr;
        ptr->level = point->level + 1;
    }
	else {
        point->right_child = ptr;
        ptr->level = point->level + 1;
    }      
	return root;	// root may be updated   

}

void print_level(Tree root)
{
    if (root==NULL)
        return;  
    printf("%d %d\n", root->data, root->level);
    print_level(root->left_child);
    print_level(root->right_child);
}

int main()
{
    int n, key;
    Tree root = NULL;
    printf("Input the number of integers:\n");
    scanf("%d",&n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    root->level = 1;
    print_level(root);
    return 0;
}

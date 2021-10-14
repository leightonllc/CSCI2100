#include <stdio.h>
#include <stdlib.h>

void PrintArray(int A[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int A[], int left, int right){
    int pivot = A[right];
    int i = left -1;
    for (int j = left; j < right; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    i++;
    swap(&A[i], &A[right]);
    return i;
}
void QuickSort(int A[], int left, int right){
    if (left < right) {
        int pivot = Partition(A, left, right);
        QuickSort(A, left, pivot - 1);
        QuickSort(A, pivot + 1, right);
    }
}

int main()
{
    int n, *a;
    printf("Input the number of integers:\n");
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int)*n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    QuickSort(a, 0, n-1);
    PrintArray(a, n);
    return 0;
}
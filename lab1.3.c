#include <stdio.h>

void sort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n; ++j)
            if (A[i] < A[j])
                {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
}

int Insert(int value, int A[], int n)
{
    // insert value into A[], return new length n
    A[n] = value;
    sort(A, n + 1);
    return n + 1;
}

void Print(int A[], int n)
{
    // print A[0], A[1], ..., A[n-1] in one line, every two integers are separated by a space
    int i;
    for (i = 0; i < n; i++) printf("%d ", A[i]);
}

int Merge(int A_1[], int A_2[], int n_1, int n_2){
    int i;
    for (i = 0; i < (n_2); i++) A_1[n_1 + i] = A_2[i];
    sort(A_1,n_1 + n_2);
    return n_1 + n_2;
}

int main()
{
    int A_1[100], A_2[100];
    int n_1, n_2; // the number of integers in A
    int value;

    // printf("Array initialization: \n");
    // printf("How many integers in FIRST array initially: ");
    scanf("%d", &n_1);
    // printf("What are the integers: ");
    int temp = 0;
    for(int i=0; i<n_1; i++){
        scanf("%d", &value);
        temp = Insert(value, A_1, temp);
    }

    // printf("How many integers in SECOND array initially: ");
    scanf("%d", &n_2);
    // printf("What are the integers: ");
    temp = 0;
    for(int i=0; i<n_2; i++){
        scanf("%d", &value);
        temp = Insert(value, A_2, temp);
    }

    // printf("Merge the SECOND array to the FIRST array: \n");
	n_1 = Merge(A_1, A_2, n_1, n_2);

    // printf("FIRST array: \n");
    Print(A_1, n_1);

	return 0;
}

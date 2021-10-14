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

int Delete(int value, int A[], int n)
{
    int i, j;
    for (i=0; i<=n; i++){
        if (A[i] == value){
            for (j=i; j <= n-1; j++) A[j] = A[j+1];
            break;
        }
    }
    return n - 1;
}

int Exist(int value, int A[], int n){
    // check whether value exists in array A[]
    int i;
    for (i=0; i<=n; i++)
        if (value == A[i]) return 1;
    return 0;
}

int Update_one(int old_value, int new_value, int A[], int n)
{
    // change old_value to new_value, return new length n
    int i;
    for (i=0; i<n; i++)
        if (A[i] == old_value) {
            A[i] = new_value;
            sort(A, n);
            return n;}
    return n;
}

int Update_all(int old_value, int new_value, int A[], int n)
{
    // change old_value to new_value, return new length n
    int i;
    for (i=0; i<n; i++)
        if (A[i] == old_value) A[i] = new_value;
    sort(A, n);
    return n;
}

void Print(int A[], int n)
{
    // print A[0], A[1], ..., A[n-1] in one line, every two integers are separated by a space
    int i;
    for (i=0;i < n;i++) printf("%d ", A[i]);
}

int main()
{
    int A[100];
    int n; // the number of integers in A
    int value, new_value;

    // printf("Array initialization: \n");
    // printf("How many integers in array initially: ");
    scanf("%d", &n);
    // printf("What are the integers: ");
    int temp = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        temp = Insert(value, A, temp);
    }
    // printf("Input a value for insertion: ");
	scanf("%d", &value);
	n = Insert(value, A, n);

	// printf("Input a value for deletion: ");
	scanf("%d", &value);
	n = Delete(value, A, n);

	// printf("Input the old and new values for update(one): ");
	scanf("%d%d", &value, &new_value);
	n = Update_one(value, new_value, A, n);

    // printf("Input the old and new values for update(all): ");
	scanf("%d%d", &value, &new_value);
	n = Update_all(value, new_value, A, n);

    // printf("Current array: \n");
	Print(A, n);

	return 0;
}

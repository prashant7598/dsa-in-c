//here we are using dynamic memory allocation for temparory array 

#include <stdio.h>

void display(int *A, int n)
{ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

// merge procedure used to sort a array by inserting element in sorted way
void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
     // Dynamically allocate temporary array
    int *B = (int *)malloc((high + 1) * sizeof(int));
    if (B == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++, k++;
        }
        else
        {
            B[k] = A[j];
            j++, k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++, k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++, k++;
    }

    for(i = low; i<=high;i++)
        A[i]= B[i];
    
    // Free dynamically allocated memory
    free(B);
}

// recursive merge sort for fully unsorted array
void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    display(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}
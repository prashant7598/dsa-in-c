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
void merge(int A[], int mid, int low, int high){
    int i, j, k, B[100];
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

    for(int i = low; i<=high;i++){
        A[i]= B[i];
    }
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
    // int arr[100];
    // int n;
    // array(arr,&n); // we want real n  not its copy to we are passing its address passing its copy   will not effect in function we created

    int arr[] = {12, 43, 2, 4, 2, 8, 53, 23};
    int arr1[] = {32, 4, 56, 79, 76, 5, 8, 1};
    int n = 8;
    display(arr,8);
    mergeSort(arr,0,7);
    display(arr,8);
    return 0;
}
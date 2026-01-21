#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // use  to find the max and minimum element

void display(int *A, int n)
{ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int maximum(int *A,int n){
    int max = INT_MIN; // Initialize with the smallest possible int value
    for(int i = 0; i<n; i++){
        if(max <A[i]) // Compare each elemen
            max = A[i]; // Update max if current element is greater
    }
    return max;
}
// If you simply did this: return INT_MAX; You’d always get: 2147483647 no matter what’s in the array

void CountSort(int *A, int n){
    int i,j;
    // find the max element in A
    int max = maximum(A,n);

    // creating the count array
    int* count = (int *)malloc((max+1)*sizeof(int));

    //initilazing the array element to 0
    for (i = 0; i<max+1; i++)
        count[i] = 0;
    
    //incrementing the corresponding index in the count arrray
    for(i = 0;i<n;i++)
        count[A[i]]++;
    
    i = 0;
    j=0;

    while (i<=max)
    {
        if(count[i]>0){
            A[j]= i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
    
}


int main()
{
    int arr[] = {12, 43, 2, 4, 2, 8, 53, 23};
    int arr1[] = {32, 4, 56, 79, 76, 5, 8, 1};
    int n = 8;
    display(arr,8);
    CountSort(arr,n);
    display(arr,8);
    return 0;
}
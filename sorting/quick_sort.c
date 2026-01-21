#include<stdio.h>

void display(int * A, int n){ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for(int i = 0; i<n ; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int partition(int * A, int low, int high){
    int pivot = A[low]; 
    int temp;
    int i = low+1;
    int j = high;
    do
    {
        while(A[i]<= pivot){
            i++;
        }

        while(A[j]> pivot){
            j--;
        }

        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i<j);

    //if i>j the do while loop will end and we swap A[low] and A[j] after that the progam will reutrn
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; //we'll return the index where we finnaly sattel the element
      
}

void quicksort(int *A, int low, int high){
    int partitionIndex; //index of pivot after partition

    if(low < high){
        partitionIndex = partition(A,low,high);
        quicksort(A, low, partitionIndex-1); // sort left sub array
        quicksort(A,partitionIndex + 1, high); // sort right sub array
    }
}

int main(){
    // int arr[100];
    // int n;
    // array(arr,&n); // we want real n  not its copy to we are passing its address passing its copy   will not effect in function we created


    int arr[] = {12,43,2,4,2,8,53,23};
    int arr1[] = {32,4,56,79,76,5,8,1};
    int n = 8;

    display(arr,n);
    quicksort(arr, 0, n-1);
    display(arr,n);

    return 0;
}
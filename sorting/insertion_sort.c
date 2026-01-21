#include<stdio.h>

void display(int * A, int n){ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for(int i = 0; i<n ; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for(int i = 1 ; i<= n - 1; i++ ){ //loop for each pass
        key = A[i]; //this is element we have to insert in sort array
        j = i-1; // index of pervious element of key
        
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
         A[j+1] = key;
    }
}

// for user input use this
void array(int a[], int * n){  //call by reference
    printf("enter number of element");
    scanf("%d", n);
    for(int i = 0; i< *n; i++){
        printf("enter %d element", i);
        scanf("%d ", &a[i]);
    
    }
}

int main(){
    // int arr[100];
    // int n;
    // array(arr,&n); // we want real n  not its copy to we are passing its address passing its copy   will not effect in function we created


    int arr[] = {12,43,2,4,2,8,53,23};

    int n = 8;
    display(arr,n);

    printf("using insertion sort here \n");
    insertionSort(arr,n);
    display(arr,n);
    return 0;
}
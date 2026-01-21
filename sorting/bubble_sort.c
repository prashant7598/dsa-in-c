#include<stdio.h>

void display(int * A, int n){ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for(int i = 0; i<n ; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

// bubble sort non-adaptive
void bubbleSort(int * A, int n){ // here A is array we want to swap and n is the number of element of array
    int temp;//for swap

    for(int i = 0; i< n; i++){ // this loop is for number of passes 
        printf("wprking on pass number %d \n", i+1);   
        for(int j = 0; j< n-1-i; j++){ // this is for number of comperision 
            if(A[j]> A[j+1]){ // to swap
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

//bubble sort adaptive  
void bubbleSortAdaptive(int * A, int n){ // here A is array we want to swap and n is the number of element of array
    int temp;//for swap
    int isSorted;

    for(int i = 0; i< n; i++){ // this loop is for number of passes 
        printf("wprking on pass number %d \n", i+1);   
        isSorted = 1;
        for(int j = 0; j< n-1-i; j++){ // this is for number of comperision 
            if(A[j]> A[j+1]){ // to swap
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
// 1 pass will always occure so if the array is sorted it will not enter in swap condition so isSorted will not become 0 thus it will break through fn since we writen :-
        if(isSorted == 1)
            return;
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
    int arr1[] = {32,4,56,79,76,5,8,1};
    int n = 8;
    display(arr,n);

    bubbleSort(arr, n);
    display(arr, n);

    bubbleSortAdaptive(arr1, n);
    display(arr1, n);

    return 0;
}
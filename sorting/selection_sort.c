#include<stdio.h>

void display(int * A, int n){ // array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
    for(int i = 0; i<n ; i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void selection_sort(int * A, int n){
    printf("running selecton sort \n");
    int indexMin, temp;
    for (int i = 0; i < n-1; i++){
        indexMin = i;
        for (int j = i+1 ; j < n; j++)
        {
            if(A[j] < A[indexMin]){
                indexMin = j;
            }
        }
        // swap code
        temp = A[i];
        A[i] = A[indexMin];
        A[indexMin] = temp;
    }
    
}

int main(){

    int A[] = {32,4,56,79,76,5,8,1};
    int n = 8;
    display(A,n);
    selection_sort(A,n);
    display(A,n);

    return 0;
}
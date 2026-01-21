#include<stdio.h>

//linear Search
int linearSearch(int arr[], int size, int element){
    for(int i = 0; i< size ; i++){
        if(arr[i] == element);
        return i;
    }
    return -1;
}

// binary search
int bianrySearch(int arr[], int size, int element){
    int low , mid ,high;
    low = 0;
    high = size -1;

    while (low <= high)
    {
       
        mid = (low + high)/ 2;
        if (arr[mid] == element)
            return mid;
        
        if (arr[mid] < element)
        {
            low = mid +1;
        }
        else
            low = mid -1;
        
        
    }
    // searching till end if we didn't get the number return -1
    return -1;
}

int main (){
    //for linear search array can be of any type
    // int arr[]= {1,2,34,55,6,68,8,56,32,24};
    // int size = sizeof(arr)/ sizeof(int);
    // int element = 55;
    // int searchIndex = linearSearch(arr, size, element);
    //here Linearsearch return some value we need another variable to store the vlaue and display it
    
    int arr[]= {1,2,4,5,6,8,18,56,124};
    int size = sizeof(arr)/ sizeof(int);
    int element = 585;
    int searchIndex = bianrySearch(arr, size, element);
    printf("the element  %d was founf at index %d", element, searchIndex);
    return 0;
}
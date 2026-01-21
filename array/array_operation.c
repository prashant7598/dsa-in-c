#include<stdio.h>
//inssertion of element.
void insertElement(int arr[], int size, int element, int index, int capacity){

	if(size >= capacity){
		printf(" \n the array is full \n the insertion is incomplete");
	}
	else{

	for(int i = size; i>= index; i--){ // the array will start from end and work till the index u want to add
		arr[i+1]= arr[i]; // to shift back (create space for element)
		
	}
	printf(" \n the element to be inserted is %d \n", element);
	arr[index]= element;	
}

}

//deletion of element
void delElement(int arr[], int size, int index){
	printf("\n deleting the element at index %d \n", index);
	printf("after deletion the element the array is \n");
	for(int i = index; i < size - 1 ; i++){
		arr[i]= arr[i+1];
	}
}

void display(int arr[], int n){
	for(int i = 0 ; i< n ;i++){
		printf(" %d ",arr[i] );
	}
}

int main(){
	int arr[10]= {1,2,3,4,5};
	int size= 5;
	int element = 33;
	int index = 2;
	display(arr, size);
    insertElement(arr, size, element, index, 10);
	size += 1; // this will increase the size to store the last element'
	
	printf(" after insertion the array is \n");
	display(arr, size);

	delElement(arr, size, 5);
	size -= 1; //to reduce the size of array
	display(arr, size) ;

	
	return 0;
	
}

#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ptr;
	int n;
	
	printf("enter the size of array \n");
	scanf("%d", &n);
	
//	use of malloc
//	ptr =(int *)malloc(n * sizeof(int));
	
//	use of calloc
 	ptr = (int *) calloc(n, sizeof(int));
 	
	for(int i = 0; i < n ; i++){
		printf("enter the element of array %d  ", i);
		scanf("%d", &ptr[i]);
	}
	
	for(int i = 0; i< n; i++){
		printf(" your array is %d = %d \n",i, ptr[i]);
	}
	
	printf("enter the size of new array u want to create");
	scanf("%d", &n);
	
	//use of realloc
	ptr = (int *) realloc(ptr , n*sizeof(int));
	
	for(int i = 0; i < n ; i++){
	printf("enter the element of array %d  ", i);
	scanf("%d", &ptr[i]);
	}
	
	for(int i = 0; i< n; i++){
		printf(" your array is %d = %d \n",i, ptr[i]);	
	}
	
	free(ptr);
//here we are using free fn after the end of program but we should always do this after creating new array
// so that the memory used by old array should be free this is good practice
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct myArray{
	int total_size;
	int used_size;
	int *ptr;
	//when we create a memory in heap it return a pointer and this ptr will point to that the address of first block. array is not a pointer, but in most expressions (like function calls), it decays (converts) to a pointer to its first element
};

void createArray(struct myArray * a, int tSize, int uSize){
	a->total_size = tSize;
	a->used_size = uSize;
	a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a){
	for(int i = 0; i < a->used_size;i++){
		printf("%d\n ", (a->ptr)[i]);
	}
}

void setval(struct myArray *a){
	int n;
	for(int i = 0; i < a->used_size;i++){
		printf("enter the element");
		scanf("%d", &n);
		(a->ptr)[i] = n; 
//a->ptr is a pointer to the first element of the array. (a->ptr)[i] means �the i-th element of that array we can also write a->ptr[i]
	}
}
void showval( struct myArray * a){
		for(int i = 0; i < a->used_size;i++){
			printf("%d\n", (a->ptr)[i]);
		}
	
}
int main(){
	struct myArray marks; // when we do this compiler create a structure marks which reserve space we inserted above (total_size and all)
	createArray(&marks, 10, 2);
	printf("we are running setval now \n");
	setval(&marks);
	printf("we are running setval now \n");
	showval(&marks);
	
	return 0;
}

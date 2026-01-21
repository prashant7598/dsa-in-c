#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;  // it point to the top element of array
    int *arr; // its is pointer which is use to dinamicaly allocate the memory
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("the stack is full, cannot push %d to the stack", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val; //ptr has arr size and top in it(we designe it)
    }
}

int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("cannot pop from the stack");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr, int i){ 
    // i is position(not index) of element we want to see but using peek function under for loop we can see all element of stsck
    int index = ptr->top - i + 1; //(top - i +1 is the  formula to find position)
    if(index < 0){
        printf("not a valid position");
        return -1;
    }
        return ptr->arr[index];  
}

int main()
{
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("before pussing , full %d \n", isFull(s));
    printf("before pussing , empty %d \n", isempty(s));
    push(s, 56);
    push(s, 26);
    push(s, 46);
    push(s, 34);
    push(s, 45);
    push(s, 32);
    push(s, 15);
    printf("After pussing , full %d \n", isFull(s));
    printf("After pussing , empty %d \n", isempty(s));
    printf("popped %d from the stack \n", pop(s));
    printf("popped %d from the stack \n", pop(s));
    printf("popped %d from the stack \n", pop(s));

    // to print the element of stack
    for (int j = 1; j <= s->top + 1 ;  j++)
    {
        printf("the value at position %d is %d \n", j, peek(s, j));
    }
    
    return 0;

}

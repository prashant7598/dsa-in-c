#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node * next;
};

int isEmpty(struct node * top);
int isFull(struct node * top);
struct node * push(struct node * top , int x);
int pop(struct node ** top);
void display(struct node *ptr);
int peek(struct node * top, int pos);
int stackbot(struct node * top);
int stacktop(struct node * top);


int isEmpty(struct node * top){
    if( top == NULL){
        return 1;
    }
    else{return 0;}
}

int isFull(struct node * top){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL){ // n == null means no dynamic memory created hence the memory is full
        return 1; 
    } 
    return 0;
}

struct node * push(struct node * top , int x){
    if(isFull(top)){
        printf("the stack is full cannot push to the stack \n");
        return top;
    }
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node ** top){ // we want to make change in top in push function to so we are using pointer of pointer and calling its address in main fn to do so we can also make top a globle variable
    if(isEmpty(*top)){
        printf("cannot pop from the stack");
    }
    
    else{
        struct node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

void display(struct node *ptr)
{
    // Here ptr is just a local pointer variable inside the function.
    // It doesn’t point anywhere by itself until we pass an argument to it when calling the function.

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
// we created a pointer of type struct node which will point to the first element and we assigned it to next to it will start pointing to next node
    }
}

int peek(struct node * top, int pos){
    struct node * ptr = top;
    int i;
    for (i = 0;(i< pos -1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }
}

int stacktop(struct node * top){
    return top->data;
}

int stackbot(struct node * top){
    struct node * ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main (){
    struct node * top = NULL;
    top = push(top ,32);
    top = push(top ,43);
    top = push(top ,14);
    top = push(top ,42);
    top = push(top ,65);
    
    // int element  = pop(&top);
    // printf("the poped element is %d", element);
    
    // printf("the element at index 1 is %d \n" , peek(1));
	int i;
    for ( i = 1; i<= 5; i++){
        printf(" the element at index %d is %d \n",i, peek(top, i));
    }
    printf("the top element is %d \n", stacktop(top));
    printf("the bottom most element is %d", stackbot(top));
    
    

    return 0;
}

/*Step-by-Step Explanation
🔸 (1) Function Arguments in C

C uses pass by value, not pass by reference.
That means when you call push(top, 32),
a copy of top (the pointer value) is sent into the function.

So inside push(), there is a local variable top — it’s a copy of the pointer from main.

(2) Inside the Function

You do this:

top = n;


This changes only the local copy of top inside push().

If you stopped there and didn’t return anything, the real top in main() would remain unchanged

top = push(top, 32);
You catch that returned pointer and update your real top.

✅ That’s why you don’t need a pointer-to-pointer here — because the updated pointer is sent back as a return value.
You’re modifying the original top pointer, but you also need to return a value (the popped element).

You need to change top (to move it to the next node)

And also return the popped value

Since you can return only one thing in C, you can’t return both.
👉 That’s why you pass &top (address of the pointer) — so the function can modify it directly.
| Operation | What it Needs to Do                    | Solution                         |
| --------- | -------------------------------------- | -------------------------------- |
| `push()`  | Change `top` and return it             | Return new top                   |
| `pop()`   | Change `top` *and* return popped value | Use pointer-to-pointer (`**top`) |
*/
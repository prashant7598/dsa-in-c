#include<stdio.h>
#include<stdlib.h>

struct node * f = NULL;
struct node * r = NULL;
struct node
{
   int data;
   struct node * next;
};

void enqueue(int val){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL){ //means the memory is not allocated  
        printf("the queue is full \n");
    }
    else{
        n->data = val;
        n->next=NULL;
        if(f == NULL){
            f = r = n;
            printf("enqueing the element %d \n", val);
        }
        else{
            r->next = n; // to link the nodes
            r = n; // to manage the rear pointer (as it always point to null )
            printf("enqueing the element %d \n", val);
        }
    }
}

int dequeue(){
    int val;
    struct node * ptr = f;
    if(f == NULL)
        printf("the queue is empty \n");
    else{
        f = ptr->next ;
        val = ptr->data;
        free(ptr);
        printf("dequeued the element %d \n", val);
    }
    return val;
    
}

void dispaly(struct node * ptr){
    printf("printing the element of linked list \n");
    while(ptr != NULL){
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dispaly(f); 
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}
    
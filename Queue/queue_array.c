#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue * q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int val){
    if(isFull(q)){
        printf("queue is full cannot enter value to it");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued: %d\n", val);
    }
}

int dequeue(struct queue * q){
    int a ;
    if(isEmpty(q)){
        printf("queue is empty cannot remove form queue");
    }
    else{
        q->f++;
        a = q->arr[q->f];
        printf("Dequeued: %d\n", a);
    }
    return a;
}

int main(){
    struct queue * q;
    q->size = 2;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));  
    
    enqueue(q, 12);
    enqueue(q, 15);
    if(isFull(q)){
        printf("queue is full \n");
    } 

    dequeue(q);
    enqueue(q, 5);

    return 0;
}
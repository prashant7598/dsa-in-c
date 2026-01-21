#include<stdio.h>
#include<stdlib.h>

struct cQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct cQueue * q){
    if((q->r+1)%(q->size) == q->f){
    return 1;
}
return 0;
}

int isEmpty(struct cQueue * q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct cQueue * q, int val){
    if(isFull(q)){
        printf("cQueue is full cannot enter value to it\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued: %d\n", val);
    }
}

int dequeue(struct cQueue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("cQueue is empty cannot remove form cQueue \n");
    }
    else{
        q->f = (q->f+1)%(q->size);
        a = q->arr[q->f];
        printf("Dequeued: %d\n", a);
    }
    return a;
}

int main(){
    struct cQueue * q;
    q->size = 3;
    q->f = q->r = 0; // if we put = -1 then after increment rear it will be equal to front(-1) so it will overwrite its own element.
    q->arr = (int*)malloc(q->size*sizeof(int));  
    
    printf("%d",isFull(q));
    
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 5);
    enqueue(q, 12);
    enqueue(q, 56);

    return 0;
}
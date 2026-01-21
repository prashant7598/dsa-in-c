#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

void dispaly(struct node * head);


void dispaly(struct node * head){
    struct node * ptr = head;
    while (ptr != NULL)
    {
        printf("the elements are %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

struct node * insert(struct node * head, int  data){
    struct node * ptr = (struct node* )malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct node * delet(struct node * head){
    struct node * p = head;
    struct node * q = p->next;
    while(q->next != NULL ){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next= second;
    head->prev= NULL;

    second->data = 6;
    second->next= third;
    second->prev = head;

    third->data = 7;
    third->next = fourth;
    third->prev = second;

    fourth->data = 8;
    fourth->next = NULL;
    fourth->prev = third;

    dispaly(head);
    
    head = insert(head , 10);
    head = insert(head , 20);
    head = insert(head , 30);
    
    dispaly(head);
    printf("after deleting \n");
     head = delet(head);
     head = delet(head);
     head = delet(head);
     dispaly(head);
    return 0;

}

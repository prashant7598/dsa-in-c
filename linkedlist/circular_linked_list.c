#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node * head);
struct node * insertATBeg(struct node * head, int data);
struct node * insertATBtw(struct node * head, int index, int data);
struct node * insertATEnd(struct node * head, int data);
struct node * deleteAtBeg(struct node * head);
struct node * deleteAtBtw(struct node * head, int index);
struct node * deleteAtEnd(struct node * head);
void display(struct node * head){
    struct node * ptr = head;
    do{
        printf("element is %d\n", ptr->data);
        ptr= ptr->next;
    }while(ptr != head); //we are using do while loop bcz at first the ptr is head so the loop will never start
}

struct node * insertATBeg(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head= ptr;
    return head;
}

struct node * insertATBtw(struct node * head, int index , int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * insertATEnd(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head;
    
    while(p->next != head){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * deleteAtBeg(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = p->next;
    head = head->next;
    free(p);
    return head;
}

struct node * deleteAtBtw(struct node * head, int index){
    struct node * p = head;
    struct node * q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q= q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node * deleteAtEnd(struct node * head){
    struct node * p = head;
    struct node * q = head->next; //one pointe will point to end and another will point to second last node which will help to assigne the next= null
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next= head;
    free(q);
    return head;    
}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    // allocating memory for node in the linked list in heap


    // linking the nodes and entering values.
    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = head;

    display(head);
    // head = insertATBeg(head, 33);
    // head = insertATBtw(head,2,33);
    // head = insertATEnd(head,22);
    // head = deleteAtBeg(head);
    head = deleteAtBtw(head,2);
    // head = deleteAtEnd(head);
    display(head);

    return 0;
}
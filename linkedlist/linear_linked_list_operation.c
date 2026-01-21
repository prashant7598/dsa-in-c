#include <stdio.h>
#include <stdlib.h>

struct node
{
    // it is a structure which contain an integer data type and a pointer next
    int data;
    struct node *next;
};

void display(struct node *ptr);
struct node *insertAtBeg(struct node *head, int data);
struct node *insertAtBtw(struct node *head, int data, int index);
struct node *insertAtEnd(struct node *head, int data);
struct node *insertAfternode(struct node *head, struct node *preNode, int data);
struct node *deleteAtBeg(struct node *head);
struct node *deleteAtBtw(struct node *head, int index);
struct node *deleteAtEnd(struct node * head);
struct node *deleteValue(struct node * head , int value);

// traversal the linked list
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

struct node *insertAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insertAtBtw(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head; // since we want to insert in btw we don't want to lose your head
    int i = 0;
    while (i != index - 1) // we want our p pointer to point the node just before the index we want to insert
    {
        p = p->next; // at i = 0 we want to point p to next node and moving to next node till we reach index-1
        i++;
    }
    // here p is pointing to the index node we want to insert and it we link
    ptr->next = p->next; // it will link ptr to the index we want to insert
    p->next = ptr;       // it will link p to ptr to form a link chain
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // after the loop p is pointing to null that means it the last node.
    p->next = ptr;    // p will point to ptr now
    ptr->next = NULL; // now ptr will point to null this means it the last node now.
    return head;
}

struct node *insertAfternode(struct node *head, struct node *preNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = preNode->next;
    preNode->next = ptr;
    return head;
}

struct node *deleteAtBeg(struct node *head)
{
    //in insertion we are creating pointer dinamically bcz we want it to exits with other nodes but in deletion we don't want the element to exits so we are not creating it dinamically.
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteAtBtw(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
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
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next= NULL;
    free(q);
    return head;    
}

// delete the given value
struct node * deleteValue(struct node * head , int value){
    struct node * p = head;
    struct node * q = head->next; //one pointe will point to end and another will point to second last node which will help to assigne the next= null
    while (q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if (q->data == value){
        p->next = q->next;
        free(q);
        printf("after deletion the value\n");
        display(head);
    }
    else{
        printf("element not found  \n");
        display(head);
    }
    
    return head;
    
}

struct node* reverse(struct node* head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse the link
        prev = current;         // move prev forward
        current = next;         // move current forward
    }

    return prev;  // new head of the reversed list
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    // allocating memory for node in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // linking the nodes and entering values.
    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;

    display(head);
    // head = insertAtBeg(head, 54);
    // printf("after insertion at end \n")

    // head = insertAtBtw(head, 33, 2);
    // printf("after insertion at between \n");

    //  head = insertAtEnd(head, 33);
    //  printf("after insertion at end \n");

    //    head = insertAfternode(head,second, 43);
    //    printf("insertion after a node is: \n");

    // head = deleteAtBeg(head);
    // printf("after deletion the list is \n");
    
    // head = deleteAtBtw(head,2);
    // printf("after deletion the list in between \n");
    
    head = deleteAtEnd(head);
    printf("after deletion the list at end \n");
    
    // head = deleteValue(head, 10);
    // printf("after deletion the given value \n");

    display(head);

    head = reverse(head);
    printf("Reversed list:\n");
    display(head);
     return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node * root){
    if(root!= NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node * root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void Inorder(struct node * root){
    if(root!= NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int main(){

    struct node * p = createNode(7); //root node
    struct node * p1 = createNode(2);
    struct node * p2 = createNode(3); 
    struct node * p3 = createNode(1); 
    struct node * p4 = createNode(5); 
    struct node * p5 = createNode(4); 

    //linking the nodes.
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;


    printf("printing preorder \t");
    preorder(p);
    
    printf("\nprinting postorder \t");
    postorder(p);

    printf("\nprinting Inorder \t");
    Inorder(p);
    
    return 0;
}

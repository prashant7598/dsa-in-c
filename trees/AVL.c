#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int max(int a, int b){
    return(a>b)?a:b;
}

void preorder(struct node * root){
    if(root!= NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int getheight(struct node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int getbalanceFactor(struct node * n){
    if(n==NULL)
        return 0; // height of left tree- right tree is 0
    
    return getheight(n->left) - getheight(n->right);
}

struct node * rightrotate(struct node * y){
    struct node * x = y->left;
    struct node * t2 = x->right;

    x->right= y;
    y->left = t2;

    y->height = max(getheight(y->right), getheight(y->left)) +1;
    x->height = max(getheight(x->right), getheight(x->left)) +1;

    return x;
}

struct node * leftrotate(struct node * x){
    struct node * y = x->right;
    struct node * t2 = y->left;

    y->left = x;
    x->right= t2;

    y->height = max(getheight(y->right), getheight(y->left)) +1;
    x->height = max(getheight(x->right), getheight(x->left)) +1;

    return y;
}

// Function to insert a value in the AVL
struct node* insert(struct node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; //Duplicate not allowed

    // update height
    node->height = 1+ max(getheight(node->left), getheight(node->right));
    //get a balance factor
    int bf = getbalanceFactor(node);

    // left left case
    if(bf>1 && key < node->left->data){
        return rightrotate(node);
    }
    
    //right right case 
    if(bf<-1 && key > node->right->data){
        return leftrotate(node);
    }
    
    // left right case
    if(bf > 1 && key > node->left->data){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    //right left  case
    if(bf < -1 && key < node->right->data){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

int main(){

    struct node * root = NULL;
    // Insert elements automatically (AVL property maintained)
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);

    return 0;
}
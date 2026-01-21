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

//to check the given tree is BST or not
int isBST(struct node *root){
    static struct node* prev = NULL; // use to the value as previous node
/* inside the function (without static), then each recursive call of isBST() would create its own separate copy of prev, and it would always reset to NULL.

That means the function would never remember what the last node was during traversal, so the BST check would fail. The variable prev is created only once for the entire function, not for each call. It retains its value between recursive calls.*/

    if(root != NULL){
        if(!isBST(root->left))
            return 0;
    
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
            return isBST(root->right);
    }
    else{
        return 1;
    }
}

void Inorder(struct node * root){
    if(root!= NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

// recursive search
struct node * search(struct node * root, int key){
    if(root == NULL){
        printf("\n Element %d not found\n", key);
        return NULL;
    }
     
    if(key == root->data){
        printf("\n Element %d found!\n", key);
        return root;
    }
    
    else if (key < root->data)
        return search(root->left,key);

    else
        return search(root->right, key);
}

//iterative search
struct node* searchIter(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            printf("Element %d found!\n", key);
            return root;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    printf("Element %d not found\n", key);
    return NULL;
}

// Function to insert a value in the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}


// function to search the inorder predecessor
struct node *inOrderPredecessor(struct node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;   
}

struct node* deleteNode(struct node * root, int value){
    struct node *iPre;
    if(root == NULL){
        return NULL;
    }

    //search for the element to delete
    if( value< root->data){
        root->left = deleteNode(root->left,value);
    }
    else if(value> root->data){
        root->right = deleteNode(root->right, value);
    }
    
    //deletion strategy when the node is found
    
    else{

        if(root->left ==NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // Case 2: Only right child
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 3: Only left child
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main(){

    struct node * root = NULL;

    // Insert elements automatically (BST property maintained)
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 47);
    
    printf("\nprinting Inorder \t");
    Inorder(root);

    // printf(" \n %d",isBST(root));
    // search(root, 4);

    deleteNode(root, 3);
    printf("\n");
    Inorder(root);
    
    return 0;
}
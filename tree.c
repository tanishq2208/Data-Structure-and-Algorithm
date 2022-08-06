#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0
#define SPACE_GAP_LEVEL 10

// structure of node of tree.
struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node node_t;

#define MAX_SIZE 10
node_t* arr[MAX_SIZE];
int front = -1;
int rear = -1;

void push(node_t* ptr ){
    if(front == MAX_SIZE + 1 || rear == MAX_SIZE + 1) { return; }

    if(front == -1 ){
        front++;
        rear++;
        arr[rear] = ptr;
        return; 
    }

    else{
        arr[++rear] = ptr;
        return;
    }
}

void pop(){
    if(front == MAX_SIZE + 1){ return; }

    else{ front++; }
    return;
}

node_t* top(){
    return arr[front];
}

void clearQueue(){
    int i;
    for(i=0;i<10;i++){
        arr[i] = EMPTYNODE;
    }
    return;
}

int empty(){
    if(front == MAX_SIZE + 1){ return 1; }

    else{ return 0; }
}

// creating a node.
node_t* createNode(int data){
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = data;
    ptr->right = EMPTYNODE;
    ptr->left = EMPTYNODE;
    return ptr;
}

// function to insert a node in tree.
node_t* insertNode(node_t* root, int data){
    if(root == EMPTYNODE){
        root = createNode(data);
        return root;
    }
    push(root);

    while(empty() != 1){
            node_t* temp = top();
            pop();

            if(temp->left != EMPTYNODE){
                push(temp->left);
            }
            else{
                temp->left = createNode(data);
                return root;
            }

            if(temp->right != EMPTYNODE){
                push(temp->right);
            }
            else{
                temp->right = createNode(data);
                return root;
            }
    }
}

// function to search for required node in tree.
node_t* searchNode(node_t* root, int data){
    if(root == EMPTYNODE){ return EMPTYNODE; }

    push(root);
    while(empty() != 1){
        node_t* temp = top();
        pop();
        if(temp->data == data){ return temp; }
        
        if(temp->left->data == data) { return temp->left; }
        else{
            push(temp->left);
        }

         if(temp->right->data == data) { return temp->right; }
        else{
            push(temp->right);
        }
    }
    return EMPTYNODE;
}

void deleteNode(node_t* root, int data){
    if(root == EMPTYNODE){ return; }

    node_t* nodeToDelete = searchNode(root, data);
    node_t* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    nodeToDelete->data = temp->right->data;
    free(temp->right);
    return;
}

// function to traverse tree in inorder.
void inorder(node_t* root){
    if(root == EMPTYNODE){ return; }

    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    return;
}

// function to traverse tree in preorder.
void preorder(node_t* root){
    if(root == EMPTYNODE){ return; }

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

// function to traverse tree in post order.
void postorder(node_t* root){
    if(root == EMPTYNODE){ return ; }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
    return;
}

void printTree(node_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printTree(root->right, space);
  
    printf("\n");
    for (int i = SPACE_GAP_LEVEL; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    printTree(root->left, space);
}

// main() function.
int main(){
    node_t* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
 
    printf("Inorder before insertion :\n");
    inorder(root);
    
    printf("\nInorder after insertion : \n");
    int key = 12;
    root = insertNode(root, key);
    inorder(root);
   /* printf("\nPreorder :\n");
    preorder(root);
    printf("\nPostorder :\n");
    postorder(root);*/
    node_t* ptr = searchNode(root, 15);
    if(ptr != EMPTYNODE) { printf("\ndata found in tree i.e. %d\n",ptr->data); }
    else if(ptr == EMPTYNODE)
    printf("\ndata is not present\n");

    printTree(root, 0);

    return 0;
}

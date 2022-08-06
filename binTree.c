#include<stdio.h>
#include<stdlib.h>

#define EMPTYNODE 0
#define SPACE_GAP_LEVEL 10

// structure of a node of a tree.
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode node_t;

// function to create a node.
node_t* createNode(int data){
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = data;
    ptr->left = EMPTYNODE;
    ptr->right = EMPTYNODE;
    return ptr;
}
int count2 = 0;

short countnodes(node_t* root){
    if(root != NULL)
    {
        countnodes(root->left);
        count2++;
        countnodes(root->right);
    }
    return count2;
}

// function to insert a node in the tree.
void insertNode(node_t* root, node_t* node){
    if(root == EMPTYNODE){ 
        root = node;
        return;
    }

    if(node->data > root->data){ 
        if(root->right == EMPTYNODE){ 
            root->right = node;
            return;
        }
        insertNode(root->right, node); 
    }
    else if(node->data < root->data){
        if(root->left == EMPTYNODE){
            root->left = node;
            return;
        }
        insertNode(root->left, node);
    }
    return;
}

// function to search for a node.
node_t* searchNode(node_t* root, int data){
    if(root == EMPTYNODE){ return EMPTYNODE; }

    node_t* node;
    if(root->data == data){
        return root;
    }
    else if(root->data > data)    
    node = searchNode(root->left, data);
    else if(root->data < data)
    node = searchNode(root->right, data);

    return node;
}
// *****************************************************
// function to delete a node.(not working)
void deleteNode(node_t* root, int data){
    if(root == EMPTYNODE){ return; }

    while(root->right){
        root = root->right;
    }
    node_t* node = searchNode(root, data);
    node->data = root->data;
    free(root);
    return;
}

// function to search for a minimum node in a tree.
int minNode(node_t* root){
    if(root == EMPTYNODE){ return 0; }

    if(root->data > root->left->data){
        while(root->left){
            root = root->left;
        }
        return root->data;
    }
    else{
        while(root->right){
            root = root->right;
        }
        return root->data;
    }
}

// function to find the lowest common ancestor(LCA) of node n1 & n2.
int lca(node_t* root, int n1, int n2){
    if(root == EMPTYNODE){ return -1; }
    int node = root->data;

    if(root->data > n1 && root->data > n2){
        node = lca(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2){
        node = lca(root->right, n1, n2);
    }
    return node;
}

// function to print thr k-th smallest element in tree using inorder traversal.
int count = 0;
void kthSmallestNode(node_t* root, int k){
    if(root == EMPTYNODE){ return; }

    if(count == k){
        printf("k-th smallest node : %d\n",root->data);
    }
    kthSmallestNode(root->left, k);
    count++;
    kthSmallestNode(root->right, k);
    return;

}

// function to print a tree.
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


// main function.
int main(){
    node_t* root = createNode(20);
    /*root->left = createNode(9);
    root->right = createNode(19);
    root->left->left = createNode(7);
    root->left->right = createNode(10);
    root->right->left = createNode(17);
    node_t* newNode = createNode(21);
    insertNode(root, newNode);*/
    insertNode(root, createNode(8));
    insertNode(root, createNode(22));
    insertNode(root, createNode(4));
    insertNode(root, createNode(12));
    insertNode(root, createNode(10));
    insertNode(root, createNode(14));

    /*newNode = createNode(16);
    insertNode(root, newNode);
    newNode = createNode(6);
    insertNode(root, newNode);*/

    /*newNode = searchNode(root, 7);
    printf("%d",newNode->data);*/

    // deleteNode(root, 9);
    /*printf("min node = %d\n",minNode(root));
    printf("lca of 10 & 22 = %d\n",lca(root, 10, 22));*/
    printf("count = %d\n", countnodes(root));
    // kthSmallestNode(root, 3);
    // printTree(root, 0);

}
#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0

// Node structure.
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node_t;

node_t* createNode(int val)
{
    node_t* head=(node_t*)malloc(sizeof(node_t));
    head->data=val;
    head->next=EMPTYNODE;
    return head;
}

// function to append a node in list.
int append(node_t* tail, node_t* newNode)
{
    if(tail==EMPTYNODE)
    return 0;

    tail->next=newNode;
    return 1;
}

void prepend(node_t* head, node_t** newHead, node_t* newNode)
{
    if(head==EMPTYNODE || newNode==EMPTYNODE)
    return;

    node_t* temp=head;
    *newHead=newNode;
    newNode->next=temp;
    return;
}

// function to check whether a data is present in link list or not.
int isData(node_t* head, int data)
{
    if(head==EMPTYNODE)
    return 0;

    while(head)
    {
        if(head->data==data)
        return 1;

        head=head->next;
    }
    return 0;
}

// function to remove a node in a link list.
void removeNode(node_t* head, node_t** newHead, int index)
{
    if(head==EMPTYNODE)
    return;

    node_t* temp, *prev, *curr;
    if(index==0)
    {
        temp=head;
        *newHead=head->next;
        free(temp);
        return;
    }
    int counter=0;
    prev=head;
    curr=head->next;
    while(curr)
    {
        counter++;
        if(counter==index)
        {
            temp=curr;
            prev=curr->next;
            free(temp);
        }
    }
    return;
}

// function to traverse the link list.
void traverse(node_t* head)
{
    if(head==EMPTYNODE)
    return;

    while(head)
    {
        printf("%d --> ",head->data);
        head=head->next;
    }
    printf("EMPTYNODE\n");
    return;
}

void deleteNode8(node_t* head, node_t* ptr){
   if(head == EMPTYNODE){ return; }
    node_t* curr, *prev, *temp;
    curr = head->next;
    prev = head;
   while(curr){
       if(curr == ptr){
           temp = curr;
           prev->next = curr->next;
           curr = curr->next;
           free(temp);
           return;
        }
        curr = curr->next;
        prev = prev->next;
   }
}
// main function.
int main(){
    node_t* head, *tail, *newNode;
    head = createNode(1);
    tail =  head;
    for(short i=2;i<11;i++){
        newNode = createNode(i);
        if(append(tail, newNode) == 1)
        tail = newNode;
    }
    traverse(head);
    node_t* temp = head;
    node_t* delPtr;
    int count = 1;
    while(count<8){
        count++;
        temp = temp->next;
       
    }
    deleteNode8(head, temp);
    traverse(head);
}
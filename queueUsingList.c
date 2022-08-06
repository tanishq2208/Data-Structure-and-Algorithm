#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int val)
{
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = val;
    ptr->next = EMPTYNODE;
    return ptr;
}

void enqueue(node_t** newTail, node_t* tail, int val)
{
    if(tail == EMPTYNODE)
    return ;
    node_t* newNode = createNode(val);
    tail->next = newNode;
    *newTail = newNode;
    return;
}

void dequeue(node_t** newHead, node_t* head)
{
    if(head == EMPTYNODE)
    return;

    node_t* temp = head;
    *newHead = head->next;
    free(temp);
    return;
}

void printQueue(node_t* head)
{
    if(head == EMPTYNODE)
    return;

    while(head)
    {
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node_t *head, *tail;
    int i;
    for(i=1;i<=5;i++)
    {
        enqueue(&tail, tail, i);
        if(i==1)
        head = tail;
    }

    printQueue(head);
}
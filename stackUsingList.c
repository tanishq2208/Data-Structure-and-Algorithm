#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node node_t;

typedef enum
{
    TRUE = 1,
    FALSE = 0,
}status;

node_t* createNode(int val)
{
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = val;
    ptr->next = EMPTYNODE;
    ptr->prev = EMPTYNODE;
    return ptr;
}

node_t* push(node_t* tail, int val)
{
    if(tail == EMPTYNODE)
    return FALSE;

    node_t* ptr = createNode(val);
    tail->next = ptr;
    ptr->prev = tail;
    return ptr;
}

node_t* pop(node_t* tail)
{
    if(tail == EMPTYNODE)
    return FALSE;

    node_t* temp = tail;
    node_t* ptr = tail->prev;
    tail->prev->next = EMPTYNODE;
    free(temp);
    return  ptr;
}

int peek(node_t* tail)
{
    if(tail == EMPTYNODE)
    return FALSE;

    return tail->data;
}

void printStack(node_t* tail)
{
    if(tail == EMPTYNODE)
    return;

    while(tail)
    {
        printf("%d-->",tail->data);
        tail = tail->prev;
    }
    printf("EMPTYNODE\n");
}

int main()
{
    node_t *head, *tail;
    int i;
    head=createNode(1);
    tail = head;
    node_t* newNode;
    for(i=2;i<=5;i++)
    {
        newNode = push(tail, i);
        tail=newNode;
    }
    printf("Stack :\n");
    printStack(tail);

    newNode = pop(tail);
    tail=newNode;
    printf("Stack after pop :\n");
    printStack(tail);

    newNode = pop(tail);
    tail=newNode;
    printf("Stack after pop :\n");
    printStack(tail);

    printf("peek-->%d\n",peek(tail));
}
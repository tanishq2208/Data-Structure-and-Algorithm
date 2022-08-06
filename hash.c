#include<stdio.h>
#include<stdlib.h>

#define EMPTYNODE 0
#define MAX_SIZE 31

int arr[MAX_SIZE];

struct Node
{
    int data;
    int key;
};

typedef struct Node node_t;

node_t* create(int data, int key)
{
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = data;
    ptr->key = key;
    return ptr;
}

int hashFunc(int key)
{
    return key % MAX_SIZE;
}

void push(node_t *ptr)
{
    arr[hashFunc(ptr->key)] = ptr->data;
}

void lookUp(int key)
{
    int index = hashFunc(key);
    if(arr[index] == 0)
    printf("data not present\n");
    else
    printf("key = %d\tdata = %d\n",index, arr[index]);
}

int main()
{
    node_t* ptr = create(5, 41);
    push(ptr);
    ptr = create(50, 52);
    push(ptr);
    ptr = create(45, 25);
    push(ptr);

    // lookUp(50);
    lookUp(41);
    lookUp(52);
    lookUp(25);
    lookUp(22);
    printf("data---->%d",arr[10]);
}
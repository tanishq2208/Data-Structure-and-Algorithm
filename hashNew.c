#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node_t;

struct Arr{
    node_t* head;
};
typedef struct Arr arr;

#define ARR_SIZE 31
arr array[ARR_SIZE];

node_t* create(){
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->next = NULL;
    return ptr;
}

int hashFunc(char key[], int sz)
{
    int i = 0, p, sum = 0;
    for(i=0;i<sz;i++){
        p = key[i];
        sum += p*(i+1);
    }
    return sum % ARR_SIZE;
}

void push(int data, char key[], int sz){
    if(array[hashFunc(key, sz)].head ==  NULL){
    array[hashFunc(key, sz)].head = create();
    array[hashFunc(key,sz)].head->data = data;
    return;
    }

    while(array[hashFunc(key, sz)].head->next != NULL){
        if(array[hashFunc(key, sz)].head->data == data){ return; }
        array[hashFunc(key, sz)].head = array[hashFunc(key, sz)].head->next;
    }
    array[hashFunc(key, sz)].head->next = create();
    array[hashFunc(key, sz)].head->next->data = data;
    return;
}

void lookUp(char key[], int sz){
    int index = hashFunc(key, sz);
    if(array[index].head != NULL){
         while(array[index].head != NULL){
                printf("data is present :\nkey--->%s\tindex-->%d\tdata-->%d\n", key, index, array[index].head->data);
                array[index].head = array[index].head->next;
         }
    }
    else
    printf("data with key ' %s 'is not present\n",key);
    return;
}

int main(){
    int data = 50;
    char key[10] = "New York";
    push(data, key, strlen(key));
    data = 90;
    char k[10] = "Paris";
    push(data, k, strlen(k));
    lookUp(key, strlen(key));
    lookUp("hello world", 11);
    push(100, "New York", 8);
    lookUp("New York", 8);
}
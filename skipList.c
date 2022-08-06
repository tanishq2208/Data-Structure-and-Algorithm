#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0

struct Node{
    int data;
    struct Node* next;
    struct Node* express;
};

typedef struct Node node_t;

node_t* createNode(int val){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = val;
    node->next = EMPTYNODE;
    return node;
}

void append(node_t* tail, node_t* newNode){
    if(tail == EMPTYNODE){ return EMPTYNODE; }

    tail->next = newNode;
    return;
}

void buildExpress(node_t* head, int sz){
    if(head == EMPTYNODE){ return; }

    node_t* temp = head;
    
    while(sz >= 3){
            short count = 0;
            while(temp->next && count < 3){
                count++;
                temp = temp->next;
            }
            head->express = temp;
            head = temp;
            sz -= 3;
        }
    
    return;
}

void printList(node_t* head){
    if(head == EMPTYNODE){ return; }

    while(head){
        printf("%d ---> ", head->data);
        head = head->next;
    }
    printf("EMPTYNODE\n");
    return;
}

void printExpress(node_t* head){
    if(head == EMPTYNODE){ return; }

    printf("express Line : \n");
    while(head){
        if(head->express != EMPTYNODE){
            printf("%d ---> ", head->data);
            head = head->express;
            continue;
        }
        head = head->next;
    }
    printf("EMPTYNODE \n");
    return;
}

void QuickSearch(node_t* head, int val){
    if(head == EMPTYNODE){ return; }

    node_t* temp;
    short i = 0;
    while(head){
        if(head->data == val){ 
            printf("val = %d fount at index : %d", val, i);
            break;
        }
        else{
            while(head->express == EMPTYNODE && head){
                if(head->express->data >= val){ break; }
                else if(head->express->data < val){
                    temp = head;
                    head = head->express;
                    if(head->express->data > val){ 
                        head = temp;
                        break; 
                    }
                    i += 3;   
                }
            }
        }
        head = head->next;
        i++;
    }
    return;
}

int main(){
    node_t* head = createNode(1), *tail;
    tail = head;
    node_t* newNode;
    int i;
    for(i=0;i<9;i++){
        newNode = createNode(i + 2);
        append(tail, newNode);
        tail = newNode;
    }
    // printList(head);
    // buildExpress(head, 10);
    // printExpress(head);
    QuickSearch(head, 3);

    return 0;
}
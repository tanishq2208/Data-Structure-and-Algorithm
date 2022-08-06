#include<stdio.h>
#include<stdlib.h>

typedef enum{
    LIST_TRUE=1,
    LIST_FALSE=0,
}status_t;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node_t;

Node_t* create(int);
void printList(Node_t*);
status_t append(Node_t*,Node_t*);
void destroyList(Node_t* );

Node_t* create(int val)
{
    Node_t* ptr=(Node_t*)malloc(sizeof(Node_t));
    ptr->data=val;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}

status_t append(Node_t* tail,Node_t* newNode)
{
    if(tail==NULL || newNode==NULL)
    return LIST_FALSE;

    tail->next=newNode;
    newNode->prev=tail;
    return LIST_TRUE;
}

void destroyList(Node_t* ptr)
{
    if(ptr==NULL)
    return;

    while(ptr)
    {
        Node_t* curr=ptr;
        printList(curr);
        ptr=ptr->next;
        ptr->next->prev=NULL;
        free(curr);
    }
    printf("EMPTYNODE");
}

status_t deleteNode(Node_t* ptr,Node_t** newHead,int index)
{
    if(ptr==NULL)
        return LIST_FALSE;
    int i=0;
    if(index==0)
    {
       *newHead=ptr->next;
       ptr->next->prev=NULL;
       free(ptr);
       return LIST_TRUE;
    }
    Node_t* temp;
    while(ptr)
    {
        i++;
        if(i==index)
        {
            temp=ptr;
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(temp);
            return LIST_TRUE;
        }
        ptr=ptr->next;
    }
    return LIST_FALSE;
}

void printList(Node_t* head)
{
    if(head==NULL)
    return;

    Node_t* node=head;
    while(node)
    {
        printf("%d-->",node->data);
        node=node->next;
    }
    printf("EMPTYNODE\n");
}

void insertNode(Node_t* ptr,Node_t** newHead,Node_t* newNode,int index)
{
    if(ptr==NULL)
    return;

    if(index==0)
    {
        *newHead=ptr->next;
        ptr->next->prev==NULL;
        free(ptr);
        return;
    }
    int i=0;
    Node_t* curr=ptr;
    while(curr)
    {
        Node_t* after=curr->next;
        i++;
        if(index==i)
        {
            curr->next=newNode;
            newNode->prev=curr;
            newNode->next=after;
            after->prev=newNode;
            return;

        }
        curr=curr->next;
    }
    return;
}

void reverse(Node_t* tail)
{
    if(tail==NULL)
    return;

    while(tail)
    {
        printf("%d-->",tail->data);
        tail=tail->prev;
    }
    printf("EMPTYNODE\n");
    return ;

}

status_t prepend(Node_t* ptr,Node_t* newNode)
{
    if(ptr==NULL || newNode==NULL)
    return LIST_FALSE;

    newNode->next=ptr;
    ptr->prev=newNode;
    return LIST_TRUE;
}

int main()
{
    Node_t* tail=NULL;
    Node_t* head=NULL;
    head=create(10);
    tail=head;
    int i;
    for(i=2;i<6;i++)
    {
        Node_t* newNode=create(10*i);
        if(LIST_TRUE==append(tail,newNode))
        tail=newNode;
    }
    printList(head);

    printf("list after reversal :\n");
    reverse(tail);
    
    for(i=9;i>5;i--)
    {
        Node_t* newNode=create(i);
         if(LIST_TRUE==prepend(head,newNode))
          head=newNode;
    }
    printList(head);
   if(LIST_TRUE==deleteNode(head,&head,2))
   printList(head);
   Node_t* newNode = create(500);
   insertNode(head, &head, newNode, 3);
   printList(head); 
}
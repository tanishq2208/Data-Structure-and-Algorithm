#include<stdio.h>
#include<stdlib.h>
#define EMPTYNODE 0

struct Node
{
    int coef;
    int exp;
    struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int coef, int exp)
{
    node_t* ptr=(node_t*)malloc(sizeof(node_t));
    ptr->coef=coef;
    ptr->exp=exp;
    ptr->next=EMPTYNODE;
    return ptr;
}

int appendNode(node_t* tail, node_t* newNode)
{
    if(newNode == EMPTYNODE)
    return 0;

    tail->next=newNode;
    return 1;
}

void traverse(node_t* head)
{
    if(head==EMPTYNODE)
    return;

    while(head)
    {
        printf("%d (x^%d) \t",head->coef, head->exp);
        head=head->next;
    }
    printf("\n");
    return;
}

int main()
{
    node_t *head1, *head2, *head3, *newNode;
    node_t *tail1, *tail2, *tail3;
    head1=createNode(1,4);
    tail1 =head1;
    int i;
    for(i=3;i>=0;i--)
    {
        newNode=createNode(5-i,i);
        if(appendNode(tail1,newNode)==1)
        tail1=newNode;
    }

    head2=createNode(5,3);
    tail2=head2;
    for(i=2;i>=0;i--)
    {
        newNode=createNode(7-i,i);
        if(appendNode(tail2,newNode)==1)
        tail2 = newNode;
    }
    printf("FIRST EXPRESSION :\n");
    traverse(head1);
    printf("SECOND EXPRESSION :\n");
    traverse(head2);
    int flag=0;

    node_t *head1_ref=head1, *head2_ref=head2;
    while(head1_ref)
    {
        while(head2_ref)
        {
            if(head1_ref->exp==head2_ref->exp)
            {
                newNode=createNode(head1_ref->coef + head2_ref->coef, head1_ref->exp);
                if(flag==0)
                {
                    flag++;
                    head3=newNode;
                    tail3 = head3;
                }
                else{
                if(appendNode(tail3,newNode)==1)
                tail3=newNode;
                }
            }
            head2_ref=head2_ref->next;
        }
        head1_ref=head1_ref->next;
        head2_ref=head2;
    }
    printf("RESULT :\n");
    traverse(head3);
}
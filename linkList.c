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

#define LENGTH_STACK 10
int stackArr[LENGTH_STACK];
int top = -1;

// function to push element in stack.
void push(int data){
    if(top == LENGTH_STACK - 1){ return; }

    stackArr[++top] = data;
    return;
}

// function to pop the top of stack;
int pop(){
    if(top == -1){ return 0; }

    return stackArr[top--];
}

// function to return the top of stack;
int front(){
    if(top == -1){ return 0; }

    return stackArr[top];
}

// function to create a node.
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

// function to insert a node in a list after a node.
void insertAfterIndex(node_t* newNode, node_t* head, int index)
{
    if(head==EMPTYNODE || newNode==EMPTYNODE)
    return;

    int counter=0;
    node_t* node=head, *temp;
    while(node)
    {
        if(index==counter)
        {
            temp=node->next;
            node->next=newNode;
            newNode->next=temp;
            return;
        }
        node=node->next;
        counter++;
    }
    return;
}

// function to prepend a node in a list.
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

// function to count the total node(n) and return to mthLastElement().
int totalNode(node_t* head){
    if(head == EMPTYNODE){ return -1; }
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

// function to find the middle element in list.
int midElement(node_t* head){
    if(head == EMPTYNODE){ return -1;}

    node_t* main_ptr = head;
    node_t* ref_ptr = head;
    
    while(ref_ptr){
        ref_ptr = ref_ptr->next->next;
        main_ptr = main_ptr->next;
    }
    return main_ptr->data;
}

// function to detect a loop in a link list.
/*int detectLoop(node_t* head){
    if(head == EMPTYNODE){ return 0; }

    node_t *fast = head, *slow = head;
    while(fast){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}*/

// function to find the m-th last element. ------> Method-2.
int mthLastElement(node_t* head, int m){
    node_t* main_ptr = head;
    node_t* ref_ptr = head;
    while(m--){
        ref_ptr = ref_ptr->next;
    }
    while(ref_ptr){
        ref_ptr = ref_ptr->next;
        main_ptr = main_ptr->next;
    }
    return main_ptr->data;
}

// function to find the m-th last element in list. -------> Method-1.
/*int mthLastElement(node_t* head, int m){
    if(head == EMPTYNODE){ return -1; }

    int count = totalNode(head) - m;
    while(head){
        head = head->next;
        count--;
        if(count == 0)
        break;

    }
    return head->data;
}*/

// function to swap pair wise element of a link list.
void pairWiseSwap(node_t* head){
    if(head == EMPTYNODE){ return; }

    int temp;
    while(head){
        temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;
    }
}

// function to check wheteher the list is palindrome or not.
int checkPalindrome(node_t* head){
    if(head == EMPTYNODE){ return 0; }
    node_t* temp = head;
    int flag = 1;
    while(head){
        push(head->data);
        head =  head->next;
    }
    int i = 0;
    while(i < totalNode(temp)/2){
        if(temp->data != pop()){
            flag = 0;
            break;
        }
        temp = temp->next;
        i++;
    }
    if(flag == 0)
    return 0;
    else 
    return 1;;
}


// main() function.
int main()
{
    node_t *head=EMPTYNODE, *tail=EMPTYNODE, *newNode;
    head=createNode(1);
    tail=head;
    for(int i=2;i<11;i++)
    {
        newNode=createNode(i);
        if(append(tail,newNode)==1)
        tail=newNode;
    }
    traverse(head);

    // tail->next = head;

    /*if(detectLoop(head) == 1)
    printf("Yes loop is present\n");
    else
    printf("No loop is not present\n");*/
    

    // if(midElement(head) != -1)
    // printf("Middle element in link list is %d\n",midElement(head));

  /* newNode = createNode(2);
    if(append(tail,newNode)==1)
    tail=newNode;

    newNode = createNode(3);
    if(append(tail,newNode)==1)
    tail=newNode;

    newNode = createNode(8);
    if(append(tail,newNode)==1)
    tail=newNode;

    newNode = createNode(1);
    if(append(tail,newNode)==1)
    tail=newNode;

    if(checkPalindrome(head) == 1)
    {
        printf("Yes list is palindrome\n");
    }
    else 
    printf("No list is not palindrome\n");
    */

    // sprintf("Last 3-rd element in link list is %d\n",mthLastElement(head, 3));
    
    /*printf("After removing index 0 :\n");
    removeNode(head,&head,0);
    traverse(head);
    newNode=createNode(100);*/

   /* printf("List after inserting node after index 2:\n");
    insertAfterNode(newNode,head,3);
    traverse(head);*/

    int i;
    #if 0
    for(i=6;i<11;i++)
    {
        newNode=createNode(i);
        appendNode(tail,newNode);
        tail=newNode;
    }
    traverse(head);
    # endif

    /*if(isData(head,5)==1)
    printf("5 is present\n");
    else
    printf("5 not present");

    if(isData(head,12)==1)
    printf("12 is present\n");
    else
    printf("12 not present\n");*/
    /*prepend(head,&head,createNode(100));
    traverse(head);*/
    /*newNode=createNode(500);
    insertAfterIsndex(newNode,head,2);
    traverse(head);*/
    // printf("last 2 element in list is %d\n",mthLastElement(head, 2));
}
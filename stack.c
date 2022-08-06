#include<stdio.h>
#include<stdlib.h>

typedef enum{
    STACK_TRUE=1,
    STACK_FALSE=0,
}status;

int *stackElement=NULL;
int top=-1;
int sz=5;


void destroy();
void createStack();
status isEmpty();
status isFull();
status peek(int *);
status pop(int *);
status push(int);
void printStack();

void destroy()
{
    if(stackElement!=NULL)
    {free(stackElement);
    stackElement=NULL;}
    return;
}

void createStack()
{
    if(stackElement!=NULL)
    destroy();

    stackElement=(int*)malloc(sz*sizeof(int));
    top=-1;
    return;
}

status push(int val)
{
    if(STACK_FALSE==isFull())
    {
        stackElement[++top]=val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status pop(int* val)
{
    if(STACK_FALSE==isEmpty())
    {
        *val=stackElement[top--];
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status peek(int* val)
{
    if(STACK_FALSE==isEmpty())
    {
        *val=stackElement[top];
      return STACK_TRUE;
    }
    return STACK_FALSE;
}

status isEmpty()
{
    if(-1==top)
    return STACK_TRUE;

    return STACK_FALSE;
}

status isFull()
{
    if(top+1==sz)
    return STACK_TRUE;

    return STACK_FALSE;
}

void printStack()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d\t",stackElement[i]);
    }
    printf("\n");
    return;
}


int main()
{
 createStack();
 push(10);
 push(34);
 push(56);
 push(45);
 push(32);
 printStack();
 int val;
 if(STACK_TRUE==pop(&val))
 printf("ITEM POPPED--->%d\n",val);
 else printf("elemnt not present\n");
  printStack();
 if(STACK_TRUE==pop(&val))
 printf("ITEM POPPED--->%d\n",val);
 else printf("elemnt not present\n");
 printStack();
if(STACK_TRUE==peek(&val))
printf("peek--->%d",val);
}
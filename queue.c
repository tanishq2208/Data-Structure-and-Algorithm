#include<stdio.h>
#include<stdlib.h>

typedef enum{
    QUEUE_TRUE=1,
    QUEUE_FALSE=0,
}status;

int *queueElements;
int front=0,back=-1;
int sz=10;

void destroy();
void createStack();
status isFull();
status isEmpty();
status enqueue(int);
status dequeue(int *);
void print();

void destroy()
{
    if(back!=-1)
    free(queueElements);
    
    queueElements=NULL;
    return;
}

void createStack()
{
    if(queueElements!=NULL)
    destroy();

    queueElements=(int*)malloc(sz*sizeof(int));
    front=0;
    back=-1;
    return;
}

status enqueue(int val)
{
    if(QUEUE_FALSE==isFull())
    {
        queueElements[++back]=val;
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status dequeue(int *val)
{
    if(QUEUE_FALSE==isEmpty())
    {
        *val=queueElements[front++];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status isFull()
{
    if(back+1==sz)
    return QUEUE_TRUE;

    return QUEUE_FALSE;
}

status isEmpty()
{
    if(back==-1)
    return QUEUE_TRUE;

    return QUEUE_FALSE;
}


void print()
{
    int i;
    for(i=front;i<=back;i++)
    {
        printf("%d\t",queueElements[i]);
    }
    printf("\n");
    return;
}

/*int main()
{
    printf("QUEUE WORKING\n");
    createStack();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print();
    int val;
    if(QUEUE_TRUE==dequeue(&val))
    printf("element dequeued--->%d\n",val);
    else
    printf("not dequeued\n");
    print();
    if(QUEUE_TRUE==dequeue(&val))
    printf("element dequeued--->%d\n",val);
    else
    printf("not dequeued\n");
    print();
}*/
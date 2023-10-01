#include<stdio.h>
#include<stdbool.h>
#define size 5
typedef struct q
{
    int front;
    int rear;
    int q[size];
}q;
q q1;
void init()
{
    q1.front = 0;
    q1.rear = -1;
}
bool isfull()
{
    if(q1.rear == size-1)
    {
        return true;
    }
    return false;
}
bool isempty()
{
    if(q1.front>q1.rear)
    {
        return true ;
    }
    return false;
}
void push(int item)
{
    if(isfull())
    {
        printf("QUEUE OVERFLOW");
        return;
    }
    else
    {
        q1.q[++q1.rear]=item;
    }
}
int del()
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW");
        return 000;
    }
    else
    {
        return q1.q[q1.front++];
    }
}
void disp()
{
    if(isempty())
    {
        printf("here");
        printf("QUEUE UNDERFLOW\n");
    }
    printf("PRESENT QUEUE :\n");
    int temp = q1.front;
    for(int i=q1.front;i<=q1.rear ; i++)
        printf("%d\n",q1.q[q1.front++]);
    q1.front = temp;
}
int main()
{
    init();
    push(10);
    push(12);
    printf("%d\n",q1.front);
    printf("%d\n",q1.rear);
    disp();
    int x = del();
    disp();
    push(13);
    disp();
}

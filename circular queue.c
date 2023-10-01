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
    q1.rear=0;
}
bool isfull()
{
    if((q1.rear+1)%size==q1.front)
        return true;
    return false;
}
bool isempty()
{
    if(q1.front==q1.rear)
        return true;
    return false;
}
void push(int ele)
{
    if(isfull())
    {
        printf("QUEUE OVERFLOW");
        return;
    }
    q1.rear=(q1.rear+1)%size;
    q1.q[q1.rear]=ele;
}
int del()
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW");
        return 000;
    }
    printf("the front is %d\n",q1.front);
    q1.front=(q1.front+1)%size;
    return q1.q[q1.front];
}
void disp()
{
    if(isempty())
    {
        printf("%d\n",q1.front);
        printf("%d\n",q1.rear);
        printf("QUEUE UNDERFLOW\n");
        return ;
    }
    int i=q1.front;
    do{
        i=(i+1)%size;
        printf("%d\t",q1.q[i]);
    }while(i!=q1.rear);
    printf("\n");
}
int main()
{
    init();
    push(10);
    push(12);
    push(13);
    push(14);
    push(15);
    //printf("%d\n",q1.front);
    //printf("%d\n",q1.rear);
    printf("1st\n");
    disp();
    int x = del();
    printf("after deleting %d\n",x);
    disp();
    push(13);
    printf("after push\n");
    disp();
    push(14);
    push(15);
    disp();
    x = del();
    disp();
    push(16);
    disp();
}



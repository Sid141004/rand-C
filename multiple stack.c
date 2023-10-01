#include<stdio.h>
/*typedef struct
{
    int key;
}mstack[10];
mstack s[10];
int top[5],b[5];
*/
int m =12;
int n =3;
int top[],b[],s[12];
void init()
{
    int i;
    printf("initialisation loop\n");
    for(i=0;i<n;i++)
    {
        b[i]=top[i]=((m/n)*i)-1;
        printf("top is %d and i is %d\n",top[i],i);
        printf("bou is %d\n",b[i]);
    }
    printf("top of 0 is %d\n",top[0]);
    printf("top of 1 is %d\n",top[1]);
    printf("top of -1 is %d\n",top[-1]);
}
void push(int s_ind,int f)
{
    printf("s_ind is %d\n",s_ind);
    printf("top is %d\n",top[s_ind]);
    printf("top of 0 is %d\n",top[0]);
    printf("boundry is %d\n",b[s_ind]);
    if(top[s_ind-1]=b[s_ind])
    {
        printf("STACK OVERFLOW");
        return;
    }
    else
    {
        s[++top[s_ind]]=f;
    }
}
void main()
{
    init();
    printf("%d\n",top[0]);
    push(0,4);
    printf("%d",s[0]);
}

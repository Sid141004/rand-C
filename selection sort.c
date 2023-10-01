#include<stdio.h>
int main()
{
    int i,j,min,pos,t;
    int a[5]={12,45,28,19,55};
    for(i=0;i<4;i++)
    {
        min=i;
        for(j=i+1;j<5;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        if(min!=i)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);
}

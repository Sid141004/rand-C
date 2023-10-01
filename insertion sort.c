#include<stdio.h>
int main()
{
    static  a[5] = {12,45,28,19,55};
    int temp,i,j;
    for(i=1;i<5;i++)
    {
        temp = a[i];
        j=i-1;
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        };
        a[j+1]=temp;
    }
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);
}

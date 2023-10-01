#include<stdio.h>
#include<string.h>
int main()
{
    char a[10],b[10],c[19],d[10];
    int i,j,len1,len2,pos,tot,o,t=0;
    printf("enter the string");
    gets(a);
    printf("enter the substring");
    gets(b);
    printf("enter the position to be inserted in:");
    scanf("%d",&pos);
    len1=strlen(a);
    len2=strlen(b);
    for(i=0;i<len1;i++)
    {
        c[i]=a[i];
    }
    c[i+1]='\0';
    tot=len1 + len2;
    o=pos+len2;
    for(i=pos;i<tot;i++)
    {
        j=c[i];
        if(t<len2)
        {
            a[i]=b[t];
            t++;
        }
        a[o]=j;
        o++;
    }
    puts(b);
    puts(a);
    puts(c);
}

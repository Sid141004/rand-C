#include<stdio.h>
int row , col , splen=0;
typedef struct
{
    int row;
    int col;
    int val;
}sparsest;
void init(sparsest a[splen+1],sparsest b[splen+1])
{
    printf("ENTER ROWS :");
    scanf("%d",&row);
    printf("ENTER COLUMNS :");
    scanf("%d",&col);
    printf("enter values:");
    int spmat[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp;
            scanf("%d",&temp);
            spmat[i][j]=temp;
            if(temp!=0)
                splen++;
        }
    }
    a[0].row=row;
    a[0].col=col;
    a[0].val=splen;

    int ind=1;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp = spmat[i][j];
            if(temp!=0)
            {
                a[ind].row=i;
                a[ind].col=j;
                a[ind].val=temp;
                ind++;
            }
        }
    }
}
void fastTranspose(sparsest a[splen+1],sparsest b[splen+1])
{
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    int tot[100]={0};
    int ind[100]={0};

    for(int i =0 ;i<splen;i++)
    {
        tot[a[i+1].col]++;
    }
    ind[0]=1;
    for(int i=1;i<splen;i++)
        ind[i]=ind[i-1]+tot[i-1];
    for(int i=1;i<=splen;i++)
    {
        int j = ind[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
    }
}
void disp(sparsest a[splen+1])
{
    for(int i=0;i<=splen;i++)
        printf("%d %d %d\n",a[i].row,a[i].col,a[i].val);
}
int main()
{
    sparsest a[splen + 1];
    sparsest b[splen +1];
    init(a , b);
    fastTranspose(a , b);
    disp(a);
}

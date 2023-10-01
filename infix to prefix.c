#include <stdio.h>
#include <string.h>
char s[20];
char infix[20];
char prefix[20];
char rev[20];
int top = -1;

void push(char c)
{
    if(top==19)
    {
        printf("STACK OVERFLOW");
        return;
    }
    s[++top]=c;
}
char pop()
{
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return 0;
    }
    return s[top--];
}
typedef enum{lpara, rpara, plus, minus, multi, div, mod, eos, operand} precedence;

int isp[10]={0,19,12,12,13,13,13,0};
int icp[10]={20,19,12,12,13,13,13,0};

precedence get_token(char c)
{
    switch(c)
    {
        case '#':return eos;
        case '(':return lpara;
        case ')':return rpara;
        case '+':return plus;
        case '-':return minus;
        case '*':return multi;
        case '/':return div;
        case '%':return mod;
        default : return operand;
    }
}
void infix2prefix()
{
    push('#');
    int n = strlen(s);

    int i=n-1;
    int j=0;
    precedence temp;
    while(i>=0)
    {
        temp = get_token(infix[i]);
        if(temp == operand)
            prefix[j++]=infix[i];
        else if(temp == lpara)
        {
            while(s[top] != rpara)
                prefix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]< isp[get_token(s[top])])
                prefix[j++]=pop();
            push(infix[i]);
        }
        i--;
    }
    while(s[top]!='#')
    {
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    puts(prefix);
    for(i=0;j>=0;j--,i++)
        rev[i]=prefix[j];
    rev[i]='\0';
}
int main()
{
    printf("Enter infix:\n");
    scanf("%s",&infix);

    infix2prefix();
    printf("Post = %s",rev);


    return 0;
}

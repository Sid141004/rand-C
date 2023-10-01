#include <stdio.h>
char s[20];
char infix[20];
char postfix[20];
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
void infix2postfix()
{
    push('#');

    int i=0;
    int j=0;
    precedence temp;
    while(infix[i] != '\0')
    {
        temp = get_token(infix[i]);
        if(temp == operand)
            postfix[j++]=infix[i];
        else if(temp == rpara)
        {
            while(s[top] != rpara)
                postfix[j++]=pop();
            pop();
        }
        else
        {
            while(icp[temp]<= isp[get_token(s[top])])
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(s[top]!='#')
    {
        postfix[j++]=pop();
    }
}
int main()
{
    printf("Enter infix:\n");
    scanf("%s",&infix);

    infix2postfix();
    printf("Post = %s",postfix);


    return 0;
}


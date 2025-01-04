#include <stdio.h>
#define max 20
char stack[max];
int top=-1;

void push(char c)
{
    if (top==max-1)
        printf("Overflow");
    else{
        top++;
        stack[top]=c;
    }
}

char pop()
{
    if (top==-1)
        printf("Underflow");
    else{
        char c=stack[top];
        top--;
        return c;
    }
}

char peek()
{
    if (top==-1)
        printf("Underflow");
    else{
        char c=stack[top];
        return c;
    }
}

char prec(char c)
{
    if (c=='^')
        return 3;
    if (c=='/' || c=='*')
        return 2;
    return 1;
}

void InfToPost(char str[])
{
    char post[100];
    int i=0,k=0;
    while (str[i]!='\0')
    {
        char c=str[i];
        if ((c<='z'&& c>='a')||(c>='0' && c<='9'))
        {
            post[k]=c;
            k++;
        }
        else if (c=='(')
            push(c);
        else if( c==')')
        {
            while(peek()!='(')
            {
                post[k]=pop();
                k++;
            }
            pop();
        }
        else{
            while (top!=-1 && prec(c)<=prec(peek()) && c!='^')
            {
                post[k]=pop();
                k++;
            }
            push(c);
        }
        i++;
    }
    while (top!=-1)
    {
        post[k]=pop();
        k++;
    }
    printf("Postfix expression is: %s",post);
}


int main() {
    char inf[100]; // 3+2-a/b^6^k*d+1
    scanf("%s",inf); //: 32+ab6k^^/d*-1+
    InfToPost(inf);
    return 0;
}
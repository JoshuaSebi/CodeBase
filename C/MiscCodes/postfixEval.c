#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int e)
{
	if(top==MAX_SIZE-1)
	{
		printf("Stack Overflow!!!!!");
	}
	else
	{
		top++;
		stack[top]=e;
	}
}

int pop()
{
	int item;
	if (top==-1)
		printf("Stack Underflow!!!!!");
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}

int is_op(char s)
{
	if (s=='+'||s=='-'||s=='*'||s=='/'||s=='^')
		return 1;
	else 
		return 0;	
}

int evaluate(char expression[20])
{
	int i=0;
	int result;
	char s=expression[i];
	while (s!='\0')
	{
		if (s>='0' && s<='9')
		{
			int num=s-'0';
			push(num);
		}
		else if (is_op(s))
        {
            int op1=pop();
            int op2=pop();
            switch(s)
            {
                case '+':
                    result=op2+op1;
                    break;
                case '-':
                    result=op2-op1;
                    break;
                case '*':
                    result=op2*op1;
                    break;
                case '/':
                    result=op2/op1;
                    break;
                case '^':
                    result=op2^op1;
                    break;
            }
            push(result);
        }
        i++;
        s = expression[i];
	}
    result=pop();
    return result;
}

int main()
{
    char pf[20];
    printf("Enter postfix expression: ");
    scanf("%s",pf);
    int val=evaluate(pf);
    printf("The Output is: %d",val);
    return 0;
}




/*
 * Postfix Evaluation
 * Language: C++
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Stack
{
	int top;
	char arr[20];
	public:
		Stack()
		{
			top=-1;
		}
		void push(char ch)
		{
			if(top>19)
				cout<<"Stack is full";
			else
			{
				arr[++top]=ch;
			}
		}
		char pop()
		{
			char ch;
			if(top<0)
			cout<<"Stack is empty";
			else
			{
				ch=arr[top--];
			}
			return ch;
		}
		char stktop()
		{
            return arr[top];
		}
};

int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='$')
        return 1;
    else
        return 0;
}


int performOperation(int op1, int op2, char op)
{
    int ans;
    switch(op){
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    case '^':
    case '$':
        ans=pow(op2,op1);
    }
    return ans;
}
int main()
{
    char exp[1000];
    int i,op1, op2, len, j, x;
    Stack s;
    printf("Enter a Prefix Expression: \n");
    gets(exp);
    int k=0;
    char str1[80];
    for(int i=strlen(exp)-1;i>=0;i--)
    {
        str1[k++]=exp[i];
    }
    str1[k]='\0';
    len = strlen(exp);
    j = 0;
    for(i=0; i<len;i++)
    {
        if(str1[i]>='0' && str1[i]<='9')
        {
            s.push(str1[i]-'0');
        }
        else if(isOperator(str1[i]))
        {
            op1 = s.stktop();
            s.pop();
            op2 = s.stktop();
            s.pop();
            s.push(performOperation(op2, op1, str1[i]));
        }
    }

    printf("Answer is %d\n", s.stktop());
    return 0;
}

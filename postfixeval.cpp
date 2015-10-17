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
			if(top==19)
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
    printf("Enter a Postfix Expression: ( e.g. 23 34 * )\n");
    gets(exp);
    len = strlen(exp);
    j = 0;
    for(i=0; i<len;i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i]-'0');
        }
        else if(isOperator(exp[i]))
        {
            op1 = s.stktop();
            s.pop();
            op2 = s.stktop();
            s.pop();
            s.push(performOperation(op1, op2, exp[i]));
        }
    }
    cout<<"Answer is: "<<(int)s.stktop();
    return 0;
}

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
class Stack{
    char a[20][20];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    void push(char s[])
    {
        strcpy(a[++top],s);
    }
    char *pop()
    {
        return a[top--];
    }
};
int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='$')
        return 1;
    else
        return 0;
}
int main()
{
    char temp[20],postfix[20],op[2],op1[20],op2[20];
    cout<<"Enter Expression \n";
    gets(postfix);
    Stack s;
    int i=0;
    while(postfix[i]!='\0')
    {
        op[0]=postfix[i];
        op[1]='\0';
        if(!isOperator(postfix[i]))
        {
            s.push(op);
        }
        else
        {
            strcpy(op2,s.pop());
            strcpy(op1,s.pop());
            strcpy(temp, "(");
            strcat(temp,op1);
            strcat(temp,op);
            strcat(temp,op2);
            strcat(temp,")");
            s.push(temp);
        }
        i++;
    }
    cout<<s.pop();
    return 0;
}

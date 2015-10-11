#include<iostream>
#include<conio.h>
#define MAXSIZE 20
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
        return arr[top--];
    }
}
void postfixToInfix(char postfix[])
{
    char temp[20];
    Stack s;
    char op[2],op1[20],op2[20];
    int i=0;
    while(postfix[i]!='/0')
    {
        op[0]=postfix[i];
        op[1]='\0';
        if(isOperand(postfix[i]))
        {
            s.push(op);
        }
        else
        {
            strcpy(op2,s.pop);
            strcpy(op1,s.pop);
            strcpy(temp, "(");
            strcat(temp,op1);
            strcat(temp,op);
            strcat(temp,op2);
            strcat(temp,")");
            s.push(temp);
        }
        i++
    }
}

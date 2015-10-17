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
void reverse(char array[30])
{
    int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j)
	{
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}
int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='$')
        return 1;
    else
        return 0;
}
int main()
{
    char temp[20],prefix[20],op[2],op1[20],op2[20];
    cout<<"Enter Expression \n";
    gets(prefix);
    reverse(prefix);
    Stack s;
    int i=0;
    while(prefix[i]!='\0')
    {
        op[0]=prefix[i];
        op[1]='\0';
        if(!isOperator(prefix[i]))
        {
            s.push(op);
        }
        else
        {
            strcpy(op2,s.pop());
            strcpy(op1,s.pop());
            strcpy(temp, "(");
            strcat(temp,op2);
            strcat(temp,op);
            strcat(temp,op1);
            strcat(temp,")");
            s.push(temp);
        }
        i++;
    }
    cout<<s.pop();
    return 0;
}

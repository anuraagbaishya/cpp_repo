#include<iostream>
#include<stdio.h>
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
		int isEmpty()
		{
            if(top==-1)
                return 1;
            else
                return 0;
        }
};
int main()
{
    Stack stk;
    char s[80];
    int i,flag=0;
    cout<<"Enter expression\n";
    gets(s);
    for(i=0; s[i]!='\0'; i=i+2)
	{
		if(s[i]=='/'&&(s[i+1]=='/'||s[i+1]=='*'))
            continue;
        else if(s[i]=='/'&&(s[i+1]!='*'||s[i+1]!='/'))
            flag=1;
	}
	for(i=0; s[i]!='\0'; i=i+2)
	{
        if(s[i]=='/'&&s[i+1]=='*')
        {
             stk.push(s[i]);
             stk.push(s[i+1]);
        }
        else if(s[i]=='*'&&s[i+1]=='/')
        {
            stk.pop();
            stk.pop();
        }
	}
	if(stk.isEmpty()&&!flag)
        cout<<"Valid";
    else
        cout<<"Invalid";
    return 0;
}

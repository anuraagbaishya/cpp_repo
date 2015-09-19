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
		void display()
		{
			for (int i=0;i<top;i++)
			{
				cout<<arr[i]<<endl;
			}
		}
		int StackEmpty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
};
int main()
{
	char str[80];
	Stack stk;
	char ch;
	int count=0,flag;
	cout<<"Enter String: " ;
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
		if((str[i]==')'||str[i]=='}'||str[i]==']')&&count==0)
        {
            flag=1;
            break;
        }
		else if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			stk.push(str[i]);
            count++;
        }
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			char ch=stk.pop();
			if(str[i]==')'&&ch!='('||str[i]=='}'&&ch!='{'||str[i]==']'&&ch!='[')
				break;
		}
		else
            continue;
	}
	if(flag==1)
        cout<<"Wrong";
	else
	if(stk.StackEmpty())
		cout<<"Correct";
	else
		cout<<"Wrong";
}

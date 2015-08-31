#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class stack
{
	int top;
	char arr[20];
	public:
		stack()
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
		int stackEmpty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
};
void main()
{
	clrscr();
	char str[80];
	stack stk;
	char ch;
	cout<<"Enter String: " ;
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
			stk.push(str[i]);
		else if(str[i]==')'||str[i]=='}'||str[i]=='}')
		{
			char ch=stk.pop();
			if(str[i]==')'&&ch!='('||str[i]=='}'&&ch!='{'||str[i]==']'&&ch!='[')
				break;
		}
	}
	if(stk.stackEmpty())
		cout<<"Correct";
	else
		cout<<"Wrong";
	getch();
}
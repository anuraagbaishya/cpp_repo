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
};
void main()
{
	clrscr();
	char str[20];
	int flag=0;
	stack stk;
	cout<<"Enter a string: \n";
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
		stk.push(str[i]);
	}
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=stk.pop())
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not Palindrome"<<endl;
	getch();
}


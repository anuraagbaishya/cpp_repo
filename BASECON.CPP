#include<iostream.h>
#include<conio.h>
#include<process.h>

class Stack
{
	int top;
	int arr[10];
	public:
	Stack()
	{
		top=-1;
	}
	void push(int item)
	{
		if(top>9)
			cout<<"Stack is full";
		else
		{
			arr[++top]=item;
		}
	}
	int pop()
	{
		int item;
		if(top<0)
		cout<<"Stack is empty";
		else
		{
			item=arr[top--];
		}
		return item;
	}
	int return_top()
	{
		if(top==-1)
			return 0;
		else
			return 1;
	}
};
void main()
{
	clrscr();
	Stack stkbin,stkoct,stkhex;
	int num,n;
	cout<<"Enter number: "<<endl;
	cin>>num;
	n=num;
	while(num>0)
	{
		stkbin.push(num%2);
		num=num/2;
	}
	num=n;
	while(num>0)
	{
		stkoct.push(num%8);
		num=num/8;
	}
	num=n;
	while(num!=0)
	{
		stkhex.push(num%16);
		num=num/16;
	}
	cout<<"Number in Binary: ";
	while(stkbin.return_top())
		cout<<stkbin.pop();
	cout<<endl;
	cout<<"Octal number: ";
	while(stkoct.return_top())
		cout<<stkoct.pop();
	cout<<endl;
	cout<<"Hexadecimal number: ";
	while(stkhex.return_top())
	{
	     int x=stkhex.pop();
	     if(x==10)
		cout<<"A";
	     else if(x==11)
		cout<<"B";
	     else if(x==12)
		cout<<"C";
	     else if(x==13)
		cout<<"D";
	     else if(x==14)
		cout<<"E";
	     else if(x==15)
		cout<<"F";
	     else
		cout<<x;
	}
	getch();
}


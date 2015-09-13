#include<iostream>
#include<stdio.h>
#define max 20
using namespace std;
const int maxs=10;
class mul_stack
{
	int s[max];
	int b[maxs],top[maxs];
	public:
		void push();
		int pop();
		void display();
		void create(int);
};

void mul_stack::push()
{
	int i,item;
	cout<<"Enter the stack number: ";
	cin>>i;
	cout<<"Enter the item to insert: ";
	cin>>item;
	if(top[i-1]==b[i])
	{
		cout<<"The stack is full: ";
		return;
	}
	else
		s[++top[i-1]]=item;
}
int mul_stack::pop()
{
	int i;
	cout<<"Enter the stack number: ";
	cin>>i;
	if(top[i-1]==b[i-1])
	return -1;
		else
	return s[top[i-1]--];
}
void mul_stack::display()
{
	int i ;
	cout<<"Enter the stack number: ";
	cin>>i;
	if(top[i-1]==b[i-1])
	{
		cout<<"Stack "<<i<<" is empty";
		return;
	}
	cout<<"Contents of stack "<<i<<": ";
	for(int k=b[i-1]+1;k<=top[i-1];k++)
	cout<<s[k];
}

void mul_stack::create(int n)
{
	for(int j=0;j<n;j++)
	{
		b[j]=top[j]=(max/n)*j-1;
	}
	b[n]=max-1;
}
int main()
{
	mul_stack ms;
	int ch,j,n,item;
	cout<<"Enter the number of stacks: ";
	cin>>n;
	ms.create(n);
	for(;;)
	{
		cout<<"\n1.push  \n2.pop  \n3.display  \n4.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:ms.push();
			break;
			case 2:
			item=ms.pop();
			if(item==-1)
				cout<<"Stack empty";
			else
				cout<<"Deleted item: "<<item;
			break;
			case 3: ms.display();
			break;
			case 4:
		}
	}
	return 0;
}



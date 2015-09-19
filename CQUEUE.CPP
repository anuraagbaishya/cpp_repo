#include<iostream>
//#include<process.h>
#define MAXSIZE 10
using namespace std;
class Queue
{
	int arr[MAXSIZE];
	int front,rear;
	public:
	Queue()
	{
		front=rear=0;
	}
	void insert(int item)
	{
		if((rear+1)%MAXSIZE==rear)
			cout<<"Queue Full\n";
		else
		{
			arr[rear]=item;
			rear=(rear+1)%MAXSIZE;
		}
	}
	int remove()
	{
		int i;
		if(rear==front)
		{
			cout<<"Queue empty\n";
			return -1;
		}
		else
		{
			i=arr[front];
			front=(front+1)%MAXSIZE;
			return i;
		}
	}
	void display()
	{
		for(int i=front;i!=rear;i=(i+1)%MAXSIZE)
			cout<<arr[i]<<endl;
	}
};
int main()
{
	//clrscr();
	Queue q;
	int ch;
	for(;;)
	{
		int item;
		cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter element: \n";
				cin>>item;
				q.insert(item);
				break;
			case 2:
				item=q.remove();
				if(item!=-1)
					cout<<item<<" removed.\n";
				break;
			case 3:
				q.display();
				break;
			case 4:
				break;
				//exit(0);
		 }
	}
}

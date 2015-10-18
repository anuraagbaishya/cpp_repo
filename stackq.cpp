#include<iostream>
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
		int retop()
		{
            return top;
		}
		int isEmpty()
		{
            if (top==-1)
                return 1;
            else
                return 0;
		}
		int isFull()
		{
            if (top==19)
                return 1;
            else
                return 0;
		}
		void resettop()
		{
            top=-1;
		}

};
int main()
{
    int ch,y,x;
    Stack s,s2;
    x=s.retop();
    do{
        char n;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter: ";
            cin>>n;
            if(s2.isEmpty()&&!s.isFull()){
                s.push(n);
            }
            else if(!s.isFull()&&s2.retop()<20)
            {
                y=s2.retop();
                s.resettop();
                for(int i=0;i<=y;i++)
                {
                    s.push(s2.pop());
                }
                s.push(n);
            }
            else if(s.isFull()||s2.isFull())
                cout<<"Queue Full\n";
            break;
            case 2:
            x=s.retop();
            for(int i=0;i<=x;i++)
                 s2.push(s.pop());
            if(s2.isEmpty())
                cout<<"Queue Empty\n";
            else
                cout<<s2.pop()<<" deleted \n";
            break;
        }
    }while(ch!=3);
}

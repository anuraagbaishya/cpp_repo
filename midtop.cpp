#include<iostream>
using namespace std;
class stack
{
	int top1,top2;
	int arr[20];
	public:
		stack()
		{
			top1=-1;
			top2=20;
		}
		void push(int stkno,int num)
		{
			if(stkno==1&&top1<9)
				arr[++top1]=num;
            else if(stkno==1&&top1>=9)
                cout<<"Stack full";
            else if(stkno==2&&top2>=10)
                arr[--top2]=num;
			else if(stkno==2&&top2<10)
                cout<<"Stack full";
		}
		int pop(int stkno)
		{
			int num;
			if(stkno==1&&top1<0)
                return -1;
			else if(stkno==1)
			{
				num=arr[top1--];
				return num;
			}
			else if(stkno==2&&top2>19)
                return -1;
            else if(stkno==2)
            {
                num=arr[top2++];
                return num;
            }
            else
                return -2;
		}
		void display(int stkno)
		{
			if(stkno==1)
			{
                for (int i=0;i<top1;i++)
                {
                    cout<<arr[i]<<endl;
                }
            }
            else if(stkno==2)
			{
                for (int i=19;i>top2;i--)
                {
                    cout<<arr[i]<<endl;
                }
            }
		}
};
int main()
{
    stack stk;
    int no,item,ch;
    do
	{
		cout<<"\n\n1.push  \n2.pop  \n3.display  \n4.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
                cout<<"Enter stack no: ";
                cin>>no;
                cout<<"Enter item: ";
                cin>>item;
                stk.push(no,item);
                break;
			case 2:
                cout<<"Enter stack no: ";
                cin>>no;
                item=stk.pop(no);
                if(item==-1)
                    cout<<"Stack "<<no<<" empty\n";
                else if(item==-2)
                    cout<<"No such stack\n";
                else
                    cout<<"Deleted item: "<<item;
                break;
			case 3:
                cout<<"Enter stack no: ";
                cin>>no;
                stk.display(no);
                break;
		}
	}while(ch!=4);
	return 0;
}

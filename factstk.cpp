#include<iostream>
using namespace::std;
class stack
{
    int top, item, a[20];
    public:
            stack()
            {
                top=-1;
            }
            void push(int n)
            {
                a[++top]=n;
            }
            int pop()
            {
                return a[top--];
            }
            int factorial(int x)
            {
                for(int i=1; i<=x; i++)
                push(i);
                int a, fact=1;
                while(top!=-1)
                {
                    a=pop();
                    fact*=a;
                }
                return fact;
            }
};
int main()
{
    stack s;
    int n,np, nc, r,ch;
    do{
        cout<<"\n\n1.nCr\n2.nPr\n3.Exit\n\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter a number:\n";
            cin>>n;
            cout<<"Enter r:\n";
            cin>>r;
            if(n<r)
                cout<<"Operation Not Possible";
            else
                cout<<(s.factorial(n)/((s.factorial(r))*s.factorial(n-r)));
            break;
            case 2:
            cout<<"Enter a number\n";
            cin>>n;
            cout<<"\nEnter r:";
            cin>>r;
            if(n<r)
                cout<<"Operation Not Possible";
            else
                cout<<(s.factorial(n)/s.factorial(n-r));
        }
    }while(ch!=3);
    return 0;
}


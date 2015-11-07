#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *create(node *,int);
	node *trav(node *);
	node *mergelist(node *,node *);
	node *merge(node *,node *);
};
node* node::create(node *first,int a)
{
    node *cu=first;
    if(cu==NULL)
    {
        cu=new node;
        cu->data=a;
        cu->next=NULL;
        return cu;
    }
    else
    {
        while(cu->next!=NULL)
            cu=cu->next;
        node *temp=new node;
        temp->data=a;
        temp->next=NULL;
        cu->next=temp;
    }
    return first;
}
node* node::trav(node *first)
{
	node *cur=first;
	if(cur!=NULL)
	{
		while(cur!=NULL)
		{
			cout<<cur->data;
			if(cur->next!=NULL)
				cout<<"--";
			cur=cur->next;
		}
		cout<<endl;
	}
	else
		cout<<"Empty list\n";
}
node* node::mergelist(node *first,node *second)
{
    node *result=NULL;
    if(first==NULL)
        return second;
    else if(second==NULL)
        return first;
    if(first->data<second->data)
    {
        result=first;
        result->next=mergelist(first->next,second);
    }
    else
    {
        result=second;
        result->next=(mergelist(second->next,first));
    }
    return result;
}
int main()
{
	node *x=NULL, *y=NULL,*z=NULL;
	node l;
	int n,i=0,a;
	cout<<"Enter no of elements in list 1:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Data: ";
		cin>>a;
		x=l.create(x,a);
	}
	cout<<endl<<"Entered List:"<<endl;
	l.trav(x);
	cout<<"Enter no of elements in list 2:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Data: ";
		cin>>a;
		y=l.create(y,a);
	}
	cout<<endl<<"Entered List: "<<endl;
	l.trav(y);
	z=l.mergelist(x,y);
	l.trav(z);
}

#include<iostream>
//#include<conio.h>
#define NULL 0
using namespace std;
class list
{
	public:
	int data;
	list *next;
	list* insert(list*,int a);
	list* insert1(list*,int a,int b);
	list* insert2(list*, int a,int b);
	list* del(list*, int a);
	list* rev(list*);
	list* traverse(list*);
	list* sort(list*);
	list* del1(list*);
	list* insert3(list*,int a);
};
	list* list::insert(list* first,int a)
	{
	       list *cu=first;
	       if(cu==NULL)
	       {
	       cu = new list();
	       cu->data=a;
	       cu->next=NULL;
	       return cu;
	       }
	       else
	       {
	       while(cu->next!=NULL)
			cu=cu->next;
	       list* temp = new list();
	       temp->data=a;
	       temp->next=NULL;
	       cu->next=temp;
	       }
	       return first;
	}
	list* list:: insert1(list* first,int a,int b)
	{       int flag=0;
		list *cu=new list;
		cu=first;

		while(cu!=NULL)
		{       if(a==cu->data)
			{
				flag=1;
				list *temp=new list;
				temp->data=b;
				temp->next=cu->next;
				cu->next=temp;
				break;
			}
			cu=cu->next;
		}
		 if(flag==0)
		 cout<<"not found";
		 return first;
	}
	  list* list:: insert2(list* first,int a,int b)
	{       int flag=0;
		list *cu=new list;
		cu=first;
		if(first->data==a)
		{ list *temp=new list;
		  temp->data=b;
		  temp->next=first;
		  return temp;
		}
		list *pre=NULL;
		pre->next=cu;
		while(cu!=NULL)
		{
		 if(a==cu->data)
			{
				flag=1;
				list *temp=new list;
				temp->data=b;
				temp->next=cu;
				pre->next=temp;
				break;
			}pre=cu;
			cu=cu->next;
			}
		 if(flag==0)
		 cout<<"not found";
		 return first;
	  }
	  list* list:: del(list* first,int a)
	  {
		int flag=0;
		list *temp=new list;
		temp=first;
		if(first->data==a)
		{ list *temp=first->next;
		delete first;
		  return temp;
		}
		list*pre=NULL;
		pre->next=temp;

		while(temp!=NULL)
		{
		      if(temp->data==a)
		       {
		       flag=1;
		       pre->next=temp->next;
		       cout<<"Deleted";
		       delete temp;

			}
		       else
		       { pre=temp;
		       temp=temp->next;
		       }
		 }
		 if(flag==0)
		  cout<<"Not found";
		  return first;
	  }
	 list* list:: traverse(list* first)
	 {
		list *temp=new list;
		temp=first;
		if(temp==NULL)
		{
		cout<<"Empty";
		return first;
		}
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
		return first;
	 }
	 list* list:: rev(list* first)
	 {
		list *cu=new list;
		cu=first;
		list *pre=NULL;
		pre->next=cu;
		if(first==NULL)
		{
		cout<<"Empty";
		 return first;
		 }
		else
		{
			while(cu!=NULL)
			{   list* temp=cu->next;
			       cu->next=pre;
				pre=cu;
				cu=temp;
			}
			cout<<"reversed";
		 }
		 return pre;
	}
	list* list::sort(list* first)
	{
		list *cu=new list;
		cu=first;
		if(cu==NULL)
		{
		cout<<"Empty";
		return first;
		}
		else
		{

		while(cu!=NULL)
		{ list *temp=cu->next;
			while(temp!=NULL)
			{
				if(temp->data<cu->data)
				{
					int a=temp->data;
					temp->data=cu->data;
					cu->data=a;
				}
				temp=temp->next;
		}cu=cu->next;
		    }
		cout<<"sorted";
		return first;
	}

	}
	list* list:: del1(list* first)
	{
		list *cu=new list;
		cu=first;
		if(cu==NULL)
		{
		cout<<"Empty";
		return first;
		}
		else
		{
			while(cu!=NULL)
			{
				list *temp=cu->next;
				cu->next=temp->next;
				cu=cu->next;
				delete temp;

			}
			cout<<"deleted";
		 }
		 return first;
	}
	 list* list:: insert3(list* first,int a)
	 {
		list *cu=new list;
		list *pre=NULL;

		cu=first;
		pre->next=cu;
		if(first->data>a)
		{ list *temp=new list;
		  temp->data=a;
		  temp->next=first;
		  return temp;
		}
		while(cu!=NULL&&cu->data<a)
		{ pre=cu;
		cu=cu->next;
		}
		list *temp=new list;
		temp->data=a;
		temp->next=cu;
		pre->next=temp;
		return first;
	 }


int main()
{
//	clrscr();
	int a;
	list l;
	list* first=NULL;
	int item,i;
	do
	{
	cout<<"\n Enter choice \n 1-insert \n 2-insert after \n 3-insert before \n 4-display \n 5-delete \n 6-revere \n 7-sort \n 8-delete alternate \n 9-insert in sorted \n 10-exit \n";
	cin>>a;
	switch(a)
	{
		case 1:cout<<"Enter item";

			cin>>item;
			first=l.insert(first,item);
			break;
		case 2:cout<<"Enter item";

			cin>>item;
			cout<<"Enter after element";
			cin>>i;
			first=l.insert1(first,i,item);
			break;
		case 3:cout<<"Enter item";
			cin>>item;
			cout<<"Enter before element";
			cin>>i;
		       first=	l.insert2(first,i,item);
			break;
		case 4:first=l.traverse(first);
		break;
		case 5:cout<<"Enter item";
			cin>>item;
		       first=l.del(first,item);
			break;
		case 6:first=l.rev(first);
		break;
		case 7:first=l.sort(first);
		break;
		case 8:first=l.del1(first);
			break;
		case 9:cout<<"Enter item";
			cin>>item;
		       first=l.insert3(first,item);
			break;
		case 10:break;
		default:cout<<"Wrong entry";
	}
      }  while(a!=10);
//      getch();
}


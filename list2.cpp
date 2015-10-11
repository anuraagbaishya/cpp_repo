#include<iostream>

//#include<conio.h>

#include<stdio.h>
using namespace std;

class node{ int data;

	    node *next;

	    node *head, *tail;

	   public:

	    node()

	    {head = NULL;

	     tail = NULL;

	    }

	    void insert();

	    void disp();

	    void del_odd();

	    void rev();

	  };

void node::insert()

{node *temp = new node;

 temp->next = NULL;

 cout<<"enter value"<<endl;

 cin>>temp->data;

 if(head!=NULL && tail!=NULL)

 {tail->next=temp;

  tail=temp;

 }

 else

   tail=head=temp;

}

void node::disp()

{node *temp=head;

 if(temp==NULL)

   cout<<"empty!"<<endl;

 while(temp!=NULL)

 {cout<<temp->data<<"\t";

  temp=temp->next;

 }

}

void node::del_odd()
{
    node *temp=head, *tempr;
    tempr=NULL;

 /*while(head->data%2!=0)

 {

  head=head->next;

  temp=temp->next;

 }*/

 while(temp!=NULL)
 {
    if(temp->data%2!=0)
    {
        node *d=temp;
        tempr->next=temp->next;
        temp=temp->next;
        delete(d);

    }
    else
    {
        tempr=temp;
        temp=temp->next;

    }

}

}

void node::rev()

{node *temp=head,*t, *r, *tempr;

 int count=0 , a=0 , c=1;

 tempr = NULL;

 while(temp!=NULL)

 {temp=temp->next;

  count++;

 }

 tempr =NULL;

 a=count/2;

 temp=head;

 while(c<=a)

 {tempr=temp;

  temp=temp->next;

  c++;

 }

 t=tempr;

 while(temp!=NULL)

 {r=temp->next;

  temp->next=tempr;

  tempr=temp;

  temp=r;

 }

 t->next=tempr;

 while(tempr->next!=t)

 {tempr=tempr->next;}

 tempr->next=NULL;

}

int main()

{node obj;

 int ch,n;

// clrscr();

 cout<<"enter no. of elements:-"<<endl;

 cin>>n;

 for(int i=0 ; i<n ; i++)

    obj.insert();

 obj.disp();

 cout<<endl;

 //obj.rev();

 //obj.disp();

 obj.del_odd();

 obj.disp();

// getch();

}

#include<iostream>
//#include<stdlib.h>
#include<stdio.h>
using namespace std;
class node
{
    int data;
    node *next, *prev;
    node *tail,*tail1,*tail2;
    int count;
    public:
    node()
    {
        //header=NULL;
        // head = NULL;
        tail=tail1=tail2 = NULL;
        count=0;
    }
    void insert();
    void disp(node*);
    void meth(node*);
    void display(node*);
};
node *h1,*h2,*head;
int main()
{
    node obj;
    int n;
    cout<<"enter no. of elements:-"<<endl;
    cin>>n;
    for(int i=0 ;
    i<n ;
    i++)
    obj.insert();
    obj.disp(head);
    obj.meth(head);
    //obj.disp(h1);
    obj.display(h2);
    cout<<endl;
    return 0;
}
// return 0;
void node::insert()
{
    node *temp = new node;
    temp->next = NULL;
    cout<<"enter value"<<endl;
    cin>>temp->data;
    if(head!=NULL && tail!=NULL)
    {
        tail->next=temp;
        temp->prev=tail;
        temp->next=head;
        head->prev=temp;
        tail=temp;
        count++;
        head->data=count;
    }
    else
    {
        head=new node();
        tail=temp;
        head->next=temp;
        temp->prev=head;
        temp->next=head;
        head->prev=temp;
        count++;
        head->data=count;
    }
    // cout<<tail->next->data<<"n";
}
void node::disp(node* head)
{
    node *temp=head;
    if(count==0)
    {
        cout<<"empty!"<<endl;
        return;
    }
    //cout<<temp->data<<"t";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void node::display(node* head)
{
    node *temp=head;
    if(temp==NULL)
    {
        cout<<"empty!"<<endl;
        return;
    }
    //cout<<temp->data<<"t";
    while(temp!=head)
    {
        cout<<temp->data<<"t";
        temp=temp->next;
    }
    cout<<endl;
}
void node::meth(node *head)
{
    node* t=new node;
    h1=new node;
    tail1=new node;
    t=head->next;
    int coun=2;
    while(t!=head)
    {
        node *m=t;
        if(coun%2==0)
        {
            if(h1==NULL)
            {
                h1=tail1=m;
                h1->next=NULL;
            }
            else
            {
                tail1->next=m;
                tail1=m;
            //    tail1->next=h1;
            }
        }
        else
        {
            if(h2==NULL)
            {
                h2=tail2=m;
                //h2->next=NULL;
            }
            else
            {
                tail2->next=m;
                tail2=m;
              //  tail2->next=h2;
            }
        }
        t=t->next;
        coun++;
    }
}

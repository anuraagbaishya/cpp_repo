#include<iostream>
//#include<conio.h>
using namespace std;
class node
{
    int data;
    node *next;
    public:
    node* insbef(node *);
    node* insaft(node *);
    node* del(node *);
    node* trav(node *);
    node* create(node *,int);
    node* rev(node *);
    node* sort(node *);
    node* delalt(node *);
    node* sortord(node *);
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
node* node::insbef(node *first)
{
    int n,flag=0;
    node *current,*prev,*temp;
    temp=new node;
    if(first!=NULL)
    {
        cout<<"Enter data: ";
        cin>>temp->data;
        cout<<"Enter element to insert before: ";
        cin>>n;
        if(first->data==n)
        {
            temp->next=first;
            first=temp;
            flag=1;
        }
        else
        {
            for(prev=first,current=first->next;current!=NULL;current=current->next,prev=prev->next)
            {
                if(current->data==n)
                {
                    temp->next=current;
                    prev->next=temp;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"Not Found ";
            }
        }
    }
    else
    {
        cout<<"List Empty n";
    }
    return first;
}
node* node::insaft(node *first)
{
    int n,flag=0;
    node *cur=new node;
    cur=first;
    if(first!=NULL)
    {
        node *temp=new node;
        cout<<"Enter element to insert after: ";
        cin>>n;
        cout<<"Enter data: ";
        cin>>temp->data;
        while (cur!=NULL)
        {
            if(cur->data==n)
            {
                flag=1;
                temp->next=cur->next;
                cur->next=temp;
                break;
            }
            cur=cur->next;
        }
        if(flag==0)
        cout<<"Element not found \n";
    }
    else
        cout<<"List Empty n";
    return first;
}
node* node::del(node *first)
{
    int flag=0;
    int n;
    node *temp=new node;
    temp=first;
    node *prev=NULL;
    cout<<"Enter element to delete: ";
    cin>>n;
    if(first->data==n)
    {
        temp=first->next;
        delete first;
        return temp;
    }
    prev->next=temp;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            flag=1;
            prev->next=temp->next;
            delete temp;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    if(flag==0)
        cout<<"Not Found\n";
}
node* node::trav(node *first)
{
    node *cur=new node;
    cur=first;
    if(first!=NULL)
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
    cout<<"List Empty \n";
    return first;
}
node* node::rev(node *first)
{
    node *temp,*current;
    current=first->next;
    first->next=NULL;
    while(current!=NULL)
    {
        temp=current;
        current=current->next;
        temp->next=first;
        first=temp;
    }
}
node* node::sort(node *first)
{
    node *current=new node;
    current=first;
    while(current!=NULL)
    {
        node *temp=current->next;
        while(temp!=NULL)
         {
            if(temp->data<current->data)
            {
                int t=temp->data;
                temp->data=current->data;
                current->data=t;
            }
            temp=temp->next;
        }
        current=current->next;
    }
    return first;
}
node* node::delalt(node *first)
{
    node *current=new node;
    current=first;
    if(current==NULL)
    {
        cout<<"Empty\n";
        return first;
    }
    else
    {
        while(current!=NULL)
        {
            node *temp=current->next;
            current->next=temp->next;
            current=current->next;
        }
    }
    return first;
}
node* node::sortord(node *first)
{
    node *current=new node;
    current=first;
    node *prev,*temp=new node;
    prev->next=current;
    int n,flag=0;
    cout<<"Enter Data: ";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    if(n<first->data)
    {
        temp->next=first;
        return temp;
    }
    else
    {
        while(current!=NULL)
        {
            if(prev->data<n && current->data>n)
            {
                flag=1;
                break;
            }
            prev=current;
            current=current->next;
        }
        if(flag==0)
        {
            current->next=temp;
        }
        else
        {
            prev->next=temp;
            temp->next=current;
        }
    }
    return first;
}
int main()
{
    //clrscr();
    int ch;
    char ch2,ch3;
    node l;
    node *first=NULL;
    cout<<"\n1)Create \n2)Insert Before\n";
    cout<<"3)Insert After\n4)Delete\n";
    cout<<"5)Traverse\n6)Reverse\n7)Sort\n8)Delete Alternate\n9)Insert Ordered\n10 Exit\n";
    do
    {
        //clrscr();
        int i;
        cout<<endl<<endl<<"Enter Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter item: ";
                cin>>i;
                first=l.create(first,i);
            }
            break;
            case 2:first=l.insbef(first);
            break;
            case 3:first=l.insaft(first);
            break;
            case 4:first=l.del(first);
            break;
            case 5:first=l.trav(first);
            break;
            case 6:first=l.rev(first);
            break;
            case 7:first=l.sort(first);
            break;
            case 8:first=l.delalt(first);
            break;
            case 9:first=l.sortord(first);
            break;
            case 10: break;
            default: cout<<"Wrong Choice\n";
        }
    }
    while(ch!=10);
    //delete first;
    //  getch();
}

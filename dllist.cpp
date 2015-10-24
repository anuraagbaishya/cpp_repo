/*
 * C++ Program to Implement Doubly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class node
{
    int info;
    node *next;
    node *prev;
    public:
        node* create_list(node *start,int value);
        node* add_begin(node *start,int value);
        node* add_after(node *start,int value, int position);
        node* delete_element(node *start,int value);
        void search_element(node *start,int value);
        void display_dlist(node *start);
        void count(node *start);
        node* reverse(node *start);
};

/*
 * Main: Conatins Menu
 */
int main()
{
    node *start=NULL;
    int choice, element, position;
    node dl;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            start=dl.create_list(start,element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            start=dl.add_begin(start,element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dl.add_after(start,element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout<<"List empty,nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_element(start,element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist(start);
            cout<<endl;
            break;
        case 6:
            dl.count(start);
            break;
        case 7:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            start=dl.reverse(start);
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}

/*
 * Create Double Link List
 */
node* node::create_list(node *start,int value)
{
    node *s, *temp;
    temp = new node;
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
    return start;
}

/*
 * Insertion at the beginning
 */
node* node::add_begin(node *start,int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return NULL;
    }
    node *temp;
    temp = new node;
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
    return start;
}

/*
 * Insertion of element at a particular position
 */
node* node::add_after(node *start,int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return NULL;
    }
    node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return NULL;
        }
    }
    tmp = new node;
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
    return start;
}

/*
 * Deletion of element from the list
 */
node* node::delete_element(node *start,int value)
{
    node *tmp, *q;
     /*first element deletion*/
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        delete tmp;
        return start;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            delete tmp;
            return start;
        }
        q = q->next;
    }
     /*last element deleted*/
    if (q->next->info == value)
    {
        tmp = q->next;
        delete tmp;
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return start;
    }
    cout<<"Element "<<value<<" not found"<<endl;
    return start;
}

/*
 * Display elements of Doubly Link List
 */
void node::display_dlist(node *start)
{
    node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}

/*
 * Number of elements in Doubly Link List
 */
void node::count(node *start)
{
    node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}

/*
 * Reverse Doubly Link List
 */
node* node::reverse(node *first)
{
    node *temp,*current;
    current=first->next;
    first->next=NULL;
    while(current!=NULL)
    {
        temp=current;
        current=current->next;
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
    return first;
}

#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
    public:
    int info;
    node *next;
};
class Queue
{
    private:
    node *rear;
    node *front;
    public:
    Queue();
    void enqueue();
    void dequeue();
    void display();
};
Queue::Queue()
{
    rear = NULL;
    front = NULL;
}
void Queue::enqueue()
{
    int data;
    node *temp = new node;
    cout<<"Enter the data to enqueue: ";
    cin>>data;
    temp->info = data;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}
void Queue::dequeue()
{
    node *temp = new node;
    if(front == NULL)
    {
        cout<<"Queue is Emtpty\n";
    }
    else
    {
        temp = front;
        front = front->next;
        cout<<"The data Dequeued is "<<temp->info;
        delete temp;
    }
}
void Queue::display()
{
    node *p = new node;
    p = front;
    if(front == NULL)
    {
        cout<<"Nothing to Display\n";
    }
    else
    {
        while(p!=NULL)
        {
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}
int main()
{
    Queue *queue=new Queue();
    int choice;
    while(true)
    {
        cout<<"1.Enqueue 2. Dequeue 3. Display 4.Quit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            queue->enqueue();
            break;
            case 2:
            queue->dequeue();
            cout<<endl;
            break;
            case 3:
            queue->display();
            cout<<endl;
            break;
            case 4:
            exit(0);
            break;
            default:
            cout<<"Invalid Input. Try again!";
            break;
        }
    }
    return 0;
}

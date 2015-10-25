#include <cstdlib>
#include <iostream>
using namespace std;

class node
{
 public:
    int data;
    node* next;
};

class StackusingList
{
  private:
      node *top;
      int count; //head
      int maxnum;
  public:
  StackusingList(int max)
  {
      top = NULL;
      maxnum = max;
      count=0;
  }
  void push(int element)
  {
      if(count == maxnum)
              cout<<"stack is full";
      else
      {
          node *newTop = new node;
          if(top == NULL)
          {
              newTop->data = element;
              newTop->next = NULL;
              top = newTop;
              count++;
          }
          else
          {
              newTop->data = element;
              newTop->next = top;
              top = newTop;
              count++;
          }
      }
  }

  void pop()
  {
      if(top == NULL)
              cout<< "nothing to pop";
      else
      {
          node * old = top;
          cout<<top->data<<" popped\n";
          top = top->next;
          count--;
          delete(old);
      }
  }
  void print()
  {
      node *temp;
      temp = top;
      while(temp!=NULL)
      {
          cout<<temp->data<<",";
          temp=temp->next;
      }
  }
};

int main() {
    int max,a;
    std::cout << "Enter no of elements" << std::endl;
    std::cin >> max;
    StackusingList *sl=new StackusingList(max);
    std::cout << "Enter elements" << std::endl;
    for (int i=0;i<max;i++) {
      cin>>a;
      sl->push(a);
    }
    sl->pop();
    cout<<"new stack\n";
    sl->print();
    return 0;
}

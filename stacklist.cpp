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
  public:
  StackusingList()
  {
      top = NULL;
  }
  void push(int element)
  {
          node *newTop = new node;
          if(top == NULL)
          {
              newTop->data = element;
              newTop->next = NULL;
              top = newTop;
          }
          else
          {
              newTop->data = element;
              newTop->next = top;
              top = newTop;
              //count++;
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
          //count--;
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
    int ch,a;
    StackusingList *sl=new StackusingList();
    do{
        std::cout<<"1.Push 2.Pop 3.Display 4.Exit\n";
        std::cin>>ch;
        switch(ch)
        {
            case 1:
            std::cout << "Enter elements" << std::endl;
            cin>>a;
            sl->push(a);
            break;
            case 2:
            sl->pop();
            break;
            case 3:
            sl->print();
            std::cout<<"\n";
            break;
        }
    }while(ch!=4);
    return 0;
}

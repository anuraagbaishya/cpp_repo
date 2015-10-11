#include<iostream>
//#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
class node{ int marks;
	    char name[20];
	    int reg_no;
	    node *next;
	    node *head;
	    node *tail;
	   public:
	    node()
	    { head = NULL;
	      tail = NULL;
	    }
	    void insert();
	    void disp();
	    void Sort();
	  };
void node::insert()
{node *temp = new node;
 temp->next = NULL;
 cout<<"enter name : ";
 cin>>temp->name;
 cout<<"enter registration no. : ";
 cin>>temp->reg_no;
 cout<<"enter marks :";
 cin>>temp->marks;
 if(head!=NULL && tail!=NULL)
 {tail->next = temp;
  tail = temp;
 }
 else
   tail=head=temp;
}
void node::disp()
{node *temp = head;
 if(temp==NULL)
   cout<<"empty!"<<endl;
 while(temp!=NULL)
 {cout<<"name : "<<temp->name<<endl;
  cout<<"registration no : "<<temp->reg_no<<endl;
  cout<<"marks : "<<temp->marks<<endl;
  temp=temp->next;
 }
}
void node::Sort()
{
    int s;
 do
 { int t; char n[20];
   node *temp = head;
   s=0;
   while(temp!=NULL)
   { if(temp->reg_no > temp->next->reg_no)
     { t = temp->reg_no;
       temp->reg_no = temp->next->reg_no;
       temp->next->reg_no = t;
       int m = temp->marks;
       temp->marks = temp->next->marks;
       temp->next->marks = m;
       strcpy(n,temp->name);
       strcpy(temp->name,temp->next->name);
       strcpy(temp->next->name,n);
       s=1;
     }

     temp = temp->next;
   }
 }while(s);
}
int main()
{node obj;
 int n;
// clrscr();
 cout<<"no. of students : ";
 cin>>n;
 for(int i=0 ; i<n ; i++)
    obj.insert();
 obj.disp();
 cout<<"log";
 obj.Sort();
 cout<<"After Sorting :-"<<endl;
 obj.disp();
 //getch();
}

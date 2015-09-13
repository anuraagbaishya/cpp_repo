#include<iostream>
#include<stdio.h>
using namespace std;
int instack(char c){
    switch(c){
        case '#':
        return -1;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '$':
        return 3;
        case '(':
        return 0;
    }
}
int infixp(char c){
    switch(c){
        case '#':
        return -1;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '$':
        return 4;
        case '(':
        return 5;
        case ')':
        return 6;
    }
}
class Stack
{
	int top;
	char arr[20];
	public:
		Stack()
		{
			top=-1;
		}
		void push(char ch)
		{
			if(top>19)
				cout<<"Stack is full";
			else
			{
				arr[++top]=ch;
			}
		}
		char pop()
		{
			char ch;
			if(top<0)
			cout<<"Stack is empty";
			else
			{
				ch=arr[top--];
			}
			return ch;
		}
		char stktop()
		{
            return arr[top];
		}
};
int main()
{
  Stack stk;
  int i=0,j=0;
  char c,d;
  char postfix[20],infix[20];
  gets(infix);
  stk.push('#');
  while(infix[i]!='\0'){
    c=infix[i];
    if((c>=97&&c<=122)||(c>=65&&c<=90)||(c>=48&&c<=57))
        postfix[j++]=c;
    else if(infix[i]==')'){
        while(stk.stktop()!='(')
            postfix[j++]=stk.pop();
        stk.pop();
    }
    else
    {
        while(instack(stk.stktop())>=infixp(infix[i]))
            postfix[j++]=stk.pop();
        stk.push(infix[i]);
    }
    i++;
  }
  while(stk.stktop()!='#')
    postfix[j++]=stk.pop();
  postfix[j]='\0';
  puts(postfix);
  return 0;
}

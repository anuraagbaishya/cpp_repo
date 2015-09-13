#include<iostream>
#include <stdio.h>
#include <string.h>
#define MAX 20
using namespace std;
class Stack
{
    int stk[MAX];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
    void push(char ch)
    {
        if(top>MAX-1)
        {
            cout<<"Stack Full";
        }
        else
            stk[++top]=ch;
    }
    char pop()
    {
        if(top==-1)
        {
            cout<<"Stack Empty";
        }
        else
            return stk[top--];
    }
    char retop()
    {
        return(stk[top]);
    }
};
void infixtoprefix(char infix[20],char prefix[20]);
void reverse(char array[30]);
int isOperator(char ch);
int prcd(char ch);
int main()
{
	char infix[20],prefix[20],temp;
	printf("Enter infix operation: ");
	gets(infix);
	infixtoprefix(infix,prefix);
	reverse(prefix);
	puts((prefix));
	return 0;
}
//--------------------------------------------------------
void infixtoprefix(char infix[20],char prefix[20])
{
	Stack stck;
	int i,j=0;
	char ch;
	stck.push('#');
	reverse(infix);
	for (i=0;i<strlen(infix);i++)
	{
		ch=infix[i];
		if (!isOperator(ch))
		{
			prefix[j]=ch;
			j++;
		}
		else if(ch==')')
			stck.push(ch);
        else if(ch == '(')
        {
            while (stck.retop()!=')')
            {
                prefix[j++]=stck.pop();
            }
            stck.pop();
        }
        else
        {
            if (prcd(stck.retop())<=prcd(ch))
            {
                stck.push(ch);
            }
            else
            {
                while(prcd(stck.retop())>=prcd(ch))
                {
                    prefix[j]=stck.pop();
                    j++;
                }
                stck.push(ch);
            }
				//end for else
        }
    }
	while (stck.retop()!='#')
	{
		prefix[j]=stck.pop();
		j++;
	}
	prefix[j]='\0';
}
////--------------------------------------------------------
void reverse(char array[30]) // for reverse of the given expression {
{
    int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j)
	{
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}
//------------------------------------------
int prcd(char ch) // returns the value that helps in the precedence {
{	switch(ch) 
	{
		case '+':
        case '-':
		return 2;
		break;
		case '*':
        case '/':
		return 4;
		break;
		case '$':
        case '^':
        return 6;
		break;
		case '#':
        case '(':
        case ')':
        return 1;
		break;
	}
}
//-------------------------------------------------
int isOperator(char ch) {
	switch(ch) {
		case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        return 1;
		break;
		default:
		        return 0;
		// returns 0 if the ch is other than given above
	}
}

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char str1[80],str2[80];
	int count=0,pos,flag=0;
	cout<<"Enter a string"<<endl;
	gets(str1);
	cout<<"Enter search string"<<endl;
	gets(str2);
	for(int i=0;i<strlen(str1);i++)
	{
		int x=i;
		if(str1[i]==str2[0])
		{
			count=1;
			pos=x;
			x++;
			for(int j=1;j<strlen(str2);j++)
			{
				if(str1[x++]==str2[j])
				{
					count++;
				}
				else
					break;
			}
		}
		if(count==strlen(str2))
		{
			flag=1;
			break;
		}
		else
			count==0;
	}
	if(flag==0)
		cout<<"Not found";
	else
		cout<<"Found at: "<<pos;
	getch();
}
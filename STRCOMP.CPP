#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char str1[80],str2[80];
	int count=0;
	cout<<"Enter 2 strings"<<endl;
	gets(str1);
	gets(str2);
	int minlen=strlen(str1)<strlen(str2)?strlen(str1):strlen(str2);
	for(int i=0;i<minlen;i++)
	{
		if(str1[i]==str2[i])
			continue;
		else
			count=((int)str1[i]-(int)str2[i]);
	}
	if(count==0)
		cout<<"Strings equal";
	else
		cout<<"Difference: "<<count;
	getch();
}
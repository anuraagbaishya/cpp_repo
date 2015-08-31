#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char str1[80],str2[80],str3[160];
	cout<<"Enter 2 strings"<<endl;
	gets(str1);
	gets(str2);
	strcpy(str3,str1);
	for(int i=strlen(str1),j=0;str2[j]!='\0';j++)
	{
		str3[i++]=str2[j];
	}
	str3[i]='\0';
	cout<<"Concatinated String: \n";
	puts(str3);
	getch();
}
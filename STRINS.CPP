#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char str1[80],str2[80],str3[160];
	int n;
	cout<<"Enter string"<<endl;
	gets(str1);
	cout<<"Enter string to insert"<<endl;
	gets(str2);
	cout<<"Enter position: ";
	cin>>n;
	int j=0,k=0;
	for(int i=0;i<(strlen(str1)+strlen(str2));i++)
	{
		if(i>=n&&i<(n+strlen(str2)))
			str3[i]=str2[j++];
		else
			str3[i]=str1[k++];
	}
	str3[i]='\0';
	cout<<"New String: \n";
	puts(str3);
	getch();
}
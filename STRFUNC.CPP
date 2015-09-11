#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int strlen(char str[80])
{
	for(int i=0;str[i]!='\0';i++);
	return i;
}
void strcat(char str1[80],char str2[80])
{
	char str3[80];
	for(int k=0;str1[k]!='\0';k++)
		str3[k]=str1[k];
	for(int i=strlen(str1),j=0;str2[j]!='\0';j++)
	{
		str3[i++]=str2[j];
	}
	str3[i]='\0';
	cout<<"Concatinated String: \n";
	puts(str3);
}
void strcomp(char str1[80], char str2[80])
{
	int count=0;
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
}
void strins(char str1[80],char str2[80],int n)
{
	int l=strlen(str1);
	int j=0,k=0;
	for(int i=0;i<l;i++)
	{
		if(i<n)
			continue;
		else
			str1[i+strlen(str2)]=str1[i];
	}
	for(i=n,j=0;str2[i]!='\0';i++)
		str1[i]=str2[j++];
	str1[l+strlen(str2)]='\0';
	cout<<"New String: \n";
	puts(str1);
}
void strdel(char str1[80],char str2[80])
{
	int count,pos,flag=0,j,k;
	char str3[80];
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
	{
		for(k=0;k<strlen(str1);k++)
			if(k<pos)
				continue;
			else if(str1[k+strlen(str2)]!='\0')
				str1[k]=str1[k+strlen(str2)];
			else if(str1[k+strlen(str2)]=='\0')
			{
			       str1[k]='\0';
			       break;
			}
	}
	cout<<"New String"<<endl;
	puts(str1);
}
void main()
{
	clrscr();
	char str1[80],str2[80];
	int ch,n;
	cout<<"Enter choice\n";
	cout<<"1. String length\n";
	cout<<"2. String concatination\n";
	cout<<"3. String comparison\n";
	cout<<"4. Insert substring\n";
	cout<<"5. Delete substring\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter string:"<<endl;
			gets(str1);
			cout<<strlen(str1);
			break;
		case 2:
			cout<<"Enter two strings:"<<endl;
			gets(str1);
			gets(str2);
			strcat(str1,str2);
			break;
		case 3:
			cout<<"Enter two strings:"<<endl;
			gets(str1);
			gets(str2);
			strcomp(str1,str2);
			break;
		case 4:
			cout<<"Enter string: "<<endl;
			gets(str1);
			cout<<"Enter string to insert:"<<endl;
			gets(str2);
			cout<<"Enter position to insert string"<<endl;
			cin>>n;
			strins(str1,str2,n);
			break;
		case 5:
			cout<<"Enter string: "<<endl;
			gets(str1);
			cout<<"Enter string to delete: "<<endl;
			gets(str2);
			strdel(str1,str2);
			break;
		default: cout<<"Wrong choice:"<<endl;
	}
	getch();
}
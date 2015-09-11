#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class student
{
	char name[80];
	int roll;
	char grade;
	public:
	void read(student *,int n);
	void disp(student *,int n);
	void sort(student *,int n);
};
void student::read(student std[10],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Enter name: ";
		gets(std[i].name);
		cout<<"Enter roll no.: ";
		cin>>std[i].roll;
		cout<<"Enter grade :" ;
		cin>>std[i].grade;
	}
}
void student::disp(student std[10],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Name:";
		puts(std[i].name);
		cout<<"Roll no.: "<<std[i].roll<<endl;
		cout<<"Grade :"<<std[i].grade<<endl;
	}
}
void student::sort(student std[10],int n)
{
	for (int i=0;i<n-1;i++)
	{
		int small=i;
		for(int j=i+1;j<n;j++)
			if (std[j].roll<std[small].roll)
				small=j;

		student temp=std[i];
		std[i]=std[small];
		std[small]=temp;
	}
}
void main()
{
	clrscr();
	student std,std1[10];
	int n;
	cout<<"Enter no. of objects"<<endl;
	cin>>n;
	std.read(std1,n);
	cout<<"\n\nDisplaying objects:\n\n"<<endl;
	std.disp(std1,n);
	cout<<"\n\nSorted objects:\n\n"<<endl;
	std.sort(std1,n);
	std.disp(std1,n);
	getch();
}
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int a[20],x,n,flag=0;
	cout<<"Enter no of elements: ";
	cin>>n;
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter element to find: ";
	cin>>x;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			cout<<"Found at "<<i+1;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"Not found";
	getch();
}


#include<iostream.h>
#include<conio.h>
void printArray(int a[10][10],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}
void main()
{
	clrscr();
	int m,n,a[10][10],b[10][10],c[10][10];
	cout<<"Enter order of array: ";
	cin>>m>>n;
	cout<<"Enter elements of 1st array: "<<endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	cout<<"Enter elements of 2nd array: "<<endl;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>b[i][j];
	for(i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>b[i][j])
				c[i][j]=a[i][j];
			else
				c[i][j]=b[i][j];
		}
	 }
	 cout<<"First Array"<<endl;
	 printArray(a,m,n);
	 cout<<"Second Array"<<endl;
	 printArray(b,m,n);
	 cout<<"Max Array"<<endl;
	 printArray(c,m,n);
	 getch();
}

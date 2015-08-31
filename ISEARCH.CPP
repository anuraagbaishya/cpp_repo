#include <iostream.h>
#include <conio.h>
void main()
{
	clrscr();
	int a[100],n,i,j,x,temp;
	cout<<"Enter the number of elements: \n";
		cin>>n;
	cout<<"\nEnter the elements: \n"  ;
	for (i=0;i<n;i++)
		cin>>a[i];
	for (i=1;i<n;i++)
	{
		j=i;
		x=a[i];
		while(j>0&&x<a[j-1])
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=x;
	}
	cout<<"\nSorted array\n"<<endl;
	for (i=0;i<n;i++)
	cout<<a[i]<<endl;
	getch();
}
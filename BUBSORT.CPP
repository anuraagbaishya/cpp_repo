#include <iostream.h>
#include <conio.h>
void main()
{
	clrscr();
	int a[100],n,i,j, temp;
	cout<<"Enter the number of elements: \n";
		cin>>n;
	cout<<"\nEnter the elements: \n"  ;
	for (i=0;i<n;i++)
		cin>>a[i];
	for (i=1;i<n;i++)
	{
		for (j=i;j>=1;j--)
		{
			if (a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1] = temp;
			}
		}
	}
	cout<<"\nSorted array\n"<<endl;
	for (i=0;i<n;i++)
		cout<<a[i]<<endl;
	getch();
}
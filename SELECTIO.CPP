#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int i,j,small,arr[100],n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter the elements: "<<endl;
	for (i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for (i=0;i<n-1;i++)
	{
		int small=i;
		for(j=i+1;j<n;j++)
			if (arr[j]<arr[small])
				small=j;

		int temp=arr[i];
		arr[i]=arr[small];
		arr[small]=temp;
	}
	cout<<"\nSorted array: ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<endl;
	getch();
}



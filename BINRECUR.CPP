#include<iostream.h>
#include<conio.h>
int binSearch(int a[20],int x,int low,int high)
{       int mid;
	mid=(low+high)/2;
	if(x>a[mid]&&low<high)
	{
		low=mid+1;
		return binSearch(a,x,low,high);
	}
	else if(x<a[mid]&&low<high)
	{
		high=mid-1;
		return binSearch(a,x,low,high);
	}
	else if(x==a[mid])
	{
		cout<<"Found at: "<<mid+1;
		return 1;
	}
	else
		return 0;
}
void main()
{
	clrscr();
	int x,n,a[20],temp,small,flag;
	cout<<"Enter no of elements: ";
	cin>>n;
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		int small=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[small])
				small=j;
		temp=a[i];
		a[i]=a[small];
		a[small]=temp;
	}
	cout<<"Enter element to search: ";
	cin>>x;
	flag=binSearch(a,x,0,n-1);
	if(flag==0)
		cout<<"Not Found";
	getch();
}

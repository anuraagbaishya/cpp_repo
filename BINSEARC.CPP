#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int x,n,low,high,temp,mid,a[20],flag=0;
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
	low=0;
	high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(x>a[mid])
			low=mid+1;
		else if(x<a[mid])
			high=mid-1;
		else
		{
			flag++;
			cout<<"Found at: "<<mid+1;
			break;
		}
	 }
	 if (flag==0)
		cout<<"Not Found";
	 getch();
}

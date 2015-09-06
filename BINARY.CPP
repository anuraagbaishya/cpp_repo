#include<iostream>
#include<conio.h>

void main()
{
 clrscr();
 int a[100],n;
 cout<<"Enter the number of terms: ";
  cin>>n;

    for(int i=0; i<n; i++)
      {
       cout<<"Enter value for A["<<i<<"]: ";
       cin>>a[i];
      }
    for(i=0;i<n-1;i++)
    {
     for(int j=0; j<n-1-i; j++)
     {
       if(a[j]>a[j+1])
       {
	    int temp=a[j];
	    a[j]=a[j+1];
	    a[j+1]=temp;
       }
     }
    }
   cout<<"Displaying sorted array: \n";

   for(i=0;i<n;i++)
    cout<<a[i]<<endl;

   int lb=0, ub=n-1, mid=(ub+lb)/2;
   int key;

   cout<<"Enter the term to be searched: ";
   cin>>key;

   while(lb<=ub)
   { if(key>a[mid])
       lb=mid+1;
     else if(key<a[mid])
       ub=mid-1;
     else
     cout<<"Element found at position "<<mid+1;
    }


    for(i=lb; i<=ub; i++)
     {
      if(a[i]==key)
       cout<<"Element found at position : "<<i;
     }

getch();

}

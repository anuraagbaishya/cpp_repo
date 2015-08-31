#include<conio.h>
#include<iostream.h>

void main()
{
clrscr();
int i,no,key,arr,j;
cout<<"Enter the number of values to be sorted."<<endl;
cin>>no;
cout<<"Enter the values."<<endl;
for(i=0;i<no;i++)
cin>>arr[i];

for(i=1;i<no;i++)
 {key=arr[i];
  j=i-1;
  while(j>=0&&arr[j]>key)
   {
    a[j+1]=a[j];
    j=j-1;
    };
   a[j+1]=key;
  };
cout<<"The sorted array is:"<<endl
for(i=0;i<no;i++)
cout<<arr[i]<<" ";
getch();
};
#include<iostream.h>
#include<conio.h>

void main()
{clrscr();

int n,a[100];
cout<<"Enter the number of terms: ";
cin>>n;

for(int i=0; i<n; i++)
  {
   cout<<"Enter value for A["<<i<<"] : ";
   cin>>a[i];
  }
  int ele,flag=0;
  cout<<"Enter the element to be searched: ":
  cin>>ele;

  for(int j=0; j<n; j++)
   { if(a[j]==ele)
     {
       flag++;
       break;
     }
   }
  if(flag==1)
  {
   cout<<"Element found at position "<<j+1;
  else
   cout<<"Element not found!";

  }

getch();
}
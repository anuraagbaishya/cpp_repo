#include<iostream.h>
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

    for(i=0; i<n-1; i++)
     for(int j=0; j<n-1-i; j++)
      {
	if(a[j]>a[j+1])
	{ int temp= a[j];
	      a[j]= a[j+1];
	      a[j+1]=temp;
	}
      }

     //displaying sorted array.

     for(i=0; i<n; i++)
     {
      cout<<a[i]<<endl;

     }

getch();

}
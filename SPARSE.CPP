#include<iostream>
#define MAXSIZE 10
using namespace std;
class sm
{
	int r,c,v;
	public:
	sm()
	{
		r=c=v=0;
	}
	void read(sm*,int,int);
	void display(sm*);
	void transpose(sm*,sm*);
	void ftranspose(sm*,sm*);
};
void sm::read(sm s[],int m,int n)
{
	s[0].r=m;
	s[0].c=n;
	int k=1,val;
	cout<<"Enter Matrix\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>val;
			if(val!=0)
			{
				s[k].r=i;
				s[k].c=j;
				s[k].v=val;
				k++;
			}
		}
	}
	s[0].v=k-1;
}
void sm::display(sm s[])
{
	int k=s[0].v;
	for(int i=0;i<=k;i++)
		cout<<s[i].r<<"\t"<<s[i].c<<"\t"<<s[i].v<<"\n";
}
void sm::transpose(sm s[],sm s2[])
{
	 int n;
	 s2[0].r=s[0].c;
	 s2[0].c=s[0].r;
	 n=s2[0].v=s[0].v;
	 int k=1;
	 if(n>0)
	 {
		for(int i=0;i<s[0].c;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(s[j].c==i)
				{
					s2[k].r=s[k].c;
					s2[k].c=s[k].r;
					s2[k].v=s[k].v;
					k++;
				}
			}
		}
	 }
}
void sm::ftranspose(sm a[], sm b[])
{
	int i,k=a[0].v,l;
	int rt[10],sp[10];
	for(i=0;i<a[0].c;i++)
	{
		rt[i]=0;
	}
	for(i=1;i<=a[0].v;i++)
	{
		rt[a[i].c]++;
	}
	sp[0]=1;
	for(i=1;i<=a[0].c;i++)
	{
		sp[i]=sp[i-1]+rt[i-1];
	}
	b[0].c=a[0].r;
	b[0].r=a[0].c;
	b[0].v=a[0].v;
	for(i=1;i<=k;i++)
	{
		l=sp[a[i].c]++;
		b[l].r=a[i].c;
		b[l].c=a[i].r;
		b[l].v=a[i].v;
	}
}
int main()
{
	//clrscr();
	int m,n;
	cout<<"Enter no. of rows: \n";
	cin>>m;
	cout<<"Enter no. of columns: \n";
	cin>>n;
	sm s[MAXSIZE],s2[MAXSIZE],s1;
	s1.read(s,m,n);
	cout<<"Sparse Matrix: \n";
	s1.display(s);
	cout<<"Transposed: \n";
	s1.transpose(s,s2);
	cout<<endl;
	s1.display(s2);
	cout<<endl;
	cout<<"Fast Transposed \n";
	s1.ftranspose(s,s2);
	s1.display(s2);
	return 0;
	//getch();

}
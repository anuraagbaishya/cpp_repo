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
	void matdisplay(sm*);
	void addsm(sm*, sm*);
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
void sm::matdisplay(sm s[])
{
    int k=1;
    for(int i=0;i<s[0].r;i++)
    {
        for(int j=0;j<s[0].c;j++)
        {
            if(s[k].r==i&&s[k].c==j)
            {
                cout<<s[k].v<<"\t";
                k++;
            }
            else
                cout<<"0\t";
        }
        cout<<endl;
    }
}
void sm::addsm(sm s[],sm s2[])
{
    sm sum[2*MAXSIZE];
    int i,j,c;
    i=j=c=1;
    if(s[0].r==s2[0].r&&s[0].c==s2[0].c)
    {
        while((i<=s[0].v)&&(j<=s2[0].v))
        {
            if(s[i].r==s2[j].r)    // if rows are equal
            {
                if(s[i].c==s2[j].c) // if columns are equal
                {
                    sum[c].r=s[i].r;
                    sum[c].c=s[i].c;
                    sum[c].v=s[i].v+s2[j].v;
                    i++;
                    j++;
                    if(sum[c].v!=0)
                        c++;
                }
                else   // if columns are not equal
                {
                    if(s[i].c<s2[j].c)
                    {
                        sum[c].r=s[i].r;
                        sum[c].c=s[i].c;
                        sum[c].v=s[i].v;
                        i++;
                        c++;
                    }
                    else
                    {
                        sum[c].r=s2[j].r;
                        sum[c].c=s2[j].c;
                        sum[c].v=s2[j].v;
                        j++;
                        c++;
                    }
                }
        }
        else   //   if rows are not equal
        {
                if(s[i].r<s2[j].r)
                {
                    sum[c].r=s[i].r;
                    sum[c].c=s[i].c;
                    sum[c].v=s[i].v;
                    i++;
                    c++;
                }
                else
                {
                    sum[c].r=s2[j].r;
                    sum[c].c=s2[j].c;
                    sum[c].v=s2[j].v;
                    j++;
                    c++;
                }
            }
        }  // end of while
        if(i<s[0].v)
        {
            for(int p=i;p<=s[0].v;p++)
            {
                sum[c].r=s[p].r;
                sum[c].c=s[p].c;
                sum[c].v=s[p].v;
                c++;
            }
        }
        else if(j<s2[0].v)
        {
            for(int p=j;p<=s2[0].v;p++)
            {
                sum[c].r=s2[p].r;
                sum[c].c=s2[p].c;
                sum[c].v=s2[p].v;
                c++;
            }
        }
        sum[0].r=s[0].r;
        sum[0].c=s[0].c;
        sum[0].v=c-1;
        cout<<"\nDisplaying as Sparse Matrix\n";
        display(sum);
        cout<<"\nDisplaying as 2D Matrix\n";
        matdisplay(sum);
    }
   else
        cout<<"Addition Not Possible";
}
int main()
{
    int m,n;
	cout<<"Enter no. of rows for 1st matrix: \n";
	cin>>m;
	cout<<"Enter no. of columns for 1st matrix: \n";
	cin>>n;
	sm s[MAXSIZE],s2[MAXSIZE],s1;
	s1.read(s,m,n);
	cout<<"Enter no. of rows for 2nd matrix: \n";
	cin>>m;
	cout<<"Enter no. of columns for 2nd matrix: \n";
	cin>>n;
	s1.read(s2,m,n);
	s1.addsm(s,s2);
	return 0;
}

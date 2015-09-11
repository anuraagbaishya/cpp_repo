#include<iostream.h>
#include<conio.h>
class time
{
	int hr,min,sec;
	public:
	void read();
	void disp();
	time add(time t1, time t2);
	time diff(time t1,time t2);
};
void time::read()
{
	cout<<"Enter hour: ";
	cin>>hr;
	cout<<"Enter minute: ";
	cin>>min;
	cout<<"Enter sec: ";
	cin>>sec;
}
void time::disp()
{
	cout<<"Time: "<<hr<<":"<<min<<":"<<sec<<endl;
}
time time::add(time t1,time t2)
{
	time t3;
	t3.hr=t1.hr+t2.hr;
	t3.min=t1.min+t2.min ;
	t3.sec=t1.sec+t2.sec  ;
	if(t3.sec>=60)
	{
		t3.min++;
		t3.sec-=60;
	}
	if(t3.min>=60)
	{
		t3.hr++;
		t3.min-=60;
	}
	return t3;
}
time time::diff(time t1,time t2)
{
	time t3;
	if(t1.hr>t2.hr)
	{
		t3.hr=t1.hr-t2.hr;
		t3.min=t1.min-t2.min ;
		t3.sec=t1.sec-t2.sec;
	}
	else
	{
		t3.hr=t2.hr-t1.hr;
		t3.min=t2.min-t1.min ;
		t3.sec=t2.sec-t1.sec  ;
	}
	if(t3.sec<0)
	{
		t3.min--;
		t3.sec+=60;
	}
	if(t3.min<60)
	{
		t3.hr--;
		t3.min+=60;
	}
	return t3;
}
void main()
{
	clrscr();
	time t1,t2,t3,t4;
	t1.read();
	t2.read();
	t3=t3.add(t1,t2);
	t4=t4.diff(t1,t2);
	t3.disp();
	t4.disp();
	getch();
}
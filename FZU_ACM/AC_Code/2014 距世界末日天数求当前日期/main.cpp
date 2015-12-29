#include<iostream>
#include <iomanip>
using namespace std;
int ifleap(int year)
{
	int yes=0;
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		yes=1;
	return yes;
}


int main()
{
	int date,y,m,d;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(cin>>date)
	{
		month[2]=28;
		y=2012;m=12;d=21;
		while(date>=(365+ifleap(y)))
		{
			date=date-365-ifleap(y);
			y=y-1;
		}//¼ÆËãÄê·Ý¡£
		if (ifleap(y)==1)
		{
			month[2]=29;
		}
		while(date>=month[m-1]&&m>=2)
		{
			date=date-month[m-1];
			m=m-1;
		}
		if(m==1)
		{
			if (date<21)
			{
				d=21-date;
			}
			else
			{	
				y=y-1;
				m=12;
				d=month[12]-(date-21);
			}
		}
		else
		{
			if (date<21)
			{
				d=21-date;
			}
			else
			{
				m=m-1;
				d=month[m]-(date-21);
			}
		}
		cout.fill('0');
		cout<<y<<'-'<<setw(2)<<m<<'-'<<setw(2)<<d<<endl;	
	}
	return 0;
}
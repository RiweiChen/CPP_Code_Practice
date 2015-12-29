#include<iostream>
using namespace std;
class Lastday
{
private:
	int year,month,day;
	long date;
public:
	Lastday(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}
	
	int numberday(int year3,int month3,int day3)
	{
		int yes;
		yes=ifleap(year3);
		if(month3==1)
			return day3;
		if(month3==2)
			return 31+day3;
		if(month3==3)
			return 31+28+yes+day3;
		if(month3==4)
			return 31+28+31+yes+day3;
		if(month3==5)
			return 31+28+31+30+yes+day3;
		if(month3==6)
			return 31+28+31+30+31+yes+day3;
		if(month3==7)
			return 31+28+31+30+31+30+yes+day3;
		if(month3==8)
			return 31+28+31+30+31+30+31+yes+day3;
		if(month3==9)
			return 31+28+31+30+31+30+31+31+yes+day3;
		if(month3==10)
			return 31+28+31+30+31+30+31+31+30+yes+day3;	
		if(month3==11)
			return 31+28+31+30+31+30+31+31+30+31+yes+day3;	
		if(month3==12)
			return 31+28+31+30+31+30+31+31+30+31+30+yes+day3;
		
		
	}
	
	int ifleap(int year)
	{
		int yes=0;
		if(((year%4==0)&&(year%100!=0))||(year%400==0))
			yes=1;
		return yes;
	}
	
	
	long dates(int y,int m,int d)
	{
		int temp=0,i;
		int years=year-y-1;
		if(years>=1)
		{
			date=365+ifleap(y)-numberday(y,m,d)+1;
			for( i=1;i<=years;i++)
			{
				if(ifleap(y+i))
					temp++;//代表中间的几个年份之间的闰年次数。
			}
			date=date+temp+years*365+numberday(year,month,day)-1;
			return date;
		}
		if(years==0)
		{
			date=365+ifleap(y)-numberday(y,m,d)+1+numberday(year,month,day)-1;
			return date;
		}
		if(years==-1)
		{
			date=numberday(year,month,day)-numberday(y,m,d);
			return date;
		}
		
		
		
	}
	
	
};//类的定义。

long days(int y,int m,int d)
{
	long datess;
	Lastday case1(y,m,d);     
	datess=case1.dates(1900,1,1);//距那一天的天数
	return datess;
}

int main()
{
	int n;
	while(cin>>n)
	{
	
		int month,year;
		int date[7]={0,0,0,0,0,0,0};
		for(year=1900;year<=1900+n-1;year++)
			for (month =1;month<=12;month++)
			{
				date[days(year,month,13)%7]++;
			}
		cout<<date[5]<<' '<<date[6]<<' '<<date[0]<<' '<<date[1]<<' '<<date[2]<<' ' <<date[3]<<' '<<date[4]<<endl;
	}
	
	return 0;
}
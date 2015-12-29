#include <iostream>
#include <iomanip>
using namespace std ;
int ifleap(int year)//判断年份
{
	int yes=0;
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		yes=1;
	return yes;
}
int main()
{
	int m,d=1;
	long date;
	int y=2000;//初始年份。
	int	month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//月份天数数组。
	char *week[7]={ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" , "Saturday"};
	
	while (cin>>date&&date!=-1)
	{
		month[2]=28;
		y=2000,d=1;
		m=(date-1)%7;
		if (date==0)
		{
			m=6;
		}
		while(date-364-ifleap(y)>0)//先计算年份。
		{
			date=date-365-ifleap(y);
			y++;
			
		}
		//跳出后可以确定年份y

		if (ifleap(y)==1)
		{
			month[2]=29;//调整新年份的月数组
		}
		while (date-month[d]+1>0)//逐个从一月开始寻找月份
		{
			date=date-month[d];
			d++;
		}
		//调整输出格式。
		cout.fill('0');
		cout<<y<<'-'<<setw(2)<<d<<'-'<<setw(2)<<date+1<<' '<<week[m]<<endl;
		
		
		
	}
	return 0;
}
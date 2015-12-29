#include<iostream>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int if_leap(int y)
{
	if ((y%4==0&&(y%100!=0))||(y%400==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int thday_of_year(int y,int m,int d)
{
	int i;
	int result=0;
	for (i=1;i<m;i++)
	{
		result=result+month[i];
	}
	result=result+d;
	if (m>2&&if_leap(y)==1)
	{
		result=result+1;
	}
	return result;
}

int main()
{
	int t;
	cin>>t;
	int i;
	int y,m,d;
	int result;
	int dth;
	for (i=0;i<t;i++)
	{
		cin>>y>>m>>d;
		dth=y-1958;
		if (m>10||(m==10&&d>25))
		{
			dth=dth+1;
		}//Ëã³öµÚ¼¸½ì¡£
		if (m<10||(m==10&&d<=25))
		{
			result=thday_of_year(y,10,25)-thday_of_year(y,m,d);
		}
		else
		{
			result=thday_of_year(y,12,31)-thday_of_year(y,m,d)+thday_of_year(y+1,10,25);
		}
		cout<<result<<" days left for celebrating the "<<dth<<"th anniversary of the founding of Fuzhou University!"<<endl;



	}
	return 0;
}
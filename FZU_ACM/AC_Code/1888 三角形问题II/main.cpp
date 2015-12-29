#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct point
{
	double x;
	double y;
};
int main()
{
	int t;
	cin>>t;
	point dates[51];
	double result;
	int i;
	for (i=1;i<=t;i++)
	{
		result=0;
		int n;
		cin>>n;
		int j;
		double a,b;
		int num=0;
		int k,m,q;
		int flag;
		for (j=0;j<n;j++)
		{
			flag=0;
			cin>>a>>b;//数据不保证不会出现坐标相同的点
			for (k=0;k<num;k++)
			{
				if (a==dates[k].x&&b==dates[k].y)
				{
					//表示出现了相同的东西。
					flag=1;
					num--;
					break;
				}
				
			}
			if (flag==0)
			{
				dates[num].x=a;
				dates[num].y=b;
			}
			num++;

		}
		
		for (k=0;k<num-2;k++)
		{
			for (m=k+1;m<num-1;m++)
			{
				for (q=m+1;q<num;q++)
				{
				//	if (((dates[k].y-dates[m].y)*(dates[q].x-dates[m].x))==(dates[q].y-dates[k].y)*(dates[m].x-dates[k].x))
					{
						//计算每个三角形的面积。
						result=result+fabs((dates[k].x*dates[m].y-dates[m].x*dates[k].y+dates[m].x*dates[q].y-dates[q].x*dates[m].y+dates[q].x*dates[k].y-dates[k].x*dates[q].y)/2.0);
						
					}
				}
			}
		}
		cout.precision(1);
		cout.setf(ios::fixed); 
		cout<<"Case "<<i<<": "<<result<<endl;
	}
	return 0;
}
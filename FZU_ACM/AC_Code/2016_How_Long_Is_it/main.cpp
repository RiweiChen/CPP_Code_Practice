//参考网上。
#include<iostream>
#include<cmath>
#define R 6378 
#define pi acos(-1.0)
//π的值。
using namespace std;
struct node
{
	double x;
	double y;
	double z;
};
node date_change(double a,double b)
{//根据数学公式转换坐标形式
	node temp;
	temp.z=sin(pi/180*a);
	temp.y=cos(pi/180*a)*cos(b*pi/180);
	temp.x=cos(pi/180*a)*sin(b*pi/180);
	return temp;
}
int main()
{
	 int times;
	 cin>>times;
	 int i;
	 for(i=0;i<times;i++)
	 {
		 double x,y,a,b;
		 cin>>x>>y>>a>>b;
		 double angle,result;
		 node point1,point2;
		 point1=date_change(x,y);
		 point2=date_change(a,b);
		 angle=acos(point1.x*point2.x+point1.y*point2.y+point1.z*point2.z);//求的两坐标的夹角。
		 result=R*angle;
		 printf("%.2lf\n",result);

	 }
	 return 0;
}


//�ο����ϡ�
#include<iostream>
#include<cmath>
#define R 6378 
#define pi acos(-1.0)
//�е�ֵ��
using namespace std;
struct node
{
	double x;
	double y;
	double z;
};
node date_change(double a,double b)
{//������ѧ��ʽת��������ʽ
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
		 angle=acos(point1.x*point2.x+point1.y*point2.y+point1.z*point2.z);//���������ļнǡ�
		 result=R*angle;
		 printf("%.2lf\n",result);

	 }
	 return 0;
}


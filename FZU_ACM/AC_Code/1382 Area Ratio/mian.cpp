#include<iostream>
#include<cmath>
using  namespace std;
//һ�������Σ�r=2S/(a+b+c)��
//����S�������������a��b��c�����������ߡ�
//����S=������p(p-a)(p-b)(p-c)������p=(a+b+c)/2 

int main()
{
	double r,a,b,c,s,p,R;
	int x1,y1,z1,x2,y2,z2,x3,y3,z3;
	while (cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3)
	{
		//sqrt((x2-x1)(x2-x1)+(y2-y1)(y2-y1)+(z2-z1)(z2-z1));�ռ�����֮��ľ��빫ʽ��
		a=sqrt((double)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)));
		b=sqrt((double)((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)+(z2-z3)*(z2-z3)));
		c=sqrt((double)((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1)));
		p=(a+b+c)/2.0;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		r=2*s/(a+b+c);
		R=a*b*c/(4*s);
	//	printf("%.3lf",R);
	//	cout<<endl;
		
	//	printf("%.3lf",r);
	//	cout<<endl;
		double result=r*r/(R*R);
		printf("%.3lf",result);//������ڽ���������Բ���֮�ȡ�
		cout<<endl;

	}
	return 0;
}
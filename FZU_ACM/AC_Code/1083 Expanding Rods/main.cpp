#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double n,c,d;
	while (true)
	{
		cin>>d>>c>>n;
		if(d<0&&c<0&&n<0)
		{
			break;
		}
		double result=0;
		double ds=(1+n*c)*d;
		if (n*c==0)
		{
			cout<<"0.000"<<endl;
			continue;
		}
	/*	double r=d/2;//���ݿɵù�ʽ��asin(d/2r)=ds/(2r);���Ǿ��Ȳ����׿����š�����
		while (asin(d/(2*r))!=ds/(2*r))
		{
			r=r+0.000001;//��������ô�ĸպá�����
		}
		result=r-sqrt(r*r-d*d/4);*/




		//���׵õ���ʽ��ds/d=sin@/@;
		long double degree1=0;
	    long double degree2=acos(-1.0)/2; //0�ȵ�180��֮����ַ���//�ǵ���1.0��ʾ���������ֶ����ԡ�
		long  double degree;
	        while (degree2-degree1>1e-12)  
		       {  
			           degree=(degree1+degree2)/2;  
							if (d/ds-sin(degree)/degree>0)  
							{  
				               degree2=degree;  
				            }  
			               else  
						   {  
			                   degree1=degree;  
			               }  
		        }  
		
		result=(d/(2*sin(degree))-d/(2*tan(degree)));  
		printf("%.3lf\n",result);
	}
	return 0;
}
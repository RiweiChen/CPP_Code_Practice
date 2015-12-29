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
	/*	double r=d/2;//根据可得公式：asin(d/2r)=ds/(2r);但是精度不容易控制呐。。。
		while (asin(d/(2*r))!=ds/(2*r))
		{
			r=r+0.000001;//不可能那么的刚好。。。
		}
		result=r-sqrt(r*r-d*d/4);*/




		//容易得到公式：ds/d=sin@/@;
		long double degree1=0;
	    long double degree2=acos(-1.0)/2; //0度到180度之间二分法。//记得用1.0表示。否则会出现二义性。
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
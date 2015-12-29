#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
	double a,b,c;
	double d,e,f;
	while (t--)
	{
		cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3>>x4>>y4>>z4;
		a=(y2-y1)*(z3-z1)-(y3-y1)*(z2-z1);
		b=(x2-x1)*(z3-z1)-(x3-x1)*(z2-z1);
		c=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
		d=(y2-y1)*(z4-z1)-(y4-y1)*(z2-z1);
		e=(x2-x1)*(z4-z1)-(x4-x1)*(z2-z1);
		f=(x2-x1)*(y4-y1)-(x4-x1)*(y2-y1);
		//cout<<'a'<<a<<'b'<<b<<'c'<<c<<"d"<<d<<"e"<<e<<"f"<<f<<endl;
		if ((a*e==b*d)&&(c*d==a*f)&&(c*e==b*f))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}


	}
	return 0;
}
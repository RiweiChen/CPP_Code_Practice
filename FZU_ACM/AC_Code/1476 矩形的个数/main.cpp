#include<iostream>
using namespace std;
int main()//纯数学问题。
{
	double a,b;//注意数值的要用double.
	while(cin>>a>>b)
	{
		double result;
		result=(a+1)*a*(b+1)*b/4;
		printf("%.0lf\n",result);
	}
	return 0;
}

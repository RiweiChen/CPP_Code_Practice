#include<iostream>
using namespace std;
int main()//����ѧ���⡣
{
	double a,b;//ע����ֵ��Ҫ��double.
	while(cin>>a>>b)
	{
		double result;
		result=(a+1)*a*(b+1)*b/4;
		printf("%.0lf\n",result);
	}
	return 0;
}

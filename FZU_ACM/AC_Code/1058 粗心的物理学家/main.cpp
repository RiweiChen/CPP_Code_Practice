//本题貌似很简单，一遍For就可以过了，但粗心的我因为加法顺序Wa了，哭~~~
//
//PS：因为精度问题，从小到大会运算使某些进位被和谐，所以本题需从大到小累加，注意！
#include <iostream>
using namespace  std;
int main()
{
	long n;
	while(cin>>n)
	{
		double sum=0.0;
		int i;
		for (i=n;i>=1;i--)
		{
			sum=sum+(double)1.0/i;
		}
		cout.setf(ios::showpoint);
		cout.precision(12);
		cout.setf(ios::fixed);
		cout<<sum<<endl;
	}

	return 0;

}

/*
#include<stdio.h>
int main()
{
long int n;
int i;
double s;
while(scanf("%d",&n)!=EOF) //输入到文件末尾结束
{
   s=0;
   for(i=n;i>=1;i--)
   {
    s+=(double)1/i; //这里是需要注意的地方，强制转换成double型
   }
   printf("%.12lf\n",s);   //输出12位小数点的表示方法
}
return 0;
}
*/
//����ò�ƺܼ򵥣�һ��For�Ϳ��Թ��ˣ������ĵ�����Ϊ�ӷ�˳��Wa�ˣ���~~~
//
//PS����Ϊ�������⣬��С���������ʹĳЩ��λ����г�����Ա�����Ӵ�С�ۼӣ�ע�⣡
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
while(scanf("%d",&n)!=EOF) //���뵽�ļ�ĩβ����
{
   s=0;
   for(i=n;i>=1;i--)
   {
    s+=(double)1/i; //��������Ҫע��ĵط���ǿ��ת����double��
   }
   printf("%.12lf\n",s);   //���12λС����ı�ʾ����
}
return 0;
}
*/
#include<iostream>
using namespace std;
/*
int f(int m,int n)
{

	int result;
	if (m==0)
	{
		result=n+1;
		
	}
	if (m>0&&n==0)
	{
		result=f(m-1,1);
	}
	if (m>0&&n>0)
	{
		result=f(m-1,f(m,n-1));
	}
	return result;
}
int main()
{
	long n,m,result;
	while(cin>>m>>n)
	{
		result=f(m,n);
		cout<<result<<endl;
	}
	return 0;
}
*///��֪���ǻᳬʱ�ģ��ɻ���д��һ�顣
int main()
{
	//�Ƶ���ʽ����m=1ʱ����A(1,n)=A(1,n-1)+1���׵õ����Ϊ��n+2;
	//��m=2ʱ�й�ʽ��A(2,n)=A(2,n-1)+2;�������׵õ�result=2n+3;
	//��m=3ʱ���Ƶ���ʽ��A(3,n)=2*A(3,n-1)+3;
	//                          ...
	//                          ...
	//                          2*A(3,0)+3;//��A(3,0)=A(2,1)=5;
	int m,n;
	while (cin>>m>>n)
	{
		int result=0;
		if (m==1)
		{
			result=n+2;
			cout<<result<<endl;
		}
		if (m==2)
		{
			result=2*n+3;
			cout<<result<<endl;
		}
		int i=0;
		if (m==3)
		{
			result=5;
			while (i<n)
			{
				result=result*2+3;
				i++;
			}
			cout<<result<<endl;
		}
	}

	return 0;
}

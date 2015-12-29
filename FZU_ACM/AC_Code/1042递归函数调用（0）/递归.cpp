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
*///明知道是会超时的，可还是写了一遍。
int main()
{
	//推导公式：当m=1时，有A(1,n)=A(1,n-1)+1容易得到结果为：n+2;
	//当m=2时有公式：A(2,n)=A(2,n-1)+2;所以容易得到result=2n+3;
	//当m=3时有推导公式：A(3,n)=2*A(3,n-1)+3;
	//                          ...
	//                          ...
	//                          2*A(3,0)+3;//而A(3,0)=A(2,1)=5;
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

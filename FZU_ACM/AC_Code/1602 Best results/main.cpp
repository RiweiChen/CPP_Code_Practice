#include<iostream>
#include<cmath>
using namespace std;
int main()
{	
	int n;
	while (cin>>n)//n大于1小于100.
	{
		int result[1000]={0};//大整数相乘。
		result[0]=1;
		int max_dig=1;
		int i,j;
		int d;
		char ch;
		for (i=0;i<n;i++)
		{
			cin>>d>>ch;
			getchar();
			for (j=0;j<max_dig;j++)
			{
				result[j]=result[j]*d;
			}
			for (j=0;j<max_dig;j++)
			{
				if (result[j]/10>0)
				{
					result[j+1]=result[j+1]+result[j]/10;
					result[j]=result[j]%10;
				}
				if (j==(max_dig-1))
				{
					if (result[j+1]>0)
					{
						max_dig++;
					}
				}
			}
			//2^n-max_dig为前导0.
			//处理后面的无效0
		}
		int b=2*n-max_dig;
		int z=0;
		j=0;
		while (result[j]==0)
		{
			z++;//标志最后的有效位的位置。
			j++;
		}
		for (j=0;j<max_dig-z;j++)
		{
			result[j]=result[j+z];
		}
		max_dig=max_dig-z;
		for (j=max_dig;j<max_dig+b;j++)
		{
			result[j]=0;
		}
		max_dig=max_dig+b;
		cout<<"0.";
		for (j=max_dig-1;j>=0;j--)
		{
			cout<<result[j];
		}
			cout<<endl;
		//cout<<result<<endl;//如果n比较大无论输出是几位都无法满足精确度。
		//只能用大整数来精确了。
	}
	return 0;
}
#include<iostream>
using namespace std;
int main()//题意要求是最低的楼高是多少。。
{
	int result;
	int a,b;
	while (cin>>a>>b)
	{
		//第一步一定是往上跳。
		result=a;
		if (a%b==0)
		{
			result=a;
			cout<<result<<endl;
			continue;
		}
		if (b%a==0)
		{
			result=b;
			cout<<result<<endl;
			continue;
		}
		int temp=a;//temp记录当前的最大高度。
		while(temp%b>0)//当不能够整除的时候。
		{
			temp=temp%b+a;//向下跳妥协，然后再往上跳一步。
			if (temp>result)
			{
				result=temp;
			}
		}//完全模拟的方法。。
		cout<<result<<endl;
	}
	return 0;
}
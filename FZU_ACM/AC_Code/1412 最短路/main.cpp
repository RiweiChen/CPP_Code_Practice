#include<iostream>
using namespace std;
int main()
{
	int a,b,c;int x,y,z;
	int t;
	cin>>t;
	int i;
	int result;int temp;int temp2,temp3;;
	for (i=0;i<t;i++)
	{
		cin>>a>>b>>c>>x>>y>>z;
		if (x==0)
		{
			result=y*y+z*z;
			cout<<result<<endl;
			continue;
		}
		if (y==0)
		{
			result=x*x+z*z;
			cout<<result<<endl;
			continue;
		}
		if (z==0)
		{
			result=x*x+y*y;
			cout<<result<<endl;
			continue;
		}
		//if(x==0||y==0||z==0)
		//{
		//	printf("%d\n",x*x+y*y+z*z);
		//	continue;
		//}
		//更简便

		if(x==a)
		{
			temp=(a+y)*(a+y)+z*z;
			temp2=(b+z)*(b+z)+(a+b-y)*(a+b-y);//这种情况很容易被遗忘掉。
			temp3=(c+y)*(c+y)+(a+c-z)*(a+c-z);//需要考虑对称性。
			result=(a+z)*(a+z)+y*y;
			//下面还有一种情况。

			if (temp<result)
			{
				result=temp;
			}
			if (temp2<result)
			{
				result=temp2;
			}
			if (temp3<result)
			{
				result=temp3;
			}
			cout<<result<<endl;
			continue;

		}
		if (y==b)
		{
			temp=(b+x)*(b+x)+z*z;
			temp2=(c+x)*(c+x)+(b+c-z)*(b+c-z);
			temp3=(a+z)*(a+z)+(b+a-x)*(b+a-x); 
			result=(b+z)*(b+z)+x*x;
			if (temp<result)
			{
				result=temp;
			}
			if (temp2<result)
			{
				result=temp2;
			}
			if (temp3<result)
			{
				result=temp3;
			}
			cout<<result<<endl;
			continue;
		}
		if (z==c)
		{
			temp=(c+y)*(c+y)+x*x;
			temp2=(a+y)*(a+y)+(a+c-x)*(a+c-x);
			temp3=(b+x)*(b+x)+(b+c-y)*(b+c-y);
			result=(c+x)*(c+x)+y*y;
			if (temp<result)
			{
				result=temp;
			}
			if (temp2<result)
			{
				result=temp2;
			}
			if (temp3<result)
			{
				result=temp3;
			}
			cout<<result<<endl;
			continue;
		}
	}
	return 0;
}
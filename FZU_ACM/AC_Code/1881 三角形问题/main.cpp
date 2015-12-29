#include<iostream>
using namespace std;
bool judge(int x,int y)
{
	if (x==y)
	{
		return false;
	}
	int temp;
	if (x>y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	//首先要确定x在第几行。
	int i;
	i=1;
	while (x>((i+1)*i)/2)
	{
		i++;
	}//说明x在第i行。
	if ((x+i==y)||(x+i+1==y))
	{
		return true;
	}
	if (x!=((i+1)*i)/2)
	{
		if (x+1==y)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int t,i;
	cin>>t;
	int x,y;
	for (i=1;i<=t;i++)
	{
		cin>>x>>y;
		if (judge(x,y))
		{
			cout<<"Case "<<i<<":"<<"Yes"<<endl;
		}
		else
		{
			cout<<"Case "<<i<<":"<<"No"<<endl;

		}
	}
	return 0;
}
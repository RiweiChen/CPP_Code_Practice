#include<iostream>
using namespace std;
bool if_can(int a,int b)
{
	if (a==1)
	{
		return false;
	}
	if (b==1)
	{
		return false;
	}
	if(a%2==1&&b%2==1)//���ж��������ǲ����ܴ������ġ�
	{
		return false;
	}
	if (a%2==0||b%2==0)
	{
		return true;
	}	
}
int main()
{
	int t;
	cin>>t;
	int i;
	int a,b;
	for (i=0;i<t;i++)
	{
		cin>>a>>b;
		if(if_can(a,b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
	return 0;
}
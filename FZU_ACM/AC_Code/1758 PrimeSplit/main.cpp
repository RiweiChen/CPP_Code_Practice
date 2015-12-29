#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
	int i;
	for(i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			if (i==1)
			{
				cout<<1;
			}
			else
			{
				cout<<' '<<i;
			}
		}
	}
	cout<<endl;
	}
	return 0;
}
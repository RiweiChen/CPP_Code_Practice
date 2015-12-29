#include<iostream>
using namespace std;
int main()
{
	
	int n,k;
	int result;
	while (cin>>n>>k)
	{
		result=n;
		while (n>=k)
		{
			result=result+n/k;
			n=n%k+n/k;//新的可以参与兑换的烟头。

		}
		cout<<result<<endl;

	}
	return 0;
}
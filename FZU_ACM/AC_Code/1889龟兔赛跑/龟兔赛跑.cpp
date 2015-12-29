#include<iostream>
using namespace std;
int main()
{
	int t,k,u,v,n,i,s1,s2;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>t>>k>>u>>v;
		s1=(t-k)*u;
		s2=t*v;
		if (s1>s2)
		{
			cout<<0<<endl;
		}
		if (s1<s2)
		{
			cout<<1<<endl;
		}
		if (s1==s2)
		{
			cout<<-1<<endl;
		}
	}

	return 0;
}
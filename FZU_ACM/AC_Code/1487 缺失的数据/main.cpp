#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int *date=new int[n+1];
		int i;
		for(i=1;i<=n;i++)
		{
			date[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			int temp;
			cin>>temp;
			date[temp]=1;
		}
		for(i=1;i<n;i++)
		{
			if(date[i]==0)
			{
				cout<<i<<endl;
				break;
			}
		}
		delete [] date;
	}
	return 0;
}
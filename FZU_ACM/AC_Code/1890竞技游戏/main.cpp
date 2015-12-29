#include <iostream>
using namespace std;
int main()
{
	int n,m,t,a,b;
	cin>>t;
	int k,j,i;
	int date[100];
	for (i=0;i<t;i++)
	{
		cin>>n>>m;
		for (j=0;j<n;j++)
		{
			cin>>date[j];
		}
		j--;
		for(k=0;k<m;k++)
		{
			cin>>a>>b;
			if (a>0)
			{
				date[b-1]=date[b-1]*2;

			}
			if (a<0)
			{
				date[b-1]=date[b-1]+2;
			}
		}
		int max=date[0];
		for (j=1;j<n;j++)
		{
			if (max<date[j])
			{
				max=date[j];
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
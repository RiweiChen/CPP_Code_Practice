#include<iostream>
using namespace std;
int main()
{
	int n,m;
	char date1[101][101];
	char date2[101][101];
	while(cin>>n>>m)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>date1[i][j];
			}
			getchar();
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>date2[i][j];
			}
			getchar();
		}
		int result=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(date1[i][j]!=date2[i][j])
					result++;
			}
		}
		cout<<result<<endl;		
	}
	return 0;
}
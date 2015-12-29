#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int dates[50000]={0};
		dates[0]=1;
		int i=1,j=1;
		int max_dig=1;
		while(i<=n)
		{
			for(j=0;j<max_dig;j++)
			{
				dates[j]=dates[j]*i;
			}
			for(j=0;j<max_dig;j++)
			{
				if(dates[j]>9)
				{
					dates[j+1]=dates[j+1]+dates[j]/10;
					dates[j]=dates[j]%10;
				}
				if(dates[max_dig]>0)
				{
					max_dig++;
				}
			}
			
			i++;
		}
		for(i=max_dig-1;i>=0;i--)
		{
			cout<<dates[i];
		}
		cout<<endl;

	}
	return 0;
}

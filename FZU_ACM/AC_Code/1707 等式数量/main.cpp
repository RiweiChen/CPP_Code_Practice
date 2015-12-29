#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int date[5001];
	while(cin>>n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",date+i);
		}
		sort(date,date+n);
		int a,b,c;
		int result=0;
		for(i=0;i<n;i++)
		{
			c=i;
			a=0;
			b=n-1;
			while(a!=b)
			{
				if(date[a]+date[b]==date[c])
				{
					
					if(a!=c&&b!=c)//可能有两个数相加等于其中一个数的情况。
					{
						result++;
					}
					a++;
					
				}
				else if(date[a]+date[b]>date[c])
					b--;
				else if(date[a]+date[b]<date[c])
					a++;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
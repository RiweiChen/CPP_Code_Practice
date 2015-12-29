#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		unsigned long long *date=new unsigned long long[n];//必须是在64位，且为无符号的。否者就会出错。
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%llu",&date[i]);
			//cin>>date[i];
		}
		sort(date,date+n);
		int flag=0;
		for(i=0;i<n;i++)//技巧，原因在于。。。。
		{
			if(date[i]==date[i+1])
			{
				i++;
			}
			else
			{
				cout<<date[i];
				if(flag==0)
				{
					cout<<' ';
					flag=1;
				}
				else
				{
					cout<<endl;
				}
			}

		}
		delete []date;
	}
	return 0;
}
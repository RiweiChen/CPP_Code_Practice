#include<iostream>
using namespace std;
bool dates[10000002];
int main()
{
	int n,d,i,j;
	int time;
	long long result;
	while(cin>>n>>d)
	{
		result=0;
		time=n/d;
		memset(dates,false,time+2);
		for(i=2;i<time;i++)
		{
			if(time%i==0)
			{
				dates[i]=true;
				j=2;
				while(i*j<time)
				{
					dates[i*j]=true;
					j++;
				}
			}
		}
		for(i=1;i<time;i++)
		{
			if(dates[i]==false)
				result=result+i*d;
		}
		cout<<result<<endl;


	}
	return 0;
}
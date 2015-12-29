#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
bool date[1000002];
int times[1000001];
int main()
{
	int i,j;
	memset(date,true,1000001);
	for (i=2;i<500001;i++)
	{
		j=2;
		if (date[i]==true)
		{
			while (i*j<=1000001)
			{
				date[i*j]=false;
				j++;
			}
			
		}
	}
	int t=0;
	for (i=2;i<=1000000;i++)
	{
		times[i]=t;
		if (date[i]==true)
		{
			t++;
		}
		
	}
	int a,b,result;
	cin>>t;
	for (i=0;i<t;i++)
	{
		cin>>a>>b;
		result=times[b]-times[a];
		if (date[b]==true)
		{
			result=result+1;
		}
		cout<<result<<endl;

	}

	
	return 0;
}
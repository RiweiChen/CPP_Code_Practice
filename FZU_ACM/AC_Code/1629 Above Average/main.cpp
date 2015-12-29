#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	for (i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int *date=new int[n];
		int j;
		int sum=0;
		for (j=0;j<n;j++)
		{
			cin>>date[j];
			sum=sum+date[j];
		}
		float average=0;
		average=sum/n;
		int num1=0;
		for (j=0;j<n;j++)
		{
			if (average<date[j])
			{
				num1++;
			}
		}
		float result;
		result=(float)num1*100/n;
		cout<<fixed<<setprecision(3)<<result<<'%'<<endl;
	}
	return 0;
}
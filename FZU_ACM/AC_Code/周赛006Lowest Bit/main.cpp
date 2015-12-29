#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int date[9]={0};
		int i=0;
		while(n!=0)
		{
			date[i++]=n%2;
			n=n/2;
		}
		for(i=0;i<=9;i++)
		{
			if(date[i]==1)
				break;
		}
		int result=0;
		result=(int)pow(2,i);
		cout<<result<<endl;
	}
	return 0;
}

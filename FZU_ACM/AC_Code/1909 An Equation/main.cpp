#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	int date[4];
	for (i=1;i<=t;i++)
	{
		cin>>date[0]>>date[1]>>date[2]>>date[3];
		sort(date,date+4);
		if (date[0]+date[3]==date[1]+date[2])
		{
			cout<<"Case "<<i<<": "<<"Yes"<<endl;
		}
		else
		{
			cout<<"Case "<<i<<": "<<"No"<<endl;

		}
	}
	return 0;
}
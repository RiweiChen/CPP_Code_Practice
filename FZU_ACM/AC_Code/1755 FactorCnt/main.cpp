#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		int num;
		num=0;
		int i;
		for (i=1;i<n;i++)
		{
			if (n%i==0)
			{
				num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
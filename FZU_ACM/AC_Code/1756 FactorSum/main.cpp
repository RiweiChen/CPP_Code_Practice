#include<iostream>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
		int i;
		if (n<=0)
		{
			//cout<<0<<endl;
			printf("0\n");
			continue;
		}
		for (i=1;i<(n/2+1);i++)
		{
			if (n%i==0)
			{
				sum=sum+i;
			}
		}
		printf("%d\n",sum);
		//cout<<sum<<endl;
	}
	return 0;
}
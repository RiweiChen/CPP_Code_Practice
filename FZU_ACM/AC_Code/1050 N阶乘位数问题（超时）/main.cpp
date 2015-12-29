#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int j,i;
		int date[100000]={0};
		date[0]=1;
		int max_of_digit=1;
		for (i=2;i<=n;i++)
		{
			
			for (j=0;j<max_of_digit;j++)
			{
				date[j]=date[j]*i;
			}//完成数据的相乘；
			for (j=0;j<max_of_digit;j++)
			{
				if (date[j]/10>0)
				{
					date[j+1]=date[j+1]+date[j]/10;
					date[j]=date[j]%10;
				
				}
				if (j==(max_of_digit-1))
				{
					if (date[j+1]>0)
					{
						max_of_digit++;
					}
				}
			}
		}
		cout<<max_of_digit<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;
int is_primer(int n)
{
	for (int i=2;i<n;i++)
	{
		if (n%i==0)
		{
			return 0;
		}		
	}
	return 1;
}
int main()
{
	int k,x=0;
	int temp=2;
	int prime[6800];
	int power[6800]={0};
	while(x<6800)
	{
		if(is_primer(temp++))
		{
			prime[x]=temp-1;
			x++;
		}
		
	}
	int temp2=0;
    cin>>k;
	for (int i=0;i<k;i++)
	{
		cin>>x;
		if (x==1)
		{
			cout<<'1'<<endl;
			continue;
		}
		temp2=0;
		for (int z=0;z<6800;z++)
		{
			power[z]=0;
		}//每次开始之前都把次方数给重新置为0.
		while (x>=prime[temp2])
		{
			while(x%prime[temp2]==0)
			{
				x=x/prime[temp2];
				power[temp2]++;

			}
			temp2++;
			

		}
		power[temp2]++;
		//输出结果；
	int test=0;
	for (int p=0;p<temp2;p++)
	{
				for (int pow=0;pow<power[p];pow++)
				{
					if(test==0)
					{
						cout<<prime[p];
						test=1;
					}
					else
					cout<<'*'<<prime[p];
				}
	}
	cout<<endl;
	}

	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int i,j,max_dig=1;
		int temp;
		int date1[1001]={0};
		int date2[1001]={0};
		date1[0]=1;
		date2[0]=1;
		if(n<=2)
		{
			cout<<1<<endl;
			continue;
		}
		int carry=0,carry1=0;
		for (i=3;i<=n;i++)
		{
			carry=0;
			carry1=0;
			for(j=0;j<max_dig;j++)//做一次加法。
			{
			
				temp=date2[j];
				if((date1[j]+date2[j]+carry)>9)   //进位标志。
				{
					carry=1;
				}
				else
				{
					carry=0;
				}
				date2[j]=(date1[j]+date2[j]+carry1)%10;
				date1[j]=temp;
				carry1=carry;
				
			if((j==(max_dig-1))&&(carry==1))
			{
				max_dig++;
			}
			}


		
		}
		for(i=max_dig-1;i>=0;i--)
		{
			cout<<date2[i];
		}
		cout<<endl;
	}

	return 0;
}
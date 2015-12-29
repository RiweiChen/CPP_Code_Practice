#include<iostream>
using namespace std;
int main()
{
/*	int n;
	int i,j;
	while(cin>>n)
	{
		int *date=new int[2*n];
		int *temp1=new int[n];
		for ( i=0;i<2*n;i++)
		{
			date[i]=i+1;
			
		}
		int judge=0;
		int  count=0;
	
		while (judge!=1)
		{
	
		
			for (j=0;j<n;j++)
			{
				temp1[j]=date[n+j];
			}
			for (i=n-1;i>=0;i--)
			{
			
				date[2*i+1]=date[i];
			}
			for (i=0;i<n;i++)
			{
				date[2*i]=temp1[i];
			}
			count++;
			for (i=0;i<2*n;i++)
			{
				if ((date[i]==i+1))
				{
					if (i==2*n-1)
					{
						judge=1;
					}
				}
					
				else
					break;
			}
		}
		cout<<count<<endl;
		delete [] temp1;
		delete [] date;
	}
*/
	//以上代码超时。
	//经过证明，可以知道跟踪第一个元素，当他回到自己的位置时，就会原次序出现。
	//任何第r个元素洗过一次后的位置是2*r%(2*n+1)....
	int n;
	while(cin>>n)
	{
		int r=2;
		int times=1;
		while(r!=1)
		{
			r=2*r%(2*n+1);
			times++;
		}
		cout<<times<<endl;
	}


	return 0;
}

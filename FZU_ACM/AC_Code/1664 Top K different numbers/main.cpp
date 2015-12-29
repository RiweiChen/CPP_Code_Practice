#include<iostream>
#include <algorithm> 
using namespace std;
int main()
{
	int n;
	int k;
	while (cin>>n>>k)
	{
		int *date=new int[n];
		int *top=new int[n];
		int i;
		for (i=0;i<n;i++)
		{
			cin>>date[i];
		}
		//因为数据小，采用冒泡排序吧。。
	//	int temp;
		int j;
		/*for (i=0;i<n;i++)
		{
			
			for (j=i;j<n;j++)
			{
				if (date[j]>date[i])
				{
					temp=date[j];
					date[j]=date[i];
					date[i]=temp;
				}

			}
		}*/
		sort(date,date+n);  
		j=0;
		top[0]=date[n-1];
		for (i=n-2;i>0;i--)
		{
			if (date[i]<date[i+1])
			{
				top[++j]=date[i];
			}

		}
		if (j<k-1)
		{
			cout<<"-1"<<endl;

		}
		else
		{
			for (i=k-1;i>0;i--)
			{
				cout<<top[i]<<' ';
			}
			cout<<top[0];
			cout<<endl;
		}
		delete []top;
		delete []date;
	}
	return 0;
}
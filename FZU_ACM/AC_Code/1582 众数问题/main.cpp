//øÏÀŸ≈≈–Ú+≤È’“°£
#include<iostream>
using namespace std;
int comp(const void *a,const void *b)
{
	return *(int*)a-*(int *)b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int *date=new int [n];
		int i=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&date[i]);
			//cin>>date[i];
		}
		qsort(date,n,sizeof(int),comp);
		int most_num,temp;
		int time_most=1,time_temp=1;
		most_num=date[0];
		int flag=0;
		for(i=1;i<n;i++)
		{
			if(flag==0)
			{
				while(date[i]==date[i-1])
				{
					time_most++;
					i++;
				}
				flag=1;
			}
			if(flag==1)
			{
				time_temp=1;
				while(date[i]==date[i-1])
				{
					temp=date[i];
					time_temp++;
					i++;
				}
				if(time_temp>time_most)
				{
					time_most=time_temp;
					most_num=temp;
				}
			

			}

		}
		cout<<most_num<<endl;

		delete [] date;

	}
	return 0;
}
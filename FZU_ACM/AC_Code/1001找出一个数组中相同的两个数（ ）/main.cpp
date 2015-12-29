/*
#include <iostream>
using namespace std;
unsigned int if_occur[1000000]={0};
int main()
{
	int n,i;
	while (cin>>n)
	{
		int *date=new int [n];
		
		for (i=0;i<n;i++) 
		{
			cin>>date[i];
			if(if_occur[date[i]]==0)
				if_occur[date[i]]=1;
			else
			{
				cout<<date[i]<<endl;
				break;
			}
		}
		for(i=0;i<1000000;i++)
		{
			if_occur[i]=0;
		}
		delete [] date;

	}
	return 0;		
}



  */
//超时。。。
/*
#include<iostream>
using namespace std;
int compare(const void *elem1, const void *elem2)
{
    return *((int *)(elem1)) - *((int *)(elem2));
}
int main()
{
	int n;
	while(cin>>n)
	{
		int *date=new int [n];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>date[i];
		}
		qsort(date,n,sizeof(int),compare);
		for(i=1;i<n;i++)
		{
			if(date[i]==date[i-1])
			{
				cout<<date[i]<<endl;
				break;
			}
		}
		delete []date;
	}
	return 0;
}
//额，快速排序后还是超时。。
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
	int i;
	long sum1=0;
	int date;
	long sum2=0;

	for(i=1;i<=n;i++)
	{
		sum2=sum2+i;
		scanf("%d",&date);
		sum1=sum1+date;
	}

	int result=sum1-sum2;
	cout<<result<<endl;

	}
	return 0;
}
*/
//理解好题意，题目是说数字只有1到n-1的范围中的n个，只有2个重复


#include<iostream>
using namespace std;
int main()
{
	int date,n, sum,i;
	while(cin>>n)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&date);
			sum+=i;
			sum-=date;
		}
		cout<<n-sum<<endl;
	}
	return 0;
}

		




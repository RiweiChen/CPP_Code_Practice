/*
#include<iostream>
using namespace std;
int median(int a,int b,int c)
{
	if(a<b)
		if(b<c)
			return b;
		else if(a<c)
			return c;
		else return a;
	else if(a<c)
		return a;
	else if(b<c)
		return c;
	else return b;
}
int partition(int *date,int first,int last,int pivot)
{
	while (true)
	{
		while(date[first]<pivot)
			first++;
		last--;
		while(date[last]>pivot)
			last--;
		if(!(first<last))
			return first;
		std::swap(date[first],date[last]);
		first++;
	}
}
void qsort(int *date,int first,int last)
{
	while(last-first>1)
	{
		int pivot=median(date[first],date[(first+(last-first)/2)],date[last-1]);
		int cut=partition(date,first,last,pivot);
		qsort(date,cut,last);
		last=cut;
	}
}

int main()
{
	int n;
	cin>>n;
	
	int *date=new int[n];
	int i;
	for(i=0;i<n;i++) 
	{
		cin>>date[i];
	}
	//完成数据的输入。
	//对数据排序。
		int m;
		cin>>m;
	
		for(i=0;i<m;i++)
		{
			int a,b;
			int j;
			cin>>a>>b;
			int *section=new int [b-a+1];
			for(j=0;j<=b-a;j++)
				section[j]=date[a-1+j];
			qsort(section,0,b-a+1);
		
			int count=1;
			for(j=1;j<b-a+1;j++)
			{
			//	cout<<section[j]<<' ';
				if(section[j]!=section[j-1])
				count ++;
			}
			//cout<<endl;
			cout<<count<<endl;		
			delete [] section;
		}
	delete [] date;
	return 0;
}
*/
//超时代码，因为重复操作太多。
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
//pair<int,int> date[100002];
//int num[100001]={0};
int main()
{
	int n,m,first,last,i,sum;
	int temp;
	while(cin>>n)
	{
		pair<int,int> *date=new pair<int,int>[n+2];
		int *num=new int[n+1];
		memset(num,0,sizeof(num[0]));
		for (i=1;i<=n;i++)
		{
			//cin>>temp;
			scanf("%d",&temp);
			date[i]=make_pair(temp,i);
		}//完成数据的输入。
		pair <int,int> *p1=&date[1],*p2=&date[n+1];
		sort(p1,p2);//调用系统函数排序。
		for (i=2;i<=n;i++)
		{
			if (date[i].first==date[i-1].first)//有重复的数据出现。
				//标记。
			{
				num[date[i].second]=date[i-1].second;
				//num[i]数组标记上一次 重复出现的位置。
				//num [i]为0，表示第i个数还未出现过。
			}
		}
		cin>>m;
		while (m--)
		{
			sum=0;
			cin>>first>>last;
			for (i=first;i<=last;i++)
			{
				if ((num[i]<first))//为0.表示为出现过。而小于first表示在first之前出现过。
				{
					sum++;
				}
				//而如果数字在first和i之间出现，表示重复出现的。数字。 。之间出现。则不用sum++;
			
			}
			cout<<sum<<endl;
		}
		delete [] date;
		delete [] num;
	}
	return 0;
}



	
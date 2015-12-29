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
	//������ݵ����롣
	//����������
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
//��ʱ���룬��Ϊ�ظ�����̫�ࡣ
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
		}//������ݵ����롣
		pair <int,int> *p1=&date[1],*p2=&date[n+1];
		sort(p1,p2);//����ϵͳ��������
		for (i=2;i<=n;i++)
		{
			if (date[i].first==date[i-1].first)//���ظ������ݳ��֡�
				//��ǡ�
			{
				num[date[i].second]=date[i-1].second;
				//num[i]��������һ�� �ظ����ֵ�λ�á�
				//num [i]Ϊ0����ʾ��i������δ���ֹ���
			}
		}
		cin>>m;
		while (m--)
		{
			sum=0;
			cin>>first>>last;
			for (i=first;i<=last;i++)
			{
				if ((num[i]<first))//Ϊ0.��ʾΪ���ֹ�����С��first��ʾ��first֮ǰ���ֹ���
				{
					sum++;
				}
				//�����������first��i֮����֣���ʾ�ظ����ֵġ����֡� ��֮����֡�����sum++;
			
			}
			cout<<sum<<endl;
		}
		delete [] date;
		delete [] num;
	}
	return 0;
}



	
#include<iostream>
using namespace std;
int f[600001];
int c[600001];
int que[600002];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(i=0;i<n;i++)
	{
		c[i]=0;
	}
	for(i=0;i<n;i++)
	{
		c[f[i]]++;
	}//先统计每个人的得票数。
	int first,last;
	first=last=0;
	for(i=0;i<n;i++)
	{
		if(c[i]==0)
			que[last++]=i;	
	}
	int j;
	while(first!=last)
	{
		j=que[first++];
		if(--c[f[j]]==0)
			que[last++]=f[j];//删除孤独者导致新的孤独者产生，入队。
	}
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(c[i]==1)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}

/*
//完全使用stl的超时代码，看来stl真的没什么效率呐。。。。
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
int n;
while(cin>>n)
{

  
	int i;
	vector<int> f;
	f.resize(n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&f[i]);
	//cin>>f[i];
	}
	queue<int> que;
	
	  vector<int> c;
	  c.resize(n);
	  for(i=0;i<n;i++)
	  {
	  c[i]=0;
	  }
	  for(i=0;i<n;i++)
	  {
	  c[f[i]]++;
	  }//先统计每个人的得票数。
	  for(i=0;i<n;i++)
	  {
	  if(c[i]==0)
	  que.push(i);//没有得票的孤独者入栈。	
	  }
	  while(!(que.empty()))
	  {
	  int j=que.front();
	  que.pop();
	  if(--c[f[j]]==0)
	  que.push(f[j]);//删除孤独者导致新的孤独者产生，入队。
	  
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
		if(c[i]==1)
		{
		//	cout<<i<<endl;
		ans++;
		}
		}
		cout<<ans<<endl;
		}
		return 0;
}
*/
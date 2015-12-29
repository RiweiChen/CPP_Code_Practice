#include<iostream>
//#include<vector>
#include<stack>
//#include<iterator>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	int result1,result2;
	stack<int> sta;
	for (i=1;i<=t;i++)
	{
		int j;
		int n;
		int flag[100001]={0};
		result1=0;
		result2=0;
		cin>>n;
		int *date1=new int[n+1];
		int *date2=new int[n+1];
		for (j=1;j<=n;j++)
		{
			scanf("%d",&date1[j]);
		}
		for (j=1;j<=n;j++)
		{
			scanf("%d",&date2[j]);
		}
		int k=0;//标记每个人的牌。
		for (k=1;k<=n;k++)
		{
			if(flag[date1[k]]==0)//未出现过。标记为0
			{
				flag[date1[k]]=1;//为1表示出现过了。
				sta.push(date1[k]);//入栈。

			}
			else//出现过了。
			{
				result1++;//这张牌没有入栈。
				while (sta.top()!=date1[k])
				{
					
					flag[sta.top()]=0;
					sta.pop();
					//解除标记
					result1++;
				}
				
				flag[sta.top()]=0;
				sta.pop();
				result1++;

			}
			if(flag[date2[k]]==0)//未出现过。标记为0
			{
				flag[date2[k]]=1;//为1表示出现过了。
				sta.push(date2[k]);//入栈。
				
			}
			else//出现过了。
			{
				result2++;
				while (sta.top()!=date2[k])
				{
					
					flag[sta.top()]=0;
					sta.pop();
					//解除标记
					result2++;
				}
				flag[sta.top()]=0;
				sta.pop();
				result2++;
				
			}

		}
		cout<<"Case "<<i<<":Apple:"<<result1<<" Gaga:"<<result2<<endl;
		
		delete []date1;
		delete []date2;
	}
	return 0;
}
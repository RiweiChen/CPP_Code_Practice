#include<iostream>
#include<queue>
using namespace std;
struct point
{
	int i;
	int j;
	
};

int main()
{
	int n,m;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		getchar();
		char **date=new char * [n+2];
		int i;
		for(i=0;i<=n+1;i++)
		{
			date[i]=new char[m+2];
		}
		int j;
		for(j=0;j<=n+1;j++)
		{
			date[j][0]='.';
			date[j][n+1]='.';
		}
		for(j=0;j<=m+1;j++)
		{
			date[0][j]='.';
			date[n+1][j]='.';
		}
		//置边框，以节省代码的复杂程度，减小判断量。
		
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>date[i][j];
			}
			getchar();
		}
		point offset[4];//设置转向
		offset[0].i=0;offset[0].j=1;
		offset[1].i=1;offset[1].j=0;
		offset[2].i=0;offset[2].j=-1;
		offset[3].i=-1;offset[3].j=0;
		queue<point> que;
		char ch;
		int result=0,temp=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(date[i][j]!='.')
				{
					ch=date[i][j];
					temp=1;//出现一个1就加一次。
					point x;
					x.i=i;
					x.j=j;
					que.push(x);
					date[i][j]='.';//入栈后就把该点置0以免重复计算。
					
					while(!que.empty())
					{
						x=que.front();
						int k;
						for(k=0;k<4;k++)
						{
							if(date[x.i+offset[k].i][x.j+offset[k].j]==ch)
							{
								point t;
								t.i=x.i+offset[k].i;
								t.j=x.j+offset[k].j;
								que.push(t);//将改点的位置入栈。
								date[x.i+offset[k].i][x.j+offset[k].j]='.';//置0处理。
								temp++;	//出现一次1就加上一次。
							}
						}
						que.pop();
						
					}
					if(temp>result)
						result=temp;
					
				}
				
			}
			cout<<result<<endl;
			for(j=0;j<n+2;j++)
			{
				delete [] date[j];
			}
			delete [] date;
			
	}
	return 0;
}
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
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
		{
			break;
		}
		int **date=new int * [n+2];
		int i;
		for(i=0;i<=n+1;i++)
		{
			date[i]=new int[m+2];
		}
		int j;
		for(j=0;j<=n+1;j++)
		{
			date[j][0]=0;
			date[j][n+1]=0;
		}
		for(j=0;j<=m+1;j++)
		{
			date[0][j]=0;
			date[n+1][j]=0;
		}
		//�ñ߿��Խ�ʡ����ĸ��ӳ̶ȣ���С�ж�����
		

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>date[i][j];

			}
		}
		point offset[4];//����ת��
		offset[0].i=0;offset[0].j=1;
		offset[1].i=1;offset[1].j=0;
		offset[2].i=0;offset[2].j=-1;
		offset[3].i=-1;offset[3].j=0;
		queue<point> que;
		int result=0,temp=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if(date[i][j]==1)
				{
					temp=1;//����һ��1�ͼ�һ�Ρ�
					point x;
					x.i=i;
					x.j=j;
					que.push(x);
					date[i][j]=0;//��ջ��ͰѸõ���0�����ظ����㡣
				
					while(!que.empty())
					{
						x=que.front();
						int k;
						for(k=0;k<4;k++)
						{
							if(date[x.i+offset[k].i][x.j+offset[k].j]==1)
							{
								point t;
								t.i=x.i+offset[k].i;
								t.j=x.j+offset[k].j;
								que.push(t);//���ĵ��λ����ջ��
								date[x.i+offset[k].i][x.j+offset[k].j]=0;//��0����
								temp++;	//����һ��1�ͼ���һ�Ρ�
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
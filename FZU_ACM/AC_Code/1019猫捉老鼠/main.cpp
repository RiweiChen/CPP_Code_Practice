#include<iostream>
using namespace std;
int main()
{
	struct point
	{
		int i;
		int j;
	};
	point turn[4];//方向循环
	turn[0].i=-1;turn[0].j=0;
	turn[1].i=0;turn[1].j=1;
	turn[2].i=1;turn[2].j=0;
	turn[3].i=0;turn[3].j=-1;
	
	char date[10][10];
	int n;
	cin>>n;
	int i;
	char ch;
	for(i=0;i<n;i++)
	{
		int j,k;
		point cat,mouse;
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				getchar(date[j][k]);
				if(date[j][k]=='c')
				{
					cat.i=j;
					cat.j=k;
				}
				if(date[j][k]=='m')
				{
					mouse.i=j;
					mouse.j=k;
				}
			}
			//cout<<endl;
		}
		//完成数据的输入。
		int times=1;
		int tc=0,tm=0;
		while(times<1000)
		{
			if((date[cat.i+turn[tc%4].i][cat.j+turn[tc%4].j]=='*')||((cat.i+turn[tc%4].i)<0)||((cat.i+turn[tc%4].i)>9))//面对的地方超过了格子范围或遇到障碍物
			{
				tc++;//转向。
			}
			else
			{
				cat.i=cat.i+turn[tc%4].i;
				cat.j=cat.j+turn[tc%4].j;
			}
			if((date[mouse.i+turn[tm%4].i][mouse.j+turn[tm%4].j]=='*')||(mouse.i+turn[tm%4].i<0)||(mouse.i+turn[tm%4].i>9))
			{
				tm++;
			}
			else
			{
				mouse.i=mouse.i+turn[tm%4].i;
				mouse.j=mouse.j+turn[tm%4].j;
			}

			if((cat.i==mouse.i)&&(cat.j==mouse.j))//抓到啦。
			{
				cout<<times<<endl;
				break;
			}
			times++;
		}//;判断一种是否可以到达的想法：如果两个都到达原来的出发点而且朝向也是相同的向北，说明已经实现了循环。
		if(times==10000)
		{
			cout<<"cann't catch"<<endl;
		}
	}
	return 0;
}
//测试数据
/*
5
..........
m......*..
c.........
..........
..........
..........
..........
..........
..........
..........
..........
*/

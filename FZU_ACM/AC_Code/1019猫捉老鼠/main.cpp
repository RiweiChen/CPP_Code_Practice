#include<iostream>
using namespace std;
int main()
{
	struct point
	{
		int i;
		int j;
	};
	point turn[4];//����ѭ��
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
		//������ݵ����롣
		int times=1;
		int tc=0,tm=0;
		while(times<1000)
		{
			if((date[cat.i+turn[tc%4].i][cat.j+turn[tc%4].j]=='*')||((cat.i+turn[tc%4].i)<0)||((cat.i+turn[tc%4].i)>9))//��Եĵط������˸��ӷ�Χ�������ϰ���
			{
				tc++;//ת��
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

			if((cat.i==mouse.i)&&(cat.j==mouse.j))//ץ������
			{
				cout<<times<<endl;
				break;
			}
			times++;
		}//;�ж�һ���Ƿ���Ե�����뷨���������������ԭ���ĳ�������ҳ���Ҳ����ͬ���򱱣�˵���Ѿ�ʵ����ѭ����
		if(times==10000)
		{
			cout<<"cann't catch"<<endl;
		}
	}
	return 0;
}
//��������
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

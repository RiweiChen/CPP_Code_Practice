#include <iostream>
using namespace std;
int main()
{
	char cell[10][10];
	int n;
	cin>>n;
	getchar();
	int i,j,k;
	for(i=0;i<n;i++)
	{
		int mx,my,cx,cy;//��ǿ�ʼʱ�������è��λ�á�0 ~ 9
		for (j=0;j<10;j++)
		{
			for (k=0;k<10;k++)
			{
				cin>>cell[j][k];
				if (cell[j][k]=='c')
				{
					cx=j;
					cy=k;
				}
				if (cell[j][k]=='m')
				{
					mx=j;
					my=k;
				}

			}
			getchar();
		}
		getchar();
		//��������������ʲô��ûȥ���룬���ҿ��Ǻܾ��˻�û�������Ǵ������˰ɡ���Ϊ������Ŀ���ࡣ�����׾Ͳ���ѭ���ġ�
		int distance_mouse=0;
		int distance_cat=0;//�տ�ʼ����Ĭ�ϳ�����
		for (k=1;k<10000;k++)
		{
			
			switch(distance_mouse%4)
			{

			
			case 0 ://������
				if (mx-1==-1||cell[mx-1][my]=='*')//�����߽���ϰ�,ת��
				{
					distance_mouse++;
					break;
				}
				else
					mx--;
				break;
			case 1 ://����
				if (my+1==10||cell[mx][my+1]=='*')
				{
					distance_mouse++;
					break;
				}
				else
					my++;
				break;

			case 2://����
				if (mx+1==10||cell[mx+1][my]=='*')
				{
					distance_mouse++;
					break;
				}
				else
					mx++;
				break;
			case 3://����
				if (my-1==-1||cell[mx][my-1]=='*')
				{
					distance_mouse++;
					break;
				}
				else
					my--;
				break;
			}	
				switch(distance_cat%4)
				{

				case 0 :
					if (cx-1==-1||cell[cx-1][cy]=='*')
					{
						distance_cat++;
						break;
					}
					else
						cx--;
					break;
				case 1 :
					if (cy+1==10||cell[cx][cy+1]=='*')
					{
						distance_cat++;
						break;
					}
					else
						cy++;
					break;
					
				case 2:
					if (cx+1==10||cell[cx+1][cy]=='*')
					{
						distance_cat++;
						break;
					}
					else
						cx++;
					break;
				case 3:
					if (cy-1==-1||cell[cx][cy-1]=='*')
					{
						distance_cat++;
						break;
					}
					else
						cy--;
				break;
				}
			if ((mx==cx)&&(my==cy))//����ͬһ���ص��������
			{
				cout<<k<<endl;
				break;
			}
			
		}
		if (k==10000)
		{
			cout<<0<<endl;
		}
		
	}


	return 0;
}

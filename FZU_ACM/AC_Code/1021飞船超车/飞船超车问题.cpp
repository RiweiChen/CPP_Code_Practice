//һ���㷨��˼·�򵥣���������Ч�ʵ��¡�
#include <iostream>
using namespace std;
int main()
{
	long n;
	while((cin>>n)&&(n!=0))
	{
		long i,j;
		long *speed=new long[n];
		long *date=new long[n];
		for(i=0;i<n;i++)
		{
			cin>>date[i]>>speed[i];
		}
		long time=0;

		for (i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if ((date[i]<date[j])&&(speed[i]>speed[j]))
				{
					time++;
				}

				
			}
		time=time%1000000;
		cout<<time<<endl;
		//��ס��Ҫ�ͷſռ䣬�ر����������С�
		delete [] speed;
		delete []  date;



	}

	return 0;
}





//���������������ȸ�������������
//

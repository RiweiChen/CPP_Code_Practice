//一下算法的思路简单，但是运行效率低下。
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
		//记住是要释放空间，特别是在无限中。
		delete [] speed;
		delete []  date;



	}

	return 0;
}





//方法二：用排序法先给两个数组排序。
//

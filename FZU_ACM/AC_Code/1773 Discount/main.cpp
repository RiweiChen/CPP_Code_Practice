#include <iostream>
using namespace std;
int main()
{
	int t;
	float p,d;
	cin>>t;
	int i;
	float pay;
	int pays;
	for(i=0;i<t;i++)
	{
		cin>>p>>d;
		pay=p*((100-d)/100);
		if (pay>(int)pay)
		{
			pay=(int)pay+1;
		}
		pays=(int)pay;
	//判八程序。
begin:
		int temp=pays;
		while (temp)
		{
			if (temp%10==8)
			{
				goto done;
			}
			temp=temp/10;
		}
		//没有跳出说明没有出现8.
		//如下进行增8处理。
		temp=pays;
		if (pays%10<8)
		{
			pays=pays+(8-pays%10);
		}
		else
		{
			//只能是末尾为9.
			pays=pays+1;
			goto begin;
		}

done:
		cout<<pays<<endl;

	}
	return 0;
}
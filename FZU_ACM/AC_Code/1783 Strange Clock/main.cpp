#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		if (n==-1)
		{
			break;
		}
		int p;
		int t;
		
		if (n%30==0)
		{
			//整除，表示整点。
			t=n/30;
			if (t<=3)
			{
				p=3-t;
			}
			else
			{
				p=12-(t-3);
			}
			cout<<"Exactly "<<p<<" o'clock"<<endl;
		}
		if (n%30!=0)
		{
			t=n/30;
			if (t<=3)
			{
				p=3-t;
			}
			else
			{
				p=12-(t-3);
			}
			cout<<"Between "<<(p-1+12)%12<<" o'clock and "<<p<<" o'clock"<<endl;
		}

	}
	return 0;
}
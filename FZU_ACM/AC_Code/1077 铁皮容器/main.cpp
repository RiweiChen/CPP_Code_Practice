#include<iostream>
#include <iomanip>
#define pi  3.1415926535898 
using namespace std;
int main()
{
	int k;
	cin>>k;
	int i;
	int n;
	for (i=0;i<k;i++)
	{
		cin>>n;
		double k=0.00;
		for (k=0.00;k<250.00;k=k+0.01)
		{
			if ((pi*k*k*k-500*k+n)>=0&&(pi*(k+0.01)*(k+0.01)*(k+0.01)-500*(k+0.01)+n)<0)
			{
				cout<<fixed<<setprecision(1)<<k<<endl;
				break;
			}

		}
		if (k>249.99)
		{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}
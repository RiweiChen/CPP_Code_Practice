#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,m;
	while(cin>>m>>n)
	{
	int temp;
	int *a=new int[m];
	int  *b=new int[n];
	int i,j;
	for (i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<n;j++)
	{
		cin>>b[j];
	}


	//≈≈–Ú
	for (i=0;i<m;i++)
	{
		for (j=i+1;j<m;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if(b[i]<b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}

	double times=0.0;
	for (i=0;i<m;i++)
	{
		if (i<n)
		{
			times=times+(double)a[i]/b[i];
		}
		else
		{
			times=times+(double)a[i];
		}
	}
	printf("%.2f\n",times);
	//cout<<setiosflags(ios::fixed)<<setprecision(2)<<times<<endl;
	delete [] a;
	delete [] b;
	}
	return 0;
}
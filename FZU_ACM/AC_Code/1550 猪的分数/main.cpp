#include<iostream>
#include<vector>
using namespace std;
struct dates
{
	int a;
	int b;
	double valu;
};
int if_meet(int a,int b)
{
	int i;
	for (i=2;i<=a;i++)
	{
		if ((a%i==0)&&(b%i==0))
		{
			return -1;
		}
	}
	return 1;
}
int main()
{
	int date;
	dates result[10000];
	while (cin>>date)
	{
		int i,j,k;
		k=0;
		for (i=1;i<date;i++)
		{
			for (j=i+1;j<=date;j++)
			{
				if(if_meet(i,j)==1)
				{
					result[k].a=i;
					result[k].b=j;
					result[k].valu=(double)i/(double)j;
					k++;
				}
			}
		}
		result[k].a=0;result[k].b=1;result[k].valu=0;
		k++;
		result[k].a=1;result[k].b=1;result[k].valu=1;
		k++;
		dates temp;
		for (i=0;i<k;i++)
		{
			for (j=i+1;j<k;j++)
			{
				if (result[i].valu>result[j].valu)
				{
					temp.a=result[i].a;
					temp.b=result[i].b;
					temp.valu=result[i].valu;
					result[i].a=result[j].a;
					result[i].b=result[j].b;
					result[i].valu=result[j].valu;
					result[j].a=temp.a;
					result[j].b=temp.b;
					result[j].valu=temp.valu;
				}
			}
		}
		for (i=0;i<k;i++)
		{
			cout<<result[i].a<<'/'<<result[i].b<<endl;
		}

	}
	return 0;
}
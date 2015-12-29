
#include<iostream>
using namespace std;
int dichotomy(double *dates,double date)//二分法查找
{
	int result;
	int i=0,j=499;
	while(date>dates[i]&&date<dates[j])
	{
		if(date>dates[(i+j)/2])
			i=(i+j)/2;
		if(date<dates[(i+j)/2])
			j=(i+j)/2;
		if(date==dates[(i+j)/2])
		{
			result=(i+j)/2;
				break;
		}
		if(j-i==1)
		{
			result=j;
			break;
		}

	}

	return  result;
}

int main()
{
	double dates[500]={0.0};
	int i;
	dates[0]=0.0;
	for(i=1;i<500;i++)
	{
		dates[i]=dates[i-1]+1.0/(double)(i+1);
	}
	int n;
	double date;
	while(cin>>date&&date!=0.00)
	{
		//二分法查找数
		n=dichotomy(dates,date);
		cout<<n<<" card(s)"<<endl;
	}
	return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
	double t[1000],length;
	int n;
	for(n=1,t[0]=0;t[n-1]<5.20;n++)
		t[n]=1/(double)(n+1)+t[n-1];
	for(;scanf(" %lf",length) != EOF & length != 0.0;)
	{
		for(n=0;t[n]<length;)
			n++;
		printf("%d card(s)\n",n);
	}
	return 0;
}
*/
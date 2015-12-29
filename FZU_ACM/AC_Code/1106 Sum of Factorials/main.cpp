#include<iostream>
using namespace std;
bool date[1000001];
int dates[10];
int tobinary(int w,int n)
{
	int k=0;
	int i,temp[10];
	while(n>0)
	{
		temp[k]=n%2;
		k++;
		n=n/2;
	}
	for(i=0;i<10;i++)
	{
		dates[i]=0;
	}
	int j=0;
	while(w-k>0)
	{
		j++;
		w--;
	}
	for(i=k-1;i>=0;i--)
	{
		dates[j]=temp[i];
		j++;
	}
	//for(i=0;i<9;i++)
	//{
	//	cout<<dates[i];
	//}
	//cout<<endl;
return 0;
}
int jiecheng(int n)
{
	int result=1;
	if(n>1)
		return n*jiecheng(n-1);
	else
		return n;
}
int main()
{
	memset(date,false,1000000);
	int meiju[10];
	int i;
	meiju[0]=1;
	for(i=1;i<=9;i++)
	{
		meiju[i]=jiecheng(i);
		//cout<<meiju[i]<<' ';
	}
//	cout<<endl;
	int time=1;
	for(i=0;i<10;i++)
	{
		time=time*2;
	}
	for(i=1;i<time;i++)
	{
		tobinary(10,i);
		int j;
		int result=0;
		for(j=0;j<10;j++)
		{
			if(dates[j]==1)
				result=result+meiju[j];
		}
		date[result]=true;
	}
	int v;
	while(cin>>v)
	{
		if(v<0)
			break;
		if(date[v]==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
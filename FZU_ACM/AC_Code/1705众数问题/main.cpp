/*
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int many,num,temp1,temp2;
	int *date=new int[n];
	int i;
	for (i=0;i<n;i++)
	{
		cin>>date[i];
	}
	if (date[0]<=date[n-1])
	{
		//从小到大排序
		many=date[0];
		num=1;
		temp2=1;
		for (i=1;i<n;i++)
		{
			if (i==1)
			{
			
				while(date[i]==date[i-1]) 
				{
					 num++;
					 i++;
				}
			}//初始时的众数和 度。
			 
			 {
				 temp1=date[i];
				 temp2=1;
				 i++;
				 while(date[i]==date[i-1])
				 {
					 temp2++;
					 i++;
				 }
				 i--;
			 }
			 if (temp2>num)
			 {
				 num=temp2;
				 many=temp1;
			 }
		}
		cout<<many<<' '<<num<<endl;
	}
	else
	{
		many=date[n-1];
		num=1;
		for (i=n-2;i>=0;i--)
		{
			if (i==n-2)
			{
			
				while(date[i]==date[i+1])
				{
					num++;
					i--;
				}
			}
			else
			{
				temp1=date[i];
				temp2=1;
				i--;
				while(date[i]==date[i+1])
				{
					temp2++;
					i--;
				}
				i++;
			}
			if (temp2>num)
			{
				num=temp2;
				many=temp1;
			}
		}
		cout<<many<<' '<<num<<endl;
	}
	delete [] date;
	return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
	int times[202]={0};
	int n;

	while(cin>>n)
	{
	int i,date;
	for(i=0;i<n;i++)
	{
		cin>>date;
		times[date+100]++;
	}
	int num,time;
	int flag=1;
	for(i=0;i<202;i++)
	{
		if((times[i]!=0)&&flag==1)
		{
			num=i-100;
			time=times[i];
			flag=0;
		}
		if(times[i]>time)
		{
			time=times[i];
			num=i-100;
		}
		

	}
	for(i=0;i<202;i++)
	{
		times[i]=0;
	}
	cout<<num<<' '<<time<<endl;
	}
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	char too_high[10]="too high";
	char too_low[10]="too low";
	char right_on[10]="right on";
	char temp[10];
	int honst=1; 
	int first=1,last=10000000;
	while((cin>>n)&&(n!=0))
	{
		getchar();
		gets(temp);
		if(strcmp(temp,too_high)==0)
		{
			if (n>last)
			{
				continue;
			}
			if (n<=last&&n>=first)
			{
				last=n-1;
			}
			else
			{
				honst=0;
			}
		}
		if(strcmp(temp,too_low)==0)
		{
			if (n<first)
			{
				continue;
			}
			if (n>=first&&n<=last)
			{
				first=n+1;
			}	
			else
			{
				honst=0;
			}	
		}
		if(strcmp(temp,right_on)==0)
		{
			if ((n>=first&&n<=last)&&(honst==1))
			{
				cout<<"The guy may be honest"<<endl;
			}
			else
			{
				cout<<"The guy is dishonest"<<endl;

			}
			honst=1;
			first=1;
			last=10000000;
		}
	}
	return 0;
}
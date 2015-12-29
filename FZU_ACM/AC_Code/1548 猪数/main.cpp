#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int show_date(int date,int digit)
{
	char result[1000];
	char temp[1000];
	int i=0;
	if(date==0)
	{
		result[0]='0';
		result[1]='\0';
	}//考虑date为零的时候
	while(date!=0)
	{
		if (date%digit>=10)
		{
			temp[i]='A'+(date%digit)-10;
		}
		else
		{
			temp[i]='0'+(date%digit);
		}
		i++;
		date=date/digit;	
	}
	i--;	
	int j=0;
	while(i>=0)
	{
		result[j]=temp[i];
		i--;
		j++;
	}
	result[j]='\0';
	cout<<result<<' ';
	return 0;
}
int digit_change(int date,int digit,char *result)
{
	int temp2=date;
	char temp[1000];
	int i=0;
	if(date==0)
	{
		result[0]='0';
		result[1]='\0';
	}//考虑date为零的时候
	while(date!=0)
	{
		
		
		if (date%digit>=10)
		{
			temp[i]='A'+(date%digit)-10;
		}
		else
		{
			temp[i]='0'+(date%digit);
		}
		i++;
		date=date/digit;	
	}
	i--;
	int j=0;
	while(i>=0)
	{
		result[j]=temp[i];
		i--;
		j++;
	}
	result[j]='\0';
	for (i=0;i<strlen(result);i++)
	{
		if (result[i]!=temp[i])
		{
			return 0;
		}
	}
	//	cout<<sqrt(temp2)<<' ';
	show_date((int)sqrt((float)temp2),digit);
	cout<<result<<endl;
	return 0;
}

int main()
{
	int b;
	char reslult[1000];
	while(cin>>b)
	{
		int i;
		for (i=1;i<=300;i++)
		{
			digit_change(i*i,b,reslult);
		}
		
	}
	
	return 0;
}
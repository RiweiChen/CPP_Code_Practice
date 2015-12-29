#include<iostream>
#include<cstring>
using namespace std;
int big_mul(int * result,char *date1,char *date2)
{
	char temp;
	int i,j;
	//去除前导0处理。
	/*
	int k=0;
	
	while(date1[k]=='0')
	{
		k++;//记录前导0的个数。
	}
	if (k>0)
	{
		for (i=k;date1[i]!='\0';i++)
		{
			date1[i-k]=date1[i];
		}
	}
	date1[i-k]='\0';

	k=0;
	while(date2[k]=='0')
	{
		k++;//记录前导0的个数。
	}
	if (k>0)
	{
		for (i=k;date2[i]!='\0';i++)
		{
			date2[i-k]=date2[i];
		}
	}
	date2[i-k]='\0';

  */
	int length1=strlen(date1);
	int length2=strlen(date2);
	int length=length1+length2-1;
	
	//字符串倒置
	if (length2<length1)
	{
		big_mul(result,date2,date1);
		return 0;
	}
	for(i=0;i<=((length1-1 )/2);i++)
	{
		temp=date1[i];
		date1[i]=date1[length1-i-1];
		date1[length1-i-1]=temp;
	}
	for(i=0;i<=((length2-1) /2);i++)
	{
		temp=date2[i];
		date2[i]=date2[length2-i-1];
		date2[length2-i-1]=temp;
	}
	for(i=0;i<length;i++)
	{
		result[i]=0;
		if (i<=length1-1)
		{
			for(j=i;j>=0;j--)
			{
				result[i]=result[i]+(date1[j]-'0')*(date2[i-j]-'0');
			}
		}
		if(i>length1-1&&i<=(length1+(length2-length1)-1))
		{
			for(j=length1-1;j>=0;j--)
			{
				result[i]=result[i]+(date1[j]-'0')*(date2[i-j]-'0');
			}
				
		}
		if(i>(length1+(length2-length1)-1))
		{
			for(j=length1-1;j>=i-(length2-1);j--)
			{
				result[i]=result[i]+(date1[j]-'0')*(date2[i-j]-'0');
			}
		}
	}

	for(i=0;i<length;i++)
	{
		if (result[i]>10)
		{
			if (i==length-1)
			{
				length++;
			}
			result[i+1]=result[i+1]+result[i]/10;
			result[i]=result[i]%10;
		}
	}
	int first=0;
	for (i=length-1;i>=0;i--)
	{
		if (first==0&&result[i]==0)
		{
			;
		}
		else
		{
			cout<<result[i];
			first=1;
		}
		
	}
	if (first==0)
	{
		cout<<0;
	}
	cout<<endl;
	return 0;

}
int main()
{
	char date1[100],date2[100];
	while (gets(date1))
	{
		int result[1000]={0};
		gets(date2);
		big_mul(result,date1,date2);
		
	}
	return 0;
}

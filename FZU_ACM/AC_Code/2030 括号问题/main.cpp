#include<iostream>
#include<stack>
using namespace std;
int date[16];
bool judge(char *str)
{
	int k=0;
	stack<char> sta;
	while(str[k]!='\0')
	{
		if(str[k]=='(')
			sta.push(str[k]);
		else
		{
			if(sta.empty()==true||sta.top()!='(')
				return false;
			else
			sta.pop();
		}
		k++;
	}
	if(sta.empty()==true)
		return true;
	else
		return false;
}
int tobinary(int w,int n)
{
	int k=0;
	int i,temp[16];
	while(n>0)
	{
		temp[k]=n%2;
		k++;
		n=n/2;
	}
	int j=0;
	while(w-k>0)
	{
		j++;
		w--;
	}
	for(i=k-1;i>=0;i--)
	{
		date[j]=temp[i];
		j++;
	}
return 0;
}
int main()
{
	char str[17];
	char temp[17];
	while(gets(str))
	{
		int i=0,n=0;
		while(str[i]!='\0')
		{
			if(str[i]=='?')
				n++;
			i++;
		}
		int time=1;
		for(i=0;i<n;i++)
		{
			time=time*2;
		}
		int result=0;
		for(i=0;i<time;i++)
		{
			int a;
			for(a=0;a<16;a++)
			{
				date[a]=0;
			}
			tobinary(n,i);
			int k=0;int j=0;
			while(str[j]!='\0')
			{
				if(str[j]!='?')
					temp[j]=str[j];
				else
				{
					if(date[k]==0)
						temp[j]='(';
					else
						temp[j]=')';
					k++;
				}
				j++;
			}
			temp[j]='\0';
			if(judge(temp)==true)
				result++;
		}
		cout<<result<<endl;
	}

	return 0;
}
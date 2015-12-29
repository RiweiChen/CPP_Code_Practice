#include<iostream>
using namespace std;
int main()
{
	char str[101];
	while (cin>>str)//小技巧。当出现第一个‘-’号时，它的后面的数字都要变成负数。而不用去管它的后面有多少个的正负号。都是一样的。
	{
		//首先要做的就是从字符串中提取每一个数字。
		int i=0;
		int temp=0;
		int flag=0;//表示是否出现负号了。
		long long result=0;
		while(str[i]!='\0')
		{
			if (str[i]!='-'&&str[i]!='+')
			{
				temp=temp*10+(str[i]-'0');
				if (str[i+1]=='\0')
				{
					if (flag==0)
					{
						result=result+temp;
					}
					else
					{
						result=result-temp;
					}
				}
			}
			else
			{
				if (str[i]=='+'&&flag==0)
				{
					result=result+temp;
					temp=0;
				}
				else if (str[i]=='-'&&flag==0)
				{
					result=result+temp;
					flag=1;
					temp=0;
				}
				else
				{
					result=result-temp;
					temp=0;
				}

			}

			i++;
		}
		cout<<result<<endl;
	}
	return 0;
}
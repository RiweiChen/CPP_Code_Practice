#include<iostream>
using namespace std;
int main()
{
	char str[101];
	while (cin>>str)//С���ɡ������ֵ�һ����-����ʱ�����ĺ�������ֶ�Ҫ��ɸ�����������ȥ�����ĺ����ж��ٸ��������š�����һ���ġ�
	{
		//����Ҫ���ľ��Ǵ��ַ�������ȡÿһ�����֡�
		int i=0;
		int temp=0;
		int flag=0;//��ʾ�Ƿ���ָ����ˡ�
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
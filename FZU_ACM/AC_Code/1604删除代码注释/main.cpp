//ע�Ȿ�⿼�ǵıȽϼ򵥡��ܶ������û�п��ǽ�ȥ�����磺"acb//woglag"
#include<iostream>
#include<cstring>
using namespace std;
char date[100001];
int main()
{
	int len=0;
	int line_len;
	while(gets(date+len)!=NULL)
	{
		line_len=strlen(date+len);
		len+=line_len;
		date[len]='\n';
		len++;
	}
	date[len]='\0';
	int i=0;
	int flag=1;
	while (i<len)
	{
		if (i+1<len&&date[i]=='/'&&date[i+1]=='/')
		{
			date[i]=date[i+1]=' ';//�ÿո���棬������ֱ����\nȥ����date[i];
			i=i+2;
			while (date[i]!='\n')
			{
				date[i]=' ';
				i++;
			}
			i++;
		}
		else if (i+1<len&&date[i]=='/'&&date[i+1]=='*'&&flag)
		{
			int j=i+2;
			while (j+1<len)
			{
				if (date[j]=='*'&&date[j+1]=='/')
				{
					break;
				}
				j++;
			}
			if (j+1==len)//û��ƥ��ʱ��
			{
				flag=0;//���ñ�־λ�������´λ�һ�α�����
				i=i+2;
				continue;
			}
			else
			{
				j++;
				for (int t=i;t<=j;t++)
				{
					if (date[t]!='\n')//�������и�ʽ��
					{
						date[t]=' ';
					}
					
				}
			
			}
			i=j+1;
		}
		else
			i++;

	}
	cout<<date;
	
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	char date[261];
	while (gets(date))//������ʽ�ַ�����
	{
		int left1=0,left2=0,right1=0,right2=0;//�������ӵ�ֵ������ʼ��Ϊ0.
		int i=0;
		int flag=1;//flag==1��ʾ������
		int temp=0;
		while (date[i]!='=')//�ȿ�����һ��������
		{
				
				//flag=1;//��һ�������ǲ�����ֵġ����Ե�Ĭ��Ϊ1����������һ��Ҳ����©����
			
				if (date[i]=='+')
				{
					temp=0;
					flag=1;
				}
				if(date[i]=='-') 
				{
					temp=0;
					flag=-1;//��ʾ������
				}
				while(date[i]>='0'&&date[i]<='9')//��ȡ�����ݡ�
				{
					temp=temp*10+(date[i]-'0');
					i++;
				}
				if (date[i]=='+'||date[i]=='-')//��ʾ�������������
				{
					left2=left2+flag*temp;
					
					if (date[i]=='+')
					{
						temp=0;
						flag=1;
					}
					if(date[i]=='-') 
					{
						temp=0;
						flag=-1;//��ʾ������
					}
				}
				if (date[i]=='x')
				{
					if (i==0)
					{
						left1=1;
					}
					else	if(date[i-1]>='0'&&date[i-1]<='9')//��ʾ�������г�����x��ϵ����
					{
						left1=left1+flag*temp;
					}
					else	if (date[i-1]=='+')
					{
						left1=left1+1;
					}
					else	if (date[i-1]=='-')
					{
						left1=left1-1;
					}
				}
				if (date[i]=='=')
				{
					if(date[i-1]>='0'&&date[i-1]<='9')//��������λ������
						left2=left2+flag*temp;
					break;
				}
			
			i++;

		}
	//	cout<<left1<<' '<<left2<<endl;

		int t=i;
		i=i+1;
		temp=0;
		flag=1;
		while (date[i]!='\0')//��������һ�ߵ������
		{
			
			//flag=1;//��һ�������ǲ�����ֵġ����Ե�Ĭ��Ϊ1����������һ��Ҳ����©����
			
			if (date[i]=='+')
			{
				temp=0;
				flag=1;
			}
			if(date[i]=='-') 
			{
				temp=0;
				flag=-1;//��ʾ������
			}
			while(date[i]>='0'&&date[i]<='9')//��ȡ�����ݡ�
			{
				temp=temp*10+(date[i]-'0');
				i++;
			}
			if (date[i]=='+'||date[i]=='-')//��ʾ�������������
			{
				right2=right2+flag*temp;
				
				if (date[i]=='+')
				{
					temp=0;
					flag=1;
				}
				if(date[i]=='-') 
				{
					temp=0;
					flag=-1;//��ʾ������
				}
			}
			if (date[i]=='x')
			{
				if (i-1==t)
				{
					right1=1;
				}
				else	if(date[i-1]>='0'&&date[i-1]<='9')//��ʾ�������г�����x��ϵ����
				{
					right1=right1+flag*temp;
				}
				else	if (date[i-1]=='+')
				{
					right1=right1+1;
				}
				else	if (date[i-1]=='-')
				{
					right1=right1-1;
				}
			}
			if (date[i]=='\0')
			{
				if(date[i-1]>='0'&&date[i-1]<='9')//��������λ������
					right2=right2+flag*temp;
				break;
			}
			
			i++;
			
		}
	//	cout<<right1<<' '<<right2<<endl;


		//�жϡ�
		int result;
		if ((left1==right1)&&(left2!=right2))
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
		else if (left1==right1&&left2==right2)//�ɱ���������⡣
		{
			
			cout<<"IDENTITY"<<endl;
		}
		else
		{
			//������ʱ��
			if ((right2-left2)*(left1-right1)>0)
			{
				result=(int)(abs(right2-left2)/abs(left1-right1));
				cout<<result<<endl;
			}
			else
			{
				result=(int)(abs(right2-left2)/abs(left1-right1));
				if (abs(right2-left2)%abs(left1-right1)>0)
				{
					result=result+1;
				}
				result=-result;
				cout<<result<<endl;

			}
		}
	}
	return 0;
}
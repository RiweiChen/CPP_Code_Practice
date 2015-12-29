#include<iostream>
using namespace std;
int main()
{
	char date[261];
	while (gets(date))//输入表达式字符串。
	{
		int left1=0,left2=0,right1=0,right2=0;//各个因子的值，并初始化为0.
		int i=0;
		int flag=1;//flag==1表示正数。
		int temp=0;
		while (date[i]!='=')//先考虑求一遍的情况。
		{
				
				//flag=1;//第一个正号是不会出现的。所以得默认为1正。而负号一个也不会漏掉。
			
				if (date[i]=='+')
				{
					temp=0;
					flag=1;
				}
				if(date[i]=='-') 
				{
					temp=0;
					flag=-1;//表示负数。
				}
				while(date[i]>='0'&&date[i]<='9')//提取出数据。
				{
					temp=temp*10+(date[i]-'0');
					i++;
				}
				if (date[i]=='+'||date[i]=='-')//表示数字输入结束。
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
						flag=-1;//表示负数。
					}
				}
				if (date[i]=='x')
				{
					if (i==0)
					{
						left1=1;
					}
					else	if(date[i-1]>='0'&&date[i-1]<='9')//表示真真切切出现了x的系数。
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
					if(date[i-1]>='0'&&date[i-1]<='9')//考虑最后的位数处理。
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
		while (date[i]!='\0')//考虑求另一边的情况。
		{
			
			//flag=1;//第一个正号是不会出现的。所以得默认为1正。而负号一个也不会漏掉。
			
			if (date[i]=='+')
			{
				temp=0;
				flag=1;
			}
			if(date[i]=='-') 
			{
				temp=0;
				flag=-1;//表示负数。
			}
			while(date[i]>='0'&&date[i]<='9')//提取出数据。
			{
				temp=temp*10+(date[i]-'0');
				i++;
			}
			if (date[i]=='+'||date[i]=='-')//表示数字输入结束。
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
					flag=-1;//表示负数。
				}
			}
			if (date[i]=='x')
			{
				if (i-1==t)
				{
					right1=1;
				}
				else	if(date[i-1]>='0'&&date[i-1]<='9')//表示真真切切出现了x的系数。
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
				if(date[i-1]>='0'&&date[i-1]<='9')//考虑最后的位数处理。
					right2=right2+flag*temp;
				break;
			}
			
			i++;
			
		}
	//	cout<<right1<<' '<<right2<<endl;


		//判断。
		int result;
		if ((left1==right1)&&(left2!=right2))
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
		else if (left1==right1&&left2==right2)//成比例，无穷解。
		{
			
			cout<<"IDENTITY"<<endl;
		}
		else
		{
			//正数的时候
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
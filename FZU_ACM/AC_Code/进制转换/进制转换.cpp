//进制转换：10进制数转换为N进制数：除N取余倒着写。。。
//试着用迭代器学东西。
/*#include<iostream>
#include<string>
using namespace std;
char * result;
void ChangDigit(int date ,int digit)
{
	char *temp;
	int i=0;
	while(date/digit>=digit)
	{
		
		if (date%digit>=10)
		{
			temp[i]='A'+(date%digit);
		}
		else
		{
			temp[i]='0'+(date%digit);
		}
		i++;
		date=date/digit;
	}
	if (date!=0)
	{
		
		if (date%digit>=10)
		{
			temp[i]='A'+(date%digit);
		}
		else
		{
			temp[i]='0'+(date%digit);
		}
	}
	else
	{
		i--;
	}
	int j=0;
	while(i>=0)
	{
		result[j]=temp[i];
		i--;
		j++;
	}
	result[j]='\0';

}

int main()
{
	int date,digit;
	while(scanf("%d%d",&date,&digit)!=EOF)
	{
		ChangDigit(date,digit);
		cout<<result<<endl;

	}
return 0;
}



*/
#include<iostream>
#include<string>
using namespace std;
char result[14];
int ChangDigit(int date ,int digit)
{
	char temp[14];
	int i=0;
	if(date==0)
	{
		result[0]='0';
		result[1]='\0';
			return 0;
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
	return 0;
}

int main()
{
	int date,digit;
	while(scanf("%d%d",&date,&digit)!=EOF)
	{
		ChangDigit(date,digit);
		cout<<result<<endl;
		
	}
	return 0;
}
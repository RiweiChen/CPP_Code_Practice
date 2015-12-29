#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int a,b,c;
	int digit;
	while(cin>>a>>b)
	{
		digit=1;
		c=a-b;
		int flag=0;
		if(c<0)
		{
			flag=1;
			c=-c;
		}
		int temp=c;
		while(temp/10>0)
		{
			temp=temp/10;
			digit++;
		}//用digit记录位数。
		stack<char> sta;
		int i;
		char ch;
		int date;
		for(i=1;i<=digit;i++)
		{
			date=c%10;
			c=c/10;
			ch=date+'0';
			sta.push(ch);
			if(i%3==0&&i!=digit)
				sta.push(',');
		}
		if(flag==1)
			sta.push('-');

		while(!sta.empty())
		{
			ch=sta.top();
			cout<<ch;
			sta.pop();
		}
		cout<<endl;
	}
	return 0;
}
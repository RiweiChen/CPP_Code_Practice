#include<iostream>
#include<deque>
#include<iterator>
using namespace std;
int main()
{
	char str[10001];
	while(cin>>str)
	{
		deque<char> deq;
		deq.resize(0);
		deque<char>::iterator itera1,itera2,itera;
		int i=0;
		while(str[i]!='\0')
		{
			if(str[i]=='(')
			{
				deq.push_back(str[i]);
			}
			if(str[i]==')')
			{
				if(deq.empty()==false&&deq.back()=='(')//重点。这不是!=0
				{
					deq.pop_back();
				}
				else
				{
					deq.push_back(str[i]);
				}
			}
			i++;
		}
		if(deq.empty()==true)//不是等于0
		{
			cout<<str<<endl;
			continue;
		}
		
		itera1=deq.begin();
		itera2=deq.end();
		for(itera=deq.begin();itera<deq.end();itera++)
		{
			cout<<*itera;
		}
		cout<<endl;
		/*
		for(itera=itera1;itera<itera2;itera++)
		{
			if(*itera==')')
				deq.push_front('(');
			if(*itera=='(')
				deq.push_back(')');
		}
		for(itera=deq.begin();itera<deq.end();itera++)
		{
			cout<<*itera;
		}
		cout<<endl;
		*/
		int length_a=0,length_b=0;
		for(itera=itera1;itera<itera2;itera++)
		{
			if (*itera==')')
			{
				length_a++;
			}
			else
			{
				length_b++;
			}
		}
		int k;
		for (k=0;k<length_a;k++)
		{
			cout<<'(';
		}
		for(itera=deq.begin();itera<deq.end();itera++)
		{
			cout<<*itera;
		}
		for (k=0;k<length_b;k++)
		{
			cout<<')';
		}
		cout<<endl;
	}
	return 0;
}
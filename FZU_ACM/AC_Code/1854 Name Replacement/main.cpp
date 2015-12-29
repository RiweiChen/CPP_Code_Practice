#include<iostream>
using namespace std;
int main()
{
	char str[1000];
	while(gets(str))
	{
		int i=0;
		while(str[i]!='\0')
		{
			if(str[i]=='c'&&str[i+1]=='c'&&str[i+2]=='Q')
			{
				str[i]='c';
				str[i+1]='x';
				str[i+2]='w';
			}
			i++;
		}
	  puts(str);
	}
	return 0;
}
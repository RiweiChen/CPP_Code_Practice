#include<iostream>
using namespace std;
int main()
{
	char str[81];
	while(gets(str))
	{
		int i=0;
		while(str[i]!='\0')
		{
			if(str[i]>=68&&str[i]<=90)
				str[i]=str[i]-3;
			else if(str[i]>=100&&str[i]<=122)
				str[i]=str[i]-3;
			else if(str[i]=='A')
				str[i]='X';
			else if(str[i]=='B')
				str[i]='Y';
			else if(str[i]=='C')
				str[i]='Z';
			else if(str[i]=='a')
				str[i]='x';
			else if(str[i]=='b')
				str[i]='y';
			else if(str[i]=='c')
				str[i]='z';
			i++;


		}
		puts(str);
	}
	return 0;
}
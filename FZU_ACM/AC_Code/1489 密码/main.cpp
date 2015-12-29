#include<iostream>
using namespace std;
int main()
{
	
	char str1[27];
	while(gets(str1))
	{
		int i=0;
		int different[255]={0};
		while(str1[i]!='\0')
		{
			
			different['A'+i]=str1[i]-'A'-i;
			different['a'+i]=different['A'+i];
			i++;
		}
		char str2[101];
		gets(str2);
		i=0;
		while(str2[i]!='\0')
		{
			str2[i]=str2[i]+different[str2[i]];
			i++;
		}
		puts(str2);
	}

		return 0;
}
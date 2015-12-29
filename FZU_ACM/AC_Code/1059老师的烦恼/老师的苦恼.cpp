#include <iostream>
#include<cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int t;
	char  str[50];
	while (gets(str))
	{
		for (t=0;t<strlen(str);t++)
		{
			if (str[t]>='A'&&str[t]<='Z')
			{
				str[t]=str[t]+32;
			}

		}
		printf("%s\n",str);
	}
	return 0;

}

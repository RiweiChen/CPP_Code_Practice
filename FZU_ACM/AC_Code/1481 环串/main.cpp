#include <iostream>
#include <cstring>
using namespace std;
void circle_ones(char *p)
{
	char temp[201];
	int n=strlen(p);
	int i;
	temp[n]='\0';
	temp[0]=p[n-1];
	for (i=0;i<n-1;i++)
	{
		temp[i+1]=p[i];
	}
	strcpy(p,temp);
}
int main()
{
	char str[201];
	int n;
	while(cin>>str)
	{
		cin>>n;
		int num=0;
		char temp[201];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			int m;
			m=strlen(temp);
			int j;
			for (j=0;j<m;j++)
			{
				
				if (strcmp(temp,str)==0)
				{
					num++;
					break;
				}
				circle_ones(temp);
			}
			

		}
		cout<<num<<endl;

	}
	
	return 0;
}
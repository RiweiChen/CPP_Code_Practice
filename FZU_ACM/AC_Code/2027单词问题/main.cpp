#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[101];
	while(cin>>str)
	{
	int i=0;
	int flag=0;
	char words[100][100];
	int j=-1;
	int k=0;
	while(str[i]!='\0')
	{
		if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
		{
			if(flag==0)
				j++;
			flag=1;
			words[j][k++]=str[i];

		}
		else 
		{
			if(flag==1)
			{
				//j++;
				flag=0;
				words[j][k]='\0';
				k=0;
			}
		}

		i++;
	}
	if(flag==1)
		words[j][k]='\0';
	for(i=0;i<=j;i++)
	{
		for(k=0;k<i;k++)
		{
			if(strcmp(words[i],words[k])==0)
				break;
		}
		if(k==i)
			cout<<words[i]<<endl;
	}
	if(j==-1)
		cout<<endl;
	}

	return 0;
}

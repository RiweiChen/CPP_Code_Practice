#include<iostream>
using namespace std;
int char_sort(char *str1,char *str2)
{
	int date[27];
	int i;
	for(i=0;i<27;i++)
	{
		date[i]=0;
	}
	i=0;
	while(str1[i]!='\0')
	{
		date[str1[i]-'A']++;
		i++;
	}
	int j=0;
	int k=0;
	for(i=0;i<27;i++)
	{
		if(date[i]!=0)
		{
			for(k=1;k<=date[i];k++)
			{
				str2[j]='A'+i;
				j++;
			}
		}	
	}
	str2[j]='\0';
	return 0;
}
int main()
{
	int t;
	int i;
	char str1[101];
	char str2[101];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		int length;
		cin>>length;
		cin>>str1;
		char_sort(str1,str2);
	//	cout<<str1<<endl;
	//	cout<<str2<<endl;
		int result=0;
		int j;
		for(j=0;j<length;j++)
		{
			if(str1[j]!=str2[j])
				result++;
		}
		cout<<"Case "<<i<<": "<<result<<endl;
	}
	return 0;
}
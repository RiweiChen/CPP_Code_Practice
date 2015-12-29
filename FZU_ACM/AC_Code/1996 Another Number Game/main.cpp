#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i;
	char name[8];
	char name1[3]="PH",name2[8]="XiaoBo";
	int flag=0;
	for(i=1;i<=t;i++)
	{
		cin>>name;
		if(strcmp(name,name1)==0)
			flag=1;//PH开始为1.
		else
			flag=-1;//否则为-1.
		int n;
		cin>>n;
		getchar();
		while(n!=1)
		{
			if(n%2==0)
			{
				n=n/2;
				flag=-flag;
			}
			else
			{
				n=n-1;
				flag=-flag;
			}
		}
		if(flag==1)
		{
			cout<<"Case "<<i<<": "<<name2<<endl;
		}
		else
		{
			cout<<"Case "<<i<<": "<<name1<<endl;
		}
	}
	return 0;
}
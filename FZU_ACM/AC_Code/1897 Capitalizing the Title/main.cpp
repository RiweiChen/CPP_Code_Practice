#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	getchar();
	int i,j;
	for (i=1;i<=t;i++)
	{
		char date[101];
		gets(date);
		j=0;
		while(date[j]!='\0')
		{
			if (j==0&&date[j]>='a'&&date[j]<='z')
			{
				date[j]=date[j]-32;
			}
			else if (date[j-1]==' '&&date[j]>='a'&&date[j]<='z')
			{
				date[j]=date[j]-32;
			}
			j++;
		}

		cout<<"Case #"<<i<<": ";
		puts(date);
	//	cout<<endl;
	}
	return 0;

}
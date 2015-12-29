#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char *date[11]={" ","one","two","three","four","five","six","seven","eight","nine","ten"};
	int i;
	int a,b;
	char date1[7],date2[7];
	for (i=0;i<t;i++)
	{
		cin>>date1;
		getchar();
		cin>>date2;
		getchar();
		int j;
		for (j=1;j<=10;j++)
		{
			if (strcmp(date[j],date1)==0)
			{
				a=j;
			}
			if (strcmp(date[j],date2)==0)
			{
				b=j;
			}
		}
		for (j=a;j<=b;j++)
		{
			if (j==a)
			{
				cout<<date[j];
			}
			else
			{
				cout<<' '<<date[j];
			}
		}
		cout<<endl;
	}
	return 0;
}
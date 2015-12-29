#include<iostream>
#include<string.h>
void oppose_order(char *line);
using namespace std;
int main()
{
	int n,temp;
	cin>>n;
	char * * article =new char* [n+1];
	for(temp=0;temp<n+1;temp++)
	{
		article[temp]=new char[200] ;
		gets(article[temp]);
	}
	
	for(temp=1;temp<n+1;temp++)
	{
		oppose_order(article[temp]);
	}	
	for(temp=1;temp<n+1;temp++)
	{
		cout<<article[temp]<<endl;
	}
	for(temp=0;temp<n+1;temp++)
	   delete []  article[temp];
	delete [] article;
	return 0;
}
void oppose_order(char * line)
{
	int n,i;
	char temp;
	n=strlen(line);
	for(i=0;i<(n/2);i++)
	{
		temp=line[i];
		line[i]=line[n-i-1];
		line[n-i-1]=temp;
	}
}






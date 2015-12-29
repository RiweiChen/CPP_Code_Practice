#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(m==0&&n==0)
			break;
		char **date=new char*[n+2];
		int i;
		for(i=0;i<n+2;i++)
		{
			date[i]=new char[m+2] ;
		}
		for(i=0;i<=n+1;i++)
		{
			date[i][0]='.';
			date[i][m+1]='.';
		}
		for(i=0;i<=m+1;i++)
		{
			date[0][i]='.';
			date[n+1][i]='.';
		}
		int j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>date[i][j];
			}
			getchar();
		}
		
		int num=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{ 
				if(date[i][j]!='*')
				{
				num=0;
				if(date[i][j+1]=='*')
					num++;
				if(date[i][j-1]=='*')
					num++;
				if(date[i+1][j]=='*')
					num++;
				if(date[i-1][j]=='*')
					num++;
				if(date[i+1][j+1]=='*')
					num++;
				if(date[i-1][j+1]=='*')
					num++;
				if(date[i+1][j-1]=='*')
					num++;
				if(date[i-1][j-1]=='*')
					num++;
				date[i][j]='0'+num;
				}
						
			}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cout<<date[i][j];
			}
		cout<<endl;
		}
		cout<<endl;
			
		for(i=0;i<n+2;i++)
		{
			delete [] date[i];
		}
		delete [] date;
	}

	return 0;
}
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	int i,j,k;
	cin>>t;
	int n,m,c;
	char str[15];
	for (i=1;i<=t;i++)
	{
		cout<<"Case "<<i<<':'<<endl;
		cin>>n>>m>>c;
		int **date=new int *[n];
		for (j=0;j<n;j++)
		{
			date[j]=new int[m];
		}


		for (j=0;j<n;j++)
		{
			for (k=0;k<m;k++)
			{
				cin>>date[j][k];
			}
		}
		getchar();
	
		for (j=0;j<c;j++)
		{
			k=0;
			gets(str);
			while (str[k]!='\0')
			{
				cout<<setw(2)<<setfill('0')<<date[str[k+1]-'1'][str[k]-'A'];
				//printf("%2d",date[str[k+1]-'1'][str[k]-'A']);
				k=k+2;

			}
			cout<<endl;
		}



		for (j=0;j<n;j++)
		{
			delete [] date[j];
		}
		delete [] date;
		

	}

	return 0;
}
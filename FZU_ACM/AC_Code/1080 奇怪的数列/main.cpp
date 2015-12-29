#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		int m;
		cin>>m;
		int *date=new int [m];
		int *temp=new int [m];
		int j;
		for(j=0;j<m;j++)     
		{
			cin>>date[j];
		}
		while(true)
		{
			temp[m-2]=date[m-1];
			for(j=m-4;j>=0;j=j-2)
			{
				temp[j]=date[j+1]-temp[j+2];
				if(temp[j]<0)
					goto over;
			}
			if(j==-1)
			{
				temp[0]=date[0]-temp[1];
				for(j=2;j<=m-1;j=j+2)
				{
					temp[j]=date[j-1]-temp[j-2];
					if(temp[j]<0)
						goto over;
				}

			}
			if(j==-2)
			{
				temp[1]=date[0]-temp[0];
				for(j=3;j<=m-1;j=j+2)
				{
					temp[j]=date[j-1]-temp[j-2];
					if(temp[j]<0)
						goto over;
				}
			}
			for(j=0;j<m;j++)
			{
				date[j]=temp[j];
			}
		}




over:
		for(j=0;j<m-1;j++)
		{
			cout<<date[j]<<' ';
		}
		cout<<date[m-1]<<endl;

		delete [] date;
		delete [] temp;
	}
	return 0;
}

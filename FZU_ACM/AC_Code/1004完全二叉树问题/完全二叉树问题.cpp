#include<iostream>
using namespace std;
int main()
{
	int line;
	while (cin>>line)
	{
		if (line==0)
		{
			cout<<0<<endl;
			continue;
		}
		
	
	;
	int i,j;
	int **date=new int *[line];
	for (i=0;i<line;i++)
	{
		date[i]=new int[i+1];
		for(j=0;j<=i;j++)
		{
			cin>>date[i][j];

		}
		
	}//������ݵ����룻


	for (i=line-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			date[i-1][j]=date[i-1][j]+(date[i][j]>date[i][j+1]?date[i][j]:date[i][j+1]);
		}
	}
	cout<<date[0][0]<<endl;
	//���ݴ���ó������

	//�ͷſռ䣻
	for (i=0;i<line;i++)
	{
		delete []date[i];
	}
	delete [] date;
	}
	return 0;
}

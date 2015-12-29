#include<iostream>
using namespace std;
struct dates
{
	int valu;
	int times;
};
int main()
{
	int n,i,j,k,t;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		char str[10001];
		dates date[10001]; 
		for (j=0;j<10001;j++)
		{
			date[j].valu=0;
			date[j].times=0;
		}
		gets(str);
		j=0;k=0;
		while(str[j]!='\0')
		{
			if(str[j]=='3')
			{
				date[k].valu=3;
				k++;
			}
			 else if(str[j]=='1')
			{
				date[k].valu=1;
				k++;
			}
			else if(str[j]=='4')
			{
				date[k].valu=4;
				k++;
			}
			j++;
		}

		int temp=0;
		for (j=k-1;j>=0;j--)
		{
			if (date[j].valu==4)
			{
				++temp;
			}
			if (date[j].valu==1)
			{
				date[j].times=temp;
			}
		}

		temp=0;
		for (j=k-1;j>=0;j--)
		{
			if (date[j].valu==1)
			{
				temp=temp+date[j].times;
			}
			if (date[j].valu==3)
			{
				date[j].times=temp;
			}
		}

		long long count=0;
		/*
		for (j=0;j<k;j++)
		{
			if(date[j].valu==3)
			{
				for (t=j+1;t<k;t++)
				{
					if(date[t].valu==1)
					{
						count=count+date[t].times;
					}
				}
			}	
		}
		cout<<"Case "<<i<<": "<<count<<endl;
		*/

		count=0;
		for (j=0;j<k;j++)
		{
			/*if(date[j].valu==3)
			{
				for (t=j+1;t<k;t++)
				{
					if(date[t].valu==1)
					{
						count=count+date[t].times;
					}
				}
			}	*/
			if(date[j].valu==3)
			{
				count=count+date[j].times;
			}

		}
	
		cout<<"Case "<<i<<": "<<count<<endl;
		 
	}
	return 0;
}



#include<iostream>
#include<cstring>
using namespace std;
struct date
{
	char name[17];
	int valu;
};
int main()
{
	int n,m;
	cin>>n>>m;
	getchar();
	{
		date *dates=new date[n];
		int i,t;
		for (i=0;i<n;i++)
		{
			cin>>dates[i].name;
			cin>>dates[i].valu;
		}
		char line[300];
		char word[25];
		for (i=0;i<m;i++)
		{
			bool *state=new bool[n];
			memset(state,false,n);
			int result=0;
			while (gets(line))
			{
				if (strcmp(line,".")==0)
				{
					break;
				}
				int j=0;
				int k=0;
				while (line[j]!='\0')
				{
					if (line[j]!=' ')
					{
						word[k]=line[j];
						k++;
					}
					else
					{
						word[k]='\0';
						k=0;
						for (t=0;t<n;t++)
						{
							if(strcmp(word,dates[t].name)==0)
							{//&&state[t]==false
								result=result+dates[t].valu;
								state[t]=true;
							}
						}

					}
					if (line[j+1]=='\0')
					{
						word[k]='\0';
						for (t=0;t<n;t++)
						{
							if(strcmp(word,dates[t].name)==0)
							{//&&state[t]==false
								result=result+dates[t].valu;
								state[t]=true;
							}
						}
					}
					j++;
				}
				


			}
			delete [] state;
			cout<<result<<endl;

		}

		delete dates;

	}

	return 0;
}
#include<iostream>
#include<deque>
#include<cstring>

using namespace std;
int main()
{
	deque<int> dates[10001];
	int n,m,i,j;
	int id,date;
	char word[6];
	while(cin>>n>>m)
	{
		for(i=0;i<m;i++)
		{
			scanf("%s",word);
			if(strcmp(word,"INIT")==0)
			{
				for(j=0;j<=n;j++)
				{
					dates[j].clear();
				}

			}
			if(strcmp(word,"PUSH")==0)
			{
				cin>>id>>date;
				dates[id].push_back(date);

			}
			if(strcmp(word,"POP")==0)
			{
				cin>>id;
				if(dates[id].empty())
				{
					cout<<"NULL"<<endl;
				}
				else
				{
					cout<<dates[id].front()<<endl;
					dates[id].pop_front();
				}


			}


		}

	}
	return 0;
}
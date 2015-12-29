#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	getchar();
	char date[201];
	
	for(i=0;i<n;i++)
	{
		queue<char> que;
		gets(date);
		int j;
		j=0;
		while (date[j]!='\0')
		{
			if (date[j]==' ')
			{
				que.push(date[j]);
			}
			else
			{
				que.push(date[j]);
				int k=1;
				while(date[j+1]!=' '&&date[j+1]!='\0')		
				{
					k++;
					j++;
				}
				if (k==1)
				{

				}
				if (k>=2)
				{
					que.push(date[j]);

				}
			}
			j++;
		}
		char ch='\n';
		que.push(ch);
		while (que.empty()==0)
		{
			ch=que.front();
			cout<<ch;
			que.pop();
		}

	}
	return 0;
}
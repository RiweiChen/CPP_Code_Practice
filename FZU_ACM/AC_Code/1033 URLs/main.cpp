#include<iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	int i;
	cin>>n;
	getchar();
	char str[61];
	for (i=1;i<=n;i++)
	{
		gets(str);
		
		char Protocol[10];
		char Host[60];
		char Port[12];
		char Path[60];
		int j;
		j=0;
		int flag;
		flag=0;
		while(str[j]!='\0')
		{
			if (flag==0)
			{
				Protocol[j]=str[j];
			}
			if ((str[j]==':')&&(str[j+1]=='/')&&(str[j+2]=='/'))
			{
				Protocol[j]='\0';
				flag=1;
				j=j+3;
			}
			if (flag==1)
			{
				int k;
				k=0;
				while((str[j]!=':')&&(str[j]!='\0')&&(str[j]!='/'))
				{
					Host[k]=str[j];
					k++;
					j++;
				}
				Host[k]='\0';
				if (str[j]==':')
				{
					flag=2;
				}
				if (str[j]=='/')
				{
					strcpy(Port,"<default>");
					flag=3;
				}
				if(str[j]=='\0')
				{
					strcpy(Port,"<default>");
					strcpy(Path,"<default>");
					break;
				}
				
			}
			if (flag==2)
			{
				int m;
				m=0;
				j++;
				while ((str[j]!='/')&&(str[j]!='\0'))                                   
				{
					Port[m]=str[j];
					m++;
					j++;
				}
				Port[m]='\0';
				if (str[j]=='\0')
				{
					strcpy(Path,"<default>");
					break;
				}
				
				if (str[j]=='/')
				{
					flag=3;
				}
			}
			if (flag==3)
			{
				int p;
				p=0;
				j++;
				while(str[j]!='\0')
				{
					Path[p]=str[j];
					p++;
					j++;
				}
				Path[p]='\0';
				break;
			}
			j++;

		}
		cout<<"URL #"<<i<<endl;
		cout<<"Protocol = "<<Protocol<<endl;
		cout<<"Host     = "<<Host<<endl;
		cout<<"Port     = "<<Port<<endl;
		cout<<"Path     = "<<Path<<endl;
		cout<<endl;

	}
	return 0;
}
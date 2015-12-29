//寻找单词的根基。
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char str[1000001];
char temp[1000001];
int main()
{
	int length;
	while(cin>>str)
	{
		if (strcmp(str,".")==0)
		{
			break;
		}
		length=strlen(str);
		//求长度的公约数分别表示出来。
		vector<int> commem_div;
		commem_div.resize(0);
		int i;
		int commen_dir_number;
		commen_dir_number=0;
		for(i=1;i<=length;i++)
		{
			if (length%i==0)
			{
				commem_div.push_back(i);
				commen_dir_number++;
			}
		}
		int j;
		for (i=0;i<commen_dir_number;i++)
		{
			strncpy(temp,str,commem_div[i]);
			temp[commem_div[i]]='\0';
			for (j=0;j<length;j++)
			{
				if (str[j]!=temp[j%commem_div[i]])
				{
					break;//不成立。
				}
			}
			if (j==length)
			{
				cout<<(length/commem_div[i])<<endl;
				break;
			}
		}
	}
	return 0;
}
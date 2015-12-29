#include<iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	
	while (cin>>n)
	{
		int num=1;
		char **str=new char *[n];
		int i=0;
		for (i=0;i<n;i++)
		{
			str[i]=new char[20];
			cin>>str[i];
		}
		int j;
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(strcmpi(str[i],str[j])==0)//已经出现过了，结束这个查找。
					break;
			}
			if(j==i)//说明没有找到。
			{
				num++;
			}

		}
	

	
		cout<<num<<endl;
		for (i=0;i<n;i++)
		{
			delete [] str[i];
		}
		delete []str;

	}
	return 0;
}
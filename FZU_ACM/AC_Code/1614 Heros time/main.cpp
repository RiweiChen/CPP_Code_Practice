#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long long result;//ע�����ݷ�Χ��long ��int ���������
	while (cin>>n)
	{
		int *date=new int[n];
		int i;
		for (i=0;i<n;i++)
		{
			cin>>date[i];
		}
		sort(date,date+n);
		result=0;
		for (i=0;i<n;i++)
		{
			date[i]=result+date[i];
			result=date[i];
		}
		result=0;
		for (i=0;i<n;i++)
		{
			result=result+date[i];
		}
		cout<<result<<endl;
		delete []date;
	}
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int n,q,l,h,num;
	int temp;
	int num_of_score[101]={0};
	while(cin>>n)
	{
		for (int m=0;m<=101;m++)
		{
			num_of_score[m]=0;

		}//ÿ��ͳ������ǰ�������㡣
		for (int i=0;i<n;i++)
		{
			cin>>temp;
			num_of_score[temp]++;
		}
		cin>>q;
		for (int k=0;k<q;k++)
		{
			num=0;// ÿ��ͳ��ǰ���㡣
			cin>>l>>h;
			for (int j=l;j<=h;j++)
			{
				num+=num_of_score[j];
			}
			cout<<num<<endl;
		}
	}


	return 0;
}
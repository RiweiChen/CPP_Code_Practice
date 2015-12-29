//对于每一个数，判断它取余3是否等于1等价与把这个数的各个位加起来取余3是否等于1.
//考虑的是一个数一个数的放，递推。
#include<iostream>
using namespace std;
int date[1000001][3]={1,2,2};//当只有一位的时候，余数为0的有1个，余数为1的有2个，余数为2的也有两个。
int main()
{
	int i,n;
	for (i=1;i<1000000;i++)
	{
		date[i][0]=(date[i-1][0]*1+date[i-1][1]*2+date[i-1][2]*2)%100007;
		date[i][1]=(date[i-1][1]*1+date[i-1][0]*2+date[i-1][2]*2)%100007;
		date[i][2]=(date[i-1][2]*1+date[i-1][1]*2+date[i-1][0]*2)%100007;

	}
	while (cin>>n)
	{
		cout<<date[n-1][1]<<endl;
	}
	return 0;
}
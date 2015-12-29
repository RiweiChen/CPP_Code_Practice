//典型的用空间换时间。
#include<iostream>
using namespace std;
bool state[10000000];
int valu[500001];
int main()
{
	memset(state,false,10000000);
	int i,j;
	valu[0]=0;
	state[0]=true;
	for(i=1;i<=500000;i++)
	{
		if((valu[i-1]-i)>0&&state[valu[i-1]-i]==false)
		{
			valu[i]=valu[i-1]-i;
		}
		else
		{
			valu[i]=valu[i-1]+i;
		}
		state[valu[i]]=true;
	}
	while((cin>>j)&&(j!=-1))
	{
		cout<<valu[j]<<endl;
	}
	return 0;
}
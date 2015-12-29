/*
#include<iostream>
using namespace std;
int main()
{
	long times[15]={111111111111111,11111111111111,1111111111111,111111111111,11111111111,1111111111,111111111,11111111,1111111,111111,11111,1111,111,11,1};
	long date;
	while(cin>>date&&date!=0)
	{
		int i;
		for(i=0;i<15;i++)
		{
			if(date%times[i]==0)
			{
				int ans=date/times[i];
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}

*/

#include <stdio.h>
int main()
{
 long  long a,ans,k;
 while(scanf("%lld",&a) && a)
 {
  ans=1,k=11;
  while(k<=a)
  {
   if(a%k==0)
    ans=k;
   k=k*10+1;
  }
  printf("%lld\n",a/ans);
 }
 return 0;
}
#include<iostream>
using namespace std;
//一个数的因子的个数相关。最大公约数为一的数的个数。
//欧拉函数。
int eular(int n)  
{  
   int ret=1,i;  
   for (i=2;i*i<=n;i++)  
        if (n%i==0)  
       {  
          n/=i,ret*=i-1;  
          while (n%i==0)  
              n/=i,ret*=i;  
       }  
    if (n>1)  
        ret*=n-1;  
    return ret;  
}  
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int result=0;
		result=eular(n);
		cout<<result<<endl;
	}
	return 0;
}
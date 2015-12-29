//主要用到的公式有：
//1.1+2+3+....+i=(1+i)*i/2;
//2.1^2+2^2+3^2+4^2+...+i^2=(i)*(i+1)*(2i+1)/6;
//3.1^3+2^3+3^3+4^3+...+i^3=(i*(i+1)/2)^2;
//
//化简后最后的公式为。Di=(i)*(i+1)*(i+2)*a/6+i*(i+1)*(i+2)*(i-1)*d/24;
//
#include<iostream>
using namespace std;
int main()
{
	long long a,d,i;//i一定要long long 
	long long result;
	int di;
	while(cin>>a>>d>>i)//须防止溢出。
	{
		di=((i%2009)*((i+1)%2009))%2009*((i+2)%2009)%2009*a/6+(((i%2009)*((i+1)%2009)%2009)*((i+2)%2009*((i-1)%2009)%2009))%2009*d/24;
		i=i%2009;
		result=(i)*(i+1)*(i+2)*a/6+i*(i+1)*(i+2)*(i-1)*d/24;
		cout<<result%2009<<endl;

	}
	return 0;
}

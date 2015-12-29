#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n ;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int sum;
		sum=a+b+c+d;
		int half=sum/2;
		if(a+b==half||a+c==half||a+d==half||b+c==half||b+d==half||c+d==half)
			cout<<"Case "<<i<<": Yes"<<endl;
		else 
			cout<<"Case "<<i<<": No"<<endl;
	}
	return 0;
}
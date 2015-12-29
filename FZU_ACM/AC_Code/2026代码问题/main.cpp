#include<iostream>
using namespace std;
int main()
{
	int x,y,z;
	while(cin>>x>>y>>z)
{
	if(x*y*z>=100000)
		cout<<'1'<<endl;
	else
		cout<<'0'<<endl;
}
	return 0;
}

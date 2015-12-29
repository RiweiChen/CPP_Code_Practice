#include<iostream>
using namespace std;
int main()
{
	char str[101];
	while(cin>>str)
	{
		int i=0;
		int one=0,two=0,three=0;
		while(str[i]!='\0')
		{
			if(str[i]=='o'&&str[i+1]=='n'&&str[i+2]=='e')
				one++;
			if(str[i]=='t'&&str[i+1]=='w'&&str[i+2]=='o')
				two++;
			if(str[i]=='t'&&str[i+1]=='h'&&str[i+2]=='r'&&str[i+3]=='e'&&str[i+4]=='e')
				three++;
			i++;
		}
		cout<<"one "<<one<<endl;
		cout<<"two "<<two<<endl;
		cout<<"three "<<three<<endl;
	}
	return 0;
}


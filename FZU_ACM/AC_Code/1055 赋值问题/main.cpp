/*
#include<iostream>
using namespace std;
struct imf
{
	char names;
	bool if_valu;
};
int main()
{
	int n;
	char str[4];
	while(cin>>n)
	{
		if(n==-1)
			continue;
		 getchar();
		int i,j;
		imf date[26];
		for(j=0;j<26;j++)
			{
				date[j].names='a'+i;
				date[j].if_valu=false;
			}
		date[0].if_valu=true;
		for(i=0;i<n;i++)
		{
			char a,temp,b;
			gets(str);
		//	if(i==0)
		//	{
		//		date[b-97].names=b;
		//		date[b-97].if_valu=true;
		//	}
			date[str[0]-97].names=str[0];
			if(date[str[2]-97].if_valu==true)
			{
				date[str[0]-97].if_valu=true;
			}
			else
			{
				date[str[0]-97].if_valu=false;
			}
		}
		int flag=0;
		int flag1=0;
		for(j=0;j<26;j++)
		{
			if(date[j].if_valu==true)
			{
				if(flag1==0)
				{
					cout<<date[j].names;
					flag1=1;
				}
				else if(flag1==1)
				{
					cout<<' '<<date[j].names;
				}
				flag=1;
			}
		}
		if(flag==0)
			cout<<"none";
		cout<<endl;
	}
	return 0;
}
*/
#include<stdio.h>

int main()
{
 int dic[26],i,n,pflag;
 char str[4];
 while(scanf("%d",&n)!=EOF)
 {
  if(n==-1)
    continue;
  getchar();
  for(i=0;i<26;i++)
     dic[i]=0;
        dic[0]=1;
        pflag=0;
  for(i=0;i<n;i++)
  {
   gets(str);
   dic[str[0]-'a']=dic[str[2]-'a'];
  }
  for(i=0;i<26;i++)
  {
   
         if(dic[i]==1)
   {
      if(i>0&&pflag==1)
        putchar(' ');
      putchar(i+'a');
            pflag=1;
   }
  }
  if(pflag==0)
     printf("none");
        printf("\n");
 }
 return 0;
}

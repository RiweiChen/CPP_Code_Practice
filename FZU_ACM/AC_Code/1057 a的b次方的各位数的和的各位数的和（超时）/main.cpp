/*
#include <iostream>
using namespace  std;
int main()
{
	
	int a,b;
	while (cin>>a>>b&&!(a==0&&b==0))
	{
		int date[100000]={0};
		int max_digit=1;
		int j,i;
		int sum_of_digit=0,sum_2_digit=0,sum_3_digit=0,sum_4_digit=0;
		if (a==0)
		{
			cout<<0<<endl;
			continue;
		}
		if (b==0)
		{
			cout<<1<<endl;
			continue;
		}
		date[0]=1;
		for ( i=0;i<b;i++)
		{
			//乘法
			for (j=0;j<max_digit;j++)
			{
				date[j]=date[j]*a;


			}//先考虑相乘
			for (j=0;j<max_digit;j++)
			{
				if (date[j]/10>0)
				{
					date[j+1]=date[j+1]+date[j]/10;
					date[j]=date[j]%10;
				}
				if (j==max_digit-1)
				{
					if(date[j+1]>0)
						max_digit++;
				}
			}//再考虑进位



		}
		//再统计各个位数之和。
		for (int k= 0;k<=max_digit;k++)
		{
			sum_of_digit+=date[k];
		}
		//cout<<sum_of_digit<<endl;
		max_digit=0;
		while(sum_of_digit>0)
		{
			sum_2_digit+=sum_of_digit%10;
			sum_of_digit=sum_of_digit/10;
		}
		//cout<<sum_2_digit<<endl;
		max_digit=0;
		while(sum_2_digit>0)
		{
			sum_3_digit+=sum_2_digit%10;
			sum_2_digit=sum_2_digit/10;
		}
		//cout<<sum_3_digit<<endl;
		max_digit=0;
		while(sum_3_digit>0)
		{
			sum_4_digit+=sum_3_digit%10;
			sum_3_digit=sum_3_digit/10;
		}
		cout<<sum_4_digit<<endl;

		



	}
	return 0;
}
*/
#include <iostream>
using namespace std;
//要求某个数的各位数字的和，只要mod 9即可，如果mod 9等于0了，那么就让它的各位数字之和就是9了 
int main()
{
    unsigned int a,b,c=1,i;
    while(cin>>a>>b)
    {
        if(a!=0 && b!=0)
        {
            for(i=1;i<=b;i++)
                c=(c*a)%9;
            if(c==0)
                cout<<9<<endl;
            else
                cout<<c<<endl;
            c=1;
        }
        else if(a==0 && b!=0)
        {
            cout<<0<<endl;
        }
        else if(a!=0 && b==0)
        {
            cout<<1<<endl;
        }
        else
            break;
    }
    return 0;
}
#include<iostream>
using namespace std;
//A*B mod C=����A mod C)*��B mod C) mod C ��
//A^B mod C=(A mod C)^(B mod C) mod C//��c����С��a��b��ʱ����Խ�ʡʱ�䡣
//��ͨ�����϶��ǲ��еġ���Ϊa,b,c���Ǻܴ������b�ܴ�,���³�ʱ��a�ܴ�ᵼ��a*aֱ�Ӿ�����ˡ�
#include<stdio.h>
//�ο����ϴ��롣
unsigned long long mul(unsigned long long a,unsigned long long b,unsigned long long c)
{//Ϊ�˷�ֹ�����������������õĳ˷���
	unsigned long long ret=0,tmp=a%c;
	while(b)
	{
		if(b&0x1)
			if((ret+=tmp)>=c)
				ret-=c;
			if((tmp<<=1)>=c)
				tmp-=c;
			b>>=1;
	} 
	return ret;
}


unsigned long long mod(unsigned long long a,unsigned long long b,unsigned long long c) 
{ 
	unsigned long long y=1; 
	while(b) 
	{ 
		if(b&1) 
			y=mul(y,a,c); 
		a=mul(a,a,c); 
		b=b>>1; 
	} 
	return y; 
}

int main() 
{ 
	unsigned long long a,b,c; 
	while(scanf("%llu%llu%llu",&a,&b,&c)!=EOF)
		printf("%llu\n",mod(a,b,c)); 
	return 0; 
}
/*

#include<stdio.h> 
#define LL unsigned long //long 

LL c; 
LL mod(LL m,LL n) 
{ 
	if(!m) return 0; 
	return (((m&1)*n)%c+(mod(m>>1,n)<<1)%c)%c; 
} 
LL count(LL a,LL b) 
{ 
	if(b==1) return a%c; 
	LL t=count(a,b>>1); 
	if(b%2==0) return mod(t,t); 
	return mod(mod(t,t),a); 
} 
int main() 
{ 
	LL a,b; 
	while(scanf("%llu %llu %llu",&a,&b,&c)!=EOF) 
		printf("%llu\n",count(a,b)%c); 
	return 0; 
} 
long power(long a,long b,long c)
{
	long result;
	return result;
}
int main()
{
	long a,b,c;
	long result;
	while (cin>>a>>b>>c)
	{
		
	}
	return 0;
}
*/
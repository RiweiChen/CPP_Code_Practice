#include<iostream>
using namespace std;
int main()//����Ҫ������͵�¥���Ƕ��١���
{
	int result;
	int a,b;
	while (cin>>a>>b)
	{
		//��һ��һ������������
		result=a;
		if (a%b==0)
		{
			result=a;
			cout<<result<<endl;
			continue;
		}
		if (b%a==0)
		{
			result=b;
			cout<<result<<endl;
			continue;
		}
		int temp=a;//temp��¼��ǰ�����߶ȡ�
		while(temp%b>0)//�����ܹ�������ʱ��
		{
			temp=temp%b+a;//��������Э��Ȼ����������һ����
			if (temp>result)
			{
				result=temp;
			}
		}//��ȫģ��ķ�������
		cout<<result<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int t,judge,i,j,result=0;
	cin>>t;
	getchar();
	for (i=0;i<t;i++)
	{
	
		char sentence[1000];
		gets(sentence);
		result=0;
		char word[50];
		int k;
		j=0;
		while(sentence[j]!='\0')
		{
			//�ҵ�һ���µĵ��ʡ�
			judge=0;
			if((((sentence[j]>='A')&&(sentence[j]<='Z'))||((sentence[j]>='a')&&(sentence[j]<='z'))))//��ʾ�µ����Ѿ����֡�
			{
				judge=1;
				k=0;
				word[k]=sentence[j];
				j++;
				while((((sentence[j]>='A')&&(sentence[j]<='Z'))||((sentence[j]>='a')&&(sentence[j]<='z'))))
				{
					k++;
					word[k]=sentence[j];
					j++;
					
				}
				k++;
				word[k]='\0';
			}
		//	cout<<word<<endl;
			if (judge==1)//����ȡ���ĵ��ʽ��з�����
			{
				k=0;
			int flag=0;
			while(word[k]!='\0')
			{
				//cout<<"flag"<<endl;
				if (flag==0)//��û���ĸ��ַ�������¼����жϡ�
				{
					if (word[k]=='l'||word[k]=='L'||word[k]=='o'||word[k]=='O'||word[k]=='v'||word[k]=='V'||word[k]=='e'||word[k]=='E')
					{
						result++;
						flag=1;
						break;
					}
				}
				k++;
			}

			}
			j++;
		}
		cout<<result<<endl;
	}
	return 0;
}
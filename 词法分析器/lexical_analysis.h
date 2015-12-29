#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
const  char keywords[32][10]={"auto", "double" ,"int","struct","break","else","long","switch","case","enum",
							"register","typedef", "char", "extern", "return" ,"union" ,"const" ,"float" ,
							"short" ,"unsigned", "continue" ,"for", "signed", "void" ,"default", "goto" ,
							"sizeof" ,"volatile" ,"do" ,"if" ,"while" ,"static"
							};

const  char operatorword[34][5]={
							"+","-","*","/","%","++","--",">","<","==",">=","<=","!=","&&","||","!","&","|","~",
							"^","<<",">>","=","+=","-=","*=","/=","%=",",","(",")","{","}","."
							};


class lexical_analysis
{
private:
	char date[1000];
	int length;
	int line;
	ofstream fileout;
	ofstream errorout;
	ifstream fileshow;
public:
	int check_if_keyword(string);
	int check_if_operatorword(string);
//	int code_input();
	int delete_comment();
	int delete_space();
	int scaner();
//	int show_result();
};

/*
int lexical_analysis::code_input()//�������롣
{
	int len=0;
	int line_len;
        while(gets(date+len)!=NULL)
        {
			line_len=strlen(date+len);
			len+=line_len;
			date[len]='\n';
			len++;
        }
        date[len]='\0';
        length=len;
        return 0;
}
*/

int lexical_analysis::delete_comment() //ɾ��ע�͡�
{
        int len=length;
        int i=0;
        int flag=1;
        while (i<len)
        {
                if (i<len&&date[i]=='\"')
                {
                        int k=i+1;
                        while (date[k]!='\"'&&date[k]!='\0')//�ַ����ڵ��ַ����ܹ���ɾ����
                        {
                                k++;
                        }
                        if (date[k]!='\0')//�� ���ڵ��ַ����ܹ����У������ܰ�����\n.
                        {
                                i=k+1;
                        }
                        else
                        {
                                i=i+1;

                        }

                }

                else if (i+1<len&&date[i]=='/'&&date[i+1]=='/')	//     //���ע�͡�
                {
                        date[i]=date[i+1]=' ';//�ÿո���棬������ֱ����\nȥ����date[i];
                        i=i+2;
                        while (date[i]!='\n')//ɾ����һ�С�
                        {
                                date[i]=' ';
                                i++;
                        }
                        i++;
                }
                else if (i+1<len&&date[i]=='/'&&date[i+1]=='*'&&flag)
                {
                        int j=i+2;
                        while (j+1<len)
                        {
                                if (date[j]=='*'&&date[j+1]=='/')
                                {
                                        break;
                                }
                                j++;
                        }
                        if (j+1==len)//���ҵ����û��ƥ��ʱ�����ñ�ǡ�
                        {
                                flag=0;//���ñ�־λ�������´λ�һ�α�����
                                i=i+2;
                                continue;
                        }
                        else
                        {
                                j++;
                                for (int t=i;t<=j;t++)
                                {
                                        if (date[t]!='\n')//�������и�ʽ��
                                        {
                                                date[t]=' ';
                                        }

                                }

                        }
                        i=j+1;
                }
                else
                {
                        i++;
                }

        }
        return 0;
}

int lexical_analysis::delete_space()
{
        char temp[1000];
        int i=0,j=0;
        if ((date[0]==' '||date[0]=='\t'))//���ܽ�����ɾ����Ϊ���������ʾ����ĵص㡣
        {
                j=0;
        }
        else
        {
                temp[0]=date[0];
                j=1;
        }
        for (i=1;i<length;i++)
        {
                if ((date[i]==' '||date[i]=='\t')&&(date[i-1]==' '||date[i-1]=='\t'))
                {
                        ;
                }
                else
                {
                        temp[j++]=date[i];
                }

        }
        for (i=0;i<j;i++)
        {
                date[i]=temp[i];
        }
        length=j;
        return 0;

}
int lexical_analysis::check_if_keyword(string word)
{
        int i=0;
        for (i=0;i<32;i++)
        {
                if(word==keywords[i])
                        return i;

        }
        return i;

}
int lexical_analysis::check_if_operatorword(string word)
{
        int i=0;
        for (i=0;i<34;i++)
        {
                if (operatorword[i]==word)
                {
                        return i;
                }

        }
        return i;
}
int lexical_analysis::scaner()
{
        fileout.open("fileout.txt");
        errorout.open("errorout.txt");
        line=1;
        int i=0;int j=0;
        char temp[50];
        for (i=0;i<length;i++)
        {
begin:
                if ((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z'))//��ĸ��ʼ����ʶ����ؼ���
                {
                        j=0;
                        temp[j]=date[i];
						j=1;i++;
                        while ((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9'))
                        {
							if (date[i]=='_')
							{
								j--;
								if (date[i+1]=='_')
								{
									errorout<<"��"<<line<<"�У���ϵ�������ϵ��»��� '_'"<<endl;
									while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t')
									{
										i++;
										
									}
									goto begin;//ʹ��goto��䷽�����������ѭ����
								}
								i++;
								continue;
							}
                            temp[j]=date[i]; 
							if (date[i+1]=='$')//�����˱�ʶ��������־��
							{
								break;
							}
							i++;
							j++;
                        }
                        temp[j]='\0';
                        int ret=check_if_keyword(temp);
                        if (ret==32)
                        {
							if (strlen(temp)>=20)
							{
								errorout<<"��"<<line<<"�У�"<<temp<<" �ַ������ȳ���20λ����"<<endl;
							}
							else
								 fileout<<'<'<<temp<<",\tid>"<<endl;
                        }
                        else
                        {
							
								 fileout<<'<'<<temp<<",\tkeyword>"<<endl;
                        }
						i--;
                }
				else if (date[i]=='_')//�»��߿�ͷ����
				{
					errorout<<"��"<<line<<"�У����»��� '_' Ϊ��ͷ����"<<endl;
					while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t')
					{
						i++;
					}
					
				}
                else if(date[i]>='0'&&date[i]<='9')//���ֳ�����
                {
					int flagh=0;//��־�Ƿ����0��ͷ��
					int t=i;
					if (date[i]=='0')//ʶ��˽��ơ�
					{
						flagh=1;
						int k=i+1;
						int result=0;
						while ((date[k]>='0'&&date[k]<='9'))
						{
							if (date[k]=='8'||date[k]=='9')
							{
								flagh=0;
								break;
							}
							
							result=result*8+(date[k]-'0');
							if(date[k+1]=='$')
							{
								break;
							}
							k++;
						}
						if (flagh==1)
						{
							if (result>32768)
							{
								errorout<<"��"<<line<<"�У�����Խ��"<<endl;
							}
							fileout<<'<'<<result<<",\tnum>"<<endl;
						}
						i=k;
					}
					if(flagh==0)//������0��ͷʱ��
					{

						i=t;
                        char word[10];
                        j=0;
                        word[0]=date[i];
						j++;i++;
                        while ((date[i]>='0'&&date[i]<='9')||(date[i]=='.')&&(date[i]!='$'))
                        {
                                word[j++]=date[i];
                                i++;
                        }
                        word[j]='\0';
                        fileout<<'<'<<word<<",\tnum>"<<endl;
						i--;
					}
                }
                else if(date[i]=='\"' )//�ַ���������
                {
						int flag=0;
                        int t=i+1;
                        char temp_string[50];
                        int j=0;
                        while (date[t]!='\"'&&t<length)
                        {
							if (date[t]=='\0')
							{
								errorout<<"��"<<line<<"��,\t�ַ������д���!"<<endl;
								i=t;//��ʾ��ƥ��ʱ��ֱ�Ӻ��Բ�ƥ�����һ�С�
								flag=1;
								break;
							}
                            temp_string[j++]=date[t];
                            t++;
                        }
                        temp_string[j]='\0';
                        if (t==length)//���ҵ��ļ�ĩβ��û��ƥ�䡣
                        {
                                errorout<<"��"<<line<<"��,\t�Ҳ������Ӧ���ַ���!"<<endl; 
                        }
                        else if (flag==0)
                        {
                                i=t;
                                fileout<<'<'<<temp_string<<",\tstring>"<<endl;
                        }

                }
                else if(date[i]=='\'')//�ַ�������
                {

                        if(date[i+2]=='\'')
                        {
                            fileout<<'<'<<date[i+1]<<",\tchar>"<<endl;
							i=i+2;
							
                        }
                        else if (date[i+3]=='\''&&date[i+1]=='\\')
                        {
                            fileout<<'<'<<date[i+1]<<date[i+2]<<",\tchar>"<<endl;
							i=i+3;
                        }
                        else
                        {
							errorout<<"��"<<line<<"��,\t�ַ������޷�ƥ�� !"<<endl;
							while (date[i]!='$'&&date[i]!=';'&&date[i]!='\0')
							{
								i++;
							}
   
                        }


                }
                else if (date[i]=='\n')//����Ƿ��С�
                {
                        line++;
                }
                else if (date[i]==' '||date[i]=='\t'||date[i]==';'||(date[i]=='$'))//�ո�ֱ��������
                {
                        ;
                }
                else //����Ƿ�Ϊ�����
                {
                        int j=0;;
                        char temp[4];
						temp[0]=date[i];
						j++;i++;
                        while ((!((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9')))
                                &&(date[i]!=' '&&date[i]!='\t'&&date[i]!='\n')&&(date[i]!='$')&&(date[i]!=';'))
                        {
                                temp[j++]=date[i];
                                i++;
                        }
                        temp[j]='\0';
                        int ret=check_if_operatorword(temp);
                        if(ret==34)
                        {
							if (strlen(temp)==1)
							{
								errorout<<"��"<<line<<"��,"<<"\t"<<temp<<"Ϊ�޷�ʶ��ķ���"<<endl;
							}
							else
                                errorout<<"��"<<line<<"��,"<<"\t"<<temp<<"Ϊ�޷�ʶ��Ĳ�����"<<endl;     
                        }
                        else
                        {
                            fileout<<'<'<<' '<<operatorword[ret]<<",\toperator>"<<endl;

                        }
						i--;
                }


        }
        return 0;

}
/*
int lexical_analysis::show_result()
{
	string str;
	cout<<"�ʷ���Ԫ��"<<endl;
	fileshow.open("fileout.txt");
	while(getline(fileshow,str))
	{
		cout<<'\t'<<str<<endl;
	}
	fileshow.clear();//io������������ر��ļ�ʱ���Ǹ��������ڡ�
	fileshow.close();
	fileshow.open("errorout.txt");
	cout<<"�ʷ�����"<<endl;
	while(getline(fileshow,str))
	{
		cout<<'\t'<<str<<endl;
	}
	fileshow.close();
	return 0;
}
*/
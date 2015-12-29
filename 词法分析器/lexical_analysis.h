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
int lexical_analysis::code_input()//代码输入。
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

int lexical_analysis::delete_comment() //删除注释。
{
        int len=length;
        int i=0;
        int flag=1;
        while (i<len)
        {
                if (i<len&&date[i]=='\"')
                {
                        int k=i+1;
                        while (date[k]!='\"'&&date[k]!='\0')//字符串内的字符不能够被删除。
                        {
                                k++;
                        }
                        if (date[k]!='\0')//“ ”内的字符不能够跨行，即不能包含有\n.
                        {
                                i=k+1;
                        }
                        else
                        {
                                i=i+1;

                        }

                }

                else if (i+1<len&&date[i]=='/'&&date[i+1]=='/')	//     //类的注释。
                {
                        date[i]=date[i+1]=' ';//用空格代替，而不是直接用\n去代替date[i];
                        i=i+2;
                        while (date[i]!='\n')//删除那一行。
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
                        if (j+1==len)//查找到最后还没有匹配时。设置标记。
                        {
                                flag=0;//设置标志位，避免下次还一次遍历。
                                i=i+2;
                                continue;
                        }
                        else
                        {
                                j++;
                                for (int t=i;t<=j;t++)
                                {
                                        if (date[t]!='\n')//保留换行格式。
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
        if ((date[0]==' '||date[0]=='\t'))//不能讲空行删除，为了下面的显示出错的地点。
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
                if ((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z'))//字母开始。标识符或关键字
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
									errorout<<"第"<<line<<"行，联系两个以上的下划线 '_'"<<endl;
									while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t')
									{
										i++;
										
									}
									goto begin;//使用goto语句方便的跳出多重循环。
								}
								i++;
								continue;
							}
                            temp[j]=date[i]; 
							if (date[i+1]=='$')//遇到了标识符结束标志。
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
								errorout<<"第"<<line<<"行，"<<temp<<" 字符串长度超过20位错误！"<<endl;
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
				else if (date[i]=='_')//下划线开头报错。
				{
					errorout<<"第"<<line<<"行，以下划线 '_' 为开头错误！"<<endl;
					while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t')
					{
						i++;
					}
					
				}
                else if(date[i]>='0'&&date[i]<='9')//数字常量。
                {
					int flagh=0;//标志是否出现0开头。
					int t=i;
					if (date[i]=='0')//识别八进制。
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
								errorout<<"第"<<line<<"行，整数越界"<<endl;
							}
							fileout<<'<'<<result<<",\tnum>"<<endl;
						}
						i=k;
					}
					if(flagh==0)//当不是0开头时。
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
                else if(date[i]=='\"' )//字符串常量。
                {
						int flag=0;
                        int t=i+1;
                        char temp_string[50];
                        int j=0;
                        while (date[t]!='\"'&&t<length)
                        {
							if (date[t]=='\0')
							{
								errorout<<"第"<<line<<"行,\t字符串跨行错误!"<<endl;
								i=t;//表示不匹配时，直接忽略不匹配的那一行。
								flag=1;
								break;
							}
                            temp_string[j++]=date[t];
                            t++;
                        }
                        temp_string[j]='\0';
                        if (t==length)//查找到文件末尾还没有匹配。
                        {
                                errorout<<"第"<<line<<"行,\t找不到相对应的字符串!"<<endl; 
                        }
                        else if (flag==0)
                        {
                                i=t;
                                fileout<<'<'<<temp_string<<",\tstring>"<<endl;
                        }

                }
                else if(date[i]=='\'')//字符常量。
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
							errorout<<"第"<<line<<"行,\t字符常量无法匹配 !"<<endl;
							while (date[i]!='$'&&date[i]!=';'&&date[i]!='\0')
							{
								i++;
							}
   
                        }


                }
                else if (date[i]=='\n')//检查是否换行。
                {
                        line++;
                }
                else if (date[i]==' '||date[i]=='\t'||date[i]==';'||(date[i]=='$'))//空格直接跳过。
                {
                        ;
                }
                else //检查是否为运算符
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
								errorout<<"第"<<line<<"行,"<<"\t"<<temp<<"为无法识别的符号"<<endl;
							}
							else
                                errorout<<"第"<<line<<"行,"<<"\t"<<temp<<"为无法识别的操作符"<<endl;     
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
	cout<<"词法单元："<<endl;
	fileshow.open("fileout.txt");
	while(getline(fileshow,str))
	{
		cout<<'\t'<<str<<endl;
	}
	fileshow.clear();//io流必须清除，关闭文件时，那个流还存在。
	fileshow.close();
	fileshow.open("errorout.txt");
	cout<<"词法错误："<<endl;
	while(getline(fileshow,str))
	{
		cout<<'\t'<<str<<endl;
	}
	fileshow.close();
	return 0;
}
*/
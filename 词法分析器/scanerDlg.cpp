// scanerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "scaner.h"
#include "scanerDlg.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
using namespace std;

struct symbol_table //符号表
{
	int num;
	string names;
	string types;
};
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
const  char keywords[32][10]={"auto", "double" ,"int","struct","break","else","long","switch","case","enum",
							"register","typedef", "char", "extern", "return" ,"union" ,"const" ,"float" ,
							"short" ,"unsigned", "continue" ,"for", "signed", "void" ,"default", "goto" ,
							"sizeof" ,"volatile" ,"do" ,"if" ,"while" ,"static"
							};

const  char operatorword[34][5]={
							"+","-","*","/","%","++","--",">","<","==",">=","<=","!=","&&","||","!","&","|","~",
							"^","<<",">>","=","+=","-=","*=","/=","%=",",","(",")","{","}","."
							};
//vector<symbol_table> sym_table;//符号表变量。
symbol_table sym_table[200];

class lexical_analysis
{

 public: 
	char date[1000];
	int length;
	int sym_table_num;
	int line;
	ofstream fileout;
	ofstream errorout;
	ifstream fileshow;
	ofstream fileinput;
	ofstream symbol_table;//符号表。

	

	int check_if_keyword(string);
	int check_if_operatorword(string);
	int delete_comment();
	int delete_space();
	int scaner();
	int insert_sym(int i,string str,string type);//符号表查询与插入。
	int isexist_sym(string str);
};
int lexical_analysis::insert_sym(int i,string str,string type)
{
	
	sym_table[i].num=i;	
	sym_table[i].names=str;
	sym_table[i].types=type;
	sym_table_num++;
	return 0;
}
int lexical_analysis::isexist_sym(string str)
{
	int i;
	for ( i=0;i<sym_table_num;i++)
	{
		if(str==sym_table[i].names)
		{
			return -1;//返回0表示存在。
		}
	}
	return i;
}

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
	sym_table_num=0;
        fileout.open("fileout.txt");
        errorout.open("errorout.txt");
		symbol_table.open("symbol_table.txt");
		symbol_table<<"标号\t"<<"名字\t"<<"类型"<<endl;
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
                        while ((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9')&&(i<length))
                        {
							if (date[i]=='_')
							{
								j--;
								if (date[i+1]=='_'&&(i<length-1))
								{
									errorout<<"第"<<line<<"行，连续两个以上的下划线 '_'错误！"<<endl;
									while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t'&&(i<length)&&(date[i]!='\r'))
									{
										i++;	
									}
									goto begin;//使用goto语句方便的跳出多重循环。
								}
								i++;
								continue;
							}
                            temp[j]=date[i]; 	
							i++;
							j++;
							if (date[i]=='$')//遇到了标识符结束标志。
							{
								break;
							}
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
							{
								 fileout<<'<'<<temp<<"\t,\tid>"<<endl;
								 if(isexist_sym(temp)!=-1)//表示不存在是，加入。
								 {
									 insert_sym(sym_table_num,temp,"id");
									 symbol_table<<sym_table_num<<"\t"<<temp<<"\t"<<"id"<<endl;
								 }
							}
                        }
                        else
                        {
							
								 fileout<<'<'<<temp<<"\t,\tkeyword>"<<endl;
								 if(isexist_sym(temp)!=-1)//表示不存在是，加入。
								 {
									 insert_sym(sym_table_num,temp,"keyword");
									 symbol_table<<sym_table_num<<"\t"<<temp<<"\t"<<"keyword"<<endl;
								 }
                        }
						i--;
                }
				else if (date[i]=='_')//下划线开头报错。
				{
					errorout<<"第"<<line<<"行，以下划线 '_' 为开头错误！"<<endl;
					while (date[i]!='\0'&&date[i]!='$'&&date[i]!=';'&&date[i]!=' '&&date[i]!='\t'&&(i<length))
					{
						i++;
					}
					i--;
					
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
						if ((date[k]>='A'&&date[k]<='Z')||(date[k]>='a'&&date[k]<='z'))//当数字后接的是字母时，被认为是词法单元id，且是错误。
						{
							i=k;
							while ((i<length)&&(date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9'))
							{
								i++;
							}
							flagh=1;
							k=i;
							errorout<<"第"<<line<<"行，数字开头的标识符错误！"<<endl;

						}
						else if (flagh==1)
						{
							if (result>32768)
							{
								errorout<<"第"<<line<<"行，整数越界"<<endl;
							}
							fileout<<'<'<<result<<"\t,\tnum>"<<endl;
							char tempp[10];
							if(isexist_sym(itoa(result,tempp,10))!=-1)//表示不存在是，加入。
							{
								insert_sym(sym_table_num,itoa(result,tempp,10),"num");
								symbol_table<<sym_table_num<<"\t"<<result<<"\t"<<"num"<<endl;
							}
						}
						i=k;
					}
					if(flagh==0)//当不是0开头时。
					{

						i=t;
                        char word[10];
                        j=0;
						if (date[i]!='0')
						{
							word[0]=date[i];
							j++;

						}
						i++;
                        while ((date[i]>='0'&&date[i]<='9')||(date[i]=='.')&&(date[i]!='$'))
                        {
                                word[j++]=date[i];
                                i++;
                        }
						if ((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z'))//当数字后接的是字母时，被认为是词法单元id，且是错误。
						{
							while ((i<length)&&((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9')))
							{
								i++;//消耗掉，便于找到下一个单元。
							}
							errorout<<"第"<<line<<"行，数字开头的标识符错误！"<<endl;	
							i--;
						}
						else
						{
							 word[j]='\0';
							 fileout<<'<'<<word<<"\t,\tnum>"<<endl;
							 if(isexist_sym(word)!=-1)//表示不存在是，加入。
							 {
								 insert_sym(sym_table_num,word,"num");
								 symbol_table<<sym_table_num<<"\t"<<word<<"\t"<<"num"<<endl;
							 }
							 i--;
						}
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
                                fileout<<'<'<<temp_string<<"\t,\tstring>"<<endl;
								if(isexist_sym(temp_string)!=-1)//表示不存在是，加入。
								{
									insert_sym(sym_table_num,temp_string,"string");
									symbol_table<<sym_table_num<<"\t"<<temp_string<<"\t"<<"string"<<endl;
								 }
                        }

                }
                else if(date[i]=='\'')//字符常量。
                {

                        if(date[i+2]=='\'')
                        {
                            fileout<<'<'<<date[i+1]<<"\t,\tchar>"<<endl;
							i=i+2;
							
                        }
                        else if (date[i+3]=='\''&&date[i+1]=='\\')
                        {
                            fileout<<'<'<<date[i+1]<<date[i+2]<<"\t,\tchar>"<<endl;
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
				else if (date[i]=='\r')
				{
					;
				}
                else if (date[i]==' '||date[i]=='\t'||(date[i]=='$'))//空格直接跳过。
                {
                        ;
                }
				else if (date[i]==';')
				{
					fileout<<'<'<<';'<<"\t,\tendmark>"<<endl;
					if(isexist_sym(";")!=-1)//表示不存在是，加入。
					{
						insert_sym(sym_table_num,";","endmark");
						symbol_table<<sym_table_num<<"\t"<<";"<<"\t"<<"endmark"<<endl;
					}
					

				}
                else //检查是否为运算符
                {
                        int j=0;;
                        char temp[4];
						temp[0]=date[i];
						j++;i++;
                        while ((!((date[i]>='A'&&date[i]<='Z')||(date[i]>='a'&&date[i]<='z')||date[i]=='_'||(date[i]>='0'&&date[i]<='9')))
                                &&(date[i]!=' '&&date[i]!='\t'&&date[i]!='\n')&&(date[i]!='$')&&(date[i]!=';')&&(i<length))
                        {
							if (date[i-1]=='}'||date[i-1]==']'||date[i-1]==')'||date[i-1]=='>'||date[i-1]=='{'||date[i-1]=='['||date[i-1]=='('||date[i-1]=='<')
							{
								break;
							}
                                temp[j++]=date[i];
                                i++;
                        }
                        temp[j]='\0';
                        int ret=check_if_operatorword(temp);
                        if(ret==34)
                        {
							if (strlen(temp)==1)
							{
								errorout<<"第"<<line<<"行,"<<"\t"<<temp<<"为无法识别的符号!"<<endl;
							}
							else
                                errorout<<"第"<<line<<"行,"<<"\t"<<temp<<"为无法识别的操作符"<<endl;     
                        }
                        else
                        {
                            fileout<<'<'<<' '<<operatorword[ret]<<"\t,\toperator>"<<endl;
							if(isexist_sym(operatorword[ret])!=-1)//表示不存在是，加入。
							{
								insert_sym(sym_table_num,operatorword[ret],"operator");
								symbol_table<<sym_table_num<<"\t"<<operatorword[ret]<<"\t"<<"operator"<<endl;
							}

                        }
						i--;
                }


        }
        return 0;

}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScanerDlg dialog

CScanerDlg::CScanerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScanerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScanerDlg)
	m_FilePath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScanerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScanerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_FilePath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScanerDlg, CDialog)
	//{{AFX_MSG_MAP(CScanerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScanerDlg message handlers

BOOL CScanerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScanerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CScanerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CScanerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScanerDlg::OnButton1() 
{
	lexical_analysis scaner;
	CString str="";
	GetDlgItemText(IDC_EDIT1,str);
	int n;
	for(n=0;n<str.GetLength();n++)
	{
		scaner.date[n]=str[n];
	}
	scaner.date[n]='\0';
	scaner.length=str.GetLength();
	scaner.delete_comment();
	scaner.delete_space();
	scaner.scaner();

	//char strs[10000];
	ofstream fileinput("codeinput.txt");
	fileinput<<str;
	ifstream fileshow;
	CString strss="";
	SetDlgItemText(IDC_EDIT2,strss);
	string temp;
	fileshow.open("fileout.txt");
	while(getline(fileshow,temp))
	{
		
		int ii=0;
		for(ii=0;ii<temp.length();ii++)
		{
			strss+=temp[ii];
		}
		strss+="\r\n";
		strss+="\r\n";
	}
	strss+='\n';
	SetDlgItemText(IDC_EDIT2,strss);

	fileshow.clear();//io流必须清除，关闭文件时，那个流还存在。
	fileshow.close();
	fileshow.open("errorout.txt");
	strss="";
	SetDlgItemText(IDC_EDIT3,strss);
	while(getline(fileshow,temp))
	{
		int ii=0;
		for(ii=0;ii<temp.length();ii++)
		{
			strss+=temp[ii];
		}
		strss+="\r\n";
		strss+="\r\n";
	}
	strss+='\n';
	SetDlgItemText(IDC_EDIT3, strss);
	fileshow.clear();//io流必须清除，关闭文件时，那个流还存在。
	fileshow.close();
	fileshow.open("symbol_table.txt");
	strss="";
	SetDlgItemText(IDC_EDIT4,strss);
	while(getline(fileshow,temp))
	{
		int ii=0;
		for(ii=0;ii<temp.length();ii++)
		{
			strss+=temp[ii];
		}
		strss+="\r\n";
		strss+="\r\n";
	}
	strss+='\n';
	SetDlgItemText(IDC_EDIT4, strss);
	fileshow.close();

/*

//	Cfile files;//不知道错在何方？
//	char strs[1000];
	files.Open("fileout.txt",CFile::modeRead);
	files.Read(strs,files.GetLength());
	SetDlgItemText(IDC_EDIT2,strs);
	//files.Clear();
	files.Close();


	files.Open("errorout.txt",CFile::modeRead);
	files.Read(strs,files.GetLength());
	SetDlgItemText(IDC_EDIT3,str);
	//files.Clear();
	files.Close();
*/	
	
}


void CScanerDlg::OnButton2() //打开菜单
{
	// TODO: Add your control notification handler code here
	char szFilters[]=
		"MyType Files (*.c)|*.c|All Files (*.*)|*.*||";
	
	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg (TRUE, "c", "*.c",
		OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);
	
	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if( fileDlg.DoModal()==IDOK )
	{
		CString pathName = fileDlg.GetPathName();
		CFile cfiles;
		ifstream fileshow;
		fileshow.open(pathName);
		CString strss;
		string temp;
		while(getline(fileshow,temp))
		{
			
			int ii=0;
			for(ii=0;ii<temp.length();ii++)
			{
				strss+=temp[ii];
			}
			strss+="\r\n";
			strss+="\r\n";
		}
		strss+='\n';
	SetDlgItemText(IDC_EDIT1,strss);

	}

	
}

void CScanerDlg::OnChangeEdit1() 
{

}

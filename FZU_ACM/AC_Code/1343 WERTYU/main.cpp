#include<iostream>
using namespace std;
char map[256];
int main()
{
	char str[201];
	map['Q']='\t';
	map['W']='Q';
	map['E']='W';
	map['R']='E';
	map['T']='R';
	map['Y']='T';
	map['U']='Y';
	map['I']='U';
	map['O']='I';
	map['P']='O';
	map['[']='P';
	map[']']='[';
	map['\\']=']';
	map['S']='A';
	map['D']='S';
	map['F']='D';
	map['G']='F';
	map['H']='G';
	map['J']='H';
	map['K']='J';
	map['L']='K';
	map[';']='L';
	map['\'']=';';
	map['\n']='\'';
	map['X']='Z';
	map['C']='X';
	map['V']='C';
	map['B']='V';
	map['N']='B';
	map['M']='N';
	map[',']='M';
	map['.']=',';
	map['/']='.';
	map[' ']=' ';
	map['1']='`';
	map['2']='1';
	map['3']='2';
	map['4']='3';
	map['5']='4';
	map['6']='5';
	map['7']='6';
	map['8']='7';
	map['9']='8';
	map['0']='9';
	map['-']='0';
	map['=']='-';
	while (gets(str))
	{
		int i=0;
		while (str[i]!='\0')
		{
			putchar(map[str[i]]);
			i++;
		}
		cout<<endl;
	}
	return 0;
}
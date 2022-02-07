#include<iostream>
#include<strstream>
using namespace std;

//字符串流的存在，可以使得数字类型变为数字字符串类型，跟c中的sprintf类似。
int main6()
{
	int i;
	char str[36] = "this is a book.";
	char ch;
	istrstream input(str, 36);
	ostrstream output(str, 36);
	cout << "字符串长度:" << strlen(str) << endl;
	input.unsetf(ios::skipws);
	for (i = 0; i < 36; i++) {
		input >> ch;
		cout << ch;
	}
	cout << endl;

	int inum1 = 93, inum2;
	double fnum1 = 89.5, fnum2;

	output << inum1 << ' ' << fnum1 << '\0';//写入字符串


	cout << "字符串长度" << strlen(str) << endl;



	istrstream input1(str, 0);
	input1 >> inum2 >> fnum2;
	cout << "整数:" << inum2 << '\t' << "浮点数:" << fnum2 << endl;
	cout << "字符串长度" << strlen(str) << endl;
	return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;

void func9_3()
{
	//流成员函数方式：
	int f = cout.flags();
	cout.setf(ios::left);
	cout.width(12);//设置后第二次输出前便会恢复
	cout << 7;
	cout.setf(ios::left);
	cout.width(12);
	cout << 8;
	cout << 9;
	cout << 10 << endl;

	cout.setf(ios::showbase);
	cout.setf(ios::oct, ios::basefield);
	cout << 10;
	cout.setf(ios::dec, ios::basefield);
	cout << 10;
	cout.setf(ios::hex, ios::basefield);
	cout << 10 << endl;

	cout << 3.1415926;
	cout.setf(ios::scientific, ios::floatfield);
	cout << 3.1415926;
	cout.setf(ios::fixed, ios::floatfield);
	cout << 3.1415926 << endl;

	char str[255];
	cin.getline(str, 255);
	cout << str;
	//流操作子方式：
	cout << left << 7 << endl;

	cout << oct << 10 << dec << 10 << hex << 10 << endl;
	cout << scientific << 3.1415926 << fixed << 3.1415926 << endl;

}

int main()
{
	func9_3();
	return 0;
}

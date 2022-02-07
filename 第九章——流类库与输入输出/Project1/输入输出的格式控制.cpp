#include<iostream>
#include<iomanip>
using namespace std;

//cout、cerr、clog是ostream类的对象，cin是istream类的对象
int main1()
{
	int inum = 255;
	cout << "十进制" << inum << '\t';
	cout.flags(ios::oct | ios::showbase);//ios类提供格式化的输入输出，格式控制符以枚举常量实现
	cout << "八进制" << inum << '\t';
	//cout.flags(ios::hex);//这是完全替代原本的格式控制符位
	cout.setf(ios::hex, ios::basefield);//这是替代basefield包含的那几位控制位
	cout << "十六进制" << inum << endl;


	cout << '\n';
	cout.unsetf(ios::basefield);

	double fnum = 31.415926;
	cout << "默认域宽为：" << cout.width() << '\n';
	cout << "默认精度为：" << cout.precision() << '\n';
	cout << "默认表达方式：" << fnum << '\n';
	cout.setf(ios::scientific, ios::floatfield);
	cout << "科学表达式方式：" << fnum << '\n';
	cout.setf(ios::fixed, ios::floatfield);
	cout << "定点表达方式：" << fnum << '\n';
	cout.precision(9);
	cout.setf(ios::scientific, ios::floatfield);
	cout << "9位科学表达式方式" << fnum << endl;

	/*上面是通过采用cout的成员函数来控制格式，下面使用流操作子来控制格式*/
	cout << '\n';
	cout.precision(6);
	cout.unsetf(ios::floatfield);
	cout << "科学表达方式" << scientific << fnum << '\n';//流操作子实际上是一个内联函数的函数调用。
	cout << "定点表达方式" << fixed << fnum << '\n';
	cout << "9位科学表达式方式" << setprecision(9) << scientific << fnum << endl;
	cout << fnum << endl;//并且由于本质上是进行了set，所以后续输出格式也同样保持。

	return 0;
}

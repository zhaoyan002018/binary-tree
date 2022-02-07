#include<iostream>
using namespace std;

//文件域、函数域、名字空间域、块域

//3种：1、局部域(包含函数域，块域(复合语句、括号、if{}))2、名字空间域(相当于更加灵活的文件域or全局域)3、类域

namespace ns1 {
	float a = 1, b, c;
	static int fun1(void) {
		int a = 1;
		return a;
	}
}

//类域实际上和名字空间域类似
class MyClass
{
public:
	char getChr() {
		return chr;//尽管chr声明在下方，仍然是正确的。原因在于编译器对标识符的解析分为俩步：1、先查找在声明中用到的名字，即数据成员和函数成员名。2、再查找函数成员内的名字
	}

private:
	char chr;
};

using namespace ns1;
int main12()
{
	cout << "进入main函数" << endl;

	cout << "ns1::a=" << a << endl;
	return 0;
}

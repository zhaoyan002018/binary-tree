#include<iostream>
using namespace std;
//静态数据成员，静态函数成员。
class Ctest {
private:
	static int count;
public:
	Ctest() {
		++count;
		cout << "对象数量=" << count << '\n';
	}
	~Ctest() {
		--count;
		cout << "对象数量=" << count << '\n';
	}
	/*
	static void Printf()
	{
		cout << "this is a test" << endl;
	}*/
	static void Printf();
};
//static void Ctest::Printf() 与友元函数类似，定义时不需要加static(friend)，因为这并非数据类型的组成部分。
void Ctest::Printf()
{
	cout << "this is a test" << endl;
}
int Ctest::count = 0;//私有怎么访问？
int main11()
{
	//int Ctest::count = 0;//无法放到main中定义
	Ctest a[3];

	a[0].Printf();
	return 0;

}

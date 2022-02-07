#include<iostream>
using namespace std;

//异常类层次结构中的虚函数
class Excp
{
public:
	virtual void print() { cerr << "发生异常" << endl; }
};

class stackExcp :public Excp {
public:
	void print() { cerr << "栈发生异常" << endl; }
};

class pushOnFull :public stackExcp {
public:
	void print() { cerr << "栈满" << endl; }
};

class popOnEmpty :public stackExcp {
public:
	void print() { cerr << "栈空" << endl; }
};

void ExcpFunc()
{
	try {
		throw popOnEmpty();
	}
	catch (Excp& eObj) {//注意必须异常声明类型为引用，才可以使用虚函数赋值兼容的特性。
		eObj.print();
	}
}


int main2()
{
	ExcpFunc();
	return 0;
}

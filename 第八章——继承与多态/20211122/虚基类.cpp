#include<iostream>
using namespace std;
//采用虚基类的多重继承中，构造和析构的次序
class Object
{
public:
	Object() { cout << "进入ob的构造函数中\n"; }
	~Object() { cout << "进入ob的析构函数中\n"; }
};

class Bclass1 {
public:
	Bclass1() { cout << "进入bc1的构造函数中\n"; }
	~Bclass1() { cout << "进入bc1的析构函数中\n"; }
};

class Bclass2 {
public:
	Bclass2() { cout << "进入bc2的构造函数中\n"; }
	~Bclass2() { cout << "进入bc2的析构函数中\n"; }
};

class Bclass3 {
public:
	Bclass3() { cout << "进入bc3的构造函数中\n"; }
	~Bclass3() { cout << "进入bc3的析构函数中\n"; }
};

class Dclass :public Bclass1, virtual Bclass3, virtual Bclass2
{
	Object object;
public:
	Dclass() :object(), Bclass2(), Bclass3(), Bclass1() { cout << "派生类建立！\n"; }
	~Dclass() { cout << "派生类析构！\n"; }
};
int main3()
{
	Dclass dd;
	cout << "主程序运行" << endl;
	return 0;
}

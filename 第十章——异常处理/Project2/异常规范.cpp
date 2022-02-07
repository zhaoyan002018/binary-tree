#include<iostream>
using namespace std;


//注意vc未实现异常规范。
class CBase {
public:
	virtual int fun1(int i) throw() {}//表示不能抛出异常
	virtual int fun2(int i, int j) throw(int) { throw i; }
	virtual string fun3(int i, string s) throw(int, string) { throw (i, s); }
};

class CDerived :public CBase {
public:
	int fun1(int i)throw(int) { throw i; }//X
	int fun2(int i, int j)throw(int) { throw i; }
	string fun3(int i, string s)throw(string) { throw s; }
};

}

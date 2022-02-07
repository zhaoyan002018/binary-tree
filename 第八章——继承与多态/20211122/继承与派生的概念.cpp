#include"iostream"
using namespace std;

//编织派生类的四步进行
/*
	1、继承基类的数据成员和函数成员。
	2、改造基类成员，类似局部变量覆盖全局变量，称为同名覆盖。
	3、发展不同名的新成员
	4、重写构造函数和析构函数，派生类并不继承基类的构造和析构函数
*/

class baseObject
{
private:
	int pri_b;
protected:
	int prt_c;
public:
	baseObject() {
		cout << "进入baseObject构造函数" << endl;
		pub_a = 1;
		pri_b = 2;
		prt_c = 3;
	}
	~baseObject() {
		cout << "进入baseObject析构函数" << endl;
	}
	int pub_a;

	int getA() { return pub_a; }
	int getB() { return pri_b; }
	int getC() { return prt_c; }
};

/*三种继承方式，即派生类三种访问方式*/
//公有派生
class derivedObject1 :public baseObject
{
public:
	derivedObject1() {
		cout << "进入derivedObject1构造函数" << endl;
		pri_b = 4;
	}
	~derivedObject1() {
		cout << "进入derivedObject1析构函数" << endl;
	}
	void printBaseInfo() {
		cout << pub_a << '\t';	//公有派生的派生类可以访问基类中的public成员
		cout << getB() << '\t';	//无法访问private成员
		cout << prt_c << '\t';	//可以访问protect成员
		cout << pri_b << '\t';	//此时用同名方式覆盖了基类中的pri_b成员。
		cout << endl;
	}
private:
	int pri_b;
};

//私有派生
class derivedObject2 :private baseObject
{
public:
	derivedObject2() {
		cout << "进入derivedObject2构造函数" << endl;
	}
	~derivedObject2() {
		cout << "进入derivedObject2析构函数" << endl;
	}
	void printBaseInfo() {
		cout << pub_a << '\t';	//公有派生的派生类可以访问基类中的public成员
		cout << getB() << '\t';	//无法访问private成员
		cout << prt_c << '\t';	//可以访问protect成员
		cout << endl;
	}

};

//保护派生
class derivedObject3 :protected baseObject
{
public:
	derivedObject3() {
		cout << "进入derivedObject3构造函数" << endl;
	}
	~derivedObject3() {
		cout << "进入derivedObject3析构函数" << endl;
	}
	void printBaseInfo() {
		cout << pub_a << '\t';	//公有派生的派生类可以访问基类中的public成员
		cout << getB() << '\t';	//无法访问private成员
		cout << prt_c << '\t';	//可以访问protect成员
		cout << endl;
	}
};

//保护派生和私有派生的区别体现在多层派生中。
class derivedObject4 :protected derivedObject2
{
public:
	derivedObject4() {
	}
	~derivedObject4() {
	}
	void printBaseInfo() {
		//从私有派生继承来的保护派生类中，无法访问最底层基类的保护和公有成员。

		cout << endl;
	}

};
class derivedObject5 :protected derivedObject3
{
public:
	derivedObject5() {
	}
	~derivedObject5() {
	}
	void printBaseInfo() {
		//从保护派生类继承来的新保护派生类中，则可以访问最底层基类的保护和公有成员。
		cout << pub_a << '\t';	//保护派生的派生类可以访问基类中的public成员
		cout << getB() << '\t';	//无法访问private成员
		cout << prt_c << '\t';	//可以访问protect成员
		cout << endl;
	}

};

int main1()
{
	class derivedObject1 obj1;
	obj1.printBaseInfo();
	int baseA = obj1.pub_a;	//外部可以访问基类的共有成员
	int baseB = obj1.getB();//外部无法访问基类的私有成员
	int baseC = obj1.getC();//也无法访问保护成员，尽管派生类中可以直接访问。
	cout << endl;


	class derivedObject2 obj2;
	obj2.printBaseInfo();
	//私有派生无法访问基类的任何接口。

	cout << endl;



	class derivedObject3 obj3;
	obj3.printBaseInfo();
	//保护派生同样无法访问基类的任何接口。
	return 0;
}

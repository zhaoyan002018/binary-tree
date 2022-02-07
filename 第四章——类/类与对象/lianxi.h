#pragma once
#include<iomanip>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;
struct Goods
{
	char Name[21];
	int Amount;
	float Price;
	float Total_value;
};

//含有成员对象的类的构造函数
//规则：先构造成员对象的数据，再构造自身类的数据，而反过来析构时，先释放自身的数据，再释放成员对象的数据。
class studentID {
	long value;
public:
	studentID(long id = 0) {
		value = id;
		cout << "赋给学生的学号" << value << endl;
	}
	~studentID()
	{
		cout << "删除学号:" << value << endl;
	}
};

class studentClass {
	long value;
public:
	studentClass(long cls = 0) {
		value = cls;
		cout << "赋给学生的班级" << value << endl;
	}
	~studentClass()
	{
		cout << "删除班级:" << value << endl;
	}
};

class student {
	studentID id;//成员对象的构造顺序与类定义的顺序一致，而与初始化列表中的顺序无关。
	studentClass cls;
	char name[20];
	int test;
public:
	//如果下方只是声明而非初始化的话，则不需要:之后的内容。实际上:后面的部分，属于函数体内，并非声明域。因此:后初始化列表的顺序没有作用，只跟类中定义的顺序有关。
	student(const char sname[] = "no name", long sid = 0) :cls(), id(sid), test(10) {//test是作为变量名进行初始化。
		//TODO why必须要const char？这样做会不会有不良后果？
		cout << "学生名" << sname << endl;
		strcpy(name, sname);
	}
	~student() {
		cout << "删除学生名：" << name << endl;
	}
};




class CGoods
{
public:
	CGoods(char[], int, float);
	CGoods(char[], float);
	CGoods(CGoods&);
	~CGoods();

	void RegisterGoods(char[], int, float);
	void CountTotal(void);
	void GetName(char[]);
	int GetAmount(void);
	float GetPrice(void);
	float GetToal_value(void);

private:
	Goods goods;
};
